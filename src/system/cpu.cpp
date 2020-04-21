#include <chrono>
#include <thread>
#include <iostream>
#include "includes/cpu.h"
#include "includes/memory.h"
#include "includes/globals.h"

CPU::CPU(Memory* memory, GPU* gpu, Timers* timers) {
    this->memory = memory;
    this->gpu = gpu;
    this->timers = timers;
    
    reset();
}

/**
 * Sets registers to default values.
 */
void CPU::reset() {
    registers.AF = 0x01B0;
    registers.BC = 0x0013;
    registers.DE = 0x00D8;
    registers.HL = 0x014D;
    registers.SP = 0xFFFE;
    registers.PC = 0x0100;
    cycles = 0;
    cyclesSinceLastSync = 0;
    lastSyncTime = 0;

    ime = false;
    pendingEnableIME = false;

    isHalted = false;
    haltBug = false;
    haltSkip = false;
    
    writeByte(IO_TIMA, 0x00);
    writeByte(IO_TMA, 0x00);
    writeByte(IO_TAC, 0xF8);
    writeByte(IO_INTERRUPT_FLAGS, 0xE1);
    writeByte(IO_SOUND1_SWEEP, 0x80);
    writeByte(IO_SOUND1_LENGTH_WAVE, 0xBF);
    writeByte(IO_SOUND1_ENVELOPE, 0xF3);
    writeByte(IO_SOUND1_HIGH_FREQUENCY, 0xBF);
    writeByte(IO_SOUND2_LENGTH_WAVE, 0x3F);
    writeByte(IO_SOUND2_ENVELOPE, 0x00);
    writeByte(IO_SOUND2_HIGH_FREQUENCY, 0xBF);
    writeByte(IO_SOUND3_ENABLE, 0x7F);
    writeByte(IO_SOUND3_LENGTH, 0xFF);
    writeByte(IO_SOUND3_OUTPUT_LEVEL, 0x9F);
    writeByte(IO_SOUND3_FREQUENCY_HIGH_DATA, 0xBF);
    writeByte(IO_SOUND4_LENGTH, 0xFF);
    writeByte(IO_SOUND4_ENVELOPE, 0x00);
    writeByte(IO_SOUND4_COUNTER, 0x00);
    writeByte(IO_SOUND4_INITIAL, 0xBF);
    writeByte(IO_SOUND_CHANNEL_CONTROL, 0x77);
    writeByte(IO_SOUND_OUTPUT_CONTROL, 0xF3);
    writeByte(IO_SOUND_ENABLE, 0xF1);
    writeByte(IO_LCDC, 0x91);
    writeByte(IO_LCD_STATUS, 0x81);
    writeByte(IO_SCROLL_Y, 0x00);
    writeByte(IO_SCROLL_X, 0x00);
    writeByte(IO_LY_COORDINATE, 0x90);
    writeByte(IO_LY_COMPARE, 0x00);
    writeByte(IO_BG_PALETTE_DATA, 0xFC);
    writeByte(IO_OBJECT_PALETTE0_DATA, 0xFF);
    writeByte(IO_OBJECT_PALETTE1_DATA, 0xFF);
    writeByte(IO_WINDOW_Y, 0x00);
    writeByte(IO_WINDOW_X, 0x00);
    writeByte(IO_INTERRUPT_ENABLE, 0x00);

    gpu->reset();
    timers->reset();
}

/*
    TODO:
        During mode 0 and mode 1 the CPU can access both VRAM and OAM. During mode 2 the CPU
        can only access VRAM, not OAM. During mode 3 OAM and VRAM can't be accessed. In GBC
        mode the CPU can't access Palette RAM (FF69h and FF6Bh) during mode 3.

*/
void CPU::writeByte(int address, int value) {
    memory->writeByte(address, value);
}

byte CPU::readByte(int address) {
    return memory->readByte(address);
}

void CPU::tick() {
    synchronize();

    bool effectiveIme = ime;

    // check if the last instruction was ei
    if(pendingEnableIME) {
        ime = true;
        pendingEnableIME = false;
    }

    // check if there are any interrupts that need to be serviced
    bool shouldServiceInterrupts = (getIF() & getIE()) != 0;

    if(isHalted && !justHalted) {
        incrementCycles(2);
    }

    if(isHalted) {
        incrementCycles(justHalted ? 4 : 2);
    }

    justHalted = false;

    if(isHalted && !effectiveIme && !shouldServiceInterrupts) {
        isHalted = false;
    } else if(effectiveIme && shouldServiceInterrupts) {
        isHalted = false;
        checkInterrupts();
    } else {
        decode(readByte(registers.PC++));
    }
}

/**
 * Sets flags in the F register. If multiple flags should be set, then they should be bitwise or'd together.
 * Example: if Z and H should be set, then they should be passed in to this method like this: Z | H
 */
void CPU::setFlags(int flags) {
    registers.F = (registers.F | flags) & 0xF0;
}

/**
 * Resets flags in the F register. If multiple flags should be reset, then they should be bitwise or'd together.
 * Example: if Z and H should be reset, then they should be passed in to this method like this: Z | H
 */
void CPU::resetFlags(int flags) {
    registers.F = (registers.F & ~flags) & 0xF0;
}

/**
 * Keeps the CPU from running as fast as it can. This will keep the frame rate at 60 fps.
 */
