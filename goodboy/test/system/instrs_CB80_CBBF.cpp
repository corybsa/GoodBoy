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
    rom = new byte[0x800000];
    testResults << std::endl << "Instructions 0xCB80 through 0xCBBF running...";
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

// res 0, b
void Instrs_CB80_CBBF::test_0xCB80() {
    loadRom({
                0xCB,
                0x80 // res 0, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xFE, "B should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 0, c
void Instrs_CB80_CBBF::test_0xCB81() {
    loadRom({
                0xCB,
                0x81 // res 0, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xFE, "C should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 0, d
void Instrs_CB80_CBBF::test_0xCB82() {
    loadRom({
                0xCB,
                0x82 // res 0, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xFE, "D should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 0, e
void Instrs_CB80_CBBF::test_0xCB83() {
    loadRom({
                0xCB,
                0x83 // res 0, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xFE, "E should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 0, h
void Instrs_CB80_CBBF::test_0xCB84() {
    loadRom({
                0xCB,
                0x84 // res 0, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xFE, "H should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 0, l
void Instrs_CB80_CBBF::test_0xCB85() {
    loadRom({
                0xCB,
                0x85 // res 0, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xFE, "L should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 0, (hl)
void Instrs_CB80_CBBF::test_0xCB86() {
    loadRom({
                0xCB,
                0x86 // res 0, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xFE, "the value pointed to by HL should be 0xFE");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 0, a
void Instrs_CB80_CBBF::test_0xCB87() {
    loadRom({
                0xCB,
                0x87 // res 0, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, b
void Instrs_CB80_CBBF::test_0xCB88() {
    loadRom({
                0xCB,
                0x88 // res 1, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xFD, "B should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, c
void Instrs_CB80_CBBF::test_0xCB89() {
    loadRom({
                0xCB,
                0x89 // res 1, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xFD, "C should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, d
void Instrs_CB80_CBBF::test_0xCB8A() {
    loadRom({
                0xCB,
                0x8A // res 1, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xFD, "D should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, e
void Instrs_CB80_CBBF::test_0xCB8B() {
    loadRom({
                0xCB,
                0x8B // res 1, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xFD, "E should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, h
void Instrs_CB80_CBBF::test_0xCB8C() {
    loadRom({
                0xCB,
                0x8C // res 1, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xFD, "H should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, l
void Instrs_CB80_CBBF::test_0xCB8D() {
    loadRom({
                0xCB,
                0x8D // res 1, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xFD, "L should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 1, (hl)
void Instrs_CB80_CBBF::test_0xCB8E() {
    loadRom({
                0xCB,
                0x8E // res 1, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xFD, "the value pointed to by HL should be 0xFD");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 1, a
void Instrs_CB80_CBBF::test_0xCB8F() {
    loadRom({
                0xCB,
                0x8F // res 1, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xFD, "A should be 0xFD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCB90_CB9F

// res 2, b
void Instrs_CB80_CBBF::test_0xCB90() {
    loadRom({
                0xCB,
                0x90 // res 2, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xFB, "B should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 2, c
void Instrs_CB80_CBBF::test_0xCB91() {
    loadRom({
                0xCB,
                0x91 // res 2, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xFB, "C should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 2, d
void Instrs_CB80_CBBF::test_0xCB92() {
    loadRom({
                0xCB,
                0x92 // res 2, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xFB, "D should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 2, e
void Instrs_CB80_CBBF::test_0xCB93() {
    loadRom({
                0xCB,
                0x93 // res 2, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xFB, "E should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 2, h
void Instrs_CB80_CBBF::test_0xCB94() {
    loadRom({
                0xCB,
                0x94 // res 2, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xFB, "H should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 2, l
void Instrs_CB80_CBBF::test_0xCB95() {
    loadRom({
                0xCB,
                0x95 // res 2, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xFB, "L should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 2, (hl)
void Instrs_CB80_CBBF::test_0xCB96() {
    loadRom({
                0xCB,
                0x96 // res 2, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xFB, "the value pointed to by HL should be 0xFB");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 2, a
void Instrs_CB80_CBBF::test_0xCB97() {
    loadRom({
                0xCB,
                0x97 // res 2, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xFB, "A should be 0xFB");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, b
void Instrs_CB80_CBBF::test_0xCB98() {
    loadRom({
                0xCB,
                0x98 // res 3, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xF7, "B should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, c
void Instrs_CB80_CBBF::test_0xCB99() {
    loadRom({
                0xCB,
                0x99 // res 3, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xF7, "C should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, d
void Instrs_CB80_CBBF::test_0xCB9A() {
    loadRom({
                0xCB,
                0x9A // res 3, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xF7, "D should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, e
void Instrs_CB80_CBBF::test_0xCB9B() {
    loadRom({
                0xCB,
                0x9B // res 3, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xF7, "E should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, h
void Instrs_CB80_CBBF::test_0xCB9C() {
    loadRom({
                0xCB,
                0x9C // res 3, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xF7, "H should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, l
void Instrs_CB80_CBBF::test_0xCB9D() {
    loadRom({
                0xCB,
                0x9D // res 3, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xF7, "L should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 3, (hl)
void Instrs_CB80_CBBF::test_0xCB9E() {
    loadRom({
                0xCB,
                0x9E // res 3, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xF7, "the value pointed to by HL should be 0xF7");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 3, a
void Instrs_CB80_CBBF::test_0xCB9F() {
    loadRom({
                0xCB,
                0x9F // res 3, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xF7, "A should be 0xF7");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCBA0_CBAF

// res 4, b
void Instrs_CB80_CBBF::test_0xCBA0() {
    loadRom({
                0xCB,
                0xA0 // res 4, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xEF, "B should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 4, c
void Instrs_CB80_CBBF::test_0xCBA1() {
    loadRom({
                0xCB,
                0xA1 // res 4, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xEF, "C should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 4, d
void Instrs_CB80_CBBF::test_0xCBA2() {
    loadRom({
                0xCB,
                0xA2 // res 4, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xEF, "D should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 4, e
void Instrs_CB80_CBBF::test_0xCBA3() {
    loadRom({
                0xCB,
                0xA3 // res 4, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xEF, "E should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 4, h
void Instrs_CB80_CBBF::test_0xCBA4() {
    loadRom({
                0xCB,
                0xA4 // res 4, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xEF, "H should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 4, l
void Instrs_CB80_CBBF::test_0xCBA5() {
    loadRom({
                0xCB,
                0xA5 // res 4, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xEF, "L should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 4, (hl)
void Instrs_CB80_CBBF::test_0xCBA6() {
    loadRom({
                0xCB,
                0xA6 // res 4, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xEF, "the value pointed to by HL should be 0xEF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 4, a
void Instrs_CB80_CBBF::test_0xCBA7() {
    loadRom({
                0xCB,
                0xA7 // res 4, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xEF, "A should be 0xEF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, b
void Instrs_CB80_CBBF::test_0xCBA8() {
    loadRom({
                0xCB,
                0xA8 // res 5, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xDF, "B should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, c
void Instrs_CB80_CBBF::test_0xCBA9() {
    loadRom({
                0xCB,
                0xA9 // res 5, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xDF, "C should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, d
void Instrs_CB80_CBBF::test_0xCBAA() {
    loadRom({
                0xCB,
                0xAA // res 5, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xDF, "D should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, e
void Instrs_CB80_CBBF::test_0xCBAB() {
    loadRom({
                0xCB,
                0xAB // res 5, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xDF, "E should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, h
void Instrs_CB80_CBBF::test_0xCBAC() {
    loadRom({
                0xCB,
                0xAC // res 5, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xDF, "H should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, l
void Instrs_CB80_CBBF::test_0xCBAD() {
    loadRom({
                0xCB,
                0xAD // res 5, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xDF, "L should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 5, (hl)
void Instrs_CB80_CBBF::test_0xCBAE() {
    loadRom({
                0xCB,
                0xAE // res 5, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xDF, "the value pointed to by HL should be 0xDF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 5, a
void Instrs_CB80_CBBF::test_0xCBAF() {
    loadRom({
                0xCB,
                0xAF // res 5, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xDF, "A should be 0xDF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCBB0_CBBF

// res 6, b
void Instrs_CB80_CBBF::test_0xCBB0() {
    loadRom({
                0xCB,
                0xB0 // res 6, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xBF, "B should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 6, c
void Instrs_CB80_CBBF::test_0xCBB1() {
    loadRom({
                0xCB,
                0xB1 // res 6, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xBF, "C should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 6, d
void Instrs_CB80_CBBF::test_0xCBB2() {
    loadRom({
                0xCB,
                0xB2 // res 6, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xBF, "D should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 6, e
void Instrs_CB80_CBBF::test_0xCBB3() {
    loadRom({
                0xCB,
                0xB3 // res 6, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xBF, "E should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 6, h
void Instrs_CB80_CBBF::test_0xCBB4() {
    loadRom({
                0xCB,
                0xB4 // res 6, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xBF, "H should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 6, l
void Instrs_CB80_CBBF::test_0xCBB5() {
    loadRom({
                0xCB,
                0xB5 // res 6, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xBF, "L should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 6, (hl)
void Instrs_CB80_CBBF::test_0xCBB6() {
    loadRom({
                0xCB,
                0xB6 // res 6, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xBF, "the value pointed to by HL should be 0xBF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 6, a
void Instrs_CB80_CBBF::test_0xCBB7() {
    loadRom({
                0xCB,
                0xB7 // res 6, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xBF, "A should be 0xBF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, b
void Instrs_CB80_CBBF::test_0xCBB8() {
    loadRom({
                0xCB,
                0xB8 // res 7, b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x7F, "B should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, c
void Instrs_CB80_CBBF::test_0xCBB9() {
    loadRom({
                0xCB,
                0xB9 // res 7, c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x7F, "C should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, d
void Instrs_CB80_CBBF::test_0xCBBA() {
    loadRom({
                0xCB,
                0xBA // res 7, d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x7F, "D should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, e
void Instrs_CB80_CBBF::test_0xCBBB() {
    loadRom({
                0xCB,
                0xBB // res 7, e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x7F, "E should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, h
void Instrs_CB80_CBBF::test_0xCBBC() {
    loadRom({
                0xCB,
                0xBC // res 7, h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x7F, "H should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, l
void Instrs_CB80_CBBF::test_0xCBBD() {
    loadRom({
                0xCB,
                0xBD // res 7, l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x7F, "L should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// res 7, (hl)
void Instrs_CB80_CBBF::test_0xCBBE() {
    loadRom({
                0xCB,
                0xBE // res 7, (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x7F, "the value pointed to by HL should be 0x7F");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// res 7, a
void Instrs_CB80_CBBF::test_0xCBBF() {
    loadRom({
                0xCB,
                0xBF // res 7, a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x7F, "A should be 0x7F");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion
