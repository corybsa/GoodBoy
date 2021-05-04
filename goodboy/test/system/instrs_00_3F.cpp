#include "includes/instrs_00_3F.h"

Instrs_00_3F::Instrs_00_3F(GameBoy* gameBoy) {
    gb = gameBoy;
    rom = nullptr;

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
    Test::addTest([this]() -> void { test_0x07_carry_set(); });
    Test::addTest([this]() -> void { test_0x07_carry_reset(); });
    Test::addTest([this]() -> void { test_0x08(); });
    Test::addTest([this]() -> void { test_0x09_half(); });
    Test::addTest([this]() -> void { test_0x09_carry(); });
    Test::addTest([this]() -> void { test_0x09_half_carry(); });
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
    Test::addTest([this]() -> void { test_0x0F_carry_set(); });
    Test::addTest([this]() -> void { test_0x0F_carry_reset(); });

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
    Test::addTest([this]() -> void { test_0x17_carry_set(); });
    Test::addTest([this]() -> void { test_0x17_carry_reset(); });
    Test::addTest([this]() -> void { test_0x18(); });
    Test::addTest([this]() -> void { test_0x18_backwards(); });
    Test::addTest([this]() -> void { test_0x19_half(); });
    Test::addTest([this]() -> void { test_0x19_carry(); });
    Test::addTest([this]() -> void { test_0x19_half_carry(); });
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
    Test::addTest([this]() -> void { test_0x1F_with_carry(); });

    Test::addTest([this]() -> void { test_0x20(); });
    Test::addTest([this]() -> void { test_0x20_backwards(); });
    Test::addTest([this]() -> void { test_0x20_no_jump(); });
    Test::addTest([this]() -> void { test_0x21(); });
    Test::addTest([this]() -> void { test_0x22(); });
    Test::addTest([this]() -> void { test_0x23(); });
    Test::addTest([this]() -> void { test_0x24(); });
    Test::addTest([this]() -> void { test_0x24_half(); });
    Test::addTest([this]() -> void { test_0x24_zero_half(); });
    Test::addTest([this]() -> void { test_0x25(); });
    Test::addTest([this]() -> void { test_0x25_zero_sub(); });
    Test::addTest([this]() -> void { test_0x25_sub_half(); });
    Test::addTest([this]() -> void { test_0x25_sub_half2(); });
    Test::addTest([this]() -> void { test_0x26(); });
    Test::addTest([this]() -> void { test_0x27(); });
    Test::addTest([this]() -> void { test_0x27_big_number(); });
    Test::addTest([this]() -> void { test_0x27_after_sub(); });
    Test::addTest([this]() -> void { test_0x27_after_sub_carry(); });
    Test::addTest([this]() -> void { test_0x28(); });
    Test::addTest([this]() -> void { test_0x28_backwards(); });
    Test::addTest([this]() -> void { test_0x28_no_jump(); });
    Test::addTest([this]() -> void { test_0x29_half(); });
    Test::addTest([this]() -> void { test_0x29_carry(); });
    Test::addTest([this]() -> void { test_0x29_half_carry(); });
    Test::addTest([this]() -> void { test_0x2A(); });
    Test::addTest([this]() -> void { test_0x2B(); });
    Test::addTest([this]() -> void { test_0x2C(); });
    Test::addTest([this]() -> void { test_0x2C_half(); });
    Test::addTest([this]() -> void { test_0x2C_zero_half(); });
    Test::addTest([this]() -> void { test_0x2D(); });
    Test::addTest([this]() -> void { test_0x2D_zero_sub(); });
    Test::addTest([this]() -> void { test_0x2D_sub_half(); });
    Test::addTest([this]() -> void { test_0x2D_sub_half2(); });
    Test::addTest([this]() -> void { test_0x2E(); });
    Test::addTest([this]() -> void { test_0x2F(); });

    Test::addTest([this]() -> void { test_0x30(); });
    Test::addTest([this]() -> void { test_0x30_backwards(); });
    Test::addTest([this]() -> void { test_0x30_no_jump(); });
    Test::addTest([this]() -> void { test_0x31(); });
    Test::addTest([this]() -> void { test_0x32(); });
    Test::addTest([this]() -> void { test_0x33(); });
    Test::addTest([this]() -> void { test_0x34(); });
    Test::addTest([this]() -> void { test_0x34_half(); });
    Test::addTest([this]() -> void { test_0x34_zero_half(); });
    Test::addTest([this]() -> void { test_0x35(); });
    Test::addTest([this]() -> void { test_0x35_zero_sub(); });
    Test::addTest([this]() -> void { test_0x35_sub_half(); });
    Test::addTest([this]() -> void { test_0x35_sub_half2(); });
    Test::addTest([this]() -> void { test_0x36(); });
    Test::addTest([this]() -> void { test_0x37(); });
    Test::addTest([this]() -> void { test_0x38(); });
    Test::addTest([this]() -> void { test_0x38_backwards(); });
    Test::addTest([this]() -> void { test_0x38_no_jump(); });
    Test::addTest([this]() -> void { test_0x39_half(); });
    Test::addTest([this]() -> void { test_0x39_carry(); });
    Test::addTest([this]() -> void { test_0x39_half_carry(); });
    Test::addTest([this]() -> void { test_0x3A(); });
    Test::addTest([this]() -> void { test_0x3B(); });
    Test::addTest([this]() -> void { test_0x3C(); });
    Test::addTest([this]() -> void { test_0x3C_half(); });
    Test::addTest([this]() -> void { test_0x3C_zero_half(); });
    Test::addTest([this]() -> void { test_0x3D(); });
    Test::addTest([this]() -> void { test_0x3D_zero_sub(); });
    Test::addTest([this]() -> void { test_0x3D_sub_half(); });
    Test::addTest([this]() -> void { test_0x3D_sub_half2(); });
    Test::addTest([this]() -> void { test_0x3E(); });
    Test::addTest([this]() -> void { test_0x3F_set(); });
    Test::addTest([this]() -> void { test_0x3F_reset(); });
}

