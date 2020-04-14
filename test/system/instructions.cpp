#include "includes/instructions.h"
#include <iostream>
#include <algorithm>

InstructionsTest::InstructionsTest(GameBoy* gameBoy) {
    gb = gameBoy;
    rom = NULL;

    Test::addTest([this]() -> void { test_0x00(); });
    Test::addTest([this]() -> void { test_0x01(); });
    Test::addTest([this]() -> void { test_0x02(); });
    Test::addTest([this]() -> void { test_0x03(); });
    Test::addTest([this]() -> void { test_0x04(); });
    Test::addTest([this]() -> void { test_0x04_half(); });
    Test::addTest([this]() -> void { test_0x04_zero_half(); });
    Test::addTest([this]() -> void { test_0x05(); });
    Test::addTest([this]() -> void { test_0x05_zero_sub(); });
    Test::addTest([this]() -> void { test_0x05_sub_half(); });
    Test::addTest([this]() -> void { test_0x05_sub_half2(); });
    Test::addTest([this]() -> void { test_0x06(); });
    Test::addTest([this]() -> void { test_0x07(); });
    Test::addTest([this]() -> void { test_0x08(); });
    Test::addTest([this]() -> void { test_0x09_half(); });
    Test::addTest([this]() -> void { test_0x09_carry(); });
    Test::addTest([this]() -> void { test_0x0A(); });
    Test::addTest([this]() -> void { test_0x0B(); });
    Test::addTest([this]() -> void { test_0x0C(); });
    Test::addTest([this]() -> void { test_0x0C_half(); });
    Test::addTest([this]() -> void { test_0x0C_zero_half(); });
    Test::addTest([this]() -> void { test_0x0D(); });
    Test::addTest([this]() -> void { test_0x0D_zero(); });
    Test::addTest([this]() -> void { test_0x0D_half(); });
    Test::addTest([this]() -> void { test_0x0D_half2(); });
    Test::addTest([this]() -> void { test_0x0E(); });
    Test::addTest([this]() -> void { test_0x0F(); });
    Test::addTest([this]() -> void { test_0x0F_clear_carry(); });

    Test::addTest([this]() -> void { test_0x10(); });
    Test::addTest([this]() -> void { test_0x11(); });
    Test::addTest([this]() -> void { test_0x12(); });
    Test::addTest([this]() -> void { test_0x13(); });
    Test::addTest([this]() -> void { test_0x14(); });
    Test::addTest([this]() -> void { test_0x14_half(); });
    Test::addTest([this]() -> void { test_0x14_zero_half(); });
    Test::addTest([this]() -> void { test_0x15(); });
    Test::addTest([this]() -> void { test_0x15_zero(); });
    Test::addTest([this]() -> void { test_0x15_half(); });
    Test::addTest([this]() -> void { test_0x15_half2(); });
    Test::addTest([this]() -> void { test_0x16(); });
    Test::addTest([this]() -> void { test_0x17(); });
    Test::addTest([this]() -> void { test_0x18(); });
    Test::addTest([this]() -> void { test_0x19(); });
    Test::addTest([this]() -> void { test_0x1A(); });
    Test::addTest([this]() -> void { test_0x1B(); });
    Test::addTest([this]() -> void { test_0x1C(); });
    Test::addTest([this]() -> void { test_0x1C_half(); });
    Test::addTest([this]() -> void { test_0x1C_zero_half(); });
    Test::addTest([this]() -> void { test_0x1D(); });
    Test::addTest([this]() -> void { test_0x1D_zero(); });
    Test::addTest([this]() -> void { test_0x1D_half(); });
    Test::addTest([this]() -> void { test_0x1D_half2(); });
    Test::addTest([this]() -> void { test_0x1E(); });
    Test::addTest([this]() -> void { test_0x1F(); });

    Test::addTest([this]() -> void { test_0x20(); });
    Test::addTest([this]() -> void { test_0x21(); });
    Test::addTest([this]() -> void { test_0x22(); });
    Test::addTest([this]() -> void { test_0x23(); });
    Test::addTest([this]() -> void { test_0x24(); });
    Test::addTest([this]() -> void { test_0x25(); });
    Test::addTest([this]() -> void { test_0x26(); });
    Test::addTest([this]() -> void { test_0x27(); });
    Test::addTest([this]() -> void { test_0x28(); });
    Test::addTest([this]() -> void { test_0x29(); });
    Test::addTest([this]() -> void { test_0x2A(); });
    Test::addTest([this]() -> void { test_0x2B(); });
    Test::addTest([this]() -> void { test_0x2C(); });
    Test::addTest([this]() -> void { test_0x2D(); });
    Test::addTest([this]() -> void { test_0x2E(); });
    Test::addTest([this]() -> void { test_0x2F(); });

    Test::addTest([this]() -> void { test_0x30(); });
    Test::addTest([this]() -> void { test_0x31(); });
    Test::addTest([this]() -> void { test_0x32(); });
    Test::addTest([this]() -> void { test_0x33(); });
    Test::addTest([this]() -> void { test_0x34(); });
    Test::addTest([this]() -> void { test_0x35(); });
    Test::addTest([this]() -> void { test_0x36(); });
    Test::addTest([this]() -> void { test_0x37(); });
    Test::addTest([this]() -> void { test_0x38(); });
    Test::addTest([this]() -> void { test_0x39(); });
    Test::addTest([this]() -> void { test_0x3A(); });
    Test::addTest([this]() -> void { test_0x3B(); });
    Test::addTest([this]() -> void { test_0x3C(); });
    Test::addTest([this]() -> void { test_0x3D(); });
    Test::addTest([this]() -> void { test_0x3E(); });
    Test::addTest([this]() -> void { test_0x3F(); });
}

void InstructionsTest::beforeAll() {
    rom = new byte[0x800000];
}

void InstructionsTest::beforeEach() {
    std::fill(rom, rom + 0x7FFF, 0);
}

void InstructionsTest::tearDown() {
    if(rom != NULL) {
        delete[] rom;
        rom = NULL;
    }
}

void InstructionsTest::loadRom(std::vector<byte> bytes) {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
}

// nop
void InstructionsTest::test_0x00() {
    loadRom({
        0x00 // nop
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld bc, xx
void InstructionsTest::test_0x01() {
    loadRom({
        0x01, // ld bc, 0xC0DE
        0xDE,
        0xC0
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.BC, 0xC0DE, "BC should be 0xC0DE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (bc), a
void InstructionsTest::test_0x02() {
    loadRom({
        0x3E, // ld a, $42
        0x42,
        0x01, // ld bc, $C000
        0x00,
        0xC0,
        0x02 // ld (bc), a
    });

    gb->cpu->tick();
    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x106, "PC should be 0x106");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->registers.BC, 0xC000, "BC should be 0xC000");
    expect(gb->memory->readByte(0xC000), 0x42, "The value in memory pointed to by BC should be 0x42");
    expect(gb->cpu->cycles, 28, "should take 28 cycles");
}

// inc bc
void InstructionsTest::test_0x03() {
    loadRom({
        0x01, // ld bc, $0001
        0x01,
        0x00,
        0x03 // inc bc
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x106, "PC should be 0x106");
    expect(gb->cpu->registers.BC, 0x0002, "BC should be 0x0002");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

// inc b
void InstructionsTest::test_0x04() {
    loadRom({
        0x06, // ld b, $00
        0x00,
        0x04 // inc b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0x01, "B should be 0x01");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// inc b
void InstructionsTest::test_0x04_half() {
    loadRom({
        0x06, // ld b, $0F
        0x0F,
        0x04 // inc b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0x10, "B should be 0x10");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// inc b
void InstructionsTest::test_0x04_zero_half() {
    loadRom({
        0x06, // ld b, $FF
        0xFF,
        0x04 // inc b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec b
void InstructionsTest::test_0x05() {
    loadRom({
        0x06, // ld b, $FF
        0xFF,
        0x05 // dec b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0xFE, "B should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec b
void InstructionsTest::test_0x05_zero_sub() {
    loadRom({
        0x06, // ld b, $01
        0x01,
        0x05 // dec b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB | CARRY, "ZERO, SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec b
void InstructionsTest::test_0x05_sub_half() {
    loadRom({
        0x06, // ld b, $10
        0x10,
        0x05 // dec b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0x0F, "B should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec b
void InstructionsTest::test_0x05_sub_half2() {
    loadRom({
        0x06, // ld b, $00
        0x00,
        0x05 // dec b
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.B, 0xFF, "B should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld b, x
void InstructionsTest::test_0x06() {
    loadRom({
        0x06, // ld b, $F3
        0xF3
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0xF3, "B should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rlca
void InstructionsTest::test_0x07() {
    loadRom({
        0x3E, // ld a, $85
        0x85,
        0x07 // rlca
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.A, 0x0B, "A should be 0x0B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (xx), sp
void InstructionsTest::test_0x08() {
    loadRom({
        0x31, // ld sp, $C0DE
        0xDE,
        0xC0,
        0x08, // ld ($C000), sp
        0x00,
        0xC0
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x106, "PC should be 0x106");
    expect(gb->cpu->registers.SP, 0xC0DE, "SP should be 0xC0DE");
    expect(gb->memory->readByte(0xC000), 0xC0DE, "the value in memory pointed to by 0xC000 should be 0xC0DE");
    expect(gb->cpu->cycles, 32, "should take 32 cycles");
}

// add hl, bc
void InstructionsTest::test_0x09_half() {
    loadRom({
        0x01, // ld bc, $0605
        0x05,
        0x06,
        0x21, // ld hl, $8A23
        0x23,
        0x8A,
        0x09 // add hl, bc
    });

    gb->cpu->tick();
    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->registers.HL, 0x9028, "HL should be 0x9028");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 32, "should take 32 cycles");
}

// add hl, bc
void InstructionsTest::test_0x09_carry() {
    loadRom({
        0x01, // ld bc, $FFFF
        0xFF,
        0xFF,
        0x21, // ld hl, $0001
        0x01,
        0x00,
        0x09 // add hl, bc
    });

    gb->cpu->tick();
    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->registers.HL, 0x0000, "HL should be 0x0000");
    expect(gb->cpu->registers.F, ZERO | CARRY, "ZERO and CARRY flags should be set");
    expect(gb->cpu->cycles, 32, "should take 32 cycles");
}

// ld a, (bc)
void InstructionsTest::test_0x0A() {
    loadRom({
        0x01, // ld bc, $C000
        0x00,
        0xC0,
        0x0A // ld a, (bc)
    });

    gb->memory->writeByte(0xC000, 0x12);

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->registers.BC, 0xC000, "BC should be 0xC000");
    expect(gb->cpu->registers.A, 0x12, "A should be 0x12");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

// dec bc
void InstructionsTest::test_0x0B() {
    loadRom({
        0x01, // ld bc, $C000
        0x00,
        0xC0,
        0x0B // dec bc
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->registers.BC, 0xBFFF, "BC should be 0xBFFF");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

// inc c
void InstructionsTest::test_0x0C() {
    loadRom({
        0x0E, // ld c, $00
        0x00,
        0x0C // inc c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0x01, "C should be 0x01");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x0C_half() {
    loadRom({
        0x0E, // ld c, $0F
        0x0F,
        0x0C // inc c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0x10, "C should be 0x10");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x0C_zero_half() {
    loadRom({
        0x0E, // ld c, $FF
        0xFF,
        0x0C // inc c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec c
void InstructionsTest::test_0x0D() {
    loadRom({
        0x0E, // ld c, $FF
        0xFF,
        0x0D // dec c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0xFE, "C should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x0D_zero() {
    loadRom({
        0x0E, // ld c, $01
        0x01,
        0x0D // dec c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB | CARRY, "ZERO, SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x0D_half() {
    loadRom({
        0x0E, // ld c, $10
        0x10,
        0x0D // dec c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0x0F, "C should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x0D_half2() {
    loadRom({
        0x0E, // ld c, $00
        0x00,
        0x0D // dec c
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.C, 0xFF, "C should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld c, x
void InstructionsTest::test_0x0E() {
    loadRom({
        0x0E, // ld c, $F3
        0xF3
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0xF3, "C should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rrca
void InstructionsTest::test_0x0F() {
    loadRom({
        0x3E, // ld a, $3B
        0x3B,
        0x0F // rrca
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x9D, "A should be 0x9D");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x0F_clear_carry() {
    loadRom({
        0x3E, // ld a, $AA
        0xAA,
        0x0F // rrca
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x55, "A should be 0x55");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}


// stop
void InstructionsTest::test_0x10() {
    loadRom({
        0x10, // stop
        0x00
    });

    gb->cpu->tick();

    // TODO: how to test this?
    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld de, xx
void InstructionsTest::test_0x11() {
    loadRom({
        0x11, // ld de, $C0DE
        0xDE,
        0xC0
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.DE, 0xC0DE, "DE should be 0xC0DE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (de), a
void InstructionsTest::test_0x12() {
    loadRom({
        0x3E, // ld a, $42
        0x42,
        0x11, // ld de, $C000
        0x00,
        0xC0,
        0x12 // ld (de), a
    });

    gb->cpu->tick();
    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x106, "PC should be 0x106");
    expect(gb->cpu->registers.A, 0x42, "DE should be 0x42");
    expect(gb->cpu->registers.DE, 0xC000, "DE should be 0xC000");
    expect(gb->memory->readByte(0xC000), 0x42, "Value in memory pointed to by DE should be 0x42");
    expect(gb->cpu->cycles, 28, "should take 28 cycles");
}

// inc de
void InstructionsTest::test_0x13() {
    loadRom({
        0x11, // ld de, $0001
        0x01,
        0x00,
        0x13 // inc de
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->registers.DE, 0x0002, "DE should be 0x0002");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

// inc d
void InstructionsTest::test_0x14() {
    loadRom({
        0x16, // ld d, $00
        0x00,
        0x14 // inc d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0x01, "D should be 0x01");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x14_half() {
    loadRom({
        0x16, // ld d, $0F
        0x0F,
        0x14 // inc d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0x10, "D should be 0x10");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF | CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x14_zero_half() {
    loadRom({
        0x16, // ld d, $FF
        0xFF,
        0x14 // inc d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "HALF | CARRY flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec d
void InstructionsTest::test_0x15() {
    loadRom({
        0x16, // ld d, $FF
        0xFF,
        0x15 // dec d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0xFE, "D should be 0xFE");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x15_zero() {
    loadRom({
        0x16, // ld d, $01
        0x01,
        0x15 // dec d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB | CARRY, "ZERO, SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x15_half() {
    loadRom({
        0x16, // ld d, $10
        0x10,
        0x15 // dec d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0x0F, "D should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void InstructionsTest::test_0x15_half2() {
    loadRom({
        0x16, // ld d, $00
        0x00,
        0x15 // dec d
    });

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.D, 0xFF, "D should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld d, x
void InstructionsTest::test_0x16() {
    loadRom({
        0x16, // ld d, $F3
        0xF3
    });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xF3, "D should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void InstructionsTest::test_0x17() {

}

void InstructionsTest::test_0x18() {

}

void InstructionsTest::test_0x19() {

}

void InstructionsTest::test_0x1A() {

}

void InstructionsTest::test_0x1B() {

}

void InstructionsTest::test_0x1C() {

}

void InstructionsTest::test_0x1C_half() {

}

void InstructionsTest::test_0x1C_zero_half() {

}

void InstructionsTest::test_0x1D() {

}

void InstructionsTest::test_0x1D_zero() {

}

void InstructionsTest::test_0x1D_half() {

}

void InstructionsTest::test_0x1D_half2() {

}

void InstructionsTest::test_0x1E() {

}

void InstructionsTest::test_0x1F() {

}


void InstructionsTest::test_0x20() {}
void InstructionsTest::test_0x21() {}
void InstructionsTest::test_0x22() {}
void InstructionsTest::test_0x23() {}
void InstructionsTest::test_0x24() {}
void InstructionsTest::test_0x25() {}
void InstructionsTest::test_0x26() {}
void InstructionsTest::test_0x27() {}
void InstructionsTest::test_0x28() {}
void InstructionsTest::test_0x29() {}
void InstructionsTest::test_0x2A() {}
void InstructionsTest::test_0x2B() {}
void InstructionsTest::test_0x2C() {}
void InstructionsTest::test_0x2D() {}
void InstructionsTest::test_0x2E() {}
void InstructionsTest::test_0x2F() {}

void InstructionsTest::test_0x30() {}
void InstructionsTest::test_0x31() {}
void InstructionsTest::test_0x32() {}
void InstructionsTest::test_0x33() {}
void InstructionsTest::test_0x34() {}
void InstructionsTest::test_0x35() {}
void InstructionsTest::test_0x36() {}
void InstructionsTest::test_0x37() {}
void InstructionsTest::test_0x38() {}
void InstructionsTest::test_0x39() {}
void InstructionsTest::test_0x3A() {}
void InstructionsTest::test_0x3B() {}
void InstructionsTest::test_0x3C() {}
void InstructionsTest::test_0x3D() {}
void InstructionsTest::test_0x3E() {}
void InstructionsTest::test_0x3F() {}
