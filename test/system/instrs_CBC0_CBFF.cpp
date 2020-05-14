#include "includes/instrs_CBC0_CBFF.h"

Instrs_CBC0_CBFF::Instrs_CBC0_CBFF(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xCBC0(); });
    Test::addTest([this]() -> void { test_0xCBC1(); });
    Test::addTest([this]() -> void { test_0xCBC2(); });
    Test::addTest([this]() -> void { test_0xCBC3(); });
    Test::addTest([this]() -> void { test_0xCBC4(); });
    Test::addTest([this]() -> void { test_0xCBC5(); });
    Test::addTest([this]() -> void { test_0xCBC6(); });
    Test::addTest([this]() -> void { test_0xCBC7(); });
    Test::addTest([this]() -> void { test_0xCBC8(); });
    Test::addTest([this]() -> void { test_0xCBC9(); });
    Test::addTest([this]() -> void { test_0xCBCA(); });
    Test::addTest([this]() -> void { test_0xCBCB(); });
    Test::addTest([this]() -> void { test_0xCBCC(); });
    Test::addTest([this]() -> void { test_0xCBCD(); });
    Test::addTest([this]() -> void { test_0xCBCE(); });
    Test::addTest([this]() -> void { test_0xCBCF(); });

    Test::addTest([this]() -> void { test_0xCBD0(); });
    Test::addTest([this]() -> void { test_0xCBD1(); });
    Test::addTest([this]() -> void { test_0xCBD2(); });
    Test::addTest([this]() -> void { test_0xCBD3(); });
    Test::addTest([this]() -> void { test_0xCBD4(); });
    Test::addTest([this]() -> void { test_0xCBD5(); });
    Test::addTest([this]() -> void { test_0xCBD6(); });
    Test::addTest([this]() -> void { test_0xCBD7(); });
    Test::addTest([this]() -> void { test_0xCBD8(); });
    Test::addTest([this]() -> void { test_0xCBD9(); });
    Test::addTest([this]() -> void { test_0xCBDA(); });
    Test::addTest([this]() -> void { test_0xCBDB(); });
    Test::addTest([this]() -> void { test_0xCBDC(); });
    Test::addTest([this]() -> void { test_0xCBDD(); });
    Test::addTest([this]() -> void { test_0xCBDE(); });
    Test::addTest([this]() -> void { test_0xCBDF(); });

    Test::addTest([this]() -> void { test_0xCBE0(); });
    Test::addTest([this]() -> void { test_0xCBE1(); });
    Test::addTest([this]() -> void { test_0xCBE2(); });
    Test::addTest([this]() -> void { test_0xCBE3(); });
    Test::addTest([this]() -> void { test_0xCBE4(); });
    Test::addTest([this]() -> void { test_0xCBE5(); });
    Test::addTest([this]() -> void { test_0xCBE6(); });
    Test::addTest([this]() -> void { test_0xCBE7(); });
    Test::addTest([this]() -> void { test_0xCBE8(); });
    Test::addTest([this]() -> void { test_0xCBE9(); });
    Test::addTest([this]() -> void { test_0xCBEA(); });
    Test::addTest([this]() -> void { test_0xCBEB(); });
    Test::addTest([this]() -> void { test_0xCBEC(); });
    Test::addTest([this]() -> void { test_0xCBED(); });
    Test::addTest([this]() -> void { test_0xCBEE(); });
    Test::addTest([this]() -> void { test_0xCBEF(); });

    Test::addTest([this]() -> void { test_0xCBF0(); });
    Test::addTest([this]() -> void { test_0xCBF1(); });
    Test::addTest([this]() -> void { test_0xCBF2(); });
    Test::addTest([this]() -> void { test_0xCBF3(); });
    Test::addTest([this]() -> void { test_0xCBF4(); });
    Test::addTest([this]() -> void { test_0xCBF5(); });
    Test::addTest([this]() -> void { test_0xCBF6(); });
    Test::addTest([this]() -> void { test_0xCBF7(); });
    Test::addTest([this]() -> void { test_0xCBF8(); });
    Test::addTest([this]() -> void { test_0xCBF9(); });
    Test::addTest([this]() -> void { test_0xCBFA(); });
    Test::addTest([this]() -> void { test_0xCBFB(); });
    Test::addTest([this]() -> void { test_0xCBFC(); });
    Test::addTest([this]() -> void { test_0xCBFD(); });
    Test::addTest([this]() -> void { test_0xCBFE(); });
    Test::addTest([this]() -> void { test_0xCBFF(); });
}

void Instrs_CBC0_CBFF::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_CBC0_CBFF::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_CBC0_CBFF::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_CBC0_CBFF::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region rCBC0_CBCF

