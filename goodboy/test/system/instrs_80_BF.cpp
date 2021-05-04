#include "includes/instrs_80_BF.h"

Instrs_80_BF::Instrs_80_BF(GameBoy* gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0x80(); });
    Test::addTest([this]() -> void { test_0x81(); });
    Test::addTest([this]() -> void { test_0x82(); });
    Test::addTest([this]() -> void { test_0x83(); });
    Test::addTest([this]() -> void { test_0x84(); });
    Test::addTest([this]() -> void { test_0x85(); });
    Test::addTest([this]() -> void { test_0x86(); });
    Test::addTest([this]() -> void { test_0x87(); });
    Test::addTest([this]() -> void { test_0x88(); });
    Test::addTest([this]() -> void { test_0x89(); });
    Test::addTest([this]() -> void { test_0x8A(); });
    Test::addTest([this]() -> void { test_0x8B(); });
    Test::addTest([this]() -> void { test_0x8C(); });
    Test::addTest([this]() -> void { test_0x8D(); });
    Test::addTest([this]() -> void { test_0x8E(); });
    Test::addTest([this]() -> void { test_0x8F(); });

    Test::addTest([this]() -> void { test_0x90_zero(); });
    Test::addTest([this]() -> void { test_0x90_half(); });
    Test::addTest([this]() -> void { test_0x90_carry(); });
    Test::addTest([this]() -> void { test_0x91_zero(); });
    Test::addTest([this]() -> void { test_0x91_half(); });
    Test::addTest([this]() -> void { test_0x91_carry(); });
    Test::addTest([this]() -> void { test_0x92_zero(); });
    Test::addTest([this]() -> void { test_0x92_half(); });
    Test::addTest([this]() -> void { test_0x92_carry(); });
    Test::addTest([this]() -> void { test_0x93_zero(); });
    Test::addTest([this]() -> void { test_0x93_half(); });
    Test::addTest([this]() -> void { test_0x93_carry(); });
    Test::addTest([this]() -> void { test_0x94_zero(); });
    Test::addTest([this]() -> void { test_0x94_half(); });
    Test::addTest([this]() -> void { test_0x94_carry(); });
    Test::addTest([this]() -> void { test_0x95_zero(); });
    Test::addTest([this]() -> void { test_0x95_half(); });
    Test::addTest([this]() -> void { test_0x95_carry(); });
    Test::addTest([this]() -> void { test_0x96_zero(); });
    Test::addTest([this]() -> void { test_0x96_half(); });
    Test::addTest([this]() -> void { test_0x96_carry(); });
    Test::addTest([this]() -> void { test_0x97(); });
    Test::addTest([this]() -> void { test_0x98(); });
    Test::addTest([this]() -> void { test_0x98_zero(); });
    Test::addTest([this]() -> void { test_0x98_half_carry(); });
    Test::addTest([this]() -> void { test_0x99(); });
    Test::addTest([this]() -> void { test_0x99_zero(); });
    Test::addTest([this]() -> void { test_0x99_half_carry(); });
    Test::addTest([this]() -> void { test_0x9A(); });
    Test::addTest([this]() -> void { test_0x9A_zero(); });
    Test::addTest([this]() -> void { test_0x9A_half_carry(); });
    Test::addTest([this]() -> void { test_0x9B(); });
    Test::addTest([this]() -> void { test_0x9B_zero(); });
    Test::addTest([this]() -> void { test_0x9B_half_carry(); });
    Test::addTest([this]() -> void { test_0x9C(); });
    Test::addTest([this]() -> void { test_0x9C_zero(); });
    Test::addTest([this]() -> void { test_0x9C_half_carry(); });
    Test::addTest([this]() -> void { test_0x9D(); });
    Test::addTest([this]() -> void { test_0x9D_zero(); });
    Test::addTest([this]() -> void { test_0x9D_half_carry(); });
    Test::addTest([this]() -> void { test_0x9E(); });
    Test::addTest([this]() -> void { test_0x9E_zero(); });
    Test::addTest([this]() -> void { test_0x9E_half_carry(); });
    Test::addTest([this]() -> void { test_0x9F_zero(); });
    Test::addTest([this]() -> void { test_0x9F_half_carry(); });

    Test::addTest([this]() -> void { test_0xA0_half(); });
    Test::addTest([this]() -> void { test_0xA0_zero_half(); });
    Test::addTest([this]() -> void { test_0xA1_half(); });
    Test::addTest([this]() -> void { test_0xA1_zero_half(); });
    Test::addTest([this]() -> void { test_0xA2_half(); });
    Test::addTest([this]() -> void { test_0xA2_zero_half(); });
    Test::addTest([this]() -> void { test_0xA3_half(); });
    Test::addTest([this]() -> void { test_0xA3_zero_half(); });
    Test::addTest([this]() -> void { test_0xA4_half(); });
    Test::addTest([this]() -> void { test_0xA4_zero_half(); });
    Test::addTest([this]() -> void { test_0xA5_half(); });
    Test::addTest([this]() -> void { test_0xA5_zero_half(); });
    Test::addTest([this]() -> void { test_0xA6_half(); });
    Test::addTest([this]() -> void { test_0xA6_zero_half(); });
    Test::addTest([this]() -> void { test_0xA7_half(); });
    Test::addTest([this]() -> void { test_0xA7_zero_half(); });
    Test::addTest([this]() -> void { test_0xA8(); });
    Test::addTest([this]() -> void { test_0xA8_zero(); });
    Test::addTest([this]() -> void { test_0xA9(); });
    Test::addTest([this]() -> void { test_0xA9_zero(); });
    Test::addTest([this]() -> void { test_0xAA(); });
    Test::addTest([this]() -> void { test_0xAA_zero(); });
    Test::addTest([this]() -> void { test_0xAB(); });
    Test::addTest([this]() -> void { test_0xAB_zero(); });
    Test::addTest([this]() -> void { test_0xAC(); });
    Test::addTest([this]() -> void { test_0xAC_zero(); });
    Test::addTest([this]() -> void { test_0xAD(); });
    Test::addTest([this]() -> void { test_0xAD_zero(); });
    Test::addTest([this]() -> void { test_0xAE(); });
    Test::addTest([this]() -> void { test_0xAE_zero(); });
    Test::addTest([this]() -> void { test_0xAF(); });

    Test::addTest([this]() -> void { test_0xB0(); });
    Test::addTest([this]() -> void { test_0xB0_zero(); });
    Test::addTest([this]() -> void { test_0xB1(); });
    Test::addTest([this]() -> void { test_0xB1_zero(); });
    Test::addTest([this]() -> void { test_0xB2(); });
    Test::addTest([this]() -> void { test_0xB2_zero(); });
    Test::addTest([this]() -> void { test_0xB3(); });
    Test::addTest([this]() -> void { test_0xB3_zero(); });
    Test::addTest([this]() -> void { test_0xB4(); });
    Test::addTest([this]() -> void { test_0xB4_zero(); });
    Test::addTest([this]() -> void { test_0xB5(); });
    Test::addTest([this]() -> void { test_0xB5_zero(); });
    Test::addTest([this]() -> void { test_0xB6(); });
    Test::addTest([this]() -> void { test_0xB6_zero(); });
    Test::addTest([this]() -> void { test_0xB7(); });
    Test::addTest([this]() -> void { test_0xB7_zero(); });
    Test::addTest([this]() -> void { test_0xB8_zero(); });
    Test::addTest([this]() -> void { test_0xB8_half(); });
    Test::addTest([this]() -> void { test_0xB8_carry(); });
    Test::addTest([this]() -> void { test_0xB9_zero(); });
    Test::addTest([this]() -> void { test_0xB9_half(); });
    Test::addTest([this]() -> void { test_0xB9_carry(); });
    Test::addTest([this]() -> void { test_0xBA_zero(); });
    Test::addTest([this]() -> void { test_0xBA_half(); });
    Test::addTest([this]() -> void { test_0xBA_carry(); });
    Test::addTest([this]() -> void { test_0xBB_zero(); });
    Test::addTest([this]() -> void { test_0xBB_half(); });
    Test::addTest([this]() -> void { test_0xBB_carry(); });
    Test::addTest([this]() -> void { test_0xBC_zero(); });
    Test::addTest([this]() -> void { test_0xBC_half(); });
    Test::addTest([this]() -> void { test_0xBC_carry(); });
    Test::addTest([this]() -> void { test_0xBD_zero(); });
    Test::addTest([this]() -> void { test_0xBD_half(); });
    Test::addTest([this]() -> void { test_0xBD_carry(); });
    Test::addTest([this]() -> void { test_0xBE_zero(); });
    Test::addTest([this]() -> void { test_0xBE_half(); });
    Test::addTest([this]() -> void { test_0xBE_carry(); });
    Test::addTest([this]() -> void { test_0xBF(); });
}

