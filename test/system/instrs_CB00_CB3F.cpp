#include "includes/instrs_CB00_CB3F.h"

Instrs_CB00_CB3F::Instrs_CB00_CB3F(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xCB00_zero(); });
    Test::addTest([this]() -> void { test_0xCB00_carry(); });
    Test::addTest([this]() -> void { test_0xCB01_zero(); });
    Test::addTest([this]() -> void { test_0xCB01_carry(); });
    Test::addTest([this]() -> void { test_0xCB02_zero(); });
    Test::addTest([this]() -> void { test_0xCB02_carry(); });
    Test::addTest([this]() -> void { test_0xCB03_zero(); });
    Test::addTest([this]() -> void { test_0xCB03_carry(); });
    Test::addTest([this]() -> void { test_0xCB04_zero(); });
    Test::addTest([this]() -> void { test_0xCB04_carry(); });
    Test::addTest([this]() -> void { test_0xCB05_zero(); });
    Test::addTest([this]() -> void { test_0xCB05_carry(); });
    Test::addTest([this]() -> void { test_0xCB06_zero(); });
    Test::addTest([this]() -> void { test_0xCB06_carry(); });
    Test::addTest([this]() -> void { test_0xCB07_zero(); });
    Test::addTest([this]() -> void { test_0xCB07_carry(); });
    Test::addTest([this]() -> void { test_0xCB08_zero(); });
    Test::addTest([this]() -> void { test_0xCB08_carry(); });
    Test::addTest([this]() -> void { test_0xCB09_zero(); });
    Test::addTest([this]() -> void { test_0xCB09_carry(); });
    Test::addTest([this]() -> void { test_0xCB0A_zero(); });
    Test::addTest([this]() -> void { test_0xCB0A_carry(); });
    Test::addTest([this]() -> void { test_0xCB0B_zero(); });
    Test::addTest([this]() -> void { test_0xCB0B_carry(); });
    Test::addTest([this]() -> void { test_0xCB0C_zero(); });
    Test::addTest([this]() -> void { test_0xCB0C_carry(); });
    Test::addTest([this]() -> void { test_0xCB0D_zero(); });
    Test::addTest([this]() -> void { test_0xCB0D_carry(); });
    Test::addTest([this]() -> void { test_0xCB0E_zero(); });
    Test::addTest([this]() -> void { test_0xCB0E_carry(); });
    Test::addTest([this]() -> void { test_0xCB0F_zero(); });
    Test::addTest([this]() -> void { test_0xCB0F_carry(); });

    Test::addTest([this]() -> void { test_0xCB10(); });
    Test::addTest([this]() -> void { test_0xCB10_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB11(); });
    Test::addTest([this]() -> void { test_0xCB11_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB12(); });
    Test::addTest([this]() -> void { test_0xCB12_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB13(); });
    Test::addTest([this]() -> void { test_0xCB13_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB14(); });
    Test::addTest([this]() -> void { test_0xCB14_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB15(); });
    Test::addTest([this]() -> void { test_0xCB15_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB16(); });
    Test::addTest([this]() -> void { test_0xCB16_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB17(); });
    Test::addTest([this]() -> void { test_0xCB17_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB18(); });
    Test::addTest([this]() -> void { test_0xCB18_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB19(); });
    Test::addTest([this]() -> void { test_0xCB19_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB1A(); });
    Test::addTest([this]() -> void { test_0xCB1A_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB1B(); });
    Test::addTest([this]() -> void { test_0xCB1B_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB1C(); });
    Test::addTest([this]() -> void { test_0xCB1C_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB1D(); });
    Test::addTest([this]() -> void { test_0xCB1D_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB1E(); });
    Test::addTest([this]() -> void { test_0xCB1E_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB1F(); });
    Test::addTest([this]() -> void { test_0xCB1F_zero_carry(); });

    Test::addTest([this]() -> void { test_0xCB20_carry(); });
    Test::addTest([this]() -> void { test_0xCB20_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB21_carry(); });
    Test::addTest([this]() -> void { test_0xCB21_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB22_carry(); });
    Test::addTest([this]() -> void { test_0xCB22_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB23_carry(); });
    Test::addTest([this]() -> void { test_0xCB23_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB24_carry(); });
    Test::addTest([this]() -> void { test_0xCB24_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB25_carry(); });
    Test::addTest([this]() -> void { test_0xCB25_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB26_carry(); });
    Test::addTest([this]() -> void { test_0xCB26_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB27_carry(); });
    Test::addTest([this]() -> void { test_0xCB27_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB28(); });
    Test::addTest([this]() -> void { test_0xCB28_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB29(); });
    Test::addTest([this]() -> void { test_0xCB29_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB2A(); });
    Test::addTest([this]() -> void { test_0xCB2A_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB2B(); });
    Test::addTest([this]() -> void { test_0xCB2B_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB2C(); });
    Test::addTest([this]() -> void { test_0xCB2C_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB2D(); });
    Test::addTest([this]() -> void { test_0xCB2D_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB2E(); });
    Test::addTest([this]() -> void { test_0xCB2E_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB2F(); });
    Test::addTest([this]() -> void { test_0xCB2F_zero_carry(); });

    Test::addTest([this]() -> void { test_0xCB30(); });
    Test::addTest([this]() -> void { test_0xCB30_zero(); });
    Test::addTest([this]() -> void { test_0xCB31(); });
    Test::addTest([this]() -> void { test_0xCB31_zero(); });
    Test::addTest([this]() -> void { test_0xCB32(); });
    Test::addTest([this]() -> void { test_0xCB32_zero(); });
    Test::addTest([this]() -> void { test_0xCB33(); });
    Test::addTest([this]() -> void { test_0xCB33_zero(); });
    Test::addTest([this]() -> void { test_0xCB34(); });
    Test::addTest([this]() -> void { test_0xCB34_zero(); });
    Test::addTest([this]() -> void { test_0xCB35(); });
    Test::addTest([this]() -> void { test_0xCB35_zero(); });
    Test::addTest([this]() -> void { test_0xCB36(); });
    Test::addTest([this]() -> void { test_0xCB36_zero(); });
    Test::addTest([this]() -> void { test_0xCB37(); });
    Test::addTest([this]() -> void { test_0xCB37_zero(); });
    Test::addTest([this]() -> void { test_0xCB38_carry(); });
    Test::addTest([this]() -> void { test_0xCB38_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB39_carry(); });
    Test::addTest([this]() -> void { test_0xCB39_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB3A_carry(); });
    Test::addTest([this]() -> void { test_0xCB3A_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB3B_carry(); });
    Test::addTest([this]() -> void { test_0xCB3B_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB3C_carry(); });
    Test::addTest([this]() -> void { test_0xCB3C_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB3D_carry(); });
    Test::addTest([this]() -> void { test_0xCB3D_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB3E_carry(); });
    Test::addTest([this]() -> void { test_0xCB3E_zero_carry(); });
    Test::addTest([this]() -> void { test_0xCB3F_carry(); });
    Test::addTest([this]() -> void { test_0xCB3F_zero_carry(); });
}

