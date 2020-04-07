#include "includes/memory.h"
#include "includes/globals.h"

#include <iostream>

void Memory::setGpuCallback(std::function<void(word, byte, byte)> callback) {
    gpuCallback = callback;
}

byte Memory::getByteAt(word address) {
    word addr;

    if(address <= 0x3FFF) {
        return cartridge[address];
    } else if(address <= 0x7FFF) {
        addr = (address - 0x4000) + (currentRomBank * 0x4000);
        return cartridge[addr];
    } else if(address <= 0x9FFF) {
        addr = 0x1FFF - (0x9FFF - address);
        return vram[addr];
    } else if(address <= 0xBFFF) {
        addr = (0x1FFF - (0xBFFF - address)) + (currentRamBank * 0x2000);
        return sram[addr];
    } else if(address <= 0xDFFF) {
        addr = 0x1FFF - (0xDFFF - address);
        return wram[addr];
    } else if(address <= 0xFDFF) {
        addr = 0x1DFF - (0xFDFF - address);
        return eram[addr];
    } else if(address <= 0xFE9F) {
        addr = 0x9F - (0xFE9F - address);
        return oam[addr];
    } else if(address <= 0xFEFF) {
        // reading from this area on DMG always returns 0
        return 0x00;
    } else if(address <= 0xFF7F) {
        addr = 0x7F - (0xFF7F - address);
        byte value = io[addr];

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
            byte lcdc = getByteAt(IO_LCDC);

            // when LCD is off, bits 0 through 2 return 0
            if((lcdc & 0x80) != 0x80) {
                return (0x80 | value) & 0xF8;
            } else {
                return (0x80 | value);
            }
        } else if(address == IO_LY_COORDINATE) {
            bool isLcdOn = (getByteAt(IO_LCDC) & 0x80) == 0x80;

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
    } else if(address <= 0xFFFE) {
        addr = 0x7E - (0xFFFE - address);
        return hram[addr];
    } else {
        return ie[0];
    }
}

void Memory::setByteAt(word address, byte value) {
    word addr;

    if(address <= 0x7FFF) {
        writeBank(address, value);
    } else if(address <= 0x9FFF) {
        addr = 0x1FFF - (0x9FFF - address);
        vram[addr] = value;

        word index = addr & 0xFFFE;
        byte byte1 = vram[addr];
        byte byte2 = vram[addr + 1];
        gpuCallback(addr, byte1, byte2);
    } else if(address <= 0xBFFF) {
        addr = 0x1FFF - (0xBFFF - address);

        if(isRamEnabled) {
            addr = (addr - 0x1FFF) + (currentRamBank * 0x2000);
        }

        sram[addr] = value;
    } else if(address <= 0xDFFF) {
        addr = 0x1FFF - (0xDFFF - address);
        wram[addr] = value;

        // writes to this area are copied to eram
        if(addr < 0x1E00) {
            eram[addr] = value;
        }
    } else if(address <= 0xFDFF) {
        addr = 0x1DFF - (0xFDFF - address);

        // writes to this area are redirected to 0xC000 through 0xDDFF (wram & eram)
        wram[addr] = value;
        eram[addr] = value;
    } else if(address <= 0xFE9F) {
        addr = 0x9F - (0xFE9F - address);
        oam[addr] = value;
    } else if(address <= 0xFEFF) {
        // write are ignored on the gameboy
    } else if(address <= 0xFF7F) {
        addr = 0x7F - (0xFF7F - address);

        if(address == IO_DIVIDER) {
            int targetBit = getTimerSystemBit();

            // TIMA can be increased if the system counter has reached half the clocks it needs to increase
            if((TIMER_SYSTEM_COUNTER & targetBit) == targetBit) {
                incrementTima();
            }

            TIMER_SYSTEM_COUNTER = 0;
            io[addr] = 0;
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

            io[addr] = value;
        } else if(address == IO_TAC) {
            int tac = io[addr];
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

            io[addr] = 0xE0 | value;
        } else if(address == IO_LCD_STATUS) {
            int lcdc = getByteAt(IO_LCDC);

            // When LCD is off bits 0 through 2 return 0 also bit 7 is always 1
            if((lcdc & 0x80) != 0x80) {
                io[addr] = (0x80 | value) & 0xF8;
            } else {
                io[addr] = (0x80 | value);
            }
        } else if(address == IO_BG_PALETTE_DATA) {
            BG_PALETTE_DATA = value;
            io[addr] = value;
        } else {
            io[addr] = value;
        }

        if(address == IO_LY_COORDINATE || address == IO_LY_COMPARE) {
            compareLY();
        }
    } else if(address <= 0xFFFE) {
        addr = 0x7E - (0xFFFE - address);
        hram[addr] = value;
    } else {
        ie[0] = value;
    }
}

void Memory::loadRom(byte* rom) {
    cartridge = rom;
    romBankType = getRomBankType(cartridge[0x147]);
}

byte* Memory::getRom() {
    return cartridge;
}

void Memory::updateDiv(byte value) {
    setByteAt(IO_DIVIDER, value);
}

int Memory::getTimerSystemBit() {
    byte tac = getByteAt(IO_TAC) & 0x03;
    return 1 << (9 - (2 * tac));
}

void Memory::incrementTima() {
    int tima = getByteAt(IO_TIMA) + 1;

    if(tima > 0xFF) {
        tima = getByteAt(IO_TMA);
        int flags = getByteAt(IO_INTERRUPT_FLAGS) | INTERRUPT_TIMER;
        setByteAt(IO_INTERRUPT_FLAGS, flags);
    }

    setByteAt(IO_TIMA, tima);
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

    byte lcdc = getByteAt(IO_LCDC);

    // don't compare ly if LCD is OFF
    if((lcdc & 0x80) != 0x80) {
        return;
    }

    byte lyc = getByteAt(IO_LY_COMPARE);
    byte ly = getByteAt(IO_LY_COORDINATE);
    byte status = getByteAt(IO_LCD_STATUS);

    // the enable bit is NOT enabled. skip check.
    if((status & 0x40) != 0x40) {
        return;
    }

    if(lyc == ly) {
        byte interruptFlags = getByteAt(IO_INTERRUPT_FLAGS);

        // set the coincidence flag
        setByteAt(IO_LCD_STATUS, status | 0x04);

        // request LCD STAT interrupt
        setByteAt(IO_INTERRUPT_FLAGS, interruptFlags | INTERRUPT_LCD_STAT);
    } else {
        // clear the coincidence flag
        setByteAt(IO_LCD_STATUS, status | ~0x04);
    }
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

void Memory::writeBank(word address, byte value) {
    /* if(address <= 0x1FFF) {
        if(romBankType == ROM_BANK_MBC1 || romBankType == ROM_BANK_MBC2) {
            enableRamBanking(address, value);
        }
    } else if(address <= 0x3FFF) {
        if(romBankType == ROM_BANK_MBC1 || romBankType == ROM_BANK_MBC2) {
            changeLowRomBank(value);
        }
    } else if(address <= 0x5FFF) {
        if(romBankType == ROM_BANK_MBC1) {
            changeHighRomBank(value);
        } else {
            changeRamBank(value);
        }
    } else if(address <= 0x7FFF) {
        if(romBankType == ROM_BANK_MBC1) {
            changeBankMode(value);
        }
    } */

    if(address <= 0x1FFF) {
        // writing to this address range any value with 0x0A in the lower nibble enables RAM
        if(romBankType == ROM_BANK_MBC1) {
            isRamEnabled = (value & 0x0A) == 0x0A;
        }
    } else if(address <= 0x3FFF) {
        // this range is used to select the lower 5 bits of ROM bank number (0x01 - 0x1F)
        // write 0x00 will be translated to 0x01. This will make banks 0x00, 0x20, 0x40 and 0x60 impossible to map.
        // banks 0x01, 0x21, 0x41 and 0x61 will be selected instead
    } else if(address <= 0x5FFF) {
        // this is a 2 bit register that can select RAM banks 0 - 3 or specify the upper 2 bits of ROM bank, depending on the cartridge.
    } else {
        // this is a 1 bit register that selects if the two bits in register at 0x4000 - 0x5FFF are used to select
        // the two upper bits of the ROM bank number or the RAM bank number
        // mode 0 will enable ROM banking mode (enabled by default).
        // only RAM bank 0 can be accessed in this mode, even if the mapped bank before the mode change wasn't bank 0
        // mode 1 will enable RAM banking mode and only ROM banks 0x01 - 0x1F will be able to be accessed.
        // if other ROM bank is selected ROM bank will be changed to the corresponding in 0x01 - 0x1F by clearing the upper 2 bits
    }
}

void Memory::enableRamBanking(word address, byte value) {
    // when a game wants to enable RAM banking bit 4 must be 0 for MBC2 cartridges
    if(romBankType == ROM_BANK_MBC2 && (address >> 0x10) == 0x10) {
        return;
    }

    // when a game wants to write to RAM banks the lower nibble must be 0x0A
    isRamEnabled = (value & 0x0F) == 0x0A;
}

void Memory::changeLowRomBank(byte value) {
    if(romBankType == ROM_BANK_MBC2) {
        currentRomBank = value & 0x0F;

        // rom bank can't be zero
        if(currentRomBank == 0) {
            currentRomBank = 1;
        }

        return;
    }

    currentRomBank = (currentRomBank & 0xE0) | (value &0x1F);

    if(currentRomBank == 0) {
        currentRomBank = 1;
    }
}

void Memory::changeHighRomBank(byte value) {
    currentRomBank = (currentRomBank & 0x1F) | (value & 0xE0);

    if(currentRomBank == 0) {
        currentRomBank = 1;
    }
}

void Memory::changeRamBank(byte value) {
    currentRamBank = value & 0x03;
}

void Memory::changeBankMode(byte value) {
    if((value & 0x01) == 0) {
        isRomEnabled = true;
        currentRamBank = 0;
    } else {
        isRomEnabled = false;
    }
}