void Instrs_80_BF::beforeAll() {
    rom = new byte[0x800000];
    testResults << std::endl << "Instructions 0x80 through 0xBF running...";
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

#pragma region r0x80_0x8F

// add a, b
void Instrs_80_BF::test_0x80() {
    loadRom({
                0x80 // add a, b
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.B = 0xC6;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// add a, c
void Instrs_80_BF::test_0x81() {
    loadRom({
                0x81 // add a, c
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.C = 0xC6;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// add a, d
void Instrs_80_BF::test_0x82() {
    loadRom({
                0x82 // add a, d
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.D = 0xC6;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// add a, e
void Instrs_80_BF::test_0x83() {
    loadRom({
                0x83 // add a, e
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.E = 0xC6;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// add a, h
void Instrs_80_BF::test_0x84() {
    loadRom({
                0x84 // add a, h
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.H = 0xC6;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// add a, l
void Instrs_80_BF::test_0x85() {
    loadRom({
                0x85 // add a, l
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.L = 0xC6;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// add a, (hl)
void Instrs_80_BF::test_0x86() {
    loadRom({
                0x86 // add a, (hl)
            });

    gb->cpu->registers.A = 0x3A;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0xC6);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// add a, a
void Instrs_80_BF::test_0x87() {
    loadRom({
                0x87 // add a, a
            });

    gb->cpu->registers.A = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, b
void Instrs_80_BF::test_0x88() {
    loadRom({
                0x88 // adc a, b
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.B = 0x1E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, c
void Instrs_80_BF::test_0x89() {
    loadRom({
                0x89 // adc a, c
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.C = 0x1E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, d
void Instrs_80_BF::test_0x8A() {
    loadRom({
                0x8A // adc a, d
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.D = 0x1E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, e
void Instrs_80_BF::test_0x8B() {
    loadRom({
                0x8B // adc a, e
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.E = 0x1E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, h
void Instrs_80_BF::test_0x8C() {
    loadRom({
                0x8C // adc a, h
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.H = 0x1E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, l
void Instrs_80_BF::test_0x8D() {
    loadRom({
                0x8D // adc a, l
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.L = 0x1E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// adc a, (hl)
void Instrs_80_BF::test_0x8E() {
    loadRom({
                0x8E // adc a, (hl)
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x1E);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// adc a, a
void Instrs_80_BF::test_0x8F() {
    loadRom({
                0x8F // adc a, a
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x01, "A should be 0x01");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x90_0x9F

// sub b
void Instrs_80_BF::test_0x90_zero() {
    loadRom({
                0x90 // sub b
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.B = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x90_half() {
    loadRom({
                0x90 // sub b
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.B = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x90_carry() {
    loadRom({
                0x90 // sub b
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.B = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sub c
void Instrs_80_BF::test_0x91_zero() {
    loadRom({
                0x91 // sub c
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.C = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x91_half() {
    loadRom({
                0x91 // sub c
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.C = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x91_carry() {
    loadRom({
                0x91 // sub c
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.C = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sub d
void Instrs_80_BF::test_0x92_zero() {
    loadRom({
                0x92 // sub d
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.D = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x92_half() {
    loadRom({
                0x92 // sub d
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.D = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x92_carry() {
    loadRom({
                0x92 // sub d
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.D = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sub e
void Instrs_80_BF::test_0x93_zero() {
    loadRom({
                0x93 // sub e
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.E = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x93_half() {
    loadRom({
                0x93 // sub e
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.E = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x93_carry() {
    loadRom({
                0x93 // sub e
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.E = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sub h
void Instrs_80_BF::test_0x94_zero() {
    loadRom({
                0x94 // sub h
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.H = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x94_half() {
    loadRom({
                0x94 // sub h
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.H = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x94_carry() {
    loadRom({
                0x94 // sub h
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.H = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sub l
void Instrs_80_BF::test_0x95_zero() {
    loadRom({
                0x95 // sub l
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.L = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x95_half() {
    loadRom({
                0x95 // sub l
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.L = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x95_carry() {
    loadRom({
                0x95 // sub l
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.L = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sub (hl)
void Instrs_80_BF::test_0x96_zero() {
    loadRom({
                0x96 // sub (hl)
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x3E);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0x96_half() {
    loadRom({
                0x96 // sub (hl)
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x0F);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2F, "A should be 0x2F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0x96_carry() {
    loadRom({
                0x96 // sub (hl)
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x40);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sub a
void Instrs_80_BF::test_0x97() {
    loadRom({
                0x97 // sub a
            });

    gb->cpu->registers.A = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, b
void Instrs_80_BF::test_0x98() {
    loadRom({
                0x98 // sbc a, b
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.B = 0x2A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x98_zero() {
    loadRom({
                0x98 // sbc a, b
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.B = 0x3A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x98_half_carry() {
    loadRom({
                0x98 // sbc a, b
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.B = 0x4F;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, c
void Instrs_80_BF::test_0x99() {
    loadRom({
                0x99 // sbc a, c
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.C = 0x2A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x99_zero() {
    loadRom({
                0x99 // sbc a, c
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.C = 0x3A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x99_half_carry() {
    loadRom({
                0x99 // sbc a, c
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.C = 0x4F;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, d
void Instrs_80_BF::test_0x9A() {
    loadRom({
                0x9A // sbc a, d
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.D = 0x2A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9A_zero() {
    loadRom({
                0x9A // sbc a, d
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.D = 0x3A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9A_half_carry() {
    loadRom({
                0x9A // sbc a, d
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.D = 0x4F;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, e
void Instrs_80_BF::test_0x9B() {
    loadRom({
                0x9B // sbc a, e
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.E = 0x2A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9B_zero() {
    loadRom({
                0x9B // sbc a, e
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.E = 0x3A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9B_half_carry() {
    loadRom({
                0x9B // sbc a, e
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.E = 0x4F;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, h
void Instrs_80_BF::test_0x9C() {
    loadRom({
                0x9C // sbc a, h
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.H = 0x2A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9C_zero() {
    loadRom({
                0x9C // sbc a, h
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.H = 0x3A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9C_half_carry() {
    loadRom({
                0x9C // sbc a, h
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.H = 0x4F;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, l
void Instrs_80_BF::test_0x9D() {
    loadRom({
                0x9D // sbc a, l
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.L = 0x2A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9D_zero() {
    loadRom({
                0x9D // sbc a, l
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.L = 0x3A;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9D_half_carry() {
    loadRom({
                0x9D // sbc a, l
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.L = 0x4F;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// sbc a, (hl)
void Instrs_80_BF::test_0x9E() {
    loadRom({
                0x9E // sbc a, (hl)
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x2A);
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0x9E_zero() {
    loadRom({
                0x9E // sbc a, (hl)
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x3A);
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0x9E_half_carry() {
    loadRom({
                0x9E // sbc a, (hl)
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x4F);
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sbc a, a
void Instrs_80_BF::test_0x9F_zero() {
    loadRom({
                0x9F // sbc a, a
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->resetFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x9F_half_carry() {
    loadRom({
                0x9F // sbc a, a
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFF, "A should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}


#pragma endregion

#pragma region r0xA0_0xAF

// and b
void Instrs_80_BF::test_0xA0_half() {
    loadRom({
                0xA0 // and b
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.B = 0x3F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA0_zero_half() {
    loadRom({
                0xA0 // and b
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// and c
void Instrs_80_BF::test_0xA1_half() {
    loadRom({
                0xA1 // and c
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.C = 0x3F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA1_zero_half() {
    loadRom({
                0xA1 // and c
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// and d
void Instrs_80_BF::test_0xA2_half() {
    loadRom({
                0xA2 // and d
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.D = 0x3F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA2_zero_half() {
    loadRom({
                0xA2 // and d
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// and e
void Instrs_80_BF::test_0xA3_half() {
    loadRom({
                0xA3 // and e
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.E = 0x3F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA3_zero_half() {
    loadRom({
                0xA3 // and e
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// and h
void Instrs_80_BF::test_0xA4_half() {
    loadRom({
                0xA4 // and h
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.H = 0x3F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA4_zero_half() {
    loadRom({
                0xA4 // and h
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// and l
void Instrs_80_BF::test_0xA5_half() {
    loadRom({
                0xA5 // and l
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.L = 0x3F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA5_zero_half() {
    loadRom({
                0xA5 // and l
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// and (hl)
void Instrs_80_BF::test_0xA6_half() {
    loadRom({
                0xA6 // and (hl)
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x3F);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0xA6_zero_half() {
    loadRom({
                0xA6 // and (hl)
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x00);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// and a
void Instrs_80_BF::test_0xA7_half() {
    loadRom({
                0xA7 // and a
            });

    gb->cpu->registers.A = 0x5A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA7_zero_half() {
    loadRom({
                0xA7 // and a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor b
void Instrs_80_BF::test_0xA8() {
    loadRom({
                0xA8 // xor b
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.B = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA8_zero() {
    loadRom({
                0xA8 // xor b
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor c
void Instrs_80_BF::test_0xA9() {
    loadRom({
                0xA9 // xor c
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.C = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xA9_zero() {
    loadRom({
                0xA9 // xor c
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor d
void Instrs_80_BF::test_0xAA() {
    loadRom({
                0xAA // xor d
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.D = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xAA_zero() {
    loadRom({
                0xAA // xor d
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor e
void Instrs_80_BF::test_0xAB() {
    loadRom({
                0xAB // xor e
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.E = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xAB_zero() {
    loadRom({
                0xAB // xor e
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor h
void Instrs_80_BF::test_0xAC() {
    loadRom({
                0xAC // xor h
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.H = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xAC_zero() {
    loadRom({
                0xAC // xor h
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor l
void Instrs_80_BF::test_0xAD() {
    loadRom({
                0xAD // xor l
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.L = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xAD_zero() {
    loadRom({
                0xAD // xor l
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// xor (hl)
void Instrs_80_BF::test_0xAE() {
    loadRom({
                0xAE // xor (hl)
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x0F);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0xAE_zero() {
    loadRom({
                0xAE // xor (hl)
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0xFF);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// xor a
void Instrs_80_BF::test_0xAF() {
    loadRom({
                0xAF // xor a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0xB0_0xBF

// or b
void Instrs_80_BF::test_0xB0() {
    loadRom({
                0xB0 // or b
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.B = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB0_zero() {
    loadRom({
                0xB0 // or b
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// or c
void Instrs_80_BF::test_0xB1() {
    loadRom({
                0xB1 // or c
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.C = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB1_zero() {
    loadRom({
                0xB1 // or c
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// or d
void Instrs_80_BF::test_0xB2() {
    loadRom({
                0xB2 // or d
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.D = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB2_zero() {
    loadRom({
                0xB2 // or d
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// or e
void Instrs_80_BF::test_0xB3() {
    loadRom({
                0xB3 // or e
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.E = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB3_zero() {
    loadRom({
                0xB3 // or e
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// or h
void Instrs_80_BF::test_0xB4() {
    loadRom({
                0xB4 // or h
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.H = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB4_zero() {
    loadRom({
                0xB4 // or h
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// or l
void Instrs_80_BF::test_0xB5() {
    loadRom({
                0xB5 // or l
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.L = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB5_zero() {
    loadRom({
                0xB5 // or l
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// or (hl)
void Instrs_80_BF::test_0xB6() {
    loadRom({
                0xB6 // or (hl)
            });

    gb->cpu->registers.A = 0x5A;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x0F);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0xB6_zero() {
    loadRom({
                0xB6 // or (hl)
            });

    gb->cpu->registers.A = 0x00;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x00);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// or a
void Instrs_80_BF::test_0xB7() {
    loadRom({
                0xB7 // or a
            });

    gb->cpu->registers.A = 0x5A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x5A, "A should be 0x5A");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB7_zero() {
    loadRom({
                0xB7 // or a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp b
void Instrs_80_BF::test_0xB8_zero() {
    loadRom({
                0xB8 // cp b
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.B = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB8_half() {
    loadRom({
                0xB8 // cp b
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.B = 0x2F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB8_carry() {
    loadRom({
                0xB8 // cp b
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.B = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp c
void Instrs_80_BF::test_0xB9_zero() {
    loadRom({
                0xB9 // cp c
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.C = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB9_half() {
    loadRom({
                0xB9 // cp c
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.C = 0x2F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xB9_carry() {
    loadRom({
                0xB9 // cp c
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.C = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp d
void Instrs_80_BF::test_0xBA_zero() {
    loadRom({
                0xBA // cp d
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.D = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBA_half() {
    loadRom({
                0xBA // cp d
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.D = 0x2F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBA_carry() {
    loadRom({
                0xBA // cp d
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.D = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp e
void Instrs_80_BF::test_0xBB_zero() {
    loadRom({
                0xBB // cp e
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.E = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBB_half() {
    loadRom({
                0xBB // cp e
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.E = 0x2F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBB_carry() {
    loadRom({
                0xBB // cp e
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.E = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp h
void Instrs_80_BF::test_0xBC_zero() {
    loadRom({
                0xBC // cp h
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.H = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBC_half() {
    loadRom({
                0xBC // cp h
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.H = 0x2F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBC_carry() {
    loadRom({
                0xBC // cp h
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.H = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp l
void Instrs_80_BF::test_0xBD_zero() {
    loadRom({
                0xBD // cp l
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.L = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBD_half() {
    loadRom({
                0xBD // cp l
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.L = 0x2F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0xBD_carry() {
    loadRom({
                0xBD // cp l
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.L = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// cp (hl)
void Instrs_80_BF::test_0xBE_zero() {
    loadRom({
                0xBE // cp (hl)
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x3C);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0xBE_half() {
    loadRom({
                0xBE // cp (hl)
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x2F);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_80_BF::test_0xBE_carry() {
    loadRom({
                0xBE // cp (hl)
            });

    gb->cpu->registers.A = 0x3C;
    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x40);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// cp a
void Instrs_80_BF::test_0xBF() {
    loadRom({
                0xBF // cp a
            });

    gb->cpu->registers.A = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion