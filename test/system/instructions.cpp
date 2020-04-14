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
    Test::addTest([this]() -> void { test_0x05(); });
    Test::addTest([this]() -> void { test_0x06(); });
    Test::addTest([this]() -> void { test_0x07(); });
    Test::addTest([this]() -> void { test_0x08(); });
    Test::addTest([this]() -> void { test_0x09(); });
    Test::addTest([this]() -> void { test_0x0A(); });
    Test::addTest([this]() -> void { test_0x0B(); });
    Test::addTest([this]() -> void { test_0x0C(); });
    Test::addTest([this]() -> void { test_0x0D(); });
    Test::addTest([this]() -> void { test_0x0E(); });
    Test::addTest([this]() -> void { test_0x0F(); });
    Test::addTest([this]() -> void { test_0x10(); });
    Test::addTest([this]() -> void { test_0x11(); });
    Test::addTest([this]() -> void { test_0x12(); });
    Test::addTest([this]() -> void { test_0x13(); });
    Test::addTest([this]() -> void { test_0x14(); });
    Test::addTest([this]() -> void { test_0x15(); });
    Test::addTest([this]() -> void { test_0x16(); });
    Test::addTest([this]() -> void { test_0x17(); });
    Test::addTest([this]() -> void { test_0x18(); });
    Test::addTest([this]() -> void { test_0x19(); });
    Test::addTest([this]() -> void { test_0x1A(); });
    Test::addTest([this]() -> void { test_0x1B(); });
    Test::addTest([this]() -> void { test_0x1C(); });
    Test::addTest([this]() -> void { test_0x1D(); });
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
    Test::addTest([this]() -> void { test_0x77(); });
    Test::addTest([this]() -> void { test_0x78(); });
    Test::addTest([this]() -> void { test_0x79(); });
    Test::addTest([this]() -> void { test_0x7A(); });
    Test::addTest([this]() -> void { test_0x7B(); });
    Test::addTest([this]() -> void { test_0x7C(); });
    Test::addTest([this]() -> void { test_0x7D(); });
    Test::addTest([this]() -> void { test_0x7E(); });
    Test::addTest([this]() -> void { test_0x7F(); });
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
    Test::addTest([this]() -> void { test_0x90(); });
    Test::addTest([this]() -> void { test_0x91(); });
    Test::addTest([this]() -> void { test_0x92(); });
    Test::addTest([this]() -> void { test_0x93(); });
    Test::addTest([this]() -> void { test_0x94(); });
    Test::addTest([this]() -> void { test_0x95(); });
    Test::addTest([this]() -> void { test_0x96(); });
    Test::addTest([this]() -> void { test_0x97(); });
    Test::addTest([this]() -> void { test_0x98(); });
    Test::addTest([this]() -> void { test_0x99(); });
    Test::addTest([this]() -> void { test_0x9A(); });
    Test::addTest([this]() -> void { test_0x9B(); });
    Test::addTest([this]() -> void { test_0x9C(); });
    Test::addTest([this]() -> void { test_0x9D(); });
    Test::addTest([this]() -> void { test_0x9E(); });
    Test::addTest([this]() -> void { test_0x9F(); });
    Test::addTest([this]() -> void { test_0xA0(); });
    Test::addTest([this]() -> void { test_0xA1(); });
    Test::addTest([this]() -> void { test_0xA2(); });
    Test::addTest([this]() -> void { test_0xA3(); });
    Test::addTest([this]() -> void { test_0xA4(); });
    Test::addTest([this]() -> void { test_0xA5(); });
    Test::addTest([this]() -> void { test_0xA6(); });
    Test::addTest([this]() -> void { test_0xA7(); });
    Test::addTest([this]() -> void { test_0xA8(); });
    Test::addTest([this]() -> void { test_0xA9(); });
    Test::addTest([this]() -> void { test_0xAA(); });
    Test::addTest([this]() -> void { test_0xAB(); });
    Test::addTest([this]() -> void { test_0xAC(); });
    Test::addTest([this]() -> void { test_0xAD(); });
    Test::addTest([this]() -> void { test_0xAE(); });
    Test::addTest([this]() -> void { test_0xAF(); });
    Test::addTest([this]() -> void { test_0xB0(); });
    Test::addTest([this]() -> void { test_0xB1(); });
    Test::addTest([this]() -> void { test_0xB2(); });
    Test::addTest([this]() -> void { test_0xB3(); });
    Test::addTest([this]() -> void { test_0xB4(); });
    Test::addTest([this]() -> void { test_0xB5(); });
    Test::addTest([this]() -> void { test_0xB6(); });
    Test::addTest([this]() -> void { test_0xB7(); });
    Test::addTest([this]() -> void { test_0xB8(); });
    Test::addTest([this]() -> void { test_0xB9(); });
    Test::addTest([this]() -> void { test_0xBA(); });
    Test::addTest([this]() -> void { test_0xBB(); });
    Test::addTest([this]() -> void { test_0xBC(); });
    Test::addTest([this]() -> void { test_0xBD(); });
    Test::addTest([this]() -> void { test_0xBE(); });
    Test::addTest([this]() -> void { test_0xBF(); });
    Test::addTest([this]() -> void { test_0xC0(); });
    Test::addTest([this]() -> void { test_0xC1(); });
    Test::addTest([this]() -> void { test_0xC2(); });
    Test::addTest([this]() -> void { test_0xC3(); });
    Test::addTest([this]() -> void { test_0xC4(); });
    Test::addTest([this]() -> void { test_0xC5(); });
    Test::addTest([this]() -> void { test_0xC6(); });
    Test::addTest([this]() -> void { test_0xC7(); });
    Test::addTest([this]() -> void { test_0xC8(); });
    Test::addTest([this]() -> void { test_0xC9(); });
    Test::addTest([this]() -> void { test_0xCA(); });
    Test::addTest([this]() -> void { test_0xCB(); });
    Test::addTest([this]() -> void { test_0xCC(); });
    Test::addTest([this]() -> void { test_0xCD(); });
    Test::addTest([this]() -> void { test_0xCE(); });
    Test::addTest([this]() -> void { test_0xCF(); });
    Test::addTest([this]() -> void { test_0xD0(); });
    Test::addTest([this]() -> void { test_0xD1(); });
    Test::addTest([this]() -> void { test_0xD2(); });
    Test::addTest([this]() -> void { test_0xD3(); });
    Test::addTest([this]() -> void { test_0xD4(); });
    Test::addTest([this]() -> void { test_0xD5(); });
    Test::addTest([this]() -> void { test_0xD6(); });
    Test::addTest([this]() -> void { test_0xD7(); });
    Test::addTest([this]() -> void { test_0xD8(); });
    Test::addTest([this]() -> void { test_0xD9(); });
    Test::addTest([this]() -> void { test_0xDA(); });
    Test::addTest([this]() -> void { test_0xDB(); });
    Test::addTest([this]() -> void { test_0xDC(); });
    Test::addTest([this]() -> void { test_0xDD(); });
    Test::addTest([this]() -> void { test_0xDE(); });
    Test::addTest([this]() -> void { test_0xDF(); });
    Test::addTest([this]() -> void { test_0xE0(); });
    Test::addTest([this]() -> void { test_0xE1(); });
    Test::addTest([this]() -> void { test_0xE2(); });
    Test::addTest([this]() -> void { test_0xE3(); });
    Test::addTest([this]() -> void { test_0xE4(); });
    Test::addTest([this]() -> void { test_0xE5(); });
    Test::addTest([this]() -> void { test_0xE6(); });
    Test::addTest([this]() -> void { test_0xE7(); });
    Test::addTest([this]() -> void { test_0xE8(); });
    Test::addTest([this]() -> void { test_0xE9(); });
    Test::addTest([this]() -> void { test_0xEA(); });
    Test::addTest([this]() -> void { test_0xEB(); });
    Test::addTest([this]() -> void { test_0xEC(); });
    Test::addTest([this]() -> void { test_0xED(); });
    Test::addTest([this]() -> void { test_0xEE(); });
    Test::addTest([this]() -> void { test_0xEF(); });
    Test::addTest([this]() -> void { test_0xF0(); });
    Test::addTest([this]() -> void { test_0xF1(); });
    Test::addTest([this]() -> void { test_0xF2(); });
    Test::addTest([this]() -> void { test_0xF3(); });
    Test::addTest([this]() -> void { test_0xF4(); });
    Test::addTest([this]() -> void { test_0xF5(); });
    Test::addTest([this]() -> void { test_0xF6(); });
    Test::addTest([this]() -> void { test_0xF7(); });
    Test::addTest([this]() -> void { test_0xF8(); });
    Test::addTest([this]() -> void { test_0xF9(); });
    Test::addTest([this]() -> void { test_0xFA(); });
    Test::addTest([this]() -> void { test_0xFB(); });
    Test::addTest([this]() -> void { test_0xFC(); });
    Test::addTest([this]() -> void { test_0xFD(); });
    Test::addTest([this]() -> void { test_0xFE(); });
    Test::addTest([this]() -> void { test_0xFF(); });
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

