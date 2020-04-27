#include "includes/instrs_80_BF.h"

Instrs_80_BF::Instrs_80_BF(GameBoy* gameBoy) {
    gb = gameBoy;
    rom = nullptr;
}

void Instrs_80_BF::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0x80 through 0xBF running...");
}

void Instrs_80_BF::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_80_BF::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_80_BF::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}
