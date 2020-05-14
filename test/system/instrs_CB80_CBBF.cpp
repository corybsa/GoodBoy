#include "includes/instrs_CB80_CBBF.h"

Instrs_CB80_CBBF::Instrs_CB80_CBBF(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xCB80(); });
    Test::addTest([this]() -> void { test_0xCB81(); });
    Test::addTest([this]() -> void { test_0xCB82(); });
    Test::addTest([this]() -> void { test_0xCB83(); });
    Test::addTest([this]() -> void { test_0xCB84(); });
    Test::addTest([this]() -> void { test_0xCB85(); });
    Test::addTest([this]() -> void { test_0xCB86(); });
    Test::addTest([this]() -> void { test_0xCB87(); });
    Test::addTest([this]() -> void { test_0xCB88(); });
    Test::addTest([this]() -> void { test_0xCB89(); });
    Test::addTest([this]() -> void { test_0xCB8A(); });
    Test::addTest([this]() -> void { test_0xCB8B(); });
    Test::addTest([this]() -> void { test_0xCB8C(); });
    Test::addTest([this]() -> void { test_0xCB8D(); });
    Test::addTest([this]() -> void { test_0xCB8E(); });
    Test::addTest([this]() -> void { test_0xCB8F(); });

    Test::addTest([this]() -> void { test_0xCB90(); });
    Test::addTest([this]() -> void { test_0xCB91(); });
    Test::addTest([this]() -> void { test_0xCB92(); });
    Test::addTest([this]() -> void { test_0xCB93(); });
    Test::addTest([this]() -> void { test_0xCB94(); });
    Test::addTest([this]() -> void { test_0xCB95(); });
    Test::addTest([this]() -> void { test_0xCB96(); });
    Test::addTest([this]() -> void { test_0xCB97(); });
    Test::addTest([this]() -> void { test_0xCB98(); });
    Test::addTest([this]() -> void { test_0xCB99(); });
    Test::addTest([this]() -> void { test_0xCB9A(); });
    Test::addTest([this]() -> void { test_0xCB9B(); });
    Test::addTest([this]() -> void { test_0xCB9C(); });
    Test::addTest([this]() -> void { test_0xCB9D(); });
    Test::addTest([this]() -> void { test_0xCB9E(); });
    Test::addTest([this]() -> void { test_0xCB9F(); });

    Test::addTest([this]() -> void { test_0xCBA0(); });
    Test::addTest([this]() -> void { test_0xCBA1(); });
    Test::addTest([this]() -> void { test_0xCBA2(); });
    Test::addTest([this]() -> void { test_0xCBA3(); });
    Test::addTest([this]() -> void { test_0xCBA4(); });
    Test::addTest([this]() -> void { test_0xCBA5(); });
    Test::addTest([this]() -> void { test_0xCBA6(); });
    Test::addTest([this]() -> void { test_0xCBA7(); });
    Test::addTest([this]() -> void { test_0xCBA8(); });
    Test::addTest([this]() -> void { test_0xCBA9(); });
    Test::addTest([this]() -> void { test_0xCBAA(); });
    Test::addTest([this]() -> void { test_0xCBAB(); });
    Test::addTest([this]() -> void { test_0xCBAC(); });
    Test::addTest([this]() -> void { test_0xCBAD(); });
    Test::addTest([this]() -> void { test_0xCBAE(); });
    Test::addTest([this]() -> void { test_0xCBAF(); });

    Test::addTest([this]() -> void { test_0xCBB0(); });
    Test::addTest([this]() -> void { test_0xCBB1(); });
    Test::addTest([this]() -> void { test_0xCBB2(); });
    Test::addTest([this]() -> void { test_0xCBB3(); });
    Test::addTest([this]() -> void { test_0xCBB4(); });
    Test::addTest([this]() -> void { test_0xCBB5(); });
    Test::addTest([this]() -> void { test_0xCBB6(); });
    Test::addTest([this]() -> void { test_0xCBB7(); });
    Test::addTest([this]() -> void { test_0xCBB8(); });
    Test::addTest([this]() -> void { test_0xCBB9(); });
    Test::addTest([this]() -> void { test_0xCBBA(); });
    Test::addTest([this]() -> void { test_0xCBBB(); });
    Test::addTest([this]() -> void { test_0xCBBC(); });
    Test::addTest([this]() -> void { test_0xCBBD(); });
    Test::addTest([this]() -> void { test_0xCBBE(); });
    Test::addTest([this]() -> void { test_0xCBBF(); });
}

