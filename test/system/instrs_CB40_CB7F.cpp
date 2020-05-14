#include "includes/instrs_CB40_CB7F.h"

Instrs_CB40_CB7F::Instrs_CB40_CB7F(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xCB40_half(); });
    Test::addTest([this]() -> void { test_0xCB40_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB41_half(); });
    Test::addTest([this]() -> void { test_0xCB41_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB42_half(); });
    Test::addTest([this]() -> void { test_0xCB42_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB43_half(); });
    Test::addTest([this]() -> void { test_0xCB43_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB44_half(); });
    Test::addTest([this]() -> void { test_0xCB44_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB45_half(); });
    Test::addTest([this]() -> void { test_0xCB45_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB46_half(); });
    Test::addTest([this]() -> void { test_0xCB46_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB47_half(); });
    Test::addTest([this]() -> void { test_0xCB47_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB48_half(); });
    Test::addTest([this]() -> void { test_0xCB48_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB49_half(); });
    Test::addTest([this]() -> void { test_0xCB49_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB4A_half(); });
    Test::addTest([this]() -> void { test_0xCB4A_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB4B_half(); });
    Test::addTest([this]() -> void { test_0xCB4B_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB4C_half(); });
    Test::addTest([this]() -> void { test_0xCB4C_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB4D_half(); });
    Test::addTest([this]() -> void { test_0xCB4D_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB4E_half(); });
    Test::addTest([this]() -> void { test_0xCB4E_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB4F_half(); });
    Test::addTest([this]() -> void { test_0xCB4F_half_zero(); });

    Test::addTest([this]() -> void { test_0xCB50_half(); });
    Test::addTest([this]() -> void { test_0xCB50_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB51_half(); });
    Test::addTest([this]() -> void { test_0xCB51_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB52_half(); });
    Test::addTest([this]() -> void { test_0xCB52_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB53_half(); });
    Test::addTest([this]() -> void { test_0xCB53_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB54_half(); });
    Test::addTest([this]() -> void { test_0xCB54_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB55_half(); });
    Test::addTest([this]() -> void { test_0xCB55_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB56_half(); });
    Test::addTest([this]() -> void { test_0xCB56_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB57_half(); });
    Test::addTest([this]() -> void { test_0xCB57_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB58_half(); });
    Test::addTest([this]() -> void { test_0xCB58_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB59_half(); });
    Test::addTest([this]() -> void { test_0xCB59_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB5A_half(); });
    Test::addTest([this]() -> void { test_0xCB5A_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB5B_half(); });
    Test::addTest([this]() -> void { test_0xCB5B_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB5C_half(); });
    Test::addTest([this]() -> void { test_0xCB5C_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB5D_half(); });
    Test::addTest([this]() -> void { test_0xCB5D_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB5E_half(); });
    Test::addTest([this]() -> void { test_0xCB5E_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB5F_half(); });
    Test::addTest([this]() -> void { test_0xCB5F_half_zero(); });

    Test::addTest([this]() -> void { test_0xCB60_half(); });
    Test::addTest([this]() -> void { test_0xCB60_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB61_half(); });
    Test::addTest([this]() -> void { test_0xCB61_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB62_half(); });
    Test::addTest([this]() -> void { test_0xCB62_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB63_half(); });
    Test::addTest([this]() -> void { test_0xCB63_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB64_half(); });
    Test::addTest([this]() -> void { test_0xCB64_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB65_half(); });
    Test::addTest([this]() -> void { test_0xCB65_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB66_half(); });
    Test::addTest([this]() -> void { test_0xCB66_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB67_half(); });
    Test::addTest([this]() -> void { test_0xCB67_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB68_half(); });
    Test::addTest([this]() -> void { test_0xCB68_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB69_half(); });
    Test::addTest([this]() -> void { test_0xCB69_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB6A_half(); });
    Test::addTest([this]() -> void { test_0xCB6A_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB6B_half(); });
    Test::addTest([this]() -> void { test_0xCB6B_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB6C_half(); });
    Test::addTest([this]() -> void { test_0xCB6C_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB6D_half(); });
    Test::addTest([this]() -> void { test_0xCB6D_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB6E_half(); });
    Test::addTest([this]() -> void { test_0xCB6E_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB6F_half(); });
    Test::addTest([this]() -> void { test_0xCB6F_half_zero(); });

    Test::addTest([this]() -> void { test_0xCB70_half(); });
    Test::addTest([this]() -> void { test_0xCB70_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB71_half(); });
    Test::addTest([this]() -> void { test_0xCB71_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB72_half(); });
    Test::addTest([this]() -> void { test_0xCB72_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB73_half(); });
    Test::addTest([this]() -> void { test_0xCB73_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB74_half(); });
    Test::addTest([this]() -> void { test_0xCB74_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB75_half(); });
    Test::addTest([this]() -> void { test_0xCB75_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB76_half(); });
    Test::addTest([this]() -> void { test_0xCB76_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB77_half(); });
    Test::addTest([this]() -> void { test_0xCB77_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB78_half(); });
    Test::addTest([this]() -> void { test_0xCB78_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB79_half(); });
    Test::addTest([this]() -> void { test_0xCB79_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB7A_half(); });
    Test::addTest([this]() -> void { test_0xCB7A_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB7B_half(); });
    Test::addTest([this]() -> void { test_0xCB7B_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB7C_half(); });
    Test::addTest([this]() -> void { test_0xCB7C_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB7D_half(); });
    Test::addTest([this]() -> void { test_0xCB7D_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB7E_half(); });
    Test::addTest([this]() -> void { test_0xCB7E_half_zero(); });
    Test::addTest([this]() -> void { test_0xCB7F_half(); });
    Test::addTest([this]() -> void { test_0xCB7F_half_zero(); });
}

