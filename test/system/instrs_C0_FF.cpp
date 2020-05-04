#include "includes/instrs_C0_FF.h"

Instrs_C0_FF::Instrs_C0_FF(GameBoy* gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xC0(); });
    Test::addTest([this]() -> void { test_0xC0_no_return(); });
    Test::addTest([this]() -> void { test_0xC1(); });
    Test::addTest([this]() -> void { test_0xC2(); });
    Test::addTest([this]() -> void { test_0xC2_no_jump(); });
    Test::addTest([this]() -> void { test_0xC3(); });
    Test::addTest([this]() -> void { test_0xC4(); });
    Test::addTest([this]() -> void { test_0xC4_no_call(); });
    Test::addTest([this]() -> void { test_0xC5(); });
    Test::addTest([this]() -> void { test_0xC6(); });
    Test::addTest([this]() -> void { test_0xC7(); });
    Test::addTest([this]() -> void { test_0xC8(); });
    Test::addTest([this]() -> void { test_0xC8_no_return(); });
    Test::addTest([this]() -> void { test_0xC9(); });
    Test::addTest([this]() -> void { test_0xCA(); });
    Test::addTest([this]() -> void { test_0xCA_no_jump(); });
    Test::addTest([this]() -> void { test_0xCC(); });
    Test::addTest([this]() -> void { test_0xCC_no_call(); });
    Test::addTest([this]() -> void { test_0xCD(); });
    Test::addTest([this]() -> void { test_0xCE(); });
    Test::addTest([this]() -> void { test_0xCF(); });

    Test::addTest([this]() -> void { test_0xD0(); });
    Test::addTest([this]() -> void { test_0xD0_no_return(); });
    Test::addTest([this]() -> void { test_0xD1(); });
    Test::addTest([this]() -> void { test_0xD2(); });
    Test::addTest([this]() -> void { test_0xD2_no_jump(); });
    Test::addTest([this]() -> void { test_0xD3(); });
    Test::addTest([this]() -> void { test_0xD4(); });
    Test::addTest([this]() -> void { test_0xD4_no_call(); });
    Test::addTest([this]() -> void { test_0xD5(); });
    Test::addTest([this]() -> void { test_0xD6(); });
    Test::addTest([this]() -> void { test_0xD7(); });
    Test::addTest([this]() -> void { test_0xD8(); });
    Test::addTest([this]() -> void { test_0xD8_no_return(); });
    Test::addTest([this]() -> void { test_0xD9(); });
    Test::addTest([this]() -> void { test_0xDA(); });
    Test::addTest([this]() -> void { test_0xDA_no_jump(); });
    Test::addTest([this]() -> void { test_0xDB(); });
    Test::addTest([this]() -> void { test_0xDC(); });
    Test::addTest([this]() -> void { test_0xDC_no_call(); });
    Test::addTest([this]() -> void { test_0xDD(); });
    Test::addTest([this]() -> void { test_0xDE(); });
    Test::addTest([this]() -> void { test_0xDE_zero(); });
    Test::addTest([this]() -> void { test_0xDE_half_carry(); });
    Test::addTest([this]() -> void { test_0xDF(); });

    Test::addTest([this]() -> void { test_0xE0(); });
    Test::addTest([this]() -> void { test_0xE1(); });
    Test::addTest([this]() -> void { test_0xE2(); });
    Test::addTest([this]() -> void { test_0xE3(); });
    Test::addTest([this]() -> void { test_0xE4(); });
    Test::addTest([this]() -> void { test_0xE5(); });
    Test::addTest([this]() -> void { test_0xE6_half(); });
    Test::addTest([this]() -> void { test_0xE6_zero_half(); });
    Test::addTest([this]() -> void { test_0xE7(); });
    Test::addTest([this]() -> void { test_0xE8(); });
    Test::addTest([this]() -> void { test_0xE8_negative(); });
    Test::addTest([this]() -> void { test_0xE9(); });
    Test::addTest([this]() -> void { test_0xEA(); });
    Test::addTest([this]() -> void { test_0xEB(); });
    Test::addTest([this]() -> void { test_0xEC(); });
    Test::addTest([this]() -> void { test_0xED(); });
    Test::addTest([this]() -> void { test_0xEE(); });
    Test::addTest([this]() -> void { test_0xEE_zero(); });
    Test::addTest([this]() -> void { test_0xEF(); });

    Test::addTest([this]() -> void { test_0xF0(); });
    Test::addTest([this]() -> void { test_0xF1(); });
    Test::addTest([this]() -> void { test_0xF2(); });
    Test::addTest([this]() -> void { test_0xF3(); });
    Test::addTest([this]() -> void { test_0xF4(); });
    Test::addTest([this]() -> void { test_0xF5(); });
    Test::addTest([this]() -> void { test_0xF6(); });
    Test::addTest([this]() -> void { test_0xF6_zero(); });
    Test::addTest([this]() -> void { test_0xF7(); });
    Test::addTest([this]() -> void { test_0xF8(); });
    Test::addTest([this]() -> void { test_0xF9(); });
    Test::addTest([this]() -> void { test_0xFA(); });
    Test::addTest([this]() -> void { test_0xFB(); });
    Test::addTest([this]() -> void { test_0xFC(); });
    Test::addTest([this]() -> void { test_0xFD(); });
    Test::addTest([this]() -> void { test_0xFE_zero(); });
    Test::addTest([this]() -> void { test_0xFE_half(); });
    Test::addTest([this]() -> void { test_0xFE_carry(); });
    Test::addTest([this]() -> void { test_0xFF(); });
}