void Instrs_CBC0_CBFF::test_0xCBC0() {}
void Instrs_CBC0_CBFF::test_0xCBC1() {}
void Instrs_CBC0_CBFF::test_0xCBC2() {}
void Instrs_CBC0_CBFF::test_0xCBC3() {}
void Instrs_CBC0_CBFF::test_0xCBC4() {}
void Instrs_CBC0_CBFF::test_0xCBC5() {}
void Instrs_CBC0_CBFF::test_0xCBC6() {}
void Instrs_CBC0_CBFF::test_0xCBC7() {}
void Instrs_CBC0_CBFF::test_0xCBC8() {}
void Instrs_CBC0_CBFF::test_0xCBC9() {}
void Instrs_CBC0_CBFF::test_0xCBCA() {}
void Instrs_CBC0_CBFF::test_0xCBCB() {}
void Instrs_CBC0_CBFF::test_0xCBCC() {}
void Instrs_CBC0_CBFF::test_0xCBCD() {}
void Instrs_CBC0_CBFF::test_0xCBCE() {}
void Instrs_CBC0_CBFF::test_0xCBCF() {}

#pragma endregion

#pragma region rCBD0_CBDF

void Instrs_CBC0_CBFF::test_0xCBD0() {}
void Instrs_CBC0_CBFF::test_0xCBD1() {}
void Instrs_CBC0_CBFF::test_0xCBD2() {}
void Instrs_CBC0_CBFF::test_0xCBD3() {}
void Instrs_CBC0_CBFF::test_0xCBD4() {}
void Instrs_CBC0_CBFF::test_0xCBD5() {}
void Instrs_CBC0_CBFF::test_0xCBD6() {}
void Instrs_CBC0_CBFF::test_0xCBD7() {}
void Instrs_CBC0_CBFF::test_0xCBD8() {}
void Instrs_CBC0_CBFF::test_0xCBD9() {}
void Instrs_CBC0_CBFF::test_0xCBDA() {}
void Instrs_CBC0_CBFF::test_0xCBDB() {}
void Instrs_CBC0_CBFF::test_0xCBDC() {}
void Instrs_CBC0_CBFF::test_0xCBDD() {}
void Instrs_CBC0_CBFF::test_0xCBDE() {}
void Instrs_CBC0_CBFF::test_0xCBDF() {}

#pragma endregion

#pragma region rCBE0_CBEF

void Instrs_CBC0_CBFF::test_0xCBE0() {}
void Instrs_CBC0_CBFF::test_0xCBE1() {}
void Instrs_CBC0_CBFF::test_0xCBE2() {}
void Instrs_CBC0_CBFF::test_0xCBE3() {}
void Instrs_CBC0_CBFF::test_0xCBE4() {}
void Instrs_CBC0_CBFF::test_0xCBE5() {}
void Instrs_CBC0_CBFF::test_0xCBE6() {}
void Instrs_CBC0_CBFF::test_0xCBE7() {}
void Instrs_CBC0_CBFF::test_0xCBE8() {}
void Instrs_CBC0_CBFF::test_0xCBE9() {}
void Instrs_CBC0_CBFF::test_0xCBEA() {}
void Instrs_CBC0_CBFF::test_0xCBEB() {}
void Instrs_CBC0_CBFF::test_0xCBEC() {}
void Instrs_CBC0_CBFF::test_0xCBED() {}
void Instrs_CBC0_CBFF::test_0xCBEE() {}
void Instrs_CBC0_CBFF::test_0xCBEF() {}

#pragma endregion

#pragma region rCBF0_CBFF

void Instrs_CBC0_CBFF::test_0xCBF0() {}
void Instrs_CBC0_CBFF::test_0xCBF1() {}
void Instrs_CBC0_CBFF::test_0xCBF2() {}
void Instrs_CBC0_CBFF::test_0xCBF3() {}
void Instrs_CBC0_CBFF::test_0xCBF4() {}
void Instrs_CBC0_CBFF::test_0xCBF5() {}
void Instrs_CBC0_CBFF::test_0xCBF6() {}
void Instrs_CBC0_CBFF::test_0xCBF7() {}
void Instrs_CBC0_CBFF::test_0xCBF8() {}
void Instrs_CBC0_CBFF::test_0xCBF9() {}
void Instrs_CBC0_CBFF::test_0xCBFA() {}
void Instrs_CBC0_CBFF::test_0xCBFB() {}
void Instrs_CBC0_CBFF::test_0xCBFC() {}
void Instrs_CBC0_CBFF::test_0xCBFD() {}
void Instrs_CBC0_CBFF::test_0xCBFE() {}
void Instrs_CBC0_CBFF::test_0xCBFF() {}

#pragma endregion