void Instrs_CB40_CB7F::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_CB40_CB7F::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_CB40_CB7F::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_CB40_CB7F::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region rCB40_CB4F

// bit 0, b
void Instrs_CB40_CB7F::test_0xCB40_half() {
    loadRom({
                0xCB,
                0x40 // bit 0, b
            });

    gb->cpu->registers.B = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB40_half_zero() {
    loadRom({
                0xCB,
                0x40 // bit 0, b
            });

    gb->cpu->registers.B = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 0, c
void Instrs_CB40_CB7F::test_0xCB41_half() {
    loadRom({
                0xCB,
                0x41 // bit 0, c
            });

    gb->cpu->registers.C = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB41_half_zero() {
    loadRom({
                0xCB,
                0x41 // bit 0, c
            });

    gb->cpu->registers.C = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 0, d
void Instrs_CB40_CB7F::test_0xCB42_half() {
    loadRom({
                0xCB,
                0x42 // bit 0, d
            });

    gb->cpu->registers.D = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB42_half_zero() {
    loadRom({
                0xCB,
                0x42 // bit 0, d
            });

    gb->cpu->registers.D = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 0, e
void Instrs_CB40_CB7F::test_0xCB43_half() {
    loadRom({
                0xCB,
                0x43 // bit 0, e
            });

    gb->cpu->registers.E = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB43_half_zero() {
    loadRom({
                0xCB,
                0x43 // bit 0, e
            });

    gb->cpu->registers.E = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 0, h
void Instrs_CB40_CB7F::test_0xCB44_half() {
    loadRom({
                0xCB,
                0x44 // bit 0, h
            });

    gb->cpu->registers.H = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB44_half_zero() {
    loadRom({
                0xCB,
                0x44 // bit 0, h
            });

    gb->cpu->registers.H = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 0, l
void Instrs_CB40_CB7F::test_0xCB45_half() {
    loadRom({
                0xCB,
                0x45 // bit 0, l
            });

    gb->cpu->registers.L = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB45_half_zero() {
    loadRom({
                0xCB,
                0x45 // bit 0, l
            });

    gb->cpu->registers.L = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 0, (hl)
void Instrs_CB40_CB7F::test_0xCB46_half() {
    loadRom({
                0xCB,
                0x46 // bit 0, (hl)
            });

    gb->memory->writeByte(0xC000, 0x01);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB46_half_zero() {
    loadRom({
                0xCB,
                0x46 // bit 0, (hl)
            });

    gb->memory->writeByte(0xC000, 0x04);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 0, a
void Instrs_CB40_CB7F::test_0xCB47_half() {
    loadRom({
                0xCB,
                0x47 // bit 0, a
            });

    gb->cpu->registers.A = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB47_half_zero() {
    loadRom({
                0xCB,
                0x47 // bit 0, a
            });

    gb->cpu->registers.A = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, b
void Instrs_CB40_CB7F::test_0xCB48_half() {
    loadRom({
                0xCB,
                0x48 // bit 1, b
            });

    gb->cpu->registers.B = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB48_half_zero() {
    loadRom({
                0xCB,
                0x48 // bit 1, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, c
void Instrs_CB40_CB7F::test_0xCB49_half() {
    loadRom({
                0xCB,
                0x49 // bit 1, c
            });

    gb->cpu->registers.C = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB49_half_zero() {
    loadRom({
                0xCB,
                0x49 // bit 1, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, d
void Instrs_CB40_CB7F::test_0xCB4A_half() {
    loadRom({
                0xCB,
                0x4A // bit 1, d
            });

    gb->cpu->registers.D = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB4A_half_zero() {
    loadRom({
                0xCB,
                0x4A // bit 1, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, e
void Instrs_CB40_CB7F::test_0xCB4B_half() {
    loadRom({
                0xCB,
                0x4B // bit 1, e
            });

    gb->cpu->registers.E = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB4B_half_zero() {
    loadRom({
                0xCB,
                0x4B // bit 1, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, h
void Instrs_CB40_CB7F::test_0xCB4C_half() {
    loadRom({
                0xCB,
                0x4C // bit 1, h
            });

    gb->cpu->registers.H = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB4C_half_zero() {
    loadRom({
                0xCB,
                0x4C // bit 1, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, l
void Instrs_CB40_CB7F::test_0xCB4D_half() {
    loadRom({
                0xCB,
                0x4D // bit 1, l
            });

    gb->cpu->registers.L = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB4D_half_zero() {
    loadRom({
                0xCB,
                0x4D // bit 1, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 1, (hl)
void Instrs_CB40_CB7F::test_0xCB4E_half() {
    loadRom({
                0xCB,
                0x4E // bit 1, (hl)
            });

    gb->memory->writeByte(0xC000, 0x02);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB4E_half_zero() {
    loadRom({
                0xCB,
                0x4E // bit 1, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 1, a
void Instrs_CB40_CB7F::test_0xCB4F_half() {
    loadRom({
                0xCB,
                0x4F // bit 1, a
            });

    gb->cpu->registers.A = 0x02;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB4F_half_zero() {
    loadRom({
                0xCB,
                0x4F // bit 1, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCB50_CB5F

// bit 2, b
void Instrs_CB40_CB7F::test_0xCB50_half() {
    loadRom({
                0xCB,
                0x50 // bit 2, b
            });

    gb->cpu->registers.B = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB50_half_zero() {
    loadRom({
                0xCB,
                0x50 // bit 2, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 2, c
void Instrs_CB40_CB7F::test_0xCB51_half() {
    loadRom({
                0xCB,
                0x51 // bit 2, c
            });

    gb->cpu->registers.C = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB51_half_zero() {
    loadRom({
                0xCB,
                0x51 // bit 2, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 2, d
void Instrs_CB40_CB7F::test_0xCB52_half() {
    loadRom({
                0xCB,
                0x52 // bit 2, d
            });

    gb->cpu->registers.D = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB52_half_zero() {
    loadRom({
                0xCB,
                0x52 // bit 2, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 2, e
void Instrs_CB40_CB7F::test_0xCB53_half() {
    loadRom({
                0xCB,
                0x53 // bit 2, e
            });

    gb->cpu->registers.E = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB53_half_zero() {
    loadRom({
                0xCB,
                0x53 // bit 2, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 2, h
void Instrs_CB40_CB7F::test_0xCB54_half() {
    loadRom({
                0xCB,
                0x54 // bit 2, h
            });

    gb->cpu->registers.H = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB54_half_zero() {
    loadRom({
                0xCB,
                0x54 // bit 2, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 2, l
void Instrs_CB40_CB7F::test_0xCB55_half() {
    loadRom({
                0xCB,
                0x55 // bit 2, l
            });

    gb->cpu->registers.L = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB55_half_zero() {
    loadRom({
                0xCB,
                0x55 // bit 2, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 2, (hl)
void Instrs_CB40_CB7F::test_0xCB56_half() {
    loadRom({
                0xCB,
                0x56 // bit 2, (hl)
            });

    gb->memory->writeByte(0xC000, 0x04);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB56_half_zero() {
    loadRom({
                0xCB,
                0x56 // bit 2, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 2, a
void Instrs_CB40_CB7F::test_0xCB57_half() {
    loadRom({
                0xCB,
                0x57 // bit 2, a
            });

    gb->cpu->registers.A = 0x04;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB57_half_zero() {
    loadRom({
                0xCB,
                0x57 // bit 2, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, b
void Instrs_CB40_CB7F::test_0xCB58_half() {
    loadRom({
                0xCB,
                0x58 // bit 3, b
            });

    gb->cpu->registers.B = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB58_half_zero() {
    loadRom({
                0xCB,
                0x58 // bit 3, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, c
void Instrs_CB40_CB7F::test_0xCB59_half() {
    loadRom({
                0xCB,
                0x59 // bit 3, c
            });

    gb->cpu->registers.C = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB59_half_zero() {
    loadRom({
                0xCB,
                0x59 // bit 3, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, d
void Instrs_CB40_CB7F::test_0xCB5A_half() {
    loadRom({
                0xCB,
                0x5A // bit 3, d
            });

    gb->cpu->registers.D = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB5A_half_zero() {
    loadRom({
                0xCB,
                0x5A // bit 3, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, e
void Instrs_CB40_CB7F::test_0xCB5B_half() {
    loadRom({
                0xCB,
                0x5B // bit 3, e
            });

    gb->cpu->registers.E = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB5B_half_zero() {
    loadRom({
                0xCB,
                0x5B // bit 3, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, h
void Instrs_CB40_CB7F::test_0xCB5C_half() {
    loadRom({
                0xCB,
                0x5C // bit 3, h
            });

    gb->cpu->registers.H = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB5C_half_zero() {
    loadRom({
                0xCB,
                0x5C // bit 3, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, l
void Instrs_CB40_CB7F::test_0xCB5D_half() {
    loadRom({
                0xCB,
                0x5D // bit 3, l
            });

    gb->cpu->registers.L = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB5D_half_zero() {
    loadRom({
                0xCB,
                0x5D // bit 3, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 3, (hl)
void Instrs_CB40_CB7F::test_0xCB5E_half() {
    loadRom({
                0xCB,
                0x5E // bit 3, (hl)
            });

    gb->memory->writeByte(0xC000, 0x08);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB5E_half_zero() {
    loadRom({
                0xCB,
                0x5E // bit 3, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 3, a
void Instrs_CB40_CB7F::test_0xCB5F_half() {
    loadRom({
                0xCB,
                0x5F // bit 3, a
            });

    gb->cpu->registers.A = 0x08;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB5F_half_zero() {
    loadRom({
                0xCB,
                0x5F // bit 3, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCB60_CB6F

// bit 4, b
void Instrs_CB40_CB7F::test_0xCB60_half() {
    loadRom({
                0xCB,
                0x60 // bit 4, b
            });

    gb->cpu->registers.B = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB60_half_zero() {
    loadRom({
                0xCB,
                0x60 // bit 4, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 4, c
void Instrs_CB40_CB7F::test_0xCB61_half() {
    loadRom({
                0xCB,
                0x61 // bit 4, c
            });

    gb->cpu->registers.C = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB61_half_zero() {
    loadRom({
                0xCB,
                0x61 // bit 4, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 4, d
void Instrs_CB40_CB7F::test_0xCB62_half() {
    loadRom({
                0xCB,
                0x62 // bit 4, d
            });

    gb->cpu->registers.D = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB62_half_zero() {
    loadRom({
                0xCB,
                0x62 // bit 4, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 4, e
void Instrs_CB40_CB7F::test_0xCB63_half() {
    loadRom({
                0xCB,
                0x63 // bit 4, e
            });

    gb->cpu->registers.E = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB63_half_zero() {
    loadRom({
                0xCB,
                0x63 // bit 4, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 4, h
void Instrs_CB40_CB7F::test_0xCB64_half() {
    loadRom({
                0xCB,
                0x64 // bit 4, h
            });

    gb->cpu->registers.H = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB64_half_zero() {
    loadRom({
                0xCB,
                0x64 // bit 4, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 4, l
void Instrs_CB40_CB7F::test_0xCB65_half() {
    loadRom({
                0xCB,
                0x65 // bit 4, l
            });

    gb->cpu->registers.L = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB65_half_zero() {
    loadRom({
                0xCB,
                0x65 // bit 4, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 4, (hl)
void Instrs_CB40_CB7F::test_0xCB66_half() {
    loadRom({
                0xCB,
                0x66 // bit 4, (hl)
            });

    gb->memory->writeByte(0xC000, 0x10);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB66_half_zero() {
    loadRom({
                0xCB,
                0x66 // bit 4, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 4, a
void Instrs_CB40_CB7F::test_0xCB67_half() {
    loadRom({
                0xCB,
                0x67 // bit 4, a
            });

    gb->cpu->registers.A = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB67_half_zero() {
    loadRom({
                0xCB,
                0x67 // bit 4, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, b
void Instrs_CB40_CB7F::test_0xCB68_half() {
    loadRom({
                0xCB,
                0x68 // bit 5, b
            });

    gb->cpu->registers.B = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB68_half_zero() {
    loadRom({
                0xCB,
                0x68 // bit 5, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, c
void Instrs_CB40_CB7F::test_0xCB69_half() {
    loadRom({
                0xCB,
                0x69 // bit 5, c
            });

    gb->cpu->registers.C = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB69_half_zero() {
    loadRom({
                0xCB,
                0x69 // bit 5, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, d
void Instrs_CB40_CB7F::test_0xCB6A_half() {
    loadRom({
                0xCB,
                0x6A // bit 5, d
            });

    gb->cpu->registers.D = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB6A_half_zero() {
    loadRom({
                0xCB,
                0x6A // bit 5, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, e
void Instrs_CB40_CB7F::test_0xCB6B_half() {
    loadRom({
                0xCB,
                0x6B // bit 5, e
            });

    gb->cpu->registers.E = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB6B_half_zero() {
    loadRom({
                0xCB,
                0x6B // bit 5, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, h
void Instrs_CB40_CB7F::test_0xCB6C_half() {
    loadRom({
                0xCB,
                0x6C // bit 5, h
            });

    gb->cpu->registers.H = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB6C_half_zero() {
    loadRom({
                0xCB,
                0x6C // bit 5, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, l
void Instrs_CB40_CB7F::test_0xCB6D_half() {
    loadRom({
                0xCB,
                0x6D // bit 5, l
            });

    gb->cpu->registers.L = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB6D_half_zero() {
    loadRom({
                0xCB,
                0x6D // bit 5, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 5, (hl)
void Instrs_CB40_CB7F::test_0xCB6E_half() {
    loadRom({
                0xCB,
                0x6E // bit 5, (hl)
            });

    gb->memory->writeByte(0xC000, 0x20);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB6E_half_zero() {
    loadRom({
                0xCB,
                0x6E // bit 5, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 5, a
void Instrs_CB40_CB7F::test_0xCB6F_half() {
    loadRom({
                0xCB,
                0x6F // bit 5, a
            });

    gb->cpu->registers.A = 0x20;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB6F_half_zero() {
    loadRom({
                0xCB,
                0x6F // bit 5, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCB70_CB7F

// bit 6, b
void Instrs_CB40_CB7F::test_0xCB70_half() {
    loadRom({
                0xCB,
                0x70 // bit 6, b
            });

    gb->cpu->registers.B = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB70_half_zero() {
    loadRom({
                0xCB,
                0x70 // bit 6, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 6, c
void Instrs_CB40_CB7F::test_0xCB71_half() {
    loadRom({
                0xCB,
                0x71 // bit 6, c
            });

    gb->cpu->registers.C = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB71_half_zero() {
    loadRom({
                0xCB,
                0x71 // bit 6, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 6, d
void Instrs_CB40_CB7F::test_0xCB72_half() {
    loadRom({
                0xCB,
                0x72 // bit 6, d
            });

    gb->cpu->registers.D = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB72_half_zero() {
    loadRom({
                0xCB,
                0x72 // bit 6, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 6, e
void Instrs_CB40_CB7F::test_0xCB73_half() {
    loadRom({
                0xCB,
                0x73 // bit 6, e
            });

    gb->cpu->registers.E = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB73_half_zero() {
    loadRom({
                0xCB,
                0x73 // bit 6, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 6, h
void Instrs_CB40_CB7F::test_0xCB74_half() {
    loadRom({
                0xCB,
                0x74 // bit 6, h
            });

    gb->cpu->registers.H = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB74_half_zero() {
    loadRom({
                0xCB,
                0x74 // bit 6, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 6, l
void Instrs_CB40_CB7F::test_0xCB75_half() {
    loadRom({
                0xCB,
                0x75 // bit 6, l
            });

    gb->cpu->registers.L = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB75_half_zero() {
    loadRom({
                0xCB,
                0x75 // bit 6, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 6, (hl)
void Instrs_CB40_CB7F::test_0xCB76_half() {
    loadRom({
                0xCB,
                0x76 // bit 6, (hl)
            });

    gb->memory->writeByte(0xC000, 0x40);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB76_half_zero() {
    loadRom({
                0xCB,
                0x76 // bit 6, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 6, a
void Instrs_CB40_CB7F::test_0xCB77_half() {
    loadRom({
                0xCB,
                0x77 // bit 6, a
            });

    gb->cpu->registers.A = 0x40;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB77_half_zero() {
    loadRom({
                0xCB,
                0x77 // bit 6, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, b
void Instrs_CB40_CB7F::test_0xCB78_half() {
    loadRom({
                0xCB,
                0x78 // bit 7, b
            });

    gb->cpu->registers.B = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB78_half_zero() {
    loadRom({
                0xCB,
                0x78 // bit 7, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, c
void Instrs_CB40_CB7F::test_0xCB79_half() {
    loadRom({
                0xCB,
                0x79 // bit 7, c
            });

    gb->cpu->registers.C = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB79_half_zero() {
    loadRom({
                0xCB,
                0x79 // bit 7, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, d
void Instrs_CB40_CB7F::test_0xCB7A_half() {
    loadRom({
                0xCB,
                0x7A // bit 7, d
            });

    gb->cpu->registers.D = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB7A_half_zero() {
    loadRom({
                0xCB,
                0x7A // bit 7, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, e
void Instrs_CB40_CB7F::test_0xCB7B_half() {
    loadRom({
                0xCB,
                0x7B // bit 7, e
            });

    gb->cpu->registers.E = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB7B_half_zero() {
    loadRom({
                0xCB,
                0x7B // bit 7, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, h
void Instrs_CB40_CB7F::test_0xCB7C_half() {
    loadRom({
                0xCB,
                0x7C // bit 7, h
            });

    gb->cpu->registers.H = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB7C_half_zero() {
    loadRom({
                0xCB,
                0x7C // bit 7, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, l
void Instrs_CB40_CB7F::test_0xCB7D_half() {
    loadRom({
                0xCB,
                0x7D // bit 7, l
            });

    gb->cpu->registers.L = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB7D_half_zero() {
    loadRom({
                0xCB,
                0x7D // bit 7, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// bit 7, (hl)
void Instrs_CB40_CB7F::test_0xCB7E_half() {
    loadRom({
                0xCB,
                0x7E // bit 7, (hl)
            });

    gb->memory->writeByte(0xC000, 0x80);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_CB40_CB7F::test_0xCB7E_half_zero() {
    loadRom({
                0xCB,
                0x7E // bit 7, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// bit 7, a
void Instrs_CB40_CB7F::test_0xCB7F_half() {
    loadRom({
                0xCB,
                0x7F // bit 7, a
            });

    gb->cpu->registers.A = 0x80;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_CB40_CB7F::test_0xCB7F_half_zero() {
    loadRom({
                0xCB,
                0x7F // bit 7, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion
