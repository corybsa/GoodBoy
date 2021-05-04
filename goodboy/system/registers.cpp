#include "includes/types.h"
#include "includes/registers.h"

byte Registers::get8Bit(int reg) const {
    switch(reg) {
        case 0b000:
            return B;
        case 0b001:
            return C;
        case 0b010:
            return D;
        case 0b011:
            return E;
        case 0b100:
            return H;
        case 0b101:
            return L;
        case 0b111:
            return A;
    }

    return 0;
}

void Registers::set8Bit(int reg, byte value) {
    switch(reg) {
        case 0b000:
            B = value;
        case 0b001:
            C = value;
        case 0b010:
            D = value;
        case 0b011:
            E = value;
        case 0b100:
            H = value;
        case 0b101:
            L = value;
        case 0b111:
            A = value;
    }
}

word Registers::get16Bit(int reg, bool useAF) const {
    switch(reg) {
        case 0b00:
            return BC;
        case 0b01:
            return DE;
        case 0b10:
            return HL;
        case 0b11:
            return useAF ? AF : SP;
    }

    return 0;
}

void Registers::set16Bit(int reg, word value, bool useAF) {
    switch(reg) {
        case 0b00:
            BC = value;
        case 0b01:
            DE = value;
        case 0b10:
            HL = value;
        case 0b11:
            if(useAF) {
                AF = value;
            } else {
                SP = value;
            }
    }
}
