#include <chrono>
#include <thread>
#include <iostream>
#include <sstream>
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

    isRunning = false;
    ime = false;
    pendingEnableIME = false;
    isStopped = false;
    isHalted = false;
    haltBug = false;
    justHalted = false;
    
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
    Timers::reset();
}

/*
    TODO:
        During mode 0 and mode 1 the CPU can access both VRAM and OAM.
        During mode 2 the CPU can only access VRAM, not OAM.
        During mode 3 OAM and VRAM can't be accessed.
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

    int x = opCode >> 6; // the opcode's 1st octal digit (i.e. bits 7-6)
    int y = (opCode & 0b00111000) >> 3; // the opcode's 2nd octal digit (i.e. bits 5-3)
    int z = opCode & 0b00000111; // the opcode's 3rd octal digit (i.e. bits 2-0)
    int p = y >> 1; // y rightshifted one position (i.e. bits 5-4)
    int q = y % 2; // y modulo 2 (i.e. bit 3)

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
}

/**
 * Decode CB-prefixed op code to find out which instruction to execute.
 */
void CPU::decodeCB(byte opCode) {
    int x = opCode >> 6; // the opcode's 1st octal digit (i.e. bits 7-6)
    int y = (opCode & 0b00111000) >> 3; // the opcode's 2nd octal digit (i.e. bits 5-3)
    int z = opCode & 0b00000111; // the opcode's 3rd octal digit (i.e. bits 2-0)

    switch(x) {
        case 0b00:
            switch(y) {
                case 0b000: // rlc [b, c, d, e, h, l, a] | 0xCB00, 0xCB01, 0xCB02, 0xCB03, 0xCB04, 0xCB05, 0xCB07
                    if(z != 0b110) {
                        registers.set8Bit(z, rlc(registers.get8Bit(z)));
                    } else { // rlc (hl) | 0xCB06
                        writeByte(registers.HL, rlc(readByte(registers.HL)));
                    }

                    break;
                case 0b001: // rrc [b, c, d, e, h, l, a] | 0xCB08, 0xCB09, 0xCB0A, 0xCB0B, 0xCB0C, 0xCB0E, 0xCB0F
                    if(z != 0b110) {
                        registers.set8Bit(z, rrc(registers.get8Bit(z)));
                    } else { // rrc (hl) | 0xCB0E
                        writeByte(registers.HL, rrc(readByte(registers.HL)));
                    }

                    break;
                case 0b010: // rl [b, c, d, e, h, l, a] | 0xCB10, 0xCB11, 0xCB12, 0xCB13, 0xCB14, 0xCB15, 0xCB17
                    if(z != 0b110) {
                        registers.set8Bit(z, rl(registers.get8Bit(z)));
                    } else { // rl (hl) | 0xCB16
                        writeByte(registers.HL, rl(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b011: // rr [b, c, d, e, h, l, a] | 0xCB18, 0xCB19, 0xCB1A, 0xCB1B, 0xCB1C, 0xCB1E, 0xCB1F
                    if(z != 0b110) {
                        registers.set8Bit(z, rr(registers.get8Bit(z)));
                    } else { // rr (hl) | 0xCB1E
                        writeByte(registers.HL, rr(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b100: // sla [b, c, d, e, h, l, a] | 0xCB20, 0xCB21, 0xCB22, 0xCB23, 0xCB24, 0xCB25, 0xCB27
                    if(z != 0b110) {
                        registers.set8Bit(z, sla(registers.get8Bit(z)));
                    } else { // sla (hl) | 0xCB26
                        writeByte(registers.HL, sla(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b101: // sra [b, c, d, e, h, l, a] | 0xCB28, 0xCB29, 0xCB2A, 0xCB2B, 0xCB2C, 0xCB2E, 0xCB2F
                    if(z != 0b110) {
                        registers.set8Bit(z, sra(registers.get8Bit(z)));
                    } else { // sra (hl) | 0xCB2E
                        writeByte(registers.HL, sra(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b110: // swap [b, c, d, e, h, l, a] | 0xCB30, 0xCB31, 0xCB32, 0xCB33, 0xCB34, 0xCB35, 0xCB37
                    if(z != 0b110) {
                        registers.set8Bit(z, swap(registers.get8Bit(z)));
                    } else { // swap (hl) | 0xCB36
                        writeByte(registers.HL, swap(readByte(registers.HL)));
                    }
                    
                    break;
                case 0b111: // srl [b, c, d, e, h, l, a] | 0xCB38, 0xCB39, 0xCB3A, 0xCB3B, 0xCB3C, 0xCB3E, 0xCB3F
                    if(z != 0b110) {
                        registers.set8Bit(z, srl(registers.get8Bit(z)));
                    } else { // srl (hl) | 0xCB3E
                        writeByte(registers.HL, srl(readByte(registers.HL)));
                    }
                    
                    break;
            }
            break;
        case 0b01: // bit [0, 1, 2, 3, 4, 5, 6, 7], [b, c, d, e, h, l, a]
            // 0xCB40, 0xCB41, 0xCB42, 0xCB43, 0xCB44, 0xCB45, 0xCB47, 0xCB48, 0xCB49, 0xCB4A, 0xCB4B, 0xCB4C, 0xCB4D, 0xCB4F
            // 0xCB50, 0xCB51, 0xCB52, 0xCB53, 0xCB54, 0xCB55, 0xCB57, 0xCB58, 0xCB59, 0xCB5A, 0xCB5B, 0xCB5C, 0xCB5D, 0xCB5F
            // 0xCB60, 0xCB61, 0xCB62, 0xCB63, 0xCB64, 0xCB65, 0xCB67, 0xCB68, 0xCB69, 0xCB6A, 0xCB6B, 0xCB6C, 0xCB6D, 0xCB6F
            // 0xCB70, 0xCB71, 0xCB72, 0xCB73, 0xCB74, 0xCB75, 0xCB77, 0xCB78, 0xCB79, 0xCB7A, 0xCB7B, 0xCB7C, 0xCB7D, 0xCB7F
            if(z != 0b110) {
                bit(y, registers.get8Bit(z));
            } else { // bit [0, 1, 2, 3, 4, 5, 6, 7], (hl)
                // 0xCB46, 0xCB4E, 0xCB56, 0xCB5E, 0xCB66, 0xCB6E, 0xCB76, 0xCB7E
                bit(y, readByte(registers.HL));
            }

            break;
        case 0b10: // res [0, 1, 2, 3, 4, 5, 6, 7], [b, c, d, e, h, l, a]
            // 0xCB80, 0xCB81, 0xCB82, 0xCB83, 0xCB84, 0xCB85, 0xCB87, 0xCB88, 0xCB89, 0xCB8A, 0xCB8B, 0xCB8C, 0xCB8D, 0xCB8F
            // 0xCB90, 0xCB91, 0xCB92, 0xCB93, 0xCB94, 0xCB95, 0xCB97, 0xCB98, 0xCB99, 0xCB9A, 0xCB9B, 0xCB9C, 0xCB9D, 0xCB9F
            // 0xCBA0, 0xCBA1, 0xCBA2, 0xCBA3, 0xCBA4, 0xCBA5, 0xCBA7, 0xCBA8, 0xCBA9, 0xCBAA, 0xCBAB, 0xCBAC, 0xCBAD, 0xCBAF
            // 0xCBB0, 0xCBB1, 0xCBB2, 0xCBB3, 0xCBB4, 0xCBB5, 0xCBB7, 0xCBB8, 0xCBB9, 0xCBBA, 0xCBBB, 0xCBBC, 0xCBBD, 0xCBBF
            if(z != 0b110) {
                registers.set8Bit(z, res(y, registers.get8Bit(z)));
            } else { // res [0, 1, 2, 3, 4, 5, 6, 7], (hl)
                // 0xCB86, 0xCB8E, 0xCB96, 0xCB9E, 0xCBA6, 0xCBAE, 0xCBB6, 0xCBBE
                writeByte(registers.HL, res(y, readByte(registers.HL)));
            }

            break;
        case 0b11: // set [0, 1, 2, 3, 4, 5, 6, 7], [b, c, d, e, h, l, a]
            // 0xCBC0, 0xCBC1, 0xCBC2, 0xCBC3, 0xCBC4, 0xCBC5, 0xCBC7, 0xCBC8, 0xCBC9, 0xCBCA, 0xCBCB, 0xCBCC, 0xCBCD, 0xCBCF
            // 0xCBD0, 0xCBD1, 0xCBD2, 0xCBD3, 0xCBD4, 0xCBD5, 0xCBD7, 0xCBD8, 0xCBD9, 0xCBDA, 0xCBDB, 0xCBDC, 0xCBDD, 0xCBDF
            // 0xCBE0, 0xCBE1, 0xCBE2, 0xCBE3, 0xCBE4, 0xCBE5, 0xCBE7, 0xCBE8, 0xCBE9, 0xCBEA, 0xCBEB, 0xCBEC, 0xCBED, 0xCBEF
            // 0xCBF0, 0xCBF1, 0xCBF2, 0xCBF3, 0xCBF4, 0xCBF5, 0xCBF7, 0xCBF8, 0xCBF9, 0xCBFA, 0xCBFB, 0xCBFC, 0xCBFD, 0xCBFF
            if(z != 0b110) {
                registers.set8Bit(z, set(y, registers.get8Bit(z)));
            } else { // set [0, 1, 2, 3, 4, 5, 6, 7], (hl)
                // 0xCBC6, 0xCBCE, 0xCBD6, 0xCBDE, 0xCBE6, 0xCBEE, 0xCBF6, 0xCBFE
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
                case 0b000: // nop | 0x00
                    incrementCycles(4);

                    break;
                case 0b001: // ld (xx), sp | 0x08
                    writeByte(getWord(), registers.SP & 0xFF);
                    writeByte(getWord() + 1, registers.SP >> 8);
                    incrementCycles(20);
                    registers.PC += 2;

                    break;
                case 0b010: // stop | 0x10
                    stop();
                    incrementCycles(4);
                    registers.PC += 1;

                    break;
                case 0b011: // jr x | 0x18
                    jumpRelative(getByte());
                    incrementCycles(12);

                    break;
                case 0b100: // jr nz x | 0x20
                    if((registers.F & ZERO) != ZERO) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
                case 0b101: // jr z x | 0x28
                    if((registers.F & ZERO) == ZERO) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
                case 0b110: // jr nc x | 0x30
                    if((registers.F & CARRY) != CARRY) {
                        jumpRelative(getByte());
                        incrementCycles(12);
                    } else {
                        incrementCycles(8);
                        registers.PC += 1;
                    }

                    break;
                case 0b111: // jr c x | 0x38
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
            if(q == 0) { // ld [bc, de, hl, sp], xx | 0x01, 0x11, 0x21, 0x31
                registers.set16Bit(p, getWord(), false);
                incrementCycles(12);
                registers.PC += 2;
            } else { // add hl, [bc, de, hl, sp] | 0x09, 0x19, 0x29, 0x39
                registers.HL = add16Bit(registers.HL, registers.get16Bit(p, false));
                incrementCycles(8);
            }

            break;
        case 0b010: // indirect loading
            if(q == 0) {
                switch(p) {
                    case 0b00: // ld (bc), a | 0x02
                        writeByte(registers.BC, registers.A);

                        break;
                    case 0b01: // ld (de), a | 0x12
                        writeByte(registers.DE, registers.A);
                        
                        break;
                    case 0b10: // ld (hl+), a | 0x22
                        writeByte(registers.HL, registers.A);
                        registers.HL++;

                        break;
                    case 0b11: // ld (hl-), a | 0x32
                        writeByte(registers.HL, registers.A);
                        registers.HL--;

                        break;
                }
            } else {
                switch(p) {
                    case 0b00: // ld a, (bc) | 0x0A
                        registers.A = readByte(registers.BC);

                        break;
                    case 0b01: // ld a, (de) | 0x1A
                        registers.A = readByte(registers.DE);

                        break;
                    case 0b10: // ld a, (hl+) | 0x2A
                        registers.A = readByte(registers.HL);
                        registers.HL++;

                        break;
                    case 0b11: // ld a, (hl-) | 0x3A
                        registers.A = readByte(registers.HL);
                        registers.HL--;

                        break;
                }
            }

            incrementCycles(8);

            break;
        case 0b011: // 16-bit inc/dec
            if(q == 0) { // inc [bc, de, hl, sp] | 0x03, 0x13, 0x23, 0x33
                registers.set16Bit(p, registers.get16Bit(p, false) + 1, false);
            } else { // dev [bc, de, hl, sp] | 0x0B, 0x1B, 0x2B, 0x3B
                registers.set16Bit(p, registers.get16Bit(p, false) - 1, false);
            }

            incrementCycles(8);

            break;
        case 0b100: // 8-bit inc
            if(y == 0b110) { // inc (hl) | 0x34
                writeByte(registers.HL, increment(readByte(registers.HL)));
                incrementCycles(12);
            } else { // inc [b, c, d, e, h, l, a] | 0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C, 0x3C
                registers.set8Bit(y, increment(registers.get8Bit(y)));
                incrementCycles(4);
            }

            break;
        case 0b101: // 8-bit dec
            if(y == 0b110) { // dec (hl) | 0x35
                writeByte(registers.HL, decrement(readByte(registers.HL)));
                incrementCycles(12);
            } else { // dec [b, c, d, e, h, l, a] | 0x05, 0x0D, 0x15, 0x1D, 0x25, 0x2D, 0x3D
                registers.set8Bit(y, decrement(registers.get8Bit(y)));
                incrementCycles(4);
            }

            break;
        case 0b110: // load immediate 8-bit
            if(y == 0b110) { // ld (hl), x | 0x36
                writeByte(registers.HL, getByte());
            } else { // ld [b, c, d, e, h, l, a], x | 0x06, 0x0E, 0x16, 0x1E, 0x26, 0x2E, 0x3E
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
    if(y == 0b110 && z == 0b110) { // halt | 0x76
        halt();
        incrementCycles(4);
    } else {
        if(z == 0b110) { // ld [b, c, d, e, h, l, a], (hl) | 0x46, 0x4E, 0x56, 0x5E, 0x66, 0x6E, 0x7E
            registers.set8Bit(y, readByte(registers.HL));
            incrementCycles(8);
        } else if(y == 0b110) { // ld (hl), [b, c, d, e, h, l, a] | 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x77
            writeByte(registers.HL, registers.get8Bit(z));
            incrementCycles(8);
        } else { // ld [b, c, d, e, h, l, a], [b, c, d, e, h, l, a]
            // 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4F
            // 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x5F
            // 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x67, 0x68, 0x69, 0x6A, 0x6B, 0x6C, 0x6D, 0x6F
            // 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7F
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
            if(z !=0b110) { // add a, [b, c, d, e, h, l, a] | 0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x87
                registers.A = add8Bit(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // add a, (hl) | 0x86
                registers.A = add8Bit(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b001: // adc
            if(z !=0b110) { // adc a, [b, c, d, e, h, l, a] | 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8F
                registers.A = adc(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // adc a, (hl) | 0x8E
                registers.A = adc(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b010: // sub
            if(z !=0b110) { // sub [b, c, d, e, h, l, a] | 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x97
                registers.A = sub(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // sub (hl) | 0x96
                registers.A = sub(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b011: // sbc
            if(z !=0b110) { // sbc a, [b, c, d, e, h, l, a] | 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9F
                registers.A = sbc(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // sbc a, (hl) | 0x9E
                registers.A = sbc(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b100: // and
            if(z !=0b110) { // and [b, c, d, e, h, l, a] | 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA7
                registers.A = bitwiseAnd(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // and (hl) | 0xA6
                registers.A = bitwiseAnd(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b101: // xor
            if(z !=0b110) { // xor [b, c, d, e, h, l, a] | 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAF
                registers.A = bitwiseXor(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // xor (hl) | 0xAE
                registers.A = bitwiseXor(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b110: // or
            if(z !=0b110) { // or [b, c, d, e, h, l, a] | 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB7
                registers.A = bitwiseOr(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // or (hl) | 0xB6
                registers.A = bitwiseOr(registers.A, readByte(registers.HL));
                incrementCycles(8);
            }

            break;
        case 0b111: // cp
            if(z !=0b110) { // cp [b, c, d, e, h, l, a] | 0xB8, 0xB9, 0xBA, 0xBB, 0xBC, 0xBD, 0xBF
                cp(registers.A, registers.get8Bit(z));
                incrementCycles(4);
            } else { // cp (hl) | 0xBE
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
                case 0b000: // ret nz | 0xC0
                    if((registers.F & ZERO) != ZERO) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b001: // ret z | 0xC8
                    if((registers.F & ZERO) == ZERO) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b010: // ret nc | 0xD0
                    if((registers.F & CARRY) != CARRY) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b011: // ret c | 0xD8
                    if((registers.F & CARRY) == CARRY) {
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(20);
                    } else {
                        incrementCycles(8);
                    }

                    break;
                case 0b100: // ldh (x), a | 0xE0
                    writeByte(0xFF00 | getByte(), registers.A);
                    incrementCycles(12);
                    registers.PC += 1;

                    break;
                case 0b101: // add sp, x | 0xE8
                    registers.SP = add16Bit(registers.SP, (int8_t)getByte());
                    setFlags(ZERO);
                    incrementCycles(16);
                    registers.PC += 1;

                    break;
                case 0b110: // ldh a, (x) | 0xF0
                    registers.A = readByte(0xFF00 | getByte());
                    incrementCycles(12);
                    registers.PC += 1;

                    break;
                case 0b111: // ld hl, sp+x | 0xF8
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
            if(q == 0) { // pop [bc, de, hl, af] | 0xC1, 0xD1, 0xE1, 0xF1
                registers.set16Bit(p, combineBytes(high, low), true);
                registers.SP += 2;
                incrementCycles(12);
            } else {
                switch(p) {
                    case 0b00: // ret | 0xC9
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        incrementCycles(16);

                        break;
                    case 0b01: // reti | 0xD9
                        registers.PC = combineBytes(high, low);
                        registers.SP += 2;
                        ime = true;
                        incrementCycles(16);

                        break;
                    case 0b10: // jp hl | 0xE9
                        registers.PC = registers.HL;
                        incrementCycles(4);

                        break;
                    case 0b11: // ld sp, hl | 0xF9
                        registers.SP = registers.HL;
                        incrementCycles(8);

                        break;
                }
            }

            break;
        case 0b010: // conditional jump
            if((p >> 1) == 0) {
                switch(y) {
                    case 0b000: // jp nz, xx | 0xC2
                        if((registers.F & ZERO) != ZERO) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                    case 0b001: // jp z, xx | 0xCA
                        if((registers.F & ZERO) == ZERO) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                    case 0b010: // jp nc, xx | 0xD2
                        if((registers.F & CARRY) != CARRY) {
                            registers.PC = getWord() - 2;
                            incrementCycles(16);
                        } else {
                            incrementCycles(12);
                        }

                        break;
                    case 0b011: // jp c, xx | 0xDA
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
                    case 0b100: // ld (c), a | 0xE2
                        writeByte(0xFF00 | registers.C, registers.A);
                        incrementCycles(8);

                        break;
                    case 0b101: // ld (xx), a | 0xEA
                        writeByte(getWord(), registers.A);
                        incrementCycles(16);
                        registers.PC += 2;

                        break;
                    case 0b110: // ld a, (c) | 0xF2
                        registers.A = readByte(0xFF00 | registers.C);
                        incrementCycles(8);

                        break;
                    case 0b111: // ld a, (xx) | 0xFA
                        registers.A = readByte(getWord());
                        incrementCycles(16);
                        registers.PC += 2;

                        break;
                }
            }

            break;
        case 0b011: // assorted operations
            switch(y) {
                case 0b000: // jp xx | 0xC3
                    registers.PC = getWord();
                    incrementCycles(16);

                    break;
                case 0b001: // cb-prefixed operations | 0xCB
                    decodeCB(readByte(registers.PC++));

                    break;
                case 0b010: // illegal opcode | 0xD3
                case 0b011: // illegal opcode | 0xDB
                case 0b100: // illegal opcode | 0xE3
                case 0b101: // illegal opcode | 0xEB
                    illegalOpcode();

                    break;
                case 0b110: // di | 0xF3
                    // di immediately disables the IME and cancels any pending enabled caused by ei
                    ime = false;
                    pendingEnableIME = false;
                    incrementCycles(4);

                    break;
                case 0b111: // ei | 0xFB
                    // ei takes an extra cycle for the ime to be enabled
                    pendingEnableIME = true;
                    incrementCycles(4);

                    break;
            }

            break;
        case 0b100: // conditional calls
            switch(y) {
                case 0b000: // call nz xx | 0xC4
                    if((registers.F & ZERO) != ZERO) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b001: // call z xx | 0xCC
                    if((registers.F & ZERO) == ZERO) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b010: // call nc xx | 0xD4
                    if((registers.F & CARRY) != CARRY) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b011: // call c xx | 0xDC
                    if((registers.F & CARRY) == CARRY) {
                        call();
                    } else {
                        incrementCycles(12);
                        registers.PC += 2;
                    }

                    break;
                case 0b100: // illegal opcode | 0xE4
                case 0b101: // illegal opcode | 0xEC
                case 0b110: // illegal opcode | 0xF4
                case 0b111: // illegal opcode | 0xFC
                    illegalOpcode();

                    break;
            }

            break;
        case 0b101: // push & various ops
            if(q == 0) { // push [bc, de, hl, af] | 0xC5, 0xD5, 0xE5, 0xF5
                writeByte(registers.SP - 1, (registers.get16Bit(p, true) >> 8) & 0xFF);
                writeByte(registers.SP - 2, registers.get16Bit(p, true) & 0xFF);
                incrementCycles(16);
            } else {
                if(p == 0) { // call xx | 0xCD
                    call();
                } else { // illegal opcode | 0xED, 0xFD
                    illegalOpcode();
                }
            }

            break;
        case 0b110: // operate on accumulator and immediate operand
            switch(y) {
                case 0b000: // add a, x | 0xC6
                    registers.A = add8Bit(registers.A, getByte());

                    break;
                case 0b001: // adc a, x | 0xCE
                    registers.A = adc(registers.A, getByte());

                    break;
                case 0b010: // sub a, x | 0xD6
                    registers.A = sub(registers.A, getByte());

                    break;
                case 0b011: // sbc a, x | 0xDE
                    registers.A = sbc(registers.A, getByte());

                    break;
                case 0b100: // and a, x | 0xE6
                    registers.A = bitwiseAnd(registers.A, getByte());

                    break;
                case 0b101: // xor a, x | 0xEE
                    registers.A = bitwiseXor(registers.A, getByte());

                    break;
                case 0b110: // or a, x | 0xF6
                    registers.A = bitwiseOr(registers.A, getByte());

                    break;
                case 0b111: // cp a, x | 0xFE
                    cp(registers.A, getByte());

                    break;
            }

            incrementCycles(8);
            registers.PC += 1;

            break;
        case 0b111: // reset | 0xC7, 0xCF, 0xD7, 0xDF, 0xE7, 0xEF, 0xF7, 0xFF
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
        case 0b000: // rlca | 0x07
            rlca();

            break;
        case 0b001: // rrca | 0x0F
            rrca();

            break;
        case 0b010: // rla | 0x17
            rla();

            break;
        case 0b011: // rra | 0x1F
            rra();

            break;
        case 0b100: // daa | 0x27
            daa();

            break;
        case 0b101: // cpl | 0x2F
            cpl();

            break;
        case 0b110: // scf | 0x37
            scf();

            break;
        case 0b111: // ccf | 0x3F
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
    registers.SP -= 2;
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
    // HALF - set if there was a carry from the 3rd bit to the 4th bit, otherwise reset.
    if((value & 0x0F) == 0x0F) {
        setFlags(HALF);
    } else {
        resetFlags(HALF);
    }

    // increment value by 1
    value += 1;

    resetFlags(SUB);

    // ZERO - set if result is 0, otherwise reset
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

    // HALF - set if there was a carry (borrow) from the 4th bit to the 3rd bit, otherwise reset.
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
        if(carry || registers.A > 0x99) {
            registers.A += 0x60;
            setFlags(CARRY);
        }

        if(half || (registers.A & 0x0F) > 0x09) {
            registers.A += 0x06;
        }
    } else {
        // after a subtraction, only adjust if HALF or CARRY occurred
        if(carry) {
            registers.A -= 0x60;
        }

        if(half) {
            registers.A -= 0x06;
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
    registers.SP -= 2;
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

void CPU::illegalOpcode() {
    ime = false;
    isHalted = true;
}

std::string CPU::toString() {
    std::stringstream ss;
    ss << "AF: 0x" << toHex(registers.AF) << "\t" << "LCDC: 0x" << toHex(readByte(IO_LCDC)) << std::endl;
    ss << "BC: 0x" << toHex(registers.BC) << "\t" << "STAT: 0x" << toHex(readByte(IO_LCD_STATUS)) << std::endl;
    ss << "DE: 0x" << toHex(registers.DE) << "\t" << "LY:   0x" << toHex(readByte(IO_LY_COORDINATE)) << std::endl;
    ss << "HL: 0x" << toHex(registers.HL) << "\t" << "IE:   0x" << toHex(readByte(IO_INTERRUPT_ENABLE)) << std::endl;
    ss << "PC: 0x" << toHex(registers.PC) << "\t" << "IF:   0x" << toHex(readByte(IO_INTERRUPT_FLAGS)) << std::endl;
    ss << "SP: 0x" << toHex(registers.SP) << "\t" << "IME:  " << (ime ? "on" : "off") << std::endl;
    return ss.str();
}

