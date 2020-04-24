#include "includes/cpu.h"

CPUTest::CPUTest(GameBoy* gameBoy) {
    gb = gameBoy;

    Test::addTest([this]() -> void { setFlags(); });
    Test::addTest([this]() -> void { resetFlags(); });
    Test::addTest([this]() -> void { complexFlagLogic(); });
    Test::addTest([this]() -> void { manipulateRegisters(); });
    Test::addTest([this]() -> void { nestedInterrupt(); });
}

void CPUTest::beforeAll() {
    gb->reset();
    printf("\nCPU Tests running...");
}

void CPUTest::tearDown() {

}

void CPUTest::beforeEach() {
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

void CPUTest::setFlags() {
    gb->cpu->setFlags(ZERO);
    expect(gb->cpu->registers.F, 0b10000000, "Only ZERO flag should be set.");

    gb->cpu->setFlags(SUB);
    expect(gb->cpu->registers.F, 0b11000000, "ZERO and SUB flags should be set.");

    gb->cpu->setFlags(HALF);
    expect(gb->cpu->registers.F, 0b11100000, "ZERO, SUB and HALF flags should be set.");

    gb->cpu->setFlags(CARRY);
    expect(gb->cpu->registers.F, 0b11110000, "All flags should be set.");
}

void CPUTest::resetFlags() {
    gb->cpu->setFlags(ZERO | SUB | HALF | CARRY);

    gb->cpu->resetFlags(ZERO);
    expect(gb->cpu->registers.F, 0b01110000, "SUB, HALF and CARRY flags should be set.");

    gb->cpu->resetFlags(SUB);
    expect(gb->cpu->registers.F, 0b00110000, "HALF and CARRY flags should be set.");

    gb->cpu->resetFlags(HALF);
    expect(gb->cpu->registers.F, 0b00010000, "Only CARRY flag should be set.");

    gb->cpu->resetFlags(CARRY);
    expect(gb->cpu->registers.F, 0b00000000, "No flags should be set.");
}

void CPUTest::complexFlagLogic() {
    gb->cpu->setFlags(ZERO | CARRY);
    expect(gb->cpu->registers.F, 0b10010000, "ZERO and CARRY flags should be set.");

    gb->cpu->resetFlags(ZERO | CARRY);
    expect(gb->cpu->registers.F, 0b00000000, "No flags should be set.");

    gb->cpu->setFlags(ZERO | SUB | CARRY);
    expect(gb->cpu->registers.F, 0b11010000, "ZERO, SUB and CARRY flags should be set.");

    gb->cpu->resetFlags(ZERO | CARRY);
    expect(gb->cpu->registers.F, 0b01000000, "Only SUB flag should be set.");
}

void CPUTest::manipulateRegisters() {
    gb->cpu->registers.A = 0xAA;
    gb->cpu->registers.B = 0xBB;
    gb->cpu->registers.C = 0xCC;
    gb->cpu->registers.D = 0xDD;
    gb->cpu->registers.E = 0xEE;
    gb->cpu->registers.F = 0xFF;
    gb->cpu->registers.H = 0x11;
    gb->cpu->registers.L = 0x22;

    expect(gb->cpu->registers.A, 0xAA, "The A register should equal 0xAA.");
    expect(gb->cpu->registers.B, 0xBB, "The B register should equal 0xBB.");
    expect(gb->cpu->registers.C, 0xCC, "The C register should equal 0xCC.");
    expect(gb->cpu->registers.D, 0xDD, "The D register should equal 0xDD.");
    expect(gb->cpu->registers.E, 0xEE, "The E register should equal 0xEE.");
    expect(gb->cpu->registers.F, 0xFF, "The F register should equal 0xFF.");
    expect(gb->cpu->registers.H, 0x11, "The H register should equal 0x11.");
    expect(gb->cpu->registers.L, 0x22, "The L register should equal 0x22.");

    gb->cpu->registers.AF = 0x1122;
    gb->cpu->registers.BC = 0x3344;
    gb->cpu->registers.DE = 0x5566;
    gb->cpu->registers.HL = 0x7788;
    expect(gb->cpu->registers.A, 0x11, "The A register should equal 0x11.");
    expect(gb->cpu->registers.B, 0x33, "The B register should equal 0x33.");
    expect(gb->cpu->registers.C, 0x44, "The C register should equal 0x44.");
    expect(gb->cpu->registers.D, 0x55, "The D register should equal 0x55.");
    expect(gb->cpu->registers.E, 0x66, "The E register should equal 0x66.");
    expect(gb->cpu->registers.F, 0x22, "The F register should equal 0x22.");
    expect(gb->cpu->registers.H, 0x77, "The H register should equal 0x77.");
    expect(gb->cpu->registers.L, 0x88, "The L register should equal 0x88.");
}

void CPUTest::nestedInterrupt() {
    byte* rom = new byte[0x800000];
    
    // vblank interrupt
    rom[0x40] = 0x3E; // ld a, 0x42
    rom[0x41] = 0x42;
    rom[0x42] = 0xFB; // ei
    rom[0x43] = 0x00; // nop
    rom[0x44] = 0xC9; // ret

    // joypad interrupt
    rom[0x60] = 0x0E; // ld c, 0x42
    rom[0x61] = 0x42;
    rom[0x62] = 0xC9; // ret

    // main
    rom[0x100] = 0x06; // ld b, 0x42
    rom[0x101] = 0x42;
    rom[0x102] = 0xFB; // ei
    rom[0x103] = 0x00; // nop
    rom[0x104] = 0x76; // halt

    gb->loadRom(rom);

    byte flags = gb->memory->readIO(IO_INTERRUPT_FLAGS);
    byte ie = gb->memory->readIO(IO_INTERRUPT_ENABLE);

    // enable vblank
    gb->memory->writeIO(IO_INTERRUPT_FLAGS, flags | INTERRUPT_VBLANK);
    gb->memory->writeIO(IO_INTERRUPT_ENABLE, ie | INTERRUPT_VBLANK);

    gb->cpu->tick(); // ld b, 0x42
    expect(gb->cpu->registers.B, 0x42, "B should be 0x42");
    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");

    gb->cpu->tick(); // ei
    expect(gb->cpu->registers.PC, 0x103, "PC should be 0x103");

    gb->cpu->tick(); // nop
    expect(gb->cpu->ime, true, "IME should be enabled on the cycle after ei");
    expect(gb->cpu->registers.PC, 0x104, "PC should be 0x104");

    gb->cpu->tick(); // jump to interrupt vector
    expect(gb->cpu->registers.PC, 0x40, "PC should be 0x40");
    expect(gb->cpu->ime, false, "IME should be disabled after calling an interrupt");
    expect(gb->memory->readByte(0xFFFD), 0x01, "0x0104 should be pushed to the stack");
    expect(gb->memory->readByte(0xFFFC), 0x04, "0x0104 should be pushed to the stack");

    // should be in vblank interrupt
    gb->cpu->tick(); // ld a, 0x42
    expect(gb->cpu->registers.A, 0x42, "A should be 0x42");
    expect(gb->cpu->registers.PC, 0x42, "PC should be 0x42");

    // simlate joypad interrupt enable
    gb->memory->writeIO(IO_INTERRUPT_FLAGS, flags | INTERRUPT_JOYPAD);
    gb->memory->writeIO(IO_INTERRUPT_ENABLE, ie | INTERRUPT_JOYPAD);

    gb->cpu->tick(); // ei
    expect(gb->cpu->registers.PC, 0x43, "PC should be 0x43");

    gb->cpu->tick(); // nop
    expect(gb->cpu->ime, true, "IME should be enabled on the cycle after ei");
    expect(gb->cpu->registers.PC, 0x44, "PC should be 0x44");

    gb->cpu->tick(); // jump to joypad interrupt vector
    expect(gb->cpu->registers.PC, 0x60, "PC should be 0x60");
    expect(gb->cpu->ime, false, "IME should be disabled after calling an interrupt");
    expect(gb->memory->readByte(0xFFFB), 0x00, "0x00 should be pushed to the stack at 0xFFFB");
    expect(gb->memory->readByte(0xFFFA), 0x44, "0x44 should be pushed to the stack at 0xFFFA");

    // should be in joypad interrupt vector
    gb->cpu->tick(); // ld c, 0x42
    expect(gb->cpu->registers.C, 0x42, "C should be 0x42");
    expect(gb->cpu->registers.PC, 0x62, "PC should be 0x62");

    gb->cpu->tick(); // ret
    expect(gb->cpu->registers.PC, 0x44, "should return to vblank interrupt and PC should be 0x44");

    // back in vblank
    gb->cpu->tick(); // ret
    expect(gb->cpu->registers.PC, 0x104, "should return to main and PC should be 0x104");

    gb->cpu->tick(); // halt
    expect(gb->cpu->isHalted, true, "should halt the cpu");

    delete[] rom;
    rom = nullptr;
}