void CPU::synchronize() {
    // don't sync if not enough time passed
    if(cyclesSinceLastSync < LCDC_PERIOD / 3) {
        return;
    }

    // our target sleep time is the length in time the previous instruction took.
    unsigned long long target = (cyclesSinceLastSync * 1000000000LL) / CPU_FREQUENCY;

    // get the current nanoseconds
    unsigned long long nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

    // The sleep duration is the previous instruction time plus how long it's been since we last synced.
    // We subtract the nanoseconds to see if the CPU is running too fast.
    // If sleepDuration is positive that means that the CPU is running incredibly fast (for GameBoy standards, anyway),
    //   and we need to slow it down by sleeping.
    unsigned long long sleepDuration = target + lastSyncTime - nanoseconds;

    // check if sleepDuration is between zero and the time it takes to complete a whole frame.
    if(sleepDuration > 0 && sleepDuration < VBLANK_PERIOD) {
        sleep(sleepDuration);

        // need to keep track of how long it's been since we last synced.
        lastSyncTime = nanoseconds + sleepDuration;
    } else {
        // we need to know when we last synced.
        lastSyncTime = nanoseconds;
    }

    // We only care about the previous instruction, so we can set this to zero and it will be updated
    // after the next instruction is executed.
    cyclesSinceLastSync = 0;
}

/**
 * Sleep for `duration` nanoseconds
 */
void CPU::sleep(unsigned long long duration) {
    std::this_thread::sleep_for(std::chrono::nanoseconds(duration));
}

/**
 * Keep track of how many cycles have elapsed and also keeps track of how many cycles since the components were last synced.
 */
void CPU::incrementCycles(int n) {
    cycles += n;
    cyclesSinceLastSync += n;
    timers->tick(n);
}

/**
 * Check for the 5 different hardware interrupts and service them as needed. They are serviced in order of priority.
 * The priority is as follows:
 * VBLANK, LCD Status, Timer overflow, Serial input, JoyPad input
 *
 * with interrupts, there's three relevant clock edges when stuff happens. One clock edge is when interrupts are
 * checked during opcode fetch. Another is when the target address is decided (this is what is being tested).
 * And the third interesting clock edge is when one bit of IF is cleared
 *
 * first important clock edge (interrupt check) happens at midpoint of the machine cycle when opcode fetch is done. So that's when IME && ((IE & IF) != 0) is evaluated
 *
 * the second important clock edge (decision of which interrupt to handle) happens at midpoint of the machine cycle when the second SP push is done during interrupt dispatch
 *
 * the third important clock edge (clearing of exactly one IF bit) happens at the beginning of the machine cycle after the second SP push
 *
 * so, if for example we take a look at round 1 of ie_push test, these are the machine cycles and what happens during them:
 *
 * Round 1 source code:
 * ; Round 1: IE is written during upper byte push
 * ;
 * ; The written value is $02, which clears the INTR_TIMER bit and cancels the
 * ; interrupt dispatch. PC is set to $0000 instead of the normal jump address.
 * round1:
 *   ld hl, finish_round1
 *   xor a
 *   ldh (<IF), a
 *
 *   ld a, INTR_TIMER
 *   ldh (<IE), a
 *
 *   ei
 *   nop
 *
 *   ld sp, $0000
 *   ldh (<IF), a
 *
 *   jp fail_round1_nointr
 *
 * finish_round1:
 *   ldh a, (<IF)
 *   and %11111
 *   cp INTR_TIMER
 *   jp nz, fail_round1_if
 *
 * initial state: SP=$0000, IF=$04, IE=$04
 * M-cycle 1: jp fail_round1_nointr <- fetch of this JP opcode + interrupt check at the midpoint of the machine cycle.
 *              Interrupt check is positive, so the opcode is thrown away and interrupt dispatch is started
 *
 * M-cycle 2: delay cycle (CPU might do something internally here, but it's not observable in tests)
 * M-cycle 3: SP is decremented
 * M-cycle 4: first SP push ($02 is written to $FFFF), SP is decremented
 * M-cycle 5: second SP push (something is written to $FFFE). The interrupt target check is done at midpoint.
 *              In this case, IF=$04, IE=$02 (because of the write in previous cycle).
 *              IF & IE = $00 so the interrupt dispatch sets PC to $0000
 *
 * M-cycle 6: (clearing of one IF bit would happen here if the target check found a real interrupt target) + opcode fetch from $0000
 */
