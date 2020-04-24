#include "includes/instrs_C0_FF.h"

Instrs_C0_FF::Instrs_C0_FF(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;
}

void Instrs_C0_FF::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_C0_FF::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_C0_FF::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_C0_FF::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}