void InstructionsTest::test_0x06() {

}

void InstructionsTest::test_0x07() {

}

void InstructionsTest::test_0x08() {

}

void InstructionsTest::test_0x09() {

}

void InstructionsTest::test_0x0A() {

}

void InstructionsTest::test_0x0B() {

}

void InstructionsTest::test_0x0C() {

}

void InstructionsTest::test_0x0D() {

}

void InstructionsTest::test_0x0E() {

}

void InstructionsTest::test_0x0F() {

}


void InstructionsTest::test_0x10() {}
void InstructionsTest::test_0x11() {}
void InstructionsTest::test_0x12() {}
void InstructionsTest::test_0x13() {}
void InstructionsTest::test_0x14() {}
void InstructionsTest::test_0x15() {}
void InstructionsTest::test_0x16() {}
void InstructionsTest::test_0x17() {}
void InstructionsTest::test_0x18() {}
void InstructionsTest::test_0x19() {}
void InstructionsTest::test_0x1A() {}
void InstructionsTest::test_0x1B() {}
void InstructionsTest::test_0x1C() {}
void InstructionsTest::test_0x1D() {}
void InstructionsTest::test_0x1E() {}
void InstructionsTest::test_0x1F() {}

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

void InstructionsTest::test_0x40() {}
void InstructionsTest::test_0x41() {}
void InstructionsTest::test_0x42() {}
void InstructionsTest::test_0x43() {}
void InstructionsTest::test_0x44() {}
void InstructionsTest::test_0x45() {}
void InstructionsTest::test_0x46() {}
void InstructionsTest::test_0x47() {}
void InstructionsTest::test_0x48() {}
void InstructionsTest::test_0x49() {}
void InstructionsTest::test_0x4A() {}
void InstructionsTest::test_0x4B() {}
void InstructionsTest::test_0x4C() {}
void InstructionsTest::test_0x4D() {}
void InstructionsTest::test_0x4E() {}
void InstructionsTest::test_0x4F() {}

