#include "includes/memory.h"
#include "includes/globals.h"
#include <iostream>
#include <utility>

Memory::Memory() {
    cartridge = new byte[0x800000];
    ram = new byte[0x8000];
}

Memory::~Memory() {
    delete[] ram;

    cartridge = nullptr;
    ram = nullptr;
}

int Memory::getRomBankType(byte value) {
    switch(value) {
        case 0x01:
        case 0x02:
        case 0x03:
            return ROM_BANK_MBC1;
        case 0x05:
        case 0x06:
            return ROM_BANK_MBC2;
        case 0x0F:
        case 0x10:
        case 0x11:
        case 0x12:
        case 0x13:
            return ROM_BANK_MBC3;
        case 0x19:
        case 0x1A:
        case 0x1B:
        case 0x1C:
        case 0x1D:
        case 0x1E:
            return ROM_BANK_MBC5;
        case 0x20:
            return ROM_BANK_MBC6;
        case 0x22:
            return ROM_BANK_MBC7;
        default:
            return ROM_BANK_NONE;
    }
}

void Memory::setGpuCallback(std::function<void(word, byte, byte)> callback) {
    gpuCallback = std::move(callback);
}

byte Memory::readByte(word address) {
    word addr;

    if(address <= 0x3FFF) {
        return cartridge[address];
    } else if(address <= 0x7FFF) {
        addr = (address - 0x4000) + (currentRomBank * 0x4000);
        return cartridge[addr];
    } else if(address >= 0xA000 && address <= 0xBFFF) {
        addr = 0x1FFF - (0xBFFF - address);

        if(isRamBankEnabled) {
            addr = (addr - 0x1FFF) + (currentRamBank * 0x2000);
        }

        if(addr > 0x1FFF) {
            return cartridge[addr];
        }
    } else if(address >= 0xFEA0 && address <= 0xFEFF) {
        return 0;
    } else if(address >= 0xFF00 && address <= 0xFF7F) {
        return readIO(address);
    }

    return ram[address];
}

void Memory::writeByte(word address, byte value) {
    word addr;

    if(address <= 0x7FFF) {
        writeBank(address, value);
    } else if(address <= 0x9FFF) {
        addr = 0x1FFF - (0x9FFF - address);
        ram[address] = value;

        byte byte1 = ram[addr];
        byte byte2 = ram[addr + 1];
        gpuCallback(addr, byte1, byte2);
    } else if(address <= 0xBFFF) {
        // TODO: make sure this is right
        addr = 0x1FFF - (0xBFFF - address);

        if(isRamBankEnabled) {
            addr = (addr - 0x1FFF) + (currentRamBank * 0x2000);
        }

        if(addr > 0x1FFF) {
            cartridge[addr] = value;
        } else {
            ram[address] = value;
        }
    } else if(address <= 0xDFFF) {
        addr = 0x1FFF - (0xDFFF - address);
        ram[address] = value;

        // writes to this area are copied to eram
        if(addr < 0x1E00) {
            ram[address + 0x1000] = value;
        }
    } else if(address >= 0xE000 && address <= 0xFDFF) {
        // writes to this area are redirected to 0xC000 through 0xDDFF (wram & eram)
        ram[address] = value;
        ram[address - 0x2000] = value;
    } else if(address >= 0xFEA0 && address <= 0xFEFF) {
        // write are ignored on the gameboy
    } else if(address <= 0xFF7F) {
        writeIO(address, value);
    } else {
        ram[address] = value;
    }
}