void CPU::checkInterrupts() {
    // the IME is really a flag saying "enable/disable jumps to interrupt vectors"
    // so if it's disabled, skip checking interrupts
    if(ime) {
        word pc = registers.PC;

        // M-cycle 3: SP is decremented
        registers.SP--;

        // M-cycle 4: first SP push
        writeByte(registers.SP, (pc >> 8) & 0xFF);

        // M-cycle 4 (cont.): this is where interrupts are checked and serviced if needed
        int enabledInterrupts = getIE() & getIF();
        int interrupt = getIF();

        if(enabledInterrupts == 0) {
            registers.PC = 0x00;
        } else if((enabledInterrupts & INTERRUPT_VBLANK) == INTERRUPT_VBLANK) {
            interrupt &= ~INTERRUPT_VBLANK;
            registers.PC = 0x40;
        } else if((enabledInterrupts & INTERRUPT_LCD_STAT) == INTERRUPT_LCD_STAT) {
            interrupt &= ~INTERRUPT_LCD_STAT;
            registers.PC = 0x48;
        } else if((enabledInterrupts & INTERRUPT_TIMER) == INTERRUPT_TIMER) {
            interrupt &= ~INTERRUPT_TIMER;
            registers.PC = 0x50;
        } else if((enabledInterrupts & INTERRUPT_SERIAL) == INTERRUPT_SERIAL) {
            interrupt &= ~INTERRUPT_SERIAL;
            registers.PC = 0x58;
        } else if((enabledInterrupts & INTERRUPT_JOYPAD) == INTERRUPT_JOYPAD) {
            interrupt &= ~INTERRUPT_JOYPAD;
            registers.PC = 0x60;
        } else {
            timers->tick(4);
        }

        // M-cycle 4 (cont.): SP is decremented
        registers.SP--;

        // M-cycle 5: second SP push
        writeByte(registers.SP, pc & 0xFF);

        // M-cycle 6: one IF bit is cleared if necessary
        writeByte(IO_INTERRUPT_FLAGS, interrupt);
    }

    ime = false;

    // the GameBoy takes 20 clock cycles to dispatch an interrupt
    incrementCycles(20);
}

/**
 * Decode op code to find out which instruction to execute.
 */
void CPU::decode(byte opCode) {
    if(haltBug) {
        registers.PC--;
        haltBug = false;
    }

    // if(opCode != 0xCB) {
        int x = opCode >> 6;
        int y = (opCode & 0b00111000) >> 3;
        int z = opCode & 0b00000111;
        int p = y >> 1;
        int q = y % 2;

        switch(x) {
            case 0b00:
                doMiscOperation(y, z, q , p);
                break;
            case 0b01:
                doLoadOperation(y, z);
                break;
            case 0b10:
                doMathOperation(y, z);
                break;
            case 0b11:
                doJumpOperation(y, z, q, p);
                break;
        }
    // } else {
    //     decodeCB(readByte(registers.PC++));
    // }
}

/**
 * Decode CB-prefixed op code to find out which instruction to execute.
 */