void InstructionsTest::test_0x50() {}
void InstructionsTest::test_0x51() {}
void InstructionsTest::test_0x52() {}
void InstructionsTest::test_0x53() {}
void InstructionsTest::test_0x54() {}
void InstructionsTest::test_0x55() {}
void InstructionsTest::test_0x56() {}
void InstructionsTest::test_0x57() {}
void InstructionsTest::test_0x58() {}
void InstructionsTest::test_0x59() {}
void InstructionsTest::test_0x5A() {}
void InstructionsTest::test_0x5B() {}
void InstructionsTest::test_0x5C() {}
void InstructionsTest::test_0x5D() {}
void InstructionsTest::test_0x5E() {}
void InstructionsTest::test_0x5F() {}

void InstructionsTest::test_0x60() {}
void InstructionsTest::test_0x61() {}
void InstructionsTest::test_0x62() {}
void InstructionsTest::test_0x63() {}
void InstructionsTest::test_0x64() {}
void InstructionsTest::test_0x65() {}
void InstructionsTest::test_0x66() {}
void InstructionsTest::test_0x67() {}
void InstructionsTest::test_0x68() {}
void InstructionsTest::test_0x69() {}
void InstructionsTest::test_0x6A() {}
void InstructionsTest::test_0x6B() {}
void InstructionsTest::test_0x6C() {}
void InstructionsTest::test_0x6D() {}
void InstructionsTest::test_0x6E() {}
void InstructionsTest::test_0x6F() {}

