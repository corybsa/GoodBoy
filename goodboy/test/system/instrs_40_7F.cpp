#include "includes/instrs_40_7F.h"

Instrs_40_7F::Instrs_40_7F(GameBoy* gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0x40(); });
    Test::addTest([this]() -> void { test_0x41(); });
    Test::addTest([this]() -> void { test_0x42(); });
    Test::addTest([this]() -> void { test_0x43(); });
    Test::addTest([this]() -> void { test_0x44(); });
    Test::addTest([this]() -> void { test_0x45(); });
    Test::addTest([this]() -> void { test_0x46(); });
    Test::addTest([this]() -> void { test_0x47(); });
    Test::addTest([this]() -> void { test_0x48(); });
    Test::addTest([this]() -> void { test_0x49(); });
    Test::addTest([this]() -> void { test_0x4A(); });
    Test::addTest([this]() -> void { test_0x4B(); });
    Test::addTest([this]() -> void { test_0x4C(); });
    Test::addTest([this]() -> void { test_0x4D(); });
    Test::addTest([this]() -> void { test_0x4E(); });
    Test::addTest([this]() -> void { test_0x4F(); });

    Test::addTest([this]() -> void { test_0x50(); });
    Test::addTest([this]() -> void { test_0x51(); });
    Test::addTest([this]() -> void { test_0x52(); });
    Test::addTest([this]() -> void { test_0x53(); });
    Test::addTest([this]() -> void { test_0x54(); });
    Test::addTest([this]() -> void { test_0x55(); });
    Test::addTest([this]() -> void { test_0x56(); });
    Test::addTest([this]() -> void { test_0x57(); });
    Test::addTest([this]() -> void { test_0x58(); });
    Test::addTest([this]() -> void { test_0x59(); });
    Test::addTest([this]() -> void { test_0x5A(); });
    Test::addTest([this]() -> void { test_0x5B(); });
    Test::addTest([this]() -> void { test_0x5C(); });
    Test::addTest([this]() -> void { test_0x5D(); });
    Test::addTest([this]() -> void { test_0x5E(); });
    Test::addTest([this]() -> void { test_0x5F(); });

    Test::addTest([this]() -> void { test_0x60(); });
    Test::addTest([this]() -> void { test_0x61(); });
    Test::addTest([this]() -> void { test_0x62(); });
    Test::addTest([this]() -> void { test_0x63(); });
    Test::addTest([this]() -> void { test_0x64(); });
    Test::addTest([this]() -> void { test_0x65(); });
    Test::addTest([this]() -> void { test_0x66(); });
    Test::addTest([this]() -> void { test_0x67(); });
    Test::addTest([this]() -> void { test_0x68(); });
    Test::addTest([this]() -> void { test_0x69(); });
    Test::addTest([this]() -> void { test_0x6A(); });
    Test::addTest([this]() -> void { test_0x6B(); });
    Test::addTest([this]() -> void { test_0x6C(); });
    Test::addTest([this]() -> void { test_0x6D(); });
    Test::addTest([this]() -> void { test_0x6E(); });
    Test::addTest([this]() -> void { test_0x6F(); });

    Test::addTest([this]() -> void { test_0x70(); });
    Test::addTest([this]() -> void { test_0x71(); });
    Test::addTest([this]() -> void { test_0x72(); });
    Test::addTest([this]() -> void { test_0x73(); });
    Test::addTest([this]() -> void { test_0x74(); });
    Test::addTest([this]() -> void { test_0x75(); });
    Test::addTest([this]() -> void { test_0x76(); });
    Test::addTest([this]() -> void { test_0x76_halt_bug(); });
    Test::addTest([this]() -> void { test_0x76_halt_bug2(); });
    Test::addTest([this]() -> void { test_0x76_halt_bug_freeze(); });
    Test::addTest([this]() -> void { test_0x77(); });
    Test::addTest([this]() -> void { test_0x78(); });
    Test::addTest([this]() -> void { test_0x79(); });
    Test::addTest([this]() -> void { test_0x7A(); });
    Test::addTest([this]() -> void { test_0x7B(); });
    Test::addTest([this]() -> void { test_0x7C(); });
    Test::addTest([this]() -> void { test_0x7D(); });
    Test::addTest([this]() -> void { test_0x7E(); });
    Test::addTest([this]() -> void { test_0x7F(); });
}

void Instrs_40_7F::beforeAll() {
    rom = new byte[0x800000];
    testResults << std::endl << "Instructions 0x40 through 0x7F running...";
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

#pragma region r0x40_0x4F

// ld b, b
void Instrs_40_7F::test_0x40() {
    loadRom({
                0x40 // ld b, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, c
void Instrs_40_7F::test_0x41() {
    loadRom({
                0x41 // ld b, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, d
void Instrs_40_7F::test_0x42() {
    loadRom({
                0x42 // ld b, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, e
void Instrs_40_7F::test_0x43() {
    loadRom({
                0x43 // ld b, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, h
void Instrs_40_7F::test_0x44() {
    loadRom({
                0x44 // ld b, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, l
void Instrs_40_7F::test_0x45() {
    loadRom({
                0x45 // ld b, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, (hl)
void Instrs_40_7F::test_0x46() {
    loadRom({
                0x46 // ld b, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld b, a
void Instrs_40_7F::test_0x47() {
    loadRom({
                0x47 // ld b, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, b
void Instrs_40_7F::test_0x48() {
    loadRom({
                0x48 // ld c, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, c
void Instrs_40_7F::test_0x49() {
    loadRom({
                0x49 // ld c, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, d
void Instrs_40_7F::test_0x4A() {
    loadRom({
                0x4A // ld c, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, e
void Instrs_40_7F::test_0x4B() {
    loadRom({
                0x4B // ld c, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, h
void Instrs_40_7F::test_0x4C() {
    loadRom({
                0x4C // ld c, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, l
void Instrs_40_7F::test_0x4D() {
    loadRom({
                0x4D // ld c, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, (hl)
void Instrs_40_7F::test_0x4E() {
    loadRom({
                0x4E // ld c, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld c, a
void Instrs_40_7F::test_0x4F() {
    loadRom({
                0x4F // ld c, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x50_0x5F

// ld d, b
void Instrs_40_7F::test_0x50() {
    loadRom({
                0x50 // ld d, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, c
void Instrs_40_7F::test_0x51() {
    loadRom({
                0x51 // ld d, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, d
void Instrs_40_7F::test_0x52() {
    loadRom({
                0x52 // ld d, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, e
void Instrs_40_7F::test_0x53() {
    loadRom({
                0x53 // ld d, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, h
void Instrs_40_7F::test_0x54() {
    loadRom({
                0x54 // ld d, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, l
void Instrs_40_7F::test_0x55() {
    loadRom({
                0x55 // ld d, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, (hl)
void Instrs_40_7F::test_0x56() {
    loadRom({
                0x56 // ld d, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld d, a
void Instrs_40_7F::test_0x57() {
    loadRom({
                0x57 // ld d, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x42, "D should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, b
void Instrs_40_7F::test_0x58() {
    loadRom({
                0x58 // ld e, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, c
void Instrs_40_7F::test_0x59() {
    loadRom({
                0x59 // ld e, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, d
void Instrs_40_7F::test_0x5A() {
    loadRom({
                0x5A // ld e, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, e
void Instrs_40_7F::test_0x5B() {
    loadRom({
                0x5B // ld e, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, h
void Instrs_40_7F::test_0x5C() {
    loadRom({
                0x5C // ld e, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, l
void Instrs_40_7F::test_0x5D() {
    loadRom({
                0x5D // ld e, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, (hl)
void Instrs_40_7F::test_0x5E() {
    loadRom({
                0x5E // ld e, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld e, a
void Instrs_40_7F::test_0x5F() {
    loadRom({
                0x5F // ld e, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x42, "E should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x60_0x6F

// ld h, b
void Instrs_40_7F::test_0x60() {
    loadRom({
                0x60 // ld h, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, c
void Instrs_40_7F::test_0x61() {
    loadRom({
                0x61 // ld h, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, d
void Instrs_40_7F::test_0x62() {
    loadRom({
                0x62 // ld h, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, e
void Instrs_40_7F::test_0x63() {
    loadRom({
                0x63 // ld h, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, h
void Instrs_40_7F::test_0x64() {
    loadRom({
                0x64 // ld h, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, l
void Instrs_40_7F::test_0x65() {
    loadRom({
                0x65 // ld h, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, (hl)
void Instrs_40_7F::test_0x66() {
    loadRom({
                0x66 // ld h, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld h, a
void Instrs_40_7F::test_0x67() {
    loadRom({
                0x67 // ld h, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x42, "H should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, b
void Instrs_40_7F::test_0x68() {
    loadRom({
                0x68 // ld l, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, c
void Instrs_40_7F::test_0x69() {
    loadRom({
                0x69 // ld l, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, d
void Instrs_40_7F::test_0x6A() {
    loadRom({
                0x6A // ld l, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, e
void Instrs_40_7F::test_0x6B() {
    loadRom({
                0x6B // ld l, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, h
void Instrs_40_7F::test_0x6C() {
    loadRom({
                0x6C // ld l, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, l
void Instrs_40_7F::test_0x6D() {
    loadRom({
                0x6D // ld l, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, (hl)
void Instrs_40_7F::test_0x6E() {
    loadRom({
                0x6E // ld l, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld l, a
void Instrs_40_7F::test_0x6F() {
    loadRom({
                0x6F // ld l, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x42, "L should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x70_0x7F

// ld (hl), b
void Instrs_40_7F::test_0x70() {
    loadRom({
                0x70 // ld (hl), b
            });

    gb->cpu->registers.HL = 0xC000;
    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld (hl), c
void Instrs_40_7F::test_0x71() {
    loadRom({
                0x71 // ld (hl), c
            });

    gb->cpu->registers.HL = 0xC000;
    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld (hl), d
void Instrs_40_7F::test_0x72() {
    loadRom({
                0x72 // ld (hl), d
            });

    gb->cpu->registers.HL = 0xC000;
    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld (hl), e
void Instrs_40_7F::test_0x73() {
    loadRom({
                0x73 // ld (hl), e
            });

    gb->cpu->registers.HL = 0xC000;
    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld (hl), h
void Instrs_40_7F::test_0x74() {
    loadRom({
                0x74 // ld (hl), h
            });

    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0xC0, "the value in memory at 0xC000 should be 0xC0");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld (hl), l
void Instrs_40_7F::test_0x75() {
    loadRom({
                0x75 // ld (hl), l
            });

    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x00, "the value in memory at 0xC000 should be 0x00");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// halt
void Instrs_40_7F::test_0x76() {
    loadRom({
                0xFB, // ei
                0x00, // nop
                0x76 // halt
            });

    expect(gb->cpu->ime, false, "the IME should be disabled by default");
    expect(gb->cpu->isHalted, false, "the CPU should not be halted by default");

    gb->cpu->tick();
    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->ime, true, "IME should be enabled");
    expect(gb->cpu->isHalted, true, "CPu should be halted");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_40_7F::test_0x76_halt_bug() {
    loadRom({
                0xAF, // xor a
                0x76, // halt
                0x3C // inc a
            });

    gb->memory->writeIO(IO_INTERRUPT_ENABLE, 0x00);
    gb->memory->writeIO(IO_INTERRUPT_FLAGS, 0x00);

    expect(gb->cpu->ime, false, "IME should be disabled by default");

    gb->cpu->tick(); // xor a
    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");

    gb->memory->writeIO(IO_INTERRUPT_ENABLE, 0x1D);
    gb->memory->writeIO(IO_INTERRUPT_FLAGS, 0xCA);

    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->isHalted, false, "CPU should not be halted");
    expect(gb->cpu->haltBug, true, "should activate halt bug");

    gb->cpu->tick(); // inc a
    expect(gb->cpu->registers.PC, 0x102, "PC should not be incremented, due to halt bug");
    expect(gb->cpu->registers.A, 0x01, "should increment A by 1 and be 0x01");

    gb->cpu->tick(); // inc a
    expect(gb->cpu->registers.PC, 0x103, "PC should increment normally and be 0x103");
    expect(gb->cpu->registers.A, 0x02, "should increment A by 1 and be 0x02");
    expect(gb->cpu->isHalted, false, "should not be halted");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_40_7F::test_0x76_halt_bug2() {
    loadRom({
                0x76, // halt
                0xFA, // ld a, (0x1284)
                0x84,
                0x12
            });

    gb->cpu->registers.DE = 0xC000;
    gb->memory->writeByte(0x84FA, 0x42);
    gb->memory->writeIO(IO_INTERRUPT_ENABLE, 0x1D);
    gb->memory->writeIO(IO_INTERRUPT_FLAGS, 0xCA);

    expect(gb->cpu->ime, false, "IME should be disabled by default");

    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->isHalted, false, "should not be halted");
    expect(gb->cpu->haltBug, true, "should activate halt bug");

    gb->cpu->tick(); // ld a, (0x84FA) ; this operation is borked by the halt bug
    expect(gb->cpu->registers.PC, 0x103, "should increment PC by an unintended amount and be 0x103");
    expect(gb->cpu->registers.A, 0x42, "should load an unintended value into A and be 0x42");

    gb->cpu->tick(); // ld (de), a ; this operation was created due to the halt bug
    expect(gb->cpu->registers.PC, 0x104, "should increment PC appropriately for the bugged instruction and be 0x104");
    expect(gb->memory->readByte(0xC000), 0x42, "should load the value of A into the address pointed to by DE");
    expect(gb->cpu->isHalted, false, "should not be halted");
    expect(gb->cpu->cycles, 28, "should take 28 cycles");
}

void Instrs_40_7F::test_0x76_halt_bug_freeze() {
    loadRom({
                0x76, // halt
                0x76 // halt
            });

    gb->memory->writeIO(IO_INTERRUPT_ENABLE, 0x1D);
    gb->memory->writeIO(IO_INTERRUPT_FLAGS, 0xCA);

    expect(gb->cpu->ime, false, "IME should be disabled by default");

    // no matter how many ticks we do it's always going to be a halt instruction.
    // let's tick just 5 times to see if it's hung up on halt
    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->isHalted, false, "should not be halted");
    expect(gb->cpu->haltBug, true, "should activate halt bug");

    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x101, "should 'freeze' PC due to halt bug");

    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x101, "should 'freeze' PC due to halt bug");

    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x101, "should 'freeze' PC due to halt bug");

    gb->cpu->tick(); // halt
    expect(gb->cpu->registers.PC, 0x101, "should 'freeze' PC due to halt bug");
    expect(gb->cpu->isHalted, false, "should not be halted");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

// ld (hl), a
void Instrs_40_7F::test_0x77() {
    loadRom({
                0x77 // ld (hl), a
            });

    gb->cpu->registers.HL = 0xC000;
    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, b
void Instrs_40_7F::test_0x78() {
    loadRom({
                0x78 // ld a, b
            });

    gb->cpu->registers.B = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, c
void Instrs_40_7F::test_0x79() {
    loadRom({
                0x79 // ld a, c
            });

    gb->cpu->registers.C = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, d
void Instrs_40_7F::test_0x7A() {
    loadRom({
                0x7A // ld a, d
            });

    gb->cpu->registers.D = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, e
void Instrs_40_7F::test_0x7B() {
    loadRom({
                0x7B // ld a, e
            });

    gb->cpu->registers.E = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, h
void Instrs_40_7F::test_0x7C() {
    loadRom({
                0x7C // ld a, h
            });

    gb->cpu->registers.H = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, l
void Instrs_40_7F::test_0x7D() {
    loadRom({
                0x7D // ld a, l
            });

    gb->cpu->registers.L = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, (hl)
void Instrs_40_7F::test_0x7E() {
    loadRom({
                0x7E // ld a, (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, a
void Instrs_40_7F::test_0x7F() {
    loadRom({
                0x7F // ld a, a
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion