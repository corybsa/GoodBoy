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
    Test::addTest([this]() -> void { test_0x9F(); });
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
    Test::addTest([this]() -> void { test_0xA8_half(); });
    Test::addTest([this]() -> void { test_0xA8_zero_half(); });
    Test::addTest([this]() -> void { test_0xA9_half(); });
    Test::addTest([this]() -> void { test_0xA9_zero_half(); });
    Test::addTest([this]() -> void { test_0xAA_half(); });
    Test::addTest([this]() -> void { test_0xAA_zero_half(); });
    Test::addTest([this]() -> void { test_0xAB_half(); });
    Test::addTest([this]() -> void { test_0xAB_zero_half(); });
    Test::addTest([this]() -> void { test_0xAC_half(); });
    Test::addTest([this]() -> void { test_0xAC_zero_half(); });
    Test::addTest([this]() -> void { test_0xAD_half(); });
    Test::addTest([this]() -> void { test_0xAD_zero_half(); });
    Test::addTest([this]() -> void { test_0xAE_half(); });
    Test::addTest([this]() -> void { test_0xAE_zero_half(); });
    Test::addTest([this]() -> void { test_0xAF_half(); });
    Test::addTest([this]() -> void { test_0xAF_zero_half(); });

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
    Test::addTest([this]() -> void { test_0xB8(); });
    Test::addTest([this]() -> void { test_0xB8_zero(); });
    Test::addTest([this]() -> void { test_0xB9(); });
    Test::addTest([this]() -> void { test_0xB9_zero(); });
    Test::addTest([this]() -> void { test_0xBA(); });
    Test::addTest([this]() -> void { test_0xBA_zero(); });
    Test::addTest([this]() -> void { test_0xBB(); });
    Test::addTest([this]() -> void { test_0xBB_zero(); });
    Test::addTest([this]() -> void { test_0xBC(); });
    Test::addTest([this]() -> void { test_0xBC_zero(); });
    Test::addTest([this]() -> void { test_0xBD(); });
    Test::addTest([this]() -> void { test_0xBD_zero(); });
    Test::addTest([this]() -> void { test_0xBE(); });
    Test::addTest([this]() -> void { test_0xBE_zero(); });
    Test::addTest([this]() -> void { test_0xBF(); });
    Test::addTest([this]() -> void { test_0xBF_zero(); });
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