byte Memory::readIO(word address) {
    byte value = ram[address];

    if(address == IO_JOYPAD) {
        // the upper 2 bits always returns 1
        return 0xC0 | value;
    } else if(address == IO_SERIAL_TRANSFER_CONTROL) {
        // bits 1 through 6 return 1
        return 0x7E | value;
    } else if(address == IO_TAC) {
        // the upper 5 bits always return 1
        return 0xF8 | value;
    } else if(address == IO_INTERRUPT_FLAGS) {
        // the upper 3 bits always return 1
        return 0xE0 | value;
    } else if(address == IO_SOUND1_SWEEP) {
        // the 7th bit always returns 1
        return 0x80 | value;
    } else if(address == IO_SOUND3_ENABLE) {
        // bits 0 through 6  always return 1
        return 0x7F | value;
    } else if(address == IO_SOUND3_OUTPUT_LEVEL) {
        // bits 0 through 4 and bit 7 always return 1
        return 0x9F | value;
    } else if(address == IO_SOUND4_LENGTH) {
        // bits 6 and 7 always return 1
        return 0xC0 | value;
    } else if(address == IO_SOUND4_INITIAL) {
        // bits 0 through 5 always return 1
        return 0x3F | value;
    } else if(address == IO_SOUND_ENABLE) {
        // bits 4 through 6 always return 1
        return 0x70 | value;
    } else if(address == IO_LCD_STATUS) {
        byte lcdc = readIO(IO_LCDC);

        // when LCD is off, bits 0 through 2 return 0
        if((lcdc & 0x80) != 0x80) {
            return (0x80 | value) & 0xF8;
        } else {
            return (0x80 | value);
        }
    } else if(address == IO_LY_COORDINATE) {
        bool isLcdOn = (readIO(IO_LCDC) & 0x80) == 0x80;

        // when LCD is off, always return 0
        if(!isLcdOn) {
            return 0x00;
        }
    } else if(address >= 0xFF4C && address <= 0xFF7F) {
        // addresses between 0xFF4C and 0xFF7F always return 0xFF
        return 0xFF;
    } else {
        return value;
    }
}

void Memory::writeIO(word address, byte value) {
    if(address == IO_SERIAL_TRANSFER_DATA) {
        // TODO: remove this once I have LCD support
        std::cout << (char)value;
    } else if(address == IO_DIVIDER) {
        int targetBit = getTimerSystemBit();

        // TIMA can be increased if the system counter has reached half the clocks it needs to increase
        if((TIMER_SYSTEM_COUNTER & targetBit) == targetBit) {
            incrementTima();
        }

        TIMER_SYSTEM_COUNTER = 0;
        ram[address] = 0;
        return;
    } else if(address == IO_TIMA) {
        if(TIMER_STATE == TIMER_STATE_OVERFLOW) {
            // if a value is written to TIMA during the overflow period, the new value will override the TMA load
            TIMER_IS_TIMA_CHANGED = true;
            TIMER_TIMA_GLITCH = true;
        } else if(TIMER_STATE == TIMER_STATE_LOADING_TMA) {
            // if a value is written to TIMA during the period when TMA is being loaded, the write will be ignored
            TIMER_IS_TIMA_CHANGED = true;
        }

        ram[address] = value;
    } else if(address == IO_TAC) {
        int tac = ram[address];
        int oldEnable = tac & 0x04;
        int newEnable = value & 0x04;
        int targetBit = getTimerSystemBit();

        // When disabling the timer, if the system counter has reached half the clocks it
        // needs to increase, TIMA will increase
        if((oldEnable == 0x04) && (newEnable == 0) && ((TIMER_SYSTEM_COUNTER & targetBit) == targetBit)) {
            incrementTima();
        }

        int oldValue = tac & 0x03;
        int newValue = value & 0x03;

        // When changing TAC value, if the old selected bit was 0, the new one is 1 and the
        // new enable bit is 1, TIMA will increase
        if((oldValue == 0) && (newValue == 1) && (newEnable == 0x04)) {
            incrementTima();
        }
    } else if(address == IO_INTERRUPT_FLAGS) {
        // If TIMA has a pending overflow, the written value will overwrite the automatic flag set to 1.
        // If a 0 is written during this time, the interrupt won't happen.
        if(TIMER_STATE == TIMER_STATE_OVERFLOW) {
            TIMER_IS_FLAGS_CHANGED = true;
        } else if(TIMER_STATE == TIMER_STATE_LOADING_TMA) {
            TIMER_IS_FLAGS_CHANGED = true;
            TIMER_FLAG_VALUE = (value & INTERRUPT_TIMER) >> 2;
        }

        ram[address] = 0xE0 | value;
    } else if(address == IO_LCD_STATUS) {
        int lcdc = readIO(IO_LCDC);

        // When LCD is off bits 0 through 2 return 0 also bit 7 is always 1
        if((lcdc & 0x80) != 0x80) {
            ram[address] = (0x80 | value) & 0xF8;
        } else {
            ram[address] = (0x80 | value);
        }
    } else if(address == IO_BG_PALETTE_DATA) {
        BG_PALETTE_DATA = value;
        ram[address] = value;
    } else {
        ram[address] = value;
    }

    if(address == IO_LY_COORDINATE || address == IO_LY_COMPARE) {
        compareLY();
    }
}