void CPU::decodeCB(byte opCode) {
    int x = opCode >> 6;
    int y = (opCode & 0b00111000) >> 3;
    int z = opCode & 0b00000111;

    switch(x) {
        case 0b00:
            switch(y) {
                case 0b000: // rlc
                    if(z != 0b110) {
                        registers.set8Bit(z, rlc(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, rlc(readByte(registers.HL)));
                    }

                    break;
                case 0b001: // rrc
                    if(z != 0b110) {
                        registers.set8Bit(z, rlc(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, rrc(readByte(registers.HL)));
                    }

                    break;
                case 0b010: // rl
                    if(z != 0b110) {
                        registers.set8Bit(z, rl(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, rl(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b011: // rr
                    if(z != 0b110) {
                        registers.set8Bit(z, rr(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, rr(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b100: // sla
                    if(z != 0b110) {
                        registers.set8Bit(z, sla(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, sla(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b101: // sra
                    if(z != 0b110) {
                        registers.set8Bit(z, sra(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, sra(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b110: // swap
                    if(z != 0b110) {
                        registers.set8Bit(z, swap(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, swap(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b111: // srl
                    if(z != 0b110) {
                        registers.set8Bit(z, srl(registers.get8Bit(z)));
                    } else {
                        writeByte(registers.HL, srl(readByte(registers.HL)));
                    }
                    
                    break;
            }
            break;
        case 0b01: // bit
            if(z != 0b110) {
                bit(y, registers.get8Bit(z));
            } else {
                bit(y, readByte(registers.HL));
            }

            break;
        case 0b10: // res
            if(z != 0b110) {
                registers.set8Bit(z, res(y, registers.get8Bit(z)));
            } else {
                writeByte(registers.HL, res(y, readByte(registers.HL)));
            }

            break;
        case 0b11: // set
            if(z != 0b110) {
                registers.set8Bit(z, set(y, registers.get8Bit(z)));
            } else {
                writeByte(registers.HL, set(y, readByte(registers.HL)));
            }

            break;
    }

    // all CB-prefixed op codes have the same size and cycle duration
    if(z != 0b110) {
        incrementCycles(8);
    } else {
        incrementCycles(16);
    }
}

/**
 * Perform various operations.
 */
void CPU::doMiscOperation(int y, int z, int q, int p) {
    switch(z) {
        case 0b000: // relative jumps and assorted ops
            switch(y) {
                case 0b000: // nop
                    incrementCycles(4);

                    break;
                case 0b001: // ld (xx), sp
                    writeByte(getWord(), registers.SP & 0xFF);
                    writeByte(getWord() + 1, registers.SP >> 8);
                    incrementCycles(20);
                    registers.PC += 2;

                    break;
                case 0b010: // stop
                    stop();
                    incrementCycles(4);
                    registers.PC += 1;

                    break;
                case 0b011: // jr x
                    jumpRelative(getByte());
                    incrementCycles(12);

                    break;
                case 0b100: // jr nz x
                    if((registers.F & ZERO) != ZERO) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
                case 0b101: // jr z x
                    if((registers.F & ZERO) == ZERO) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
                case 0b110: // jr nc x
                    if((registers.F & CARRY) != CARRY) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
                case 0b111: // jr c x
                    if((registers.F & CARRY) == CARRY) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
            }

            break;
        case 0b001: // 16-bit immediate load/add
            if(q == 0) { // add [bc, de, hl, sp], [bc, de, hl, sp]
                registers.set16Bit(p, getWord(), false);
                incrementCycles(12);
                registers.PC += 2;
            } else { // add hl, [bc, de, hl, sp]
                registers.HL = add16Bit(registers.HL, registers.get16Bit(p, false));
                incrementCycles(8);
            }

            break;
        case 0b010: // indirect loading
            if(q == 0) {
                switch(p) {
                    case 0b00: // ld (bc), a
                        writeByte(registers.BC, registers.A);

                        break;
                    case 0b01: // ld (de), a
                        writeByte(registers.DE, registers.A);
                        
                        break;
                    case 0b10: // ld (hl+), a
                        writeByte(registers.HL, registers.A);
                        registers.HL++;

                        break;
                    case 0b11: // ld (hl-), a
                        writeByte(registers.HL, registers.A);
                        registers.HL--;

                        break;
                }
            } else {
                switch(p) {
                    case 0b00: // ld a, (bc)
                        registers.A = readByte(registers.BC);

                        break;
                    case 0b01: // ld a, (de)
                        registers.A = readByte(registers.DE);

                        break;
                    case 0b10: // ld a, (hl+)
                        registers.A = readByte(registers.HL);
                        registers.HL++;

                        break;
                    case 0b11: // ld a, (hl-)
                        registers.A = readByte(registers.HL);
                        registers.HL--;

                        break;
                }
            }

            incrementCycles(8);

            break;
        case 0b011: // 16-bit inc/dec
            if(q == 0) { // inc [bc, de, hl, sp]
                registers.set16Bit(p, registers.get16Bit(p, false) + 1, false);
            } else { // dev [bc, de, hl, sp]
                registers.set16Bit(p, registers.get16Bit(p, false) - 1, false);
            }

            incrementCycles(8);

            break;
        case 0b100: // 8-bit inc
            if(y == 0b110) { // inc (hl)
                writeByte(registers.HL, increment(readByte(registers.HL)));
                incrementCycles(8);
            } else { // inc [b, c, d, e, h, l, a]
                registers.set8Bit(y, increment(registers.get8Bit(y)));
                incrementCycles(4);
            }

            break;
        case 0b101: // 8-bit dec
            if(y == 0b110) { // dec (hl)
                writeByte(registers.HL, decrement(readByte(registers.HL)));
                incrementCycles(8);
            } else { // dec [b, c, d, e, h, l, a]
                registers.set8Bit(y, decrement(registers.get8Bit(y)));
                incrementCycles(4);
            }

            break;
        case 0b110: // load immediate 8-bit
            if(y == 0b110) { // ld (hl), x
                writeByte(registers.HL, getByte());
            } else {
                registers.set8Bit(y, getByte());
            }

            incrementCycles(8);
            registers.PC += 1;

            break;
        case 0b111: // assorted operations on accumulator/flags
            doLogicOperation(y);
            incrementCycles(4);

            break;
    }
}

/**
 * Perform various load operations
 */
void CPU::doLoadOperation(int y, int z) {
    if(y == 0b110 && z == 0b110) { // halt
        halt();
        incrementCycles(4);
    } else if(y == z) { // nop
        incrementCycles(4);
    } else {
        if(z == 0b110) { // ld [b, c, d, e, h, l, a], (hl)
            registers.set8Bit(y, readByte(registers.HL));
            incrementCycles(8);
        } else if(y == 0b110) { // ld (hl), [b, c, d, e, h, l, a]
            writeByte(registers.HL, registers.get8Bit(z));
            incrementCycles(8);
        } else { // ld [b, c, d, e, h, l, a], [b, c, d, e, h, l, a]
            registers.set8Bit(y, registers.get8Bit(z));
            incrementCycles(4);
        }
    }
}

/**
 * Perform math operations: add, adc, sub, sbc, and, xor, or, cp.
 */
void CPU::doMathOperation(int y, int z) {
    switch(y) {
        case 0b000: // add
            if(z !=0b110) { // add a, [b, c, d, e, h, l, a]
                registers.A = add8Bit(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // add a, (hl)
                registers.A = add8Bit(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b001: // adc
            if(z !=0b110) { // adc a, [b, c, d, e, h, l, a]
                registers.A = adc(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // adc a, (hl)
                registers.A = adc(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b010: // sub
            if(z !=0b110) { // sub a, [b, c, d, e, h, l, a]
                registers.A = sub(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // sub a, (hl)
                registers.A = sub(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b011: // sbc
            if(z !=0b110) { // sbc a, [b, c, d, e, h, l, a]
                registers.A = sbc(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // sbc a, (hl)
                registers.A = sbc(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b100: // and
            if(z !=0b110) { // bitwiseAnd a, [b, c, d, e, h, l, a]
                registers.A = bitwiseAnd(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // bitwiseAnd a, (hl)
                registers.A = bitwiseAnd(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b101: // xor
            if(z !=0b110) { // bitwiseXor a, [b, c, d, e, h, l, a]
                registers.A = bitwiseXor(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // bitwiseXor a, (hl)
                registers.A = bitwiseXor(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b110: // or
            if(z !=0b110) { // bitwiseOr a, [b, c, d, e, h, l, a]
                registers.A = bitwiseOr(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // bitwiseOr a, (hl)
                registers.A = bitwiseOr(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b111: // cp
            if(z !=0b110) { // cp a, [b, c, d, e, h, l, a]
                cp(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // cp a, (hl)
                cp(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
    }
}

/**
 * Perform jump, call and ret operations.
 */
void CPU::doJumpOperation(int y, int z, int q, int p) {
    byte high = readByte(registers.SP + 1);
    byte low = readByte(registers.SP);

    switch(z) {
        case 0b000: // conditional return
            switch(y) {
                case 0b000: // ret nz
                    if((registers.F & ZERO) != ZERO) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b001: // ret z
                    if((registers.F & ZERO) == ZERO) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b010: // ret nc
                    if((registers.F & CARRY) != CARRY) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b011: // ret c
                    if((registers.F & CARRY) == CARRY) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b100: // ld (x), a
                    writeByte(0xFF00 | getByte(), registers.A);
                    incrementCycles(12);
                    registers.PC += 1;

                    break;
                case 0b101: // add sp, x
                    registers.SP = add16Bit(registers.SP, getByte());
                    setFlags(ZERO);
                    incrementCycles(16);
                    registers.PC += 1;

                    break;
                case 0b110: // ld a, (x)
                    registers.A = readByte(0xFF00 | getByte());
                    incrementCycles(12);
                    registers.PC += 1;

                    break;
                case 0b111: // ld hl, sp+x
                    byte op = getByte();
                    word result = registers.SP + op;

                    // check for carry
                    if((result & 0xFFFF0000) != 0) {
                        setFlags(CARRY);
                    } else {
                        resetFlags(CARRY);
                    }

                    // check for half carry
                    if(((registers.SP & 0x0F) + (op & 0x0F)) > 0x0F) {
                        setFlags(HALF);
                    } else {
                        resetFlags(HALF);
                    }

                    resetFlags(ZERO | SUB);
                    registers.HL = result;
                    incrementCycles(12);
                    registers.PC += 1;

                    break;
            }

            break;
        case 0b001: // pop & various ops
            if(q == 0) { // pop [bc, de, hl, af]
                registers.set16Bit(p, combineBytes(high, low), true);
                registers.SP += 2;
                incrementCycles(12);
            } else {
                switch(p) {
                    case 0b00: // ret
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(16);

                        break;
                    case 0b01: // reti
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        ime = true;
                        incrementCycles(16);

                        break;
                    case 0b10: // jp hl
                        registers.PC = registers.HL;
                        incrementCycles(4);

                        break;
                    case 0b11: // ld sp, hl
                        registers.SP = registers.HL;
                        incrementCycles(8);

                        break;
                }
            }

            break;
        case 0b010: // conditional jump
            if((p >> 1) == 0) {
                switch(y) {
                    case 0b000: // jp nz xx
                        if((registers.F & ZERO) != ZERO) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                    case 0b001: // jp z xx
                        if((registers.F & ZERO) == ZERO) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                    case 0b010: // jp nc xx
                        if((registers.F & CARRY) != CARRY) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                    case 0b011: // jp c xx
                        if((registers.F & CARRY) == CARRY) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                }

                registers.PC += 2;
            } else {
                switch(y) {
                    case 0b100: // ld (c), a
                        writeByte(0xFF00 | registers.C, registers.A);
                        incrementCycles(8);

                        break;
                    case 0b101: // ld (xx), a
                        writeByte(getWord(), registers.A);
                        incrementCycles(16);
                        registers.PC += 2;

                        break;
                    case 0b110: // ld a, (c)
                        registers.A = readByte(0xFF00 | registers.C);
                        incrementCycles(8);

                        break;
                    case 0b111: // ld a, (xx)
                        registers.A = readByte(getWord());
                        incrementCycles(16);
                        registers.PC += 2;

                        break;
                }
            }

            break;
        case 0b011: // assorted operations
            switch(y) {
                case 0b000: // jp xx
                    registers.PC = getWord();
                    incrementCycles(16);

                    break;
                case 0b001: // cb-prefixed operations
                    decodeCB(readByte(registers.PC++));

                    break;
                case 0b010: // nop
                case 0b011: // nop
                case 0b100: // nop
                case 0b101: // nop
                    incrementCycles(4);

                    break;
                case 0b110: // di
                    // di immediately disables the IME and cancels any pending enabled caused by ei
                    ime = false;
                    pendingEnableIME = false;
                    incrementCycles(4);

                    break;
                case 0b111: // ei
                    // ei takes an extra cycle for the ime to be enabled
                    pendingEnableIME = true;
                    incrementCycles(4);

                    break;
            }

            break;
        case 0b100: // conditional calls
            switch(y) {
                case 0b000: // call nz xx
                    if((registers.F & ZERO) != ZERO) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b001: // call z xx
                    if((registers.F & ZERO) == ZERO) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b010: // call nc xx
                    if((registers.F & CARRY) != CARRY) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b011: // call c xx
                    if((registers.F & CARRY) == CARRY) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b100: // nop
                case 0b101: // nop
                case 0b110: // nop
                case 0b111: // nop
                    incrementCycles(4);

                    break;
            }

            break;
        case 0b101: // push & various ops
            if(q == 0) { // push [bc, de, hl, af]
                writeByte(registers.SP - 1, (registers.get16Bit(p, true) >> 8) & 0xFF);
                writeByte(registers.SP - 2, registers.get16Bit(p, true) & 0xFF);
                incrementCycles(16);
            } else {
                if(p == 0) { // call xx
                    call();
                } else { // nop
                    incrementCycles(4);
                }
            }

            break;
        case 0b110: // operate on accumulator and immediate operand
            switch(y) {
                case 0b000: // add a, x
                    registers.A = add8Bit(registers.A, getByte());

                    break;
                case 0b001: // adc a, x
                    registers.A = adc(registers.A, getByte());

                    break;
                case 0b010: // sub a, x
                    registers.A = sub(registers.A, getByte());

                    break;
                case 0b011: // sbc a, x
                    registers.A = sbc(registers.A, getByte());

                    break;
                case 0b100: // and a, x
                    registers.A = bitwiseAnd(registers.A, getByte());

                    break;
                case 0b101: // xor a, x
                    registers.A = bitwiseXor(registers.A, getByte());

                    break;
                case 0b110: // or a, x
                    registers.A = bitwiseOr(registers.A, getByte());

                    break;
                case 0b111: // cp a, x
                    cp(registers.A, getByte());

                    break;
            }

            break;
        case 0b111: // reset
            rst(y * 8);
            incrementCycles(16);

            break;
    }
}

/**
 * Perform logic operations: rlca, rrca, rla, rra, daa, cpl, scf, ccf
 */
void CPU::doLogicOperation(int y) {
    switch(y) {
        case 0b000: // rlca
            rlca();

            break;
        case 0b001: // rrca
            rrca();

            break;
        case 0b010: // rla
            rla();

            break;
        case 0b011: // rra
            rra();

            break;
        case 0b100: // daa
            daa();

            break;
        case 0b101: // cpl
            cpl();

            break;
        case 0b110: // scf
            scf();

            break;
        case 0b111: // ccf
            ccf();

            break;
    }
}

/**
 * Perform a relative jump. Increments PC by the amount of the next byte (between -128 and 127)
 */
void CPU::jumpRelative(signed char op) {
    registers.PC += op + 1;
}

/**
 * Store current PC on the stack and redirect PC to the called address.
 */
void CPU::call() {
    writeByte(registers.SP - 1, ((registers.PC + 2) >> 8) & 0xFF);
    writeByte(registers.SP - 2, (registers.PC + 2) & 0xFF);
    registers.PC = getWord();
    incrementCycles(24);
}

/**
 * Get the next byte from memory.
 */
byte CPU::getByte() {
    return readByte(registers.PC);
}

/**
 * Get the next 2 byte from memory. The GameBoy is Little Endian so the high byte and the low byte
 * are the second and first bytes from the current location, respectively.
 */
word CPU::getWord() {
    byte high = readByte(registers.PC + 1);
    byte low = readByte(registers.PC);
    return combineBytes(high, low);
}

/**
 * Combines two bytes. Example: 0xC0 + 0xDE = 0xC0DE
 */
word CPU::combineBytes(byte high, byte low) {
    return (high << 8) | low;
}

/**
 * Gets the value of the interrupt flags register.
 */
byte CPU::getIF() {
    return readByte(IO_INTERRUPT_FLAGS);
}

/**
 * Gets the value of the interrupt enable register.
 */
byte CPU::getIE() {
    return readByte(IO_INTERRUPT_ENABLE);
}

/**
 * Increments a value by 1 and sets the necessary flags.
 */
byte CPU::increment(byte value) {
    // Flags.HALF - set if there was a carry from the 3rd bit to the 4th bit, otherwise reset.
    if((value & 0x0F) == 0x0F) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    // increment value by 1
    value += 1;

    resetFlags(SUB);

    // Flags.ZERO - set if result is 0, otherwise reset
    if(value == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    return value;
}

/**
 * Decrements a value by 1 and sets the necessary flags.
 * See resources/half-carry-math.txt for explanation
 */
byte CPU::decrement(byte value) {
    // decrement value by 1 and get the first 8 bits
    byte result = value - 1;

    // Flags.HALF - set if there was a carry (borrow) from the 4th bit to the 3rd bit, otherwise reset.
    // invert value's bits, xor with (value - 1) then find out what the 4th bit is with (& 0x10).
    // If it equals zero, then there was a carry.
    if((((~value) ^ result) & 0x10) == 0) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    value = result;

    // SUB flag always set
    setFlags(SUB);

    if(value == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    return value;
}

/**
 * Adds two 16-bit numbers together and sets the necessary flags.
 */
word CPU::add16Bit(word num1, word num2) {
    int result = num1 + num2;

    if((result & 0xFFFF0000) != 0) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    if(((num1 & 0x0F00) + (num2 & 0x0F00)) > 0x0F00) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    resetFlags(SUB);
    return (word)result;
}

/**
 * Adds two 8-bit numbers together and sets the necessary flags.
 */
byte CPU::add8Bit(byte num1, byte num2) {
    int result = num1 + num2;

    if((result & 0xFF00) != 0) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    if((result & 0xFF) == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    if(((num1 & 0x0F) + (num2 & 0x0F)) > 0x0F) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    resetFlags(SUB);
    return (byte)result;
}

/**
 * Adds two 8-bit numbers with the current value of the carry flag and sets the necessary flags.
 */
byte CPU::adc(byte num1, byte num2) {
    int carry = (registers.F & CARRY) >> 4;
    int result = num1 + num2 + carry;

    if((result & 0xFF00) != 0) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    if((result & 0xFF) == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    if(((num1 & 0x0F) + (num2 & 0x0F) + carry) > 0x0F) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    resetFlags(SUB);
    return (byte)result;
}

/**
 * Subtracts num2 from num1 and sets the necessary flags.
 */
byte CPU::sub(byte num1, byte num2) {
    if(num2 > num1) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    if((num2 & 0x0F) > (num1 & 0x0F)) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    byte result = num1 - num2;

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    setFlags(SUB);
    return result;
}

/**
 * Subtracts num2 and the current value of the carry flag from num1 and sets the necessary flags.
 */
byte CPU::sbc(byte num1, byte num2) {
    int result = num1 - num2;
    result = result - ((registers.F & CARRY) >> 4);

    if(result < 0) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    result &= 0xFF;

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    if(((result ^ num2 ^ num1) & 0x10) == 0x10) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    setFlags(SUB);
    return (byte)result;
}

/**
 * Shifts value left, sets the carry flag and the 0th bit to the value of the 7th bit. Sets the necessary flags.
 */
byte CPU::rlc(byte value) {
    // check the 7th bit of value
    if((value & 0x80) == 0x80) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    // sub and half are always reset
    resetFlags(SUB | HALF);

    byte result = ((value << 1) & (~0x01)) | ((value & 0x80) >> 7);

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    return result;
}

/**
 * Shift A left by 1 bit. Carry flag is set to the 7th bit of A.
 */
void CPU::rlca() {
    int carry = (registers.A & 0x80) >> 7;

    if(carry == 1) {
        setFlags(CARRY);
    }

    // shift bit left by 1 and get the first 8 bits and set the 0th bit to whatever was at the 7th bit.
    registers.A = (registers.A << 1) | carry;
    resetFlags(ZERO | SUB | HALF);
}

/**
 * Shifts value right, sets the carry flag and the 7th bit to the value of the 0th bit. Sets the necessary flags.
 */
byte CPU::rrc(byte value) {
    // check the 0th bit of value
    if((value & 0x01) == 0x01) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    // sub and half flags are always reset
    resetFlags(SUB |  HALF);

    // shift A left by 1 bit, change the 0th bit to whatever the carry flag was.
    byte result = ((value >> 1) & (~0x01)) | ((value & 0x01) << 7);

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    return result;
}

/**
 * Shift A right by 1 bit. Carry flag is set to the 0th bit of A.
 */
void CPU::rrca() {
    int carry = registers.A & 0x01;

    if(carry == 1) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    // set the 7th bit to whatever was the the 0th bit
    registers.A = ((registers.A >> 1) & (~0x80)) | (carry << 7);
    resetFlags(ZERO | SUB | HALF);
}

/**
 * Shifts value left, sets the 0th bit to the value of the carry flag. Sets the necessary flags.
 */
byte CPU::rl(byte value) {
    int carry = registers.F & CARRY;

    if((value & 0x80) == 0x80) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    byte result = (value << 1) | carry;

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    return result;
}

/**
 * Shift A left by 1. The 0th bit of A is set to the value of the CARRY flag. CARRY flag is set to the 7th bit of A.
 */
void CPU::rla() {
    // get current state of carry flag.
    int carry = (registers.F & CARRY) >> 4;

    // check the 7th bit of A
    if((registers.A & 0x80) == 0x80) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    // shift A left by 1 bit, change the 0th bit to whatever the carry flag was
    registers.A = ((registers.A << 1) & (~0x01)) | carry;

    // all other flags are reset
    resetFlags(ZERO | SUB | HALF);
}

/**
 * Shifts value right, sets the 7th bit to the value of the carry flag. Sets the necessary flags.
 */
byte CPU::rr(byte value) {
    int carry = registers.F & CARRY;

    if((value & 0x01) == 0x01) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    byte result = (value >> 1) | (carry << 7);

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    return result;
}

/**
 * Shift A right by 1. The 7th bit of A is set to the value of the CARRY flag. CARRY flag is set the 0th bit of A.
 */
void CPU::rra() {
    // get current state of carry flag
    int carry = (registers.F & CARRY) >> 4;

    if((registers.A & 0x01) == 0x01) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    // shift A right by 1 bit, change the 7th bit to whatever the carry flag was.
    registers.A = ((registers.A >> 1) & (~0x80)) | (carry << 7);

    // all other flags are reset.
    resetFlags(ZERO | SUB | HALF);
}

/**
 * Shifts value left, sets the carry flag to the value of the 7th bit, resets the 0th bit. Sets the necessary flags.
 */
byte CPU::sla(byte value) {
    if((value & 0x80) == 0x80) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    byte result = value << 1;

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    resetFlags(SUB | HALF);
    return result;
}

/**
 * Shifts {@code value} right, sets the carry flag to the value of the 0th bit, 7th bit is unchanged. Sets the necessary flags.
 */
byte CPU::sra(byte value) {
    if((value & 0x01) == 0x01) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    byte result = (value >> 1) | (value & 0x80);

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    resetFlags(SUB | HALF);
    return result;
}

/**
 * Swaps the low and high nibbles.
 */
byte CPU::swap(byte value) {
    byte result = ((value & 0x0F) << 4) | (value >> 4);

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    resetFlags(SUB | HALF | CARRY);
    return result;
}

/**
 * Shifts value right, sets the carry flag to the value of the 0th bit, resets the 7th bit. Sets the necessary flags.
 */
byte CPU::srl(byte value) {
    if((value & 0x01) == 0x01) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    byte result = value >> 1;

    if(result == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    resetFlags(SUB | HALF);
    return result;
}

/**
 * When performing addition and subtraction, binary coded decimal (BCD) representation is
 * used to set the contents of register A to a BCD number.
 */
void CPU::daa() {
    bool sub = (registers.F & SUB) == SUB;
    bool half = (registers.F & HALF) == HALF;
    bool carry = (registers.F & CARRY) == CARRY;

    // after an addition, adjust A if HALF or CARRY occurred, or if the result is out of bounds
    if(!sub) {
        if(carry | registers.A > 0x99) {
            registers.A = registers.A + 0x60;
            setFlags(CARRY);
        }

        if(half || (registers.A & 0x0F) > 0x09) {
            registers.A = registers.A + 0x06;
        }
    } else {
        // after a subtraction, only adjust if HALF or CARRY occurred
        if(carry) {
            registers.A = registers.A - 0x60;
        }

        if(half) {
            registers.A = registers.A - 0x06;
        }
    }

    // set ZERO flag if A register is zero
    if(registers.A == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    // HALF is always reset
    resetFlags(HALF);
}

/**
 * Take the one's compliment of A and store the result in A.
 */
void CPU::cpl() {
    registers.A = ~registers.A;
    setFlags(SUB | HALF);
}

/**
 * Sets carry flag, resets half carry and subtraction flags.
 */
void CPU::scf() {
    setFlags(CARRY);
    resetFlags(SUB | HALF);
}

/**
 * Toggle the carry flag.
 */
void CPU::ccf() {
    int carry = (~registers.F & CARRY) >> 4;

    if(carry == 1) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }
}

/**
 * Copies the compliment of the specified bit at position. Sets the necessary flags.
 */
void CPU::bit(int position, byte value) {
    byte result = ~(value >> position) & 0x01;

    if(result == 1) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    setFlags(HALF);
    resetFlags(SUB);
}

/**
 * Resets the bit at position.
 */
byte CPU::res(int position, byte value) {
    // shift 1 left by however many places then invert all the bits.
    // this will give you a 0 in the place you want to reset.
    // then just bitwise AND it with the value and that bit is reset!
    return value & ~(0x01 << position);
}

/**
 * Sets the bit at position.
 */
byte CPU::set(int position, byte value) {
    return value | (0x01 << position);
}

/**
 * Performs a bitwise and operation on num1 and num2.
 */
byte CPU::bitwiseAnd(byte num1, byte num2) {
    num1 &= num2;

    if(num1 == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    setFlags(HALF);
    resetFlags(SUB | CARRY);

    return num1;
}

/**
 * Performs a bitwise xor operation on num1 and num2.
 */
byte CPU::bitwiseXor(byte num1, byte num2) {
    num1 ^= num2;

    if(num1 == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    resetFlags(SUB | HALF | CARRY);

    return num1;
}

/**
 * Performs a bitwise or operation on num1 and num2.
 */
byte CPU::bitwiseOr(byte num1, byte num2) {
    num1 |= num2;

    if(num1 == 0) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    resetFlags(SUB | HALF | CARRY);

    return num1;
}

/**
 * Compares the contents of num1 and num2 and sets flags if they are equal.
 */
void CPU::cp(byte num1, byte num2) {
    if(num1 == num2) {
        setFlags(ZERO);
    } else {
        resetFlags(ZERO);
    }

    if((num1 & 0x0F) < (num2 & 0x0F)) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    if(num1 < num2) {
        setFlags(CARRY);
    } else {
        resetFlags(CARRY);
    }

    setFlags(SUB);
}

/**
 * Push PC onto stack and reset PC to address.
 */
void CPU::rst(word address) {
    writeByte(registers.SP - 1, (registers.PC >> 8) & 0xFF);
    writeByte(registers.SP - 2, registers.PC & 0xFF);
    registers.PC = address;
}

/**
 * Stops the CPU
 */
void CPU::stop() {
    isStopped = true;
}

/**
 * Halts the CPU
 */
void CPU::halt() {
    int flags = getIF();
    int ie = getIE();

    if(ime) {
        /*
            HALT executed normally. CPU stops executing instructions until (IE & IF & 1F) != 0. When
            a flag in IF is set and the corresponding IE flag is also set, the CPU jumps to the interrupt
            vector. The return address pushed to the stack is the next instruction to the HALT, not the
            HALT itself. The IF flag corresponding to the vector the CPU has jumped in is cleared.
        */
        isHalted = true;
    } else {
        /*
            HALT mode is entered. It works like the IME = 1 case, but when an IF flag is set and
            the corresponding IE flag is also set, the CPU doesn't jump to the interrupt vector, it
            just continues executing instructions. The IF flags aren't cleared.
        */
        if((ie & flags & 0x1F) == 0) {
            isHalted = true;
            haltSkip = true;
        }
        /*
            HALT mode is not entered. HALT bug occurs: The CPU fails to increase PC when
            executing the next instruction. The IF flags aren't cleared. This results in weird
            behaviour.
        */
        else {
            isHalted = false;
            haltBug = true;
        }
    }

    justHalted = true;
}