void Instrs_CB80_CBBF::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_CB80_CBBF::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_CB80_CBBF::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_CB80_CBBF::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region rCB80_CB8F

void Instrs_CB80_CBBF::test_0xCB80() {}
void Instrs_CB80_CBBF::test_0xCB81() {}
void Instrs_CB80_CBBF::test_0xCB82() {}
void Instrs_CB80_CBBF::test_0xCB83() {}
void Instrs_CB80_CBBF::test_0xCB84() {}
void Instrs_CB80_CBBF::test_0xCB85() {}
void Instrs_CB80_CBBF::test_0xCB86() {}
void Instrs_CB80_CBBF::test_0xCB87() {}
void Instrs_CB80_CBBF::test_0xCB88() {}
void Instrs_CB80_CBBF::test_0xCB89() {}
void Instrs_CB80_CBBF::test_0xCB8A() {}
void Instrs_CB80_CBBF::test_0xCB8B() {}
void Instrs_CB80_CBBF::test_0xCB8C() {}
void Instrs_CB80_CBBF::test_0xCB8D() {}
void Instrs_CB80_CBBF::test_0xCB8E() {}
void Instrs_CB80_CBBF::test_0xCB8F() {}

#pragma endregion

#pragma region rCB90_CB9F

void Instrs_CB80_CBBF::test_0xCB90() {}
void Instrs_CB80_CBBF::test_0xCB91() {}
void Instrs_CB80_CBBF::test_0xCB92() {}
void Instrs_CB80_CBBF::test_0xCB93() {}
void Instrs_CB80_CBBF::test_0xCB94() {}
void Instrs_CB80_CBBF::test_0xCB95() {}
void Instrs_CB80_CBBF::test_0xCB96() {}
void Instrs_CB80_CBBF::test_0xCB97() {}
void Instrs_CB80_CBBF::test_0xCB98() {}
void Instrs_CB80_CBBF::test_0xCB99() {}
void Instrs_CB80_CBBF::test_0xCB9A() {}
void Instrs_CB80_CBBF::test_0xCB9B() {}
void Instrs_CB80_CBBF::test_0xCB9C() {}
void Instrs_CB80_CBBF::test_0xCB9D() {}
void Instrs_CB80_CBBF::test_0xCB9E() {}
void Instrs_CB80_CBBF::test_0xCB9F() {}

#pragma endregion

#pragma region rCBA0_CBAF

void Instrs_CB80_CBBF::test_0xCBA0() {}
void Instrs_CB80_CBBF::test_0xCBA1() {}
void Instrs_CB80_CBBF::test_0xCBA2() {}
void Instrs_CB80_CBBF::test_0xCBA3() {}
void Instrs_CB80_CBBF::test_0xCBA4() {}
void Instrs_CB80_CBBF::test_0xCBA5() {}
void Instrs_CB80_CBBF::test_0xCBA6() {}
void Instrs_CB80_CBBF::test_0xCBA7() {}
void Instrs_CB80_CBBF::test_0xCBA8() {}
void Instrs_CB80_CBBF::test_0xCBA9() {}
void Instrs_CB80_CBBF::test_0xCBAA() {}
void Instrs_CB80_CBBF::test_0xCBAB() {}
void Instrs_CB80_CBBF::test_0xCBAC() {}
void Instrs_CB80_CBBF::test_0xCBAD() {}
void Instrs_CB80_CBBF::test_0xCBAE() {}
void Instrs_CB80_CBBF::test_0xCBAF() {}

#pragma endregion

#pragma region rCBB0_CBBF

void Instrs_CB80_CBBF::test_0xCBB0() {}
void Instrs_CB80_CBBF::test_0xCBB1() {}
void Instrs_CB80_CBBF::test_0xCBB2() {}
void Instrs_CB80_CBBF::test_0xCBB3() {}
void Instrs_CB80_CBBF::test_0xCBB4() {}
void Instrs_CB80_CBBF::test_0xCBB5() {}
void Instrs_CB80_CBBF::test_0xCBB6() {}
void Instrs_CB80_CBBF::test_0xCBB7() {}
void Instrs_CB80_CBBF::test_0xCBB8() {}
void Instrs_CB80_CBBF::test_0xCBB9() {}
void Instrs_CB80_CBBF::test_0xCBBA() {}
void Instrs_CB80_CBBF::test_0xCBBB() {}
void Instrs_CB80_CBBF::test_0xCBBC() {}
void Instrs_CB80_CBBF::test_0xCBBD() {}
void Instrs_CB80_CBBF::test_0xCBBE() {}
void Instrs_CB80_CBBF::test_0xCBBF() {}

#pragma endregion