void InstructionsTest::test_0x70() {}
void InstructionsTest::test_0x71() {}
void InstructionsTest::test_0x72() {}
void InstructionsTest::test_0x73() {}
void InstructionsTest::test_0x74() {}
void InstructionsTest::test_0x75() {}
void InstructionsTest::test_0x76() {}
void InstructionsTest::test_0x77() {}
void InstructionsTest::test_0x78() {}
void InstructionsTest::test_0x79() {}
void InstructionsTest::test_0x7A() {}
void InstructionsTest::test_0x7B() {}
void InstructionsTest::test_0x7C() {}
void InstructionsTest::test_0x7D() {}
void InstructionsTest::test_0x7E() {}
void InstructionsTest::test_0x7F() {}

void InstructionsTest::test_0x80() {}
void InstructionsTest::test_0x81() {}
void InstructionsTest::test_0x82() {}
void InstructionsTest::test_0x83() {}
void InstructionsTest::test_0x84() {}
void InstructionsTest::test_0x85() {}
void InstructionsTest::test_0x86() {}
void InstructionsTest::test_0x87() {}
void InstructionsTest::test_0x88() {}
void InstructionsTest::test_0x89() {}
void InstructionsTest::test_0x8A() {}
void InstructionsTest::test_0x8B() {}
void InstructionsTest::test_0x8C() {}
void InstructionsTest::test_0x8D() {}
void InstructionsTest::test_0x8E() {}
void InstructionsTest::test_0x8F() {}

void InstructionsTest::test_0x90() {}
void InstructionsTest::test_0x91() {}
void InstructionsTest::test_0x92() {}
void InstructionsTest::test_0x93() {}
void InstructionsTest::test_0x94() {}
void InstructionsTest::test_0x95() {}
void InstructionsTest::test_0x96() {}
void InstructionsTest::test_0x97() {}
void InstructionsTest::test_0x98() {}
void InstructionsTest::test_0x99() {}
void InstructionsTest::test_0x9A() {}
void InstructionsTest::test_0x9B() {}
void InstructionsTest::test_0x9C() {}
void InstructionsTest::test_0x9D() {}
void InstructionsTest::test_0x9E() {}
void InstructionsTest::test_0x9F() {}

void InstructionsTest::test_0xA0() {}
void InstructionsTest::test_0xA1() {}
void InstructionsTest::test_0xA2() {}
void InstructionsTest::test_0xA3() {}
void InstructionsTest::test_0xA4() {}
void InstructionsTest::test_0xA5() {}
void InstructionsTest::test_0xA6() {}
void InstructionsTest::test_0xA7() {}
void InstructionsTest::test_0xA8() {}
void InstructionsTest::test_0xA9() {}
void InstructionsTest::test_0xAA() {}
void InstructionsTest::test_0xAB() {}
void InstructionsTest::test_0xAC() {}
void InstructionsTest::test_0xAD() {}
void InstructionsTest::test_0xAE() {}
void InstructionsTest::test_0xAF() {}