// sub b
void Instrs_80_BF::test_0x97() {
    loadRom({
                0x97 // sub a
            });

    gb->cpu->registers.A = 0x3E;
    gb->cpu->registers.B = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_80_BF::test_0x98() {}

void Instrs_80_BF::test_0x98_zero() {}

void Instrs_80_BF::test_0x98_half_carry() {}

void Instrs_80_BF::test_0x99() {}

void Instrs_80_BF::test_0x99_zero() {}

void Instrs_80_BF::test_0x99_half_carry() {}

void Instrs_80_BF::test_0x9A() {}

void Instrs_80_BF::test_0x9A_zero() {}

void Instrs_80_BF::test_0x9A_half_carry() {}

void Instrs_80_BF::test_0x9B() {}

void Instrs_80_BF::test_0x9B_zero() {}

void Instrs_80_BF::test_0x9B_half_carry() {}

void Instrs_80_BF::test_0x9C() {}

void Instrs_80_BF::test_0x9C_zero() {}

void Instrs_80_BF::test_0x9C_half_carry() {}

void Instrs_80_BF::test_0x9D() {}

void Instrs_80_BF::test_0x9D_zero() {}

void Instrs_80_BF::test_0x9D_half_carry() {}

void Instrs_80_BF::test_0x9E() {}

void Instrs_80_BF::test_0x9E_zero() {}

void Instrs_80_BF::test_0x9E_half_carry() {}

void Instrs_80_BF::test_0x9F() {}

void Instrs_80_BF::test_0x9F_zero() {}

void Instrs_80_BF::test_0x9F_half_carry() {}


#pragma endregion

#pragma region r0xA0_0xAF

void Instrs_80_BF::test_0xA0_half() {}
void Instrs_80_BF::test_0xA0_zero_half() {}
void Instrs_80_BF::test_0xA1_half() {}
void Instrs_80_BF::test_0xA1_zero_half() {}
void Instrs_80_BF::test_0xA2_half() {}
void Instrs_80_BF::test_0xA2_zero_half() {}
void Instrs_80_BF::test_0xA3_half() {}
void Instrs_80_BF::test_0xA3_zero_half() {}
void Instrs_80_BF::test_0xA4_half() {}
void Instrs_80_BF::test_0xA4_zero_half() {}
void Instrs_80_BF::test_0xA5_half() {}
void Instrs_80_BF::test_0xA5_zero_half() {}
void Instrs_80_BF::test_0xA6_half() {}
void Instrs_80_BF::test_0xA6_zero_half() {}
void Instrs_80_BF::test_0xA7_half() {}
void Instrs_80_BF::test_0xA7_zero_half() {}
void Instrs_80_BF::test_0xA8_half() {}
void Instrs_80_BF::test_0xA8_zero_half() {}
void Instrs_80_BF::test_0xA9_half() {}
void Instrs_80_BF::test_0xA9_zero_half() {}
void Instrs_80_BF::test_0xAA_half() {}
void Instrs_80_BF::test_0xAA_zero_half() {}
void Instrs_80_BF::test_0xAB_half() {}
void Instrs_80_BF::test_0xAB_zero_half() {}
void Instrs_80_BF::test_0xAC_half() {}
void Instrs_80_BF::test_0xAC_zero_half() {}
void Instrs_80_BF::test_0xAD_half() {}
void Instrs_80_BF::test_0xAD_zero_half() {}
void Instrs_80_BF::test_0xAE_half() {}
void Instrs_80_BF::test_0xAE_zero_half() {}
void Instrs_80_BF::test_0xAF_half() {}
void Instrs_80_BF::test_0xAF_zero_half() {}

#pragma endregion

#pragma region r0xB0_0xBF

void Instrs_80_BF::test_0xB0() {}
void Instrs_80_BF::test_0xB0_zero() {}
void Instrs_80_BF::test_0xB1() {}
void Instrs_80_BF::test_0xB1_zero() {}
void Instrs_80_BF::test_0xB2() {}
void Instrs_80_BF::test_0xB2_zero() {}
void Instrs_80_BF::test_0xB3() {}
void Instrs_80_BF::test_0xB3_zero() {}
void Instrs_80_BF::test_0xB4() {}
void Instrs_80_BF::test_0xB4_zero() {}
void Instrs_80_BF::test_0xB5() {}
void Instrs_80_BF::test_0xB5_zero() {}
void Instrs_80_BF::test_0xB6() {}
void Instrs_80_BF::test_0xB6_zero() {}
void Instrs_80_BF::test_0xB7() {}
void Instrs_80_BF::test_0xB7_zero() {}
void Instrs_80_BF::test_0xB8() {}
void Instrs_80_BF::test_0xB8_zero() {}
void Instrs_80_BF::test_0xB9() {}
void Instrs_80_BF::test_0xB9_zero() {}
void Instrs_80_BF::test_0xBA() {}
void Instrs_80_BF::test_0xBA_zero() {}
void Instrs_80_BF::test_0xBB() {}
void Instrs_80_BF::test_0xBB_zero() {}
void Instrs_80_BF::test_0xBC() {}
void Instrs_80_BF::test_0xBC_zero() {}
void Instrs_80_BF::test_0xBD() {}
void Instrs_80_BF::test_0xBD_zero() {}
void Instrs_80_BF::test_0xBE() {}
void Instrs_80_BF::test_0xBE_zero() {}
void Instrs_80_BF::test_0xBF() {}
void Instrs_80_BF::test_0xBF_zero() {}

#pragma endregion