void Instrs_00_3F::beforeAll() {
    rom = new byte[0x800000];
    testResults << std::endl << "Instructions 0x00 through 0x3F running...";
}

void Instrs_00_3F::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_00_3F::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_00_3F::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region r0x00_0x0F

// nop
void Instrs_00_3F::test_0x00() {
    loadRom({
                0x00 // nop
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld bc, xx
void Instrs_00_3F::test_0x01() {
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
void Instrs_00_3F::test_0x02() {
    loadRom({
                0x02 // ld (bc), a
            });

    gb->cpu->registers.A = 0x42;
    gb->cpu->registers.BC = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc bc
void Instrs_00_3F::test_0x03() {
    loadRom({
                0x03 // inc bc
            });

    gb->cpu->registers.BC = 0x0001;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.BC, 0x0002, "BC should be 0x0002");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc b
void Instrs_00_3F::test_0x04() {
    loadRom({
                0x04 // inc b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x01, "B should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x04_half() {
    loadRom({
                0x04 // inc b
            });

    gb->cpu->registers.B = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x10, "B should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x04_zero_half() {
    loadRom({
                0x04 // inc b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec b
void Instrs_00_3F::test_0x05() {
    loadRom({
                0x05 // dec b
            });

    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0xFE, "B should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x05_zero_sub() {
    loadRom({
                0x05 // dec b
            });

    gb->cpu->registers.B = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x00, "B should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x05_sub_half() {
    loadRom({
                0x05 // dec b
            });

    gb->cpu->registers.B = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0x0F, "B should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x05_sub_half2() {
    loadRom({
                0x05 // dec b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.B, 0xFF, "B should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld b, x
void Instrs_00_3F::test_0x06() {
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
void Instrs_00_3F::test_0x07_carry_set() {
    loadRom({
                0x07 // rlca
            });

    gb->cpu->registers.A = 0x95;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2B, "A should be 0x2B");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x07_carry_reset() {
    loadRom({
                0x07 // rlca
            });

    gb->cpu->registers.A = 0x75;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEA, "A should be 0xEA");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld (xx), sp
void Instrs_00_3F::test_0x08() {
    loadRom({
                0x08, // ld ($C000), sp
                0x00,
                0xC0
            });

    gb->cpu->registers.SP = 0xC0DE;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->memory->readByte(0xC000), 0xDE, "the value in memory at 0xC000 should be 0xDE");
    expect(gb->memory->readByte(0xC001), 0xC0, "the value in memory at 0xC001 should be 0xC0");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

// add hl, bc
void Instrs_00_3F::test_0x09_half() {
    loadRom({
                0x09 // add hl, bc
            });

    gb->cpu->registers.BC = 0x0FFF;
    gb->cpu->registers.HL = 0x0100;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x10FF, "HL should be 0x10FF");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x09_carry() {
    loadRom({
                0x09 // add hl, bc
            });

    gb->cpu->registers.BC = 0xFF00;
    gb->cpu->registers.HL = 0x1000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x0F00, "HL should be 0x0F00");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x09_half_carry() {
    loadRom({
                0x09 // add hl, bc
            });

    gb->cpu->registers.BC = 0xFFFF;
    gb->cpu->registers.HL = 0x1100;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x10FF, "HL should be 0x10FF");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, (bc)
void Instrs_00_3F::test_0x0A() {
    loadRom({
                0x0A // ld a, (bc)
            });

    gb->cpu->registers.BC = 0xC000;
    gb->memory->writeByte(0xC000, 0x12);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.BC, 0xC000, "BC should be 0xC000");
    expect(gb->cpu->registers.A, 0x12, "A should be 0x12");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// dec bc
void Instrs_00_3F::test_0x0B() {
    loadRom({
                0x0B // dec bc
            });

    gb->cpu->registers.BC = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.BC, 0xBFFF, "BC should be 0xBFFF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc c
void Instrs_00_3F::test_0x0C() {
    loadRom({
                0x0C // inc c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x01, "C should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x0C_half() {
    loadRom({
                0x0C // inc c
            });

    gb->cpu->registers.C = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x10, "C should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x0C_zero_half() {
    loadRom({
                0x0C // inc c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec c
void Instrs_00_3F::test_0x0D() {
    loadRom({
                0x0D // dec c
            });

    gb->cpu->registers.C = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0xFE, "C should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x0D_zero() {
    loadRom({
                0x0D // dec c
            });

    gb->cpu->registers.C = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x00, "C should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x0D_half() {
    loadRom({
                0x0D // dec c
            });

    gb->cpu->registers.C = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0x0F, "C should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x0D_half2() {
    loadRom({
                0x0D // dec c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.C, 0xFF, "C should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld c, x
void Instrs_00_3F::test_0x0E() {
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
void Instrs_00_3F::test_0x0F_carry_set() {
    loadRom({
                0x0F // rrca
            });

    gb->cpu->registers.A = 0x3B;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x9D, "A should be 0x9D");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x0F_carry_reset() {
    loadRom({
                0x0F // rrca
            });

    gb->cpu->registers.A = 0xAA;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x55, "A should be 0x55");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x10_0x1F

// stop
// TODO: how to test this?
void Instrs_00_3F::test_0x10() {
    loadRom({
                0x10, // stop
                0x00
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld de, xx
void Instrs_00_3F::test_0x11() {
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
void Instrs_00_3F::test_0x12() {
    loadRom({
                0x12 // ld (de), a
            });

    gb->cpu->registers.A = 0x42;
    gb->cpu->registers.DE = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x42, "the value in memory at 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc de
void Instrs_00_3F::test_0x13() {
    loadRom({
                0x13 // inc de
            });

    gb->cpu->registers.DE = 0x0001;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.DE, 0x0002, "DE should be 0x0002");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc d
void Instrs_00_3F::test_0x14() {
    loadRom({
                0x14 // inc d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x01, "D should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x14_half() {
    loadRom({
                0x14 // inc d
            });

    gb->cpu->registers.D = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x10, "D should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x14_zero_half() {
    loadRom({
                0x14 // inc d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec d
void Instrs_00_3F::test_0x15() {
    loadRom({
                0x15 // dec d
            });

    gb->cpu->registers.D = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0xFE, "D should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x15_zero() {
    loadRom({
                0x15 // dec d
            });

    gb->cpu->registers.D = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x00, "D should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x15_half() {
    loadRom({
                0x15 // dec d
            });

    gb->cpu->registers.D = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0x0F, "D should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x15_half2() {
    loadRom({
                0x15 // dec d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.D, 0xFF, "D should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld d, x
void Instrs_00_3F::test_0x16() {
    loadRom({
                0x16, // ld d, $F3
                0xF3
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0xF3, "D should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rla
void Instrs_00_3F::test_0x17_carry_set() {
    loadRom({
                0x17 // rla
            });

    gb->cpu->registers.A = 0x95;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x2A, "A should be 0x2A");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x17_carry_reset() {
    loadRom({
                0x17 // rla
            });

    gb->cpu->registers.A = 0x75;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xEA, "A should be 0xEA");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// jr x
void Instrs_00_3F::test_0x18() {
    loadRom({
                0x18, // jr $05
                0x05
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x18_backwards() {
    loadRom({
                0x18, // jr $05
                0x05,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x18, // jr $-05
                0xFB
            });

    gb->cpu->tick();
    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");

    gb->cpu->tick();
    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

// add hl, de
void Instrs_00_3F::test_0x19_half() {
    loadRom({
                0x19 // add hl, de
            });

    gb->cpu->registers.DE = 0x0FFF;
    gb->cpu->registers.HL = 0x0100;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x10FF, "HL should be 0x10FF");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x19_carry() {
    loadRom({
                0x19 // add hl, de
            });

    gb->cpu->registers.DE = 0xFF00;
    gb->cpu->registers.HL = 0x1000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x0F00, "HL should be 0x0F00");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x19_half_carry() {
    loadRom({
                0x19 // add hl, de
            });

    gb->cpu->registers.DE = 0xFFFF;
    gb->cpu->registers.HL = 0x1100;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x10FF, "HL should be 0x10FF");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, (de)
void Instrs_00_3F::test_0x1A() {
    loadRom({
                0x1A // ld a, (de)
            });

    gb->cpu->registers.DE = 0xC000;
    gb->memory->writeByte(0xC000, 0xFF);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFF, "A should be 0xFF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// dec de
void Instrs_00_3F::test_0x1B() {
    loadRom({
                0x1B // dec de
            });

    gb->cpu->registers.DE = 0x0605;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.DE, 0x0604, "DE should be 0x0604");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc e
void Instrs_00_3F::test_0x1C() {
    loadRom({
                0x1C // inc e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x01, "E should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x1C_half() {
    loadRom({
                0x1C // inc e
            });

    gb->cpu->registers.E = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x10, "E should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x1C_zero_half() {
    loadRom({
                0x1C // inc e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec e
void Instrs_00_3F::test_0x1D() {
    loadRom({
                0x1D // dec e
            });

    gb->cpu->registers.E = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0xFE, "E should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x1D_zero() {
    loadRom({
                0x1D // dec e
            });

    gb->cpu->registers.E = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x00, "E should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x1D_half() {
    loadRom({
                0x1D // dec e
            });

    gb->cpu->registers.E = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0x0F, "E should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x1D_half2() {
    loadRom({
                0x1D // dec e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.E, 0xFF, "E should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld e, x
void Instrs_00_3F::test_0x1E() {
    loadRom({
                0x1E, // ld e, $CD
                0xCD
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0xCD, "E should be 0xCD");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rra
void Instrs_00_3F::test_0x1F() {
    loadRom({
                0x1F // rra
            });

    gb->cpu->registers.A = 0x81;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x40, "A should be 0x40");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x1F_with_carry() {
    loadRom({
                0x1F // rra
            });

    gb->cpu->registers.A = 0x81;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xC0, "A should be 0xC0");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x20_0x2F

// jr nz x
void Instrs_00_3F::test_0x20() {
    loadRom({
                0x20, // jr nz, $05
                0x05
            });

    gb->cpu->resetFlags(ZERO);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x20_backwards() {
    loadRom({
                0x18, // jr $05
                0x05,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x20, // jr nz, $-05
                0xFB
            });

    gb->cpu->resetFlags(ZERO);

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_00_3F::test_0x20_no_jump() {
    loadRom({
                0x20, // jr nz, $05
                0x05
            });

    gb->cpu->setFlags(ZERO);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld hl, xx
void Instrs_00_3F::test_0x21() {
    loadRom({
                0x21, // ld hl, $DEAD
                0xAD,
                0xDE
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.HL, 0xDEAD, "HL should be 0xDEAD");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (hl+), a
void Instrs_00_3F::test_0x22() {
    loadRom({
                0x22 // ld (hl+), a
            });

    gb->cpu->registers.A = 0x56;
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x56, "the value in memory at 0xC000 should be 0x56");
    expect(gb->cpu->registers.HL, 0xC001, "HL should be 0xC001");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc hl
void Instrs_00_3F::test_0x23() {
    loadRom({
                0x23 // inc hl
            });

    gb->cpu->registers.HL = 0x0001;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x0002, "HL should be 0x0002");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc h
void Instrs_00_3F::test_0x24() {
    loadRom({
                0x24 // inc h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x01, "H should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x24_half() {
    loadRom({
                0x24 // inc h
            });

    gb->cpu->registers.H = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x10, "H should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x24_zero_half() {
    loadRom({
                0x24 // inc h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec h
void Instrs_00_3F::test_0x25() {
    loadRom({
                0x25 // dec h
            });

    gb->cpu->registers.H = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0xFE, "H should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x25_zero_sub() {
    loadRom({
                0x25 // dec h
            });

    gb->cpu->registers.H = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x00, "H should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x25_sub_half() {
    loadRom({
                0x25 // dec h
            });

    gb->cpu->registers.H = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0x0F, "H should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x25_sub_half2() {
    loadRom({
                0x25 // dec h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.H, 0xFF, "H should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld h, x
void Instrs_00_3F::test_0x26() {
    loadRom({
                0x26, // ld h, $F3
                0xF3
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0xF3, "H should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// daa
void Instrs_00_3F::test_0x27() {
    loadRom({
                0x27 // daa
            });

    gb->cpu->registers.A = 0x45 + 0x38; // 0x7D

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x83, "A should be 0x83");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x27_big_number() {
    loadRom({
                0x27 // daa
            });

    gb->cpu->registers.A = 0x80 + 0x21; // 0xA1
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x01, "A should be 0x01");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x27_after_sub() {
    loadRom({
                0x27 // daa
            });

    // simulating the following code:
    // ld a, $45
    // ld b, $38
    // sub b
    gb->cpu->registers.A = 0x45 - 0x38; // 0x0D
    gb->cpu->setFlags(SUB | HALF);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x07, "A should be 0x07");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x27_after_sub_carry() {
    loadRom({
                0x27 // daa
            });

    // simulating the following code:
    // ld a, $38
    // ld b, $45
    // sub b
    gb->cpu->registers.A = 0x38 - 0x45; // 0xF3
    gb->cpu->setFlags(SUB | CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x93, "A should be 0x93");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// jr z x
void Instrs_00_3F::test_0x28() {
    loadRom({
                0x28, // jr z, $05
                0x05
            });

    gb->cpu->setFlags(ZERO);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x28_backwards() {
    loadRom({
                0x18, // jr $05
                0x05,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x28, // jr z, $-05
                0xFB
            });

    gb->cpu->setFlags(ZERO);

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_00_3F::test_0x28_no_jump() {
    loadRom({
                0x28, // jr z, $05
                0x05
            });

    gb->cpu->resetFlags(ZERO);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// add hl, hl
void Instrs_00_3F::test_0x29_half() {
    loadRom({
                0x29 // add hl, hl
            });

    gb->cpu->registers.HL = 0x0F00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x1E00, "HL should be 0x1E00");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x29_carry() {
    loadRom({
                0x29 // add hl, hl
            });

    gb->cpu->registers.HL = 0xF000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0xE000, "HL should be 0xE000");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x29_half_carry() {
    loadRom({
                0x29 // add hl, hl
            });

    gb->cpu->registers.HL = 0xFF00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0xFE00, "HL should be 0xFE00");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, (hl+)
void Instrs_00_3F::test_0x2A() {
    loadRom({
                0x2A // ld a, (hl+)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x56);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x56, "A should be 0x56");
    expect(gb->cpu->registers.HL, 0xC001, "HL should be 0xC001");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// dec hl
void Instrs_00_3F::test_0x2B() {
    loadRom({
                0x2B // dec hl
            });

    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0xBFFF, "HL should be 0xBFFF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc l
void Instrs_00_3F::test_0x2C() {
    loadRom({
                0x2C // inc l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x01, "L should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x2C_half() {
    loadRom({
                0x2C // inc l
            });

    gb->cpu->registers.L = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x10, "L should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x2C_zero_half() {
    loadRom({
                0x2C // inc l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec l
void Instrs_00_3F::test_0x2D() {
    loadRom({
                0x2D // dec l
            });

    gb->cpu->registers.L = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0xFE, "L should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x2D_zero_sub() {
    loadRom({
                0x2D // dec l
            });

    gb->cpu->registers.L = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x00, "L should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x2D_sub_half() {
    loadRom({
                0x2D // dec l
            });

    gb->cpu->registers.L = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0x0F, "L should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x2D_sub_half2() {
    loadRom({
                0x2D // dec l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.L, 0xFF, "L should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld l, x
void Instrs_00_3F::test_0x2E() {
    loadRom({
                0x2E, // ld l, $F3
                0xF3
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0xF3, "L should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// cpl
void Instrs_00_3F::test_0x2F() {
    loadRom({
                0x2F // cpl
            });

    gb->cpu->registers.A = 0x35;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xCA, "A should be 0xCA");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion

#pragma region r0x00_0x0F

// jr nc x
void Instrs_00_3F::test_0x30() {
    loadRom({
                0x30, // jr nc, $05
                0x05
            });

    gb->cpu->resetFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x30_backwards() {
    loadRom({
                0x18, // jr $05
                0x05,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x30, // jr nc, $-05
                0xFB
            });

    gb->cpu->resetFlags(CARRY);

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_00_3F::test_0x30_no_jump() {
    loadRom({
                0x30, // jr nz, $05
                0x05
            });

    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld sp, xx
void Instrs_00_3F::test_0x31() {
    loadRom({
                0x31, // ld sp, $FFF0
                0xF0,
                0xFF
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFF0, "SP should be 0xFFF0");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (hl-), a
void Instrs_00_3F::test_0x32() {
    loadRom({
                0x32 // ld (hl-), a
            });

    gb->cpu->registers.A = 0x42;
    gb->cpu->registers.HL = 0xC001;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0xC000, "HL should be 0xC000");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc sp
void Instrs_00_3F::test_0x33() {
    loadRom({
                0x33 // inc sp
            });

    gb->cpu->registers.SP = 0x0001;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.SP, 0x0002, "SP should be 0x0002");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc (hl)
void Instrs_00_3F::test_0x34() {
    loadRom({
                0x34 // inc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x00);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x01, "address 0xC000 should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x34_half() {
    loadRom({
                0x34 // inc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x0F);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x10, "address 0xC000 should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x34_zero_half() {
    loadRom({
                0x34 // inc (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0xFF);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x00, "address 0xC000 should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// dec (hl)
void Instrs_00_3F::test_0x35() {
    loadRom({
                0x35 // dec (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0xFF);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0xFE, "address 0xC000 should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x35_zero_sub() {
    loadRom({
                0x35 // dec (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x01);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x00, "address 0xC000 should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x35_sub_half() {
    loadRom({
                0x35 // dec (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x10);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0x0F, "address 0xC000 should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x35_sub_half2() {
    loadRom({
                0x35 // dec (hl)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x00);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xC000), 0xFF, "address 0xC000 should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (hl), x
void Instrs_00_3F::test_0x36() {
    loadRom({
                0x36, // ld (hl), $F3
                0xF3
            });

    gb->cpu->registers.HL = 0xC000;
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0xF3, "address 0xC000 should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// scf
void Instrs_00_3F::test_0x37() {
    loadRom({
                0x37 // scf
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// jr c x
void Instrs_00_3F::test_0x38() {
    loadRom({
                0x38, // jr c, $05
                0x05
            });

    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x107, "PC should be 0x107");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

void Instrs_00_3F::test_0x38_backwards() {
    loadRom({
                0x18, // jr $05
                0x05,
                0x00,
                0x00,
                0x00,
                0x00,
                0x00,
                0x38, // jr c, $-05
                0xFB
            });

    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_00_3F::test_0x38_no_jump() {
    loadRom({
                0x38, // jr c, $05
                0x05
            });

    gb->cpu->resetFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// add hl, sp
void Instrs_00_3F::test_0x39_half() {
    loadRom({
                0x39 // add hl, sp
            });

    gb->cpu->registers.SP = 0x0FFF;
    gb->cpu->registers.HL = 0x0100;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x10FF, "HL should be 0x10FF");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x39_carry() {
    loadRom({
                0x39 // add hl, sp
            });

    gb->cpu->registers.SP = 0xFF00;
    gb->cpu->registers.HL = 0x1000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x0F00, "HL should be 0x0F00");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_00_3F::test_0x39_half_carry() {
    loadRom({
                0x39 // add hl, sp
            });

    gb->cpu->registers.SP = 0xFFFF;
    gb->cpu->registers.HL = 0x1100;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0x10FF, "HL should be 0x10FF");
    expect(gb->cpu->registers.F, HALF | CARRY, "HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, (hl-)
void Instrs_00_3F::test_0x3A() {
    loadRom({
                0x3A // ld a, (hl-)
            });

    gb->cpu->registers.HL = 0xC000;
    gb->memory->writeByte(0xC000, 0x56);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x56, "A should be 0x56");
    expect(gb->cpu->registers.HL, 0xBFFF, "HL should be 0xBFFF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// dec sp
void Instrs_00_3F::test_0x3B() {
    loadRom({
                0x3B // dec sp
            });

    gb->cpu->registers.SP = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.SP, 0xBFFF, "SP should be 0xBFFF");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// inc a
void Instrs_00_3F::test_0x3C() {
    loadRom({
                0x3C // inc a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x01, "A should be 0x01");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x3C_half() {
    loadRom({
                0x3C // inc a
            });

    gb->cpu->registers.A = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x3C_zero_half() {
    loadRom({
                0x3C // inc a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// dec a
void Instrs_00_3F::test_0x3D() {
    loadRom({
                0x3D // dec a
            });

    gb->cpu->registers.A = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFE, "A should be 0xFE");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x3D_zero_sub() {
    loadRom({
                0x3D // dec a
            });

    gb->cpu->registers.A = 0x01;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x3D_sub_half() {
    loadRom({
                0x3D // dec a
            });

    gb->cpu->registers.A = 0x10;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x0F, "A should be 0x0F");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x3D_sub_half2() {
    loadRom({
                0x3D // dec a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0xFF, "A should be 0xFF");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld a, x
void Instrs_00_3F::test_0x3E() {
    loadRom({
                0x3E, // ld a, $F3
                0xF3
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xF3, "A should be 0xF3");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ccf
void Instrs_00_3F::test_0x3F_set() {
    loadRom({
                0x3F // ccf
            });

    gb->cpu->resetFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, CARRY, "CARRY flag should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

void Instrs_00_3F::test_0x3F_reset() {
    loadRom({
                0x3F // ccf
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

#pragma endregion