void Memory::loadRom(byte* rom) {
    cartridge = rom;
    romBankType = getRomBankType(cartridge[0x147]);
}

void Memory::updateDiv(byte value) {
    writeIO(IO_DIVIDER, value);
}

int Memory::getTimerSystemBit() {
    byte tac = readIO(IO_TAC) & 0x03;
    return 1 << (9 - (2 * tac));
}

void Memory::incrementTima() {
    int tima = readIO(IO_TIMA) + 1;

    if(tima > 0xFF) {
        tima = readIO(IO_TMA);
        int flags = readIO(IO_INTERRUPT_FLAGS) | INTERRUPT_TIMER;
        writeIO(IO_INTERRUPT_FLAGS, flags);
    }

    writeIO(IO_TIMA, tima);
}

/**
 * The GameBoy permanently compares the value of the LYC and LY registers. When both values are identical,
 * the LY=LYC Comparison bit (2nd bit) in the STAT register becomes set, and (if enabled) a STAT interrupt is requested.
 */
void Memory::compareLY() {
    /*

    It seems as if the compare will always return 0 when the scanline starts a new line.
    The actual check only occurs after a few cycles. And it looks like it checks what the value was on the PREVIOUS cycle...
    If the check succeeds, the LY=LYC interrupt will be set in the IF register in the same clock cycle. No delay in setting the interrupt flag.

    Now something weird happens on line 153:
    The check is delayed like the other lines but, on line 153 it goes something like this:
    TODO: figure this out

    */

    byte lcdc = readIO(IO_LCDC);

    // don't compare ly if LCD is OFF
    if((lcdc & 0x80) != 0x80) {
        return;
    }

    byte lyc = readIO(IO_LY_COMPARE);
    byte ly = readIO(IO_LY_COORDINATE);
    byte status = readIO(IO_LCD_STATUS);

    // the enable bit is NOT enabled. skip check.
    if((status & 0x40) != 0x40) {
        return;
    }

    if(lyc == ly) {
        byte interruptFlags = readIO(IO_INTERRUPT_FLAGS);

        // set the coincidence flag
        writeIO(IO_LCD_STATUS, status | 0x04);

        // request LCD STAT interrupt
        writeIO(IO_INTERRUPT_FLAGS, interruptFlags | INTERRUPT_LCD_STAT);
    } else {
        // clear the coincidence flag
        writeIO(IO_LCD_STATUS, status | ~0x04);
    }
}

void Memory::writeBank(word address, byte value) {
    if(address <= 0x1FFF) { // RAM enable
        /* 
            Before a game is able to use the RAM, it must be specifically enabled. This is done by writing a value with the
            lower 4 bits being $0A somewhere in this address space. To disable RAM, any number except $0A can be written.
            It does not matter where it is written, just as long as it within the address range. You will notice that this address range
            is part of the first ROM bank, which is read only. Because it is ROM, there is obviously no way to actually write data
            to those memory locations. Instead, the write call is "intercepted" and interpreted differently by the MBC.
        */
        isRamBankEnabled = (value & 0x0A) == 0x0A;
    } else if(address <= 0x3FFF) { // ROM Bank Number
        /*
            Writing a value to this address range will select the lower 5 bits of the bank number. There are a few special cases though.
            If the value $00 is written, it will converted to bank $01. This is not an issue because bank $00 is always present at $0000-$3FFF.
            The issue lies in writing the values $20, $40, and $60. When these values are written, instead of addressing the correct ROM banks
            they will address banks $21, $41 and $61 respectively. I couldn't find an explanation of why this takes place, but I assume it has
            something to do with how the lower 5 bits are used when choosing the bank. Each of these numbers have all zeros as the lower 5 bits (0x0XX00000).
            This issue is not present in MBC2 and MBC3.

            Switching to a ROM Bank < $20
            -----------------------------
            Switching to banks $01-$1F is very simple. We only need to write our intended bank to $2000-$3FFF. Here we are switching to bank $05:

                ld $2000, $05
                ; Now able to read data from bank $05
        

            Switching to a ROM Bank > $1F
            -----------------------------
            To switch to a ROM bank greater than $1F, there is some extra legwork to be done. First, we need to switch to the ROM banking mode.
            Then we write the lower 5 bits to $2000-$3FFF and the upper 2 bits to $4000-$5FFF. For this example, I will be loading bank $46.
            This value is 0b0100 0b0110 in binary.
                ld $6000, $00    ; Set ROM mode
                ld $2000, $06    ; Set lower 5 bits, could also use $46
                ld $4000, $02    ; Set upper 2 bits
                ; Now able to read data from bank $46
        */
        if(value == 0x00 || value == 0x20 || value == 0x40 || value == 0x60) {
            value++;
        }

        if(value < 0x20) {
            currentRomBank = value & 0x1F;
        } else {
            currentRomBank = (value & 0x1F) | currentRomBank;
        }
    } else if(address <= 0x5FFF) { // RAM Bank Number or Upper Bits of ROM Bank Number
        // this is a 2 bit register that can select RAM banks 0 - 3 or specify the upper 2 bits of ROM bank, depending on the cartridge.

        /*
            Writing to this area of memory will effect the ROM or RAM modes, depending on what is written in $6000-$7FFF. Only the first
            two bits of the value matter. If in ROM mode (no RAM bank switching), it will specify the upper two bits of the ROM bank number.
            In this mode, only RAM bank $00 may be used.

            If in RAM mode, it will specify which RAM bank to load into $A000-$BFFF. In this mode, only ROM banks $00-$1F may be used.
        */
        if(!isRamBankEnabled) {
            // set the upper 2 bits
            currentRomBank = (value & 0x02) << 5 | currentRomBank;
        } else {
            currentRamBank = value & 0x03;
        }
    } else { // ROM/RAM Mode Select
        /*
            Writing either $00 or $01 to this area will select which mode the MBC is in. On an MBC1, there are two modes: 16Mb ROM/8KB RAM and 4Mb ROM/32KB RAM.
            The game is able to switch between the modes on the fly, allowing a game to access extended ROM banks during normal operation and switch to
            RAM mode temporarily when data needs to be read. Valid values are $00 for ROM mode and $01 for RAM mode.
        */
        if((value & 0x01) == 0x01) {
            // mode 1 will enable RAM banking mode and only ROM banks 0x01 - 0x1F will be able to be accessed.
            // if other ROM bank is selected ROM bank will be changed to the corresponding in 0x01 - 0x1F by clearing the upper 2 bits
            isRamBankEnabled = true;
            currentRomBank = currentRomBank & 0x3F;
        } else {
            // mode 0 will enable ROM banking mode (enabled by default).
            // only RAM bank 0 can be accessed in this mode, even if the mapped bank before the mode change wasn't bank 0
            currentRamBank = 0;
        }
    }
}