void Instrs_C0_FF::beforeAll() {
    rom = new byte[0x8000];
    printf("\nInstructions 0xC0 through 0xFF running...");
}

void Instrs_C0_FF::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_C0_FF::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_C0_FF::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region r0xC0_0xCF

// ret nz
void Instrs_C0_FF::test_0xC0() {
    rom[0x1234] = 0xC0; // ret nz

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret nz ; should return

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

void Instrs_C0_FF::test_0xC0_no_return() {
    rom[0x1234] = 0xC0; // ret nz

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
    gb->cpu->setFlags(ZERO);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret nz ; should not return

    expect(gb->cpu->registers.PC, 0x1235, "PC should be 0x1235");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// pop bc
void Instrs_C0_FF::test_0xC1() {
    loadRom({
                0xC1 // pop bc
            });

    gb->memory->writeByte(0xFFFD, 0xBE);
    gb->memory->writeByte(0xFFFC, 0xEF);
    gb->cpu->registers.SP = 0xFFFC;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.BC, 0xBEEF, "BC should be 0xBEEF");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// jp nz, xx
void Instrs_C0_FF::test_0xC2() {
    loadRom({
                0xC2, // jp nz, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_C0_FF::test_0xC2_no_jump() {
    loadRom({
                0xC2, // jp nz, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// jp xx
void Instrs_C0_FF::test_0xC3() {
    loadRom({
                0xC3, // jp $1234
                0x34,
                0x12
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// call nz, xx
void Instrs_C0_FF::test_0xC4() {
    loadRom({
                0xC4, // call nz, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x03, "the value at address 0xFFFC should be 0x03");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_C0_FF::test_0xC4_no_call() {
    loadRom({
                0xC4, // call nz, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// push bc
void Instrs_C0_FF::test_0xC5() {
    loadRom({
                0xC5 // push bc
            });

    gb->cpu->registers.BC = 0xBEEF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xFFFD), 0xBE, "the value at address 0xFFFD should be 0xBE");
    expect(gb->memory->readByte(0xFFFC), 0xEF, "the value at address 0xFFFC should be 0xEF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// add a, x
void Instrs_C0_FF::test_0xC6() {
    loadRom({
                0xC6, // add a, $C6
                0xC6
            });

    gb->cpu->registers.A = 0x3A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 00
void Instrs_C0_FF::test_0xC7() {
    loadRom({
                0xC7 // rst $00
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x00, "PC should be 0x00");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// ret z
void Instrs_C0_FF::test_0xC8() {
    rom[0x1234] = 0xC8; // ret z

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
    gb->cpu->setFlags(ZERO);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret z ; should return

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

void Instrs_C0_FF::test_0xC8_no_return() {
    rom[0x1234] = 0xC8; // ret z

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
    gb->cpu->resetFlags(ZERO);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret z ; should not return

    expect(gb->cpu->registers.PC, 0x1235, "PC should be 0x1235");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ret
void Instrs_C0_FF::test_0xC9() {
    rom[0x1234] = 0xC9; // ret

    gb->loadRom(rom);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// jp z, xx
void Instrs_C0_FF::test_0xCA() {
    loadRom({
                0xCA, // jp z, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_C0_FF::test_0xCA_no_jump() {
    loadRom({
                0xCA, // jp z, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// call z, xx
void Instrs_C0_FF::test_0xCC() {
    loadRom({
                0xCC, // call z, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x03, "the value at address 0xFFFC should be 0x03");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_C0_FF::test_0xCC_no_call() {
    loadRom({
                0xCC, // call z, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(ZERO);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// call xx
void Instrs_C0_FF::test_0xCD() {
    loadRom({
                0xCD, // call $1234
                0x34,
                0x12
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x03, "the value at address 0xFFFC should be 0x03");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

// adc a, x
void Instrs_C0_FF::test_0xCE() {
    loadRom({
                0xCE, // adc a, $1E
                0x1E
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->registers.A = 0xE1;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF | CARRY, "ZERO, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 08
void Instrs_C0_FF::test_0xCF() {
    loadRom({
                0xCF // rst $08
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x08, "PC should be 0x08");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

#pragma endregion

#pragma region r0xD0_0xDF

// ret nc
void Instrs_C0_FF::test_0xD0() {
    rom[0x1234] = 0xD0; // ret nc

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret nc ; should return

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

void Instrs_C0_FF::test_0xD0_no_return() {
    rom[0x1234] = 0xD0; // ret nc

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
    gb->cpu->setFlags(CARRY);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret nc ; should not return

    expect(gb->cpu->registers.PC, 0x1235, "PC should be 0x1235");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// pop de
void Instrs_C0_FF::test_0xD1() {
    loadRom({
                0xD1 // pop de
            });

    gb->memory->writeByte(0xFFFD, 0xBE);
    gb->memory->writeByte(0xFFFC, 0xEF);
    gb->cpu->registers.SP = 0xFFFC;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.DE, 0xBEEF, "DE should be 0xBEEF");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// jp nc, xx
void Instrs_C0_FF::test_0xD2() {
    loadRom({
                0xD2, // jp nc, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_C0_FF::test_0xD2_no_jump() {
    loadRom({
                0xD2, // jp nc, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xD3() {
    loadRom({
                0xD3 // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// call nc, xx
void Instrs_C0_FF::test_0xD4() {
    loadRom({
                0xD4, // call nc, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x03, "the value at address 0xFFFC should be 0x03");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_C0_FF::test_0xD4_no_call() {
    loadRom({
                0xD4, // call nc, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// push de
void Instrs_C0_FF::test_0xD5() {
    loadRom({
                0xD5 // push de
            });

    gb->cpu->registers.DE = 0xBEEF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xFFFD), 0xBE, "the value at address 0xFFFD should be 0xBE");
    expect(gb->memory->readByte(0xFFFC), 0xEF, "the value at address 0xFFFC should be 0xEF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// sub x
void Instrs_C0_FF::test_0xD6() {
    loadRom({
                0xD6, // sub $3E
                0x3E
            });

    gb->cpu->registers.A = 0x3E;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 10
void Instrs_C0_FF::test_0xD7() {
    loadRom({
                0xD7 // rst $10
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x10, "PC should be 0x10");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// ret c
void Instrs_C0_FF::test_0xD8() {
    rom[0x1234] = 0xD8; // ret c

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
    gb->cpu->setFlags(CARRY);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret c ; should return

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 20, "should take 20 cycles");
}

void Instrs_C0_FF::test_0xD8_no_return() {
    rom[0x1234] = 0xD8; // ret c

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
    gb->cpu->resetFlags(CARRY);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // ret c ; should not return

    expect(gb->cpu->registers.PC, 0x1235, "PC should be 0x1235");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// reti
void Instrs_C0_FF::test_0xD9() {
    rom[0x1234] = 0xD9; // reti

    gb->loadRom(rom);

    // pretend a `call $1234` command was at 0x0100
    gb->memory->writeByte(0xFFFD, 0x01);
    gb->memory->writeByte(0xFFFC, 0x03);
    gb->cpu->registers.SP = 0xFFFC;
    gb->cpu->registers.PC = 0x1234;

    gb->cpu->tick(); // reti

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->ime, true, "IME should be enabled");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// jp c, xx
void Instrs_C0_FF::test_0xDA() {
    loadRom({
                0xDA, // jp c, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_C0_FF::test_0xDA_no_jump() {
    loadRom({
                0xDA, // jp c, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xDB() {
    loadRom({
                0xDB // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// call c, xx
void Instrs_C0_FF::test_0xDC() {
    loadRom({
                0xDC, // call C, $1234
                0x34,
                0x12
            });

    gb->cpu->setFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x03, "the value at address 0xFFFC should be 0x03");
    expect(gb->cpu->cycles, 24, "should take 24 cycles");
}

void Instrs_C0_FF::test_0xDC_no_call() {
    loadRom({
                0xDC, // call C, $1234
                0x34,
                0x12
            });

    gb->cpu->resetFlags(CARRY);
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.SP, 0xFFFE, "SP should be 0xFFFE");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xDD() {
    loadRom({
                0xDD // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// sbc a, x
void Instrs_C0_FF::test_0xDE() {
    loadRom({
                0xDE, // sbc a, $2A
                0x2A
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->registers.F, SUB, "SUB flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xDE_zero() {
    loadRom({
                0xDE, // sbc a, $3A
                0x3A
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xDE_half_carry() {
    loadRom({
                0xDE, // sbc a, $4F
                0x4F
            });

    gb->cpu->registers.A = 0x3B;
    gb->cpu->setFlags(CARRY);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xEB, "A should be 0xEB");
    expect(gb->cpu->registers.F, SUB | HALF | CARRY, "SUB, HALF and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 18
void Instrs_C0_FF::test_0xDF() {
    loadRom({
                0xDF // rst $18
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x18, "PC should be 0x18");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

#pragma endregion

#pragma region r0xE0_0xEF

// ldh (x), a
void Instrs_C0_FF::test_0xE0() {
    loadRom({
                0xE0, // ldh ($15), a
                0x15
            });

    gb->cpu->registers.A = 0x50;
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xFF15), 0x50, "the value at address 0xFF15 should be 0x50");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// pop hl
void Instrs_C0_FF::test_0xE1() {
    loadRom({
                0xE1 // pop hl
            });

    gb->memory->writeByte(0xFFFD, 0xBE);
    gb->memory->writeByte(0xFFFC, 0xEF);
    gb->cpu->registers.SP = 0xFFFC;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.HL, 0xBEEF, "HL should be 0xBEEF");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld (c), a
void Instrs_C0_FF::test_0xE2() {
    loadRom({
                0xE2 // ld (c), a
            });

    gb->cpu->registers.A = 0x42;
    gb->cpu->registers.C = 0x15;
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xFF15), 0x42, "the value at address 0xFF15 should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xE3() {
    loadRom({
                0xE3 // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// illegal opcode
void Instrs_C0_FF::test_0xE4() {
    loadRom({
                0xE4 // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// push hl
void Instrs_C0_FF::test_0xE5() {
    loadRom({
                0xE5 // push hl
            });

    gb->cpu->registers.HL = 0xBEEF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xFFFD), 0xBE, "the value at address 0xFFFD should be 0xBE");
    expect(gb->memory->readByte(0xFFFC), 0xEF, "the value at address 0xFFFC should be 0xEF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// and x
void Instrs_C0_FF::test_0xE6_half() {
    loadRom({
                0xE6, // and $3F
                0x3F
            });

    gb->cpu->registers.A = 0x5A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x1A, "A should be 0x1A");
    expect(gb->cpu->registers.F, HALF, "HALF flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xE6_zero_half() {
    loadRom({
                0xE6, // and $00
                0x00
            });

    gb->cpu->registers.A = 0x5A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO | HALF, "ZERO and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 20
void Instrs_C0_FF::test_0xE7() {
    loadRom({
                0xE7 // rst $20
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x20, "PC should be 0x20");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// add sp, x
void Instrs_C0_FF::test_0xE8() {
    loadRom({
                0xE8, // add sp, $05
                0x05
            });

    gb->cpu->registers.SP = 0xFFF0;
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.SP, 0xFFF5, "SP should be 0xFFF5");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

void Instrs_C0_FF::test_0xE8_negative() {
    loadRom({
                0xE8, // add sp, $FB
                0xFB
            });

    gb->cpu->registers.SP = 0xFFF5;
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.SP, 0xFFF0, "SP should be 0xFFF0");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// jp hl
void Instrs_C0_FF::test_0xE9() {
    loadRom({
                0xE9 // jp hl
            });

    gb->cpu->registers.HL = 0x1234;
    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x1234, "PC should be 0x1234");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// ld (xx), a
void Instrs_C0_FF::test_0xEA() {
    loadRom({
                0xEA, // ld (xx), a
                0x00,
                0xC0
            });

    gb->cpu->registers.A = 0x42;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->memory->readByte(0xC000), 0x42, "the value at address 0xC000 should be 0x42");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xEB() {
    loadRom({
                0xEB // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// illegal opcode
void Instrs_C0_FF::test_0xEC() {
    loadRom({
                0xEC // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// illegal opcode
void Instrs_C0_FF::test_0xED() {
    loadRom({
                0xED // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// xor x
void Instrs_C0_FF::test_0xEE() {
    loadRom({
                0xEE, // xor $0F
                0x0F
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.B = 0x0F;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0xF0, "A should be 0xF0");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xEE_zero() {
    loadRom({
                0xEE, // xor $FF
                0xFF
            });

    gb->cpu->registers.A = 0xFF;
    gb->cpu->registers.B = 0xFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 28
void Instrs_C0_FF::test_0xEF() {
    loadRom({
                0xEF // rst $28
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x28, "PC should be 0x28");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

#pragma endregion

#pragma region r0xE0_0xEF

// ldh a, (x)
void Instrs_C0_FF::test_0xF0() {
    loadRom({
                0xF0, // ldh a, ($F0)
                0xF0
            });

    gb->memory->writeByte(0xFFF0, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// pop af
void Instrs_C0_FF::test_0xF1() {
    loadRom({
                0xF1 // pop af
            });

    gb->memory->writeByte(0xFFFD, 0xBE);
    gb->memory->writeByte(0xFFFC, 0xEF);
    gb->cpu->registers.SP = 0xFFFC;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.AF, 0xBEEF, "AF should be 0xBEEF");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld a, (c)
void Instrs_C0_FF::test_0xF2() {
    loadRom({
                0xF2 // ld a, (c)
            });

    gb->memory->writeByte(0xFFF0, 0x42);
    gb->cpu->registers.C = 0xF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// di
void Instrs_C0_FF::test_0xF3() {
    loadRom({
                0xF3 // di
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xF4() {
    loadRom({
                0xF4 // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// push af
void Instrs_C0_FF::test_0xF5() {
    loadRom({
                0xF5 // push af
            });

    gb->cpu->registers.AF = 0xBEEF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->memory->readByte(0xFFFD), 0xBE, "the value at address 0xFFFD should be 0xBE");
    expect(gb->memory->readByte(0xFFFC), 0xEF, "the value at address 0xFFFC should be 0xEF");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// or x
void Instrs_C0_FF::test_0xF6() {
    loadRom({
                0xF6, // or $0F
                0x0F
            });

    gb->cpu->registers.A = 0x5A;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x5F, "A should be 0x5F");
    expect(gb->cpu->registers.F, 0, "no flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xF6_zero() {
    loadRom({
                0xF6, // or $00
                0x00
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x00, "A should be 0x00");
    expect(gb->cpu->registers.F, ZERO, "ZERO flag should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 30
void Instrs_C0_FF::test_0xF7() {
    loadRom({
                0xF7 // rst $30
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x30, "PC should be 0x30");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// ld hl, sp+x
void Instrs_C0_FF::test_0xF8() {
    loadRom({
                0xF8, // ld hl, sp+$01
                0x01
            });

    gb->cpu->registers.SP = 0xEFFF;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.HL, 0xF000, "HL should be 0xF000");
    expect(gb->cpu->cycles, 12, "should take 12 cycles");
}

// ld sp, hl
void Instrs_C0_FF::test_0xF9() {
    loadRom({
                0xF9 // ld sp, hl
            });

    gb->cpu->registers.HL = 0xFFF0;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->registers.SP, 0xFFF0, "SP should be 0xFFF0");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// ld a, (xx)
void Instrs_C0_FF::test_0xFA() {
    loadRom({
                0xFA, // ld a, ($C000)
                0x00,
                0xC0
            });

    gb->memory->writeByte(0xC000, 0x42);

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// ei
void Instrs_C0_FF::test_0xFB() {
    loadRom({
                0xFB, // ei
                0x00 // nop
            });

    gb->cpu->ime = false;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should still be disabled");
    expect(gb->cpu->cycles, 4, "should take 4 cycles");

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->ime, true, "IME should be enabled");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// illegal opcode
void Instrs_C0_FF::test_0xFC() {
    loadRom({
                0xFC // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// illegal opcode
void Instrs_C0_FF::test_0xFD() {
    loadRom({
                0xFD // illegal opcode
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x101, "PC should be 0x101");
    expect(gb->cpu->ime, false, "IME should be disabled");
    expect(gb->cpu->isHalted, true, "CPU should be halted");
}

// cp x
void Instrs_C0_FF::test_0xFE_zero() {
    loadRom({
                0xFE, // cp $3C
                0x3C
            });

    gb->cpu->registers.A = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, ZERO | SUB, "ZERO and SUB flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xFE_half() {
    loadRom({
                0xFE, // cp $2F
                0x2F
            });

    gb->cpu->registers.A = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, SUB | HALF, "SUB and HALF flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

void Instrs_C0_FF::test_0xFE_carry() {
    loadRom({
                0xFE, // cp $40
                0x40
            });

    gb->cpu->registers.A = 0x3C;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.F, SUB | CARRY, "SUB and CARRY flags should be set");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// rst 38
void Instrs_C0_FF::test_0xFF() {
    loadRom({
                0xFF // rst $38
            });

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x38, "PC should be 0x38");
    expect(gb->cpu->registers.SP, 0xFFFC, "SP should be 0xFFFC");
    expect(gb->memory->readByte(0xFFFD), 0x01, "the value at address 0xFFFD should be 0x01");
    expect(gb->memory->readByte(0xFFFC), 0x01, "the value at address 0xFFFC should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

#pragma endregion