void Instrs_CB00_CB3F::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_CB00_CB3F::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_CB00_CB3F::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_CB00_CB3F::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region rCB00_CB0F

// rlc b
void Instrs_CB00_CB3F::test_0xCB00_zero() {
    loadRom({
                0xCB,
                0x00 // rlc b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB00_carry() {
    loadRom({
                0xCB,
                0x00 // rlc b
            });

    gb->cpu->registers.B = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x0B, "B should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlc c
void Instrs_CB00_CB3F::test_0xCB01_zero() {
    loadRom({
                0xCB,
                0x01 // rlc c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB01_carry() {
    loadRom({
                0xCB,
                0x01 // rlc c
            });

    gb->cpu->registers.C = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x0B, "C should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlc d
void Instrs_CB00_CB3F::test_0xCB02_zero() {
    loadRom({
                0xCB,
                0x02 // rlc d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB02_carry() {
    loadRom({
                0xCB,
                0x02 // rlc d
            });

    gb->cpu->registers.D = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x0B, "D should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlc e
void Instrs_CB00_CB3F::test_0xCB03_zero() {
    loadRom({
                0xCB,
                0x03 // rlc e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB03_carry() {
    loadRom({
                0xCB,
                0x03 // rlc e
            });

    gb->cpu->registers.E = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x0B, "E should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlc h
void Instrs_CB00_CB3F::test_0xCB04_zero() {
    loadRom({
                0xCB,
                0x04 // rlc h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB04_carry() {
    loadRom({
                0xCB,
                0x04 // rlc h
            });

    gb->cpu->registers.H = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x0B, "H should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlc l
void Instrs_CB00_CB3F::test_0xCB05_zero() {
    loadRom({
                0xCB,
                0x05 // rlc l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB05_carry() {
    loadRom({
                0xCB,
                0x05 // rlc l
            });

    gb->cpu->registers.L = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x0B, "L should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlc (hl)
void Instrs_CB00_CB3F::test_0xCB06_zero() {
    loadRom({
                0xCB,
                0x06 // rlc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x00);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value at address 0xC000 should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB06_carry() {
    loadRom({
                0xCB,
                0x06 // rlc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x85);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x0B, "the value at address 0xC000 should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// rlc a
void Instrs_CB00_CB3F::test_0xCB07_zero() {
    loadRom({
                0xCB,
                0x07 // rlc a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB07_carry() {
    loadRom({
                0xCB,
                0x07 // rlc a
            });

    gb->cpu->registers.A = 0x85;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x0B, "A should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc b
void Instrs_CB00_CB3F::test_0xCB08_zero() {
    loadRom({
                0xCB,
                0x08 // rrc b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB08_carry() {
    loadRom({
                0xCB,
                0x08 // rrc b
            });

    gb->cpu->registers.B = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x80, "B should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc c
void Instrs_CB00_CB3F::test_0xCB09_zero() {
    loadRom({
                0xCB,
                0x09 // rrc c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB09_carry() {
    loadRom({
                0xCB,
                0x09 // rrc c
            });

    gb->cpu->registers.C = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x80, "C should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc d
void Instrs_CB00_CB3F::test_0xCB0A_zero() {
    loadRom({
                0xCB,
                0x0A // rrc d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB0A_carry() {
    loadRom({
                0xCB,
                0x0A // rrc d
            });

    gb->cpu->registers.D = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x80, "D should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc e
void Instrs_CB00_CB3F::test_0xCB0B_zero() {
    loadRom({
                0xCB,
                0x0B // rrc e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB0B_carry() {
    loadRom({
                0xCB,
                0x0B // rrc e
            });

    gb->cpu->registers.E = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x80, "E should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc h
void Instrs_CB00_CB3F::test_0xCB0C_zero() {
    loadRom({
                0xCB,
                0x0C // rrc h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB0C_carry() {
    loadRom({
                0xCB,
                0x0C // rrc h
            });

    gb->cpu->registers.H = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x80, "H should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc l
void Instrs_CB00_CB3F::test_0xCB0D_zero() {
    loadRom({
                0xCB,
                0x0D // rrc l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB0D_carry() {
    loadRom({
                0xCB,
                0x0D // rrc l
            });

    gb->cpu->registers.L = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x80, "L should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrc (hl)
void Instrs_CB00_CB3F::test_0xCB0E_zero() {
    loadRom({
                0xCB,
                0x0E // rrc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x00);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value at address 0xC000 should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB0E_carry() {
    loadRom({
                0xCB,
                0x0E // rrc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x01);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x80, "the value at address 0xC000 should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// rrc a
void Instrs_CB00_CB3F::test_0xCB0F_zero() {
    loadRom({
                0xCB,
                0x0F // rrc a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB0F_carry() {
    loadRom({
                0xCB,
                0x0F // rrc a
            });

    gb->cpu->registers.A = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x80, "A should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCB10_CB1F

// rl b
void Instrs_CB00_CB3F::test_0xCB10() {
    loadRom({
                0xCB,
                0x10 // rl b
            });

    gb->cpu->registers.B = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x22, "B should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB10_zero_carry() {
    loadRom({
                0xCB,
                0x10 // rl b
            });

    gb->cpu->registers.B = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rl c
void Instrs_CB00_CB3F::test_0xCB11() {
    loadRom({
                0xCB,
                0x11 // rl c
            });

    gb->cpu->registers.C = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x22, "C should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB11_zero_carry() {
    loadRom({
                0xCB,
                0x11 // rl c
            });

    gb->cpu->registers.C = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rl d
void Instrs_CB00_CB3F::test_0xCB12() {
    loadRom({
                0xCB,
                0x12 // rl d
            });

    gb->cpu->registers.D = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x22, "D should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB12_zero_carry() {
    loadRom({
                0xCB,
                0x12 // rl d
            });

    gb->cpu->registers.D = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rl e
void Instrs_CB00_CB3F::test_0xCB13() {
    loadRom({
                0xCB,
                0x13 // rl e
            });

    gb->cpu->registers.E = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x22, "E should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB13_zero_carry() {
    loadRom({
                0xCB,
                0x13 // rl e
            });

    gb->cpu->registers.E = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rl h
void Instrs_CB00_CB3F::test_0xCB14() {
    loadRom({
                0xCB,
                0x14 // rl h
            });

    gb->cpu->registers.H = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x22, "H should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB14_zero_carry() {
    loadRom({
                0xCB,
                0x14 // rl h
            });

    gb->cpu->registers.H = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rl l
void Instrs_CB00_CB3F::test_0xCB15() {
    loadRom({
                0xCB,
                0x15 // rl l
            });

    gb->cpu->registers.L = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x22, "L should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB15_zero_carry() {
    loadRom({
                0xCB,
                0x15 // rl l
            });

    gb->cpu->registers.L = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rl (hl)
void Instrs_CB00_CB3F::test_0xCB16() {
    loadRom({
                0xCB,
                0x16 // rl (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x11);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x22, "the value pointed to by HL should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 16, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB16_zero_carry() {
    loadRom({
                0xCB,
                0x16 // rl (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x80);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value pointed to by HL should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 16, "should take 8 cycles");
}

// rl a
void Instrs_CB00_CB3F::test_0xCB17() {
    loadRom({
                0xCB,
                0x17 // rl a
            });

    gb->cpu->registers.A = 0x11;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x22, "A should be 0x22");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB17_zero_carry() {
    loadRom({
                0xCB,
                0x17 // rl a
            });

    gb->cpu->registers.A = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr b
void Instrs_CB00_CB3F::test_0xCB18() {
    loadRom({
                0xCB,
                0x18 // rr b
            });

    gb->cpu->registers.B = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x45, "B should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB18_zero_carry() {
    loadRom({
                0xCB,
                0x18 // rr b
            });

    gb->cpu->registers.B = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr c
void Instrs_CB00_CB3F::test_0xCB19() {
    loadRom({
                0xCB,
                0x19 // rr c
            });

    gb->cpu->registers.C = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x45, "C should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB19_zero_carry() {
    loadRom({
                0xCB,
                0x19 // rr c
            });

    gb->cpu->registers.C = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr d
void Instrs_CB00_CB3F::test_0xCB1A() {
    loadRom({
                0xCB,
                0x1A // rr d
            });

    gb->cpu->registers.D = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x45, "D should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB1A_zero_carry() {
    loadRom({
                0xCB,
                0x1A // rr d
            });

    gb->cpu->registers.D = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr e
void Instrs_CB00_CB3F::test_0xCB1B() {
    loadRom({
                0xCB,
                0x1B // rr e
            });

    gb->cpu->registers.E = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x45, "E should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB1B_zero_carry() {
    loadRom({
                0xCB,
                0x1B // rr e
            });

    gb->cpu->registers.E = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr h
void Instrs_CB00_CB3F::test_0xCB1C() {
    loadRom({
                0xCB,
                0x1C // rr h
            });

    gb->cpu->registers.H = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x45, "H should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB1C_zero_carry() {
    loadRom({
                0xCB,
                0x1C // rr h
            });

    gb->cpu->registers.H = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr l
void Instrs_CB00_CB3F::test_0xCB1D() {
    loadRom({
                0xCB,
                0x1D // rr l
            });

    gb->cpu->registers.L = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x45, "L should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB1D_zero_carry() {
    loadRom({
                0xCB,
                0x1D // rr l
            });

    gb->cpu->registers.L = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rr (hl)
void Instrs_CB00_CB3F::test_0xCB1E() {
    loadRom({
                0xCB,
                0x1E // rr (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x8A);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x45, "the value pointed to by HL should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB1E_zero_carry() {
    loadRom({
                0xCB,
                0x1E // rr (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x01);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value pointed to by HL should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// rr a
void Instrs_CB00_CB3F::test_0xCB1F() {
    loadRom({
                0xCB,
                0x1F // rr a
            });

    gb->cpu->registers.A = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x45, "A should be 0x45");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB1F_zero_carry() {
    loadRom({
                0xCB,
                0x1F // rr a
            });

    gb->cpu->registers.A = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}


#pragma endregion

#pragma region rCB20_CB2F

// sla b
void Instrs_CB00_CB3F::test_0xCB20_carry() {
    loadRom({
                0xCB,
                0x20 // sla b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xFE, "B should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB20_zero_carry() {
    loadRom({
                0xCB,
                0x20 // sla b
            });

    gb->cpu->registers.B = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sla c
void Instrs_CB00_CB3F::test_0xCB21_carry() {
    loadRom({
                0xCB,
                0x21 // sla c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xFE, "C should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB21_zero_carry() {
    loadRom({
                0xCB,
                0x21 // sla c
            });

    gb->cpu->registers.C = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sla d
void Instrs_CB00_CB3F::test_0xCB22_carry() {
    loadRom({
                0xCB,
                0x22 // sla d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xFE, "D should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB22_zero_carry() {
    loadRom({
                0xCB,
                0x22 // sla d
            });

    gb->cpu->registers.D = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sla e
void Instrs_CB00_CB3F::test_0xCB23_carry() {
    loadRom({
                0xCB,
                0x23 // sla e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xFE, "E should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB23_zero_carry() {
    loadRom({
                0xCB,
                0x23 // sla e
            });

    gb->cpu->registers.E = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sla h
void Instrs_CB00_CB3F::test_0xCB24_carry() {
    loadRom({
                0xCB,
                0x24 // sla h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xFE, "H should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB24_zero_carry() {
    loadRom({
                0xCB,
                0x24 // sla h
            });

    gb->cpu->registers.H = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sla l
void Instrs_CB00_CB3F::test_0xCB25_carry() {
    loadRom({
                0xCB,
                0x25 // sla l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xFE, "L should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB25_zero_carry() {
    loadRom({
                0xCB,
                0x25 // sla l
            });

    gb->cpu->registers.L = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sla (hl)
void Instrs_CB00_CB3F::test_0xCB26_carry() {
    loadRom({
                0xCB,
                0x26 // sla (hl))
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xFE, "the value pointed to by HL should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB26_zero_carry() {
    loadRom({
                0xCB,
                0x26 // sla (hl))
            });

    gb->memory->writeByte(0xC000, 0x80);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value pointed to by HL should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// sla a
void Instrs_CB00_CB3F::test_0xCB27_carry() {
    loadRom({
                0xCB,
                0x27 // sla a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB27_zero_carry() {
    loadRom({
                0xCB,
                0x27 // sla a
            });

    gb->cpu->registers.A = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra b
void Instrs_CB00_CB3F::test_0xCB28() {
    loadRom({
                0xCB,
                0x28 // sra b
            });

    gb->cpu->registers.B = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xC5, "B should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB28_zero_carry() {
    loadRom({
                0xCB,
                0x28 // sra b
            });

    gb->cpu->registers.B = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra c
void Instrs_CB00_CB3F::test_0xCB29() {
    loadRom({
                0xCB,
                0x29 // sra c
            });

    gb->cpu->registers.C = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xC5, "C should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB29_zero_carry() {
    loadRom({
                0xCB,
                0x29 // sra c
            });

    gb->cpu->registers.C = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra d
void Instrs_CB00_CB3F::test_0xCB2A() {
    loadRom({
                0xCB,
                0x2A // sra d
            });

    gb->cpu->registers.D = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xC5, "D should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB2A_zero_carry() {
    loadRom({
                0xCB,
                0x2A // sra d
            });

    gb->cpu->registers.D = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra e
void Instrs_CB00_CB3F::test_0xCB2B() {
    loadRom({
                0xCB,
                0x2B // sra e
            });

    gb->cpu->registers.E = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xC5, "E should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB2B_zero_carry() {
    loadRom({
                0xCB,
                0x2B // sra e
            });

    gb->cpu->registers.E = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra h
void Instrs_CB00_CB3F::test_0xCB2C() {
    loadRom({
                0xCB,
                0x2C // sra H
            });

    gb->cpu->registers.H = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xC5, "H should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB2C_zero_carry() {
    loadRom({
                0xCB,
                0x2C // sra H
            });

    gb->cpu->registers.H = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra l
void Instrs_CB00_CB3F::test_0xCB2D() {
    loadRom({
                0xCB,
                0x2D // sra l
            });

    gb->cpu->registers.L = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xC5, "L should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB2D_zero_carry() {
    loadRom({
                0xCB,
                0x2D // sra l
            });

    gb->cpu->registers.L = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// sra (hl)
void Instrs_CB00_CB3F::test_0xCB2E() {
    loadRom({
                0xCB,
                0x2E // sra b
            });

    gb->memory->writeByte(0xC000, 0x8A);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xC5, "the value pointed to by HL should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB2E_zero_carry() {
    loadRom({
                0xCB,
                0x2E // sra b
            });

    gb->memory->writeByte(0xC000, 0x01);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value pointed to by HL should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// sra a
void Instrs_CB00_CB3F::test_0xCB2F() {
    loadRom({
                0xCB,
                0x2F // sra a
            });

    gb->cpu->registers.A = 0x8A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xC5, "A should be 0xC5");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB2F_zero_carry() {
    loadRom({
                0xCB,
                0x2F // sra a
            });

    gb->cpu->registers.A = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCB30_CB3F

// swap b
void Instrs_CB00_CB3F::test_0xCB30() {
    loadRom({
                0xCB,
                0x30 // swap b
            });

    gb->cpu->registers.B = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x0F, "B should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB30_zero() {
    loadRom({
                0xCB,
                0x30 // swap b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// swap c
void Instrs_CB00_CB3F::test_0xCB31() {
    loadRom({
                0xCB,
                0x31 // swap c
            });

    gb->cpu->registers.C = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x0F, "C should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB31_zero() {
    loadRom({
                0xCB,
                0x31 // swap c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// swap d
void Instrs_CB00_CB3F::test_0xCB32() {
    loadRom({
                0xCB,
                0x32 // swap d
            });

    gb->cpu->registers.D = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x0F, "D should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB32_zero() {
    loadRom({
                0xCB,
                0x32 // swap d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// swap e
void Instrs_CB00_CB3F::test_0xCB33() {
    loadRom({
                0xCB,
                0x33 // swap e
            });

    gb->cpu->registers.E = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x0F, "E should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB33_zero() {
    loadRom({
                0xCB,
                0x33 // swap e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// swap h
void Instrs_CB00_CB3F::test_0xCB34() {
    loadRom({
                0xCB,
                0x34 // swap h
            });

    gb->cpu->registers.H = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x0F, "H should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB34_zero() {
    loadRom({
                0xCB,
                0x34 // swap h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// swap l
void Instrs_CB00_CB3F::test_0xCB35() {
    loadRom({
                0xCB,
                0x35 // swap l
            });

    gb->cpu->registers.L = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x0F, "L should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB35_zero() {
    loadRom({
                0xCB,
                0x35 // swap l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// swap (hl)
void Instrs_CB00_CB3F::test_0xCB36() {
    loadRom({
                0xCB,
                0x36 // swap (hl)
            });

    gb->memory->writeByte(0xC000, 0xF0);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x0F, "the value pointed to by HL should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB36_zero() {
    loadRom({
                0xCB,
                0x36 // swap (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value pointed to by HL should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// swap a
void Instrs_CB00_CB3F::test_0xCB37() {
    loadRom({
                0xCB,
                0x37 // swap A
            });

    gb->cpu->registers.A = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x0F, "A should be 0x0F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB37_zero() {
    loadRom({
                0xCB,
                0x37 // swap A
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl b
void Instrs_CB00_CB3F::test_0xCB38_carry() {
    loadRom({
                0xCB,
                0x38 // srl b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x7F, "B should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB38_zero_carry() {
    loadRom({
                0xCB,
                0x38 // srl b
            });

    gb->cpu->registers.B = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl c
void Instrs_CB00_CB3F::test_0xCB39_carry() {
    loadRom({
                0xCB,
                0x39 // srl c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x7F, "C should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB39_zero_carry() {
    loadRom({
                0xCB,
                0x39 // srl c
            });

    gb->cpu->registers.C = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl d
void Instrs_CB00_CB3F::test_0xCB3A_carry() {
    loadRom({
                0xCB,
                0x3A // srl d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x7F, "D should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB3A_zero_carry() {
    loadRom({
                0xCB,
                0x3A // srl d
            });

    gb->cpu->registers.D = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl e
void Instrs_CB00_CB3F::test_0xCB3B_carry() {
    loadRom({
                0xCB,
                0x3B // srl e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x7F, "E should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB3B_zero_carry() {
    loadRom({
                0xCB,
                0x3B // srl e
            });

    gb->cpu->registers.E = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl h
void Instrs_CB00_CB3F::test_0xCB3C_carry() {
    loadRom({
                0xCB,
                0x3C // srl h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x7F, "H should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB3C_zero_carry() {
    loadRom({
                0xCB,
                0x3C // srl h
            });

    gb->cpu->registers.H = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl l
void Instrs_CB00_CB3F::test_0xCB3D_carry() {
    loadRom({
                0xCB,
                0x3D // srl l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x7F, "L should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB3D_zero_carry() {
    loadRom({
                0xCB,
                0x3D // srl l
            });

    gb->cpu->registers.L = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// srl (hl)
void Instrs_CB00_CB3F::test_0xCB3E_carry() {
    loadRom({
                0xCB,
                0x3E // srl (hl)
            });

    gb->memory->writeByte(0xC000, 0xFF);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x7F, "the value pointed to by HL should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB00_CB3F::test_0xCB3E_zero_carry() {
    loadRom({
                0xCB,
                0x3E // srl (hl)
            });

    gb->memory->writeByte(0xC000, 0x01);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x00, "the value pointed to by HL should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// srl a
void Instrs_CB00_CB3F::test_0xCB3F_carry() {
    loadRom({
                0xCB,
                0x3F // srl a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x7F, "A should be 0x7F");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB00_CB3F::test_0xCB3F_zero_carry() {
    loadRom({
                0xCB,
                0x3F // srl a
            });

    gb->cpu->registers.A = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}


#pragma endregion
