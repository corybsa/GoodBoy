#include "includes/instrs_40_7F.h"

Instrs_40_7F::Instrs_40_7F(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;
}

void Instrs_40_7F::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0x40 through 0x7F running...");
}

void Instrs_40_7F::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_40_7F::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_40_7F::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}