void InstructionsTest::test_0xB0() {}
void InstructionsTest::test_0xB1() {}
void InstructionsTest::test_0xB2() {}
void InstructionsTest::test_0xB3() {}
void InstructionsTest::test_0xB4() {}
void InstructionsTest::test_0xB5() {}
void InstructionsTest::test_0xB6() {}
void InstructionsTest::test_0xB7() {}
void InstructionsTest::test_0xB8() {}
void InstructionsTest::test_0xB9() {}
void InstructionsTest::test_0xBA() {}
void InstructionsTest::test_0xBB() {}
void InstructionsTest::test_0xBC() {}
void InstructionsTest::test_0xBD() {}
void InstructionsTest::test_0xBE() {}
void InstructionsTest::test_0xBF() {}

void InstructionsTest::test_0xC0() {}
void InstructionsTest::test_0xC1() {}
void InstructionsTest::test_0xC2() {}
void InstructionsTest::test_0xC3() {}
void InstructionsTest::test_0xC4() {}
void InstructionsTest::test_0xC5() {}
void InstructionsTest::test_0xC6() {}
void InstructionsTest::test_0xC7() {}
void InstructionsTest::test_0xC8() {}
void InstructionsTest::test_0xC9() {}
void InstructionsTest::test_0xCA() {}
void InstructionsTest::test_0xCB() {}
void InstructionsTest::test_0xCC() {}
void InstructionsTest::test_0xCD() {}
void InstructionsTest::test_0xCE() {}
void InstructionsTest::test_0xCF() {}

void InstructionsTest::test_0xD0() {}
void InstructionsTest::test_0xD1() {}
void InstructionsTest::test_0xD2() {}
void InstructionsTest::test_0xD3() {}
void InstructionsTest::test_0xD4() {}
void InstructionsTest::test_0xD5() {}
void InstructionsTest::test_0xD6() {}
void InstructionsTest::test_0xD7() {}
void InstructionsTest::test_0xD8() {}
void InstructionsTest::test_0xD9() {}
void InstructionsTest::test_0xDA() {}
void InstructionsTest::test_0xDB() {}
void InstructionsTest::test_0xDC() {}
void InstructionsTest::test_0xDD() {}
void InstructionsTest::test_0xDE() {}
void InstructionsTest::test_0xDF() {}

void InstructionsTest::test_0xE0() {}
void InstructionsTest::test_0xE1() {}
void InstructionsTest::test_0xE2() {}
void InstructionsTest::test_0xE3() {}
void InstructionsTest::test_0xE4() {}
void InstructionsTest::test_0xE5() {}
void InstructionsTest::test_0xE6() {}
void InstructionsTest::test_0xE7() {}
void InstructionsTest::test_0xE8() {}
void InstructionsTest::test_0xE9() {}
void InstructionsTest::test_0xEA() {}
void InstructionsTest::test_0xEB() {}
void InstructionsTest::test_0xEC() {}
void InstructionsTest::test_0xED() {}
void InstructionsTest::test_0xEE() {}
void InstructionsTest::test_0xEF() {}

void InstructionsTest::test_0xF0() {}
void InstructionsTest::test_0xF1() {}
void InstructionsTest::test_0xF2() {}
void InstructionsTest::test_0xF3() {}
void InstructionsTest::test_0xF4() {}
void InstructionsTest::test_0xF5() {}
void InstructionsTest::test_0xF6() {}
void InstructionsTest::test_0xF7() {}
void InstructionsTest::test_0xF8() {}
void InstructionsTest::test_0xF9() {}
void InstructionsTest::test_0xFA() {}
void InstructionsTest::test_0xFB() {}
void InstructionsTest::test_0xFC() {}
void InstructionsTest::test_0xFD() {}
void InstructionsTest::test_0xFE() {}
void InstructionsTest::test_0xFF() {}
