#include "includes/instrs_CBC0_CBFF.h"

Instrs_CBC0_CBFF::Instrs_CBC0_CBFF(GameBoy *gameBoy) {
    gb = gameBoy;
    rom = nullptr;

    Test::addTest([this]() -> void { test_0xCBC0(); });
    Test::addTest([this]() -> void { test_0xCBC1(); });
    Test::addTest([this]() -> void { test_0xCBC2(); });
    Test::addTest([this]() -> void { test_0xCBC3(); });
    Test::addTest([this]() -> void { test_0xCBC4(); });
    Test::addTest([this]() -> void { test_0xCBC5(); });
    Test::addTest([this]() -> void { test_0xCBC6(); });
    Test::addTest([this]() -> void { test_0xCBC7(); });
    Test::addTest([this]() -> void { test_0xCBC8(); });
    Test::addTest([this]() -> void { test_0xCBC9(); });
    Test::addTest([this]() -> void { test_0xCBCA(); });
    Test::addTest([this]() -> void { test_0xCBCB(); });
    Test::addTest([this]() -> void { test_0xCBCC(); });
    Test::addTest([this]() -> void { test_0xCBCD(); });
    Test::addTest([this]() -> void { test_0xCBCE(); });
    Test::addTest([this]() -> void { test_0xCBCF(); });

    Test::addTest([this]() -> void { test_0xCBD0(); });
    Test::addTest([this]() -> void { test_0xCBD1(); });
    Test::addTest([this]() -> void { test_0xCBD2(); });
    Test::addTest([this]() -> void { test_0xCBD3(); });
    Test::addTest([this]() -> void { test_0xCBD4(); });
    Test::addTest([this]() -> void { test_0xCBD5(); });
    Test::addTest([this]() -> void { test_0xCBD6(); });
    Test::addTest([this]() -> void { test_0xCBD7(); });
    Test::addTest([this]() -> void { test_0xCBD8(); });
    Test::addTest([this]() -> void { test_0xCBD9(); });
    Test::addTest([this]() -> void { test_0xCBDA(); });
    Test::addTest([this]() -> void { test_0xCBDB(); });
    Test::addTest([this]() -> void { test_0xCBDC(); });
    Test::addTest([this]() -> void { test_0xCBDD(); });
    Test::addTest([this]() -> void { test_0xCBDE(); });
    Test::addTest([this]() -> void { test_0xCBDF(); });

    Test::addTest([this]() -> void { test_0xCBE0(); });
    Test::addTest([this]() -> void { test_0xCBE1(); });
    Test::addTest([this]() -> void { test_0xCBE2(); });
    Test::addTest([this]() -> void { test_0xCBE3(); });
    Test::addTest([this]() -> void { test_0xCBE4(); });
    Test::addTest([this]() -> void { test_0xCBE5(); });
    Test::addTest([this]() -> void { test_0xCBE6(); });
    Test::addTest([this]() -> void { test_0xCBE7(); });
    Test::addTest([this]() -> void { test_0xCBE8(); });
    Test::addTest([this]() -> void { test_0xCBE9(); });
    Test::addTest([this]() -> void { test_0xCBEA(); });
    Test::addTest([this]() -> void { test_0xCBEB(); });
    Test::addTest([this]() -> void { test_0xCBEC(); });
    Test::addTest([this]() -> void { test_0xCBED(); });
    Test::addTest([this]() -> void { test_0xCBEE(); });
    Test::addTest([this]() -> void { test_0xCBEF(); });

    Test::addTest([this]() -> void { test_0xCBF0(); });
    Test::addTest([this]() -> void { test_0xCBF1(); });
    Test::addTest([this]() -> void { test_0xCBF2(); });
    Test::addTest([this]() -> void { test_0xCBF3(); });
    Test::addTest([this]() -> void { test_0xCBF4(); });
    Test::addTest([this]() -> void { test_0xCBF5(); });
    Test::addTest([this]() -> void { test_0xCBF6(); });
    Test::addTest([this]() -> void { test_0xCBF7(); });
    Test::addTest([this]() -> void { test_0xCBF8(); });
    Test::addTest([this]() -> void { test_0xCBF9(); });
    Test::addTest([this]() -> void { test_0xCBFA(); });
    Test::addTest([this]() -> void { test_0xCBFB(); });
    Test::addTest([this]() -> void { test_0xCBFC(); });
    Test::addTest([this]() -> void { test_0xCBFD(); });
    Test::addTest([this]() -> void { test_0xCBFE(); });
    Test::addTest([this]() -> void { test_0xCBFF(); });
}

void Instrs_CBC0_CBFF::beforeAll() {
    rom = new byte[0x800000];
    testResults << std::endl << "Instructions 0xCBC0 through 0xCBFF running...";
}

void Instrs_CBC0_CBFF::beforeEach() {
    // reset the first 0x8000 bytes of the rom. I'm sure I won't use more than that...
    std::fill(rom, rom + 0x7FFF, 0);
    gb->cpu->registers.PC = 0x100;
    gb->cpu->registers.SP = 0xFFFE;
}

void Instrs_CBC0_CBFF::tearDown() {
    if(rom != nullptr) {
        delete[] rom;
        rom = nullptr;
    }
}

/**
 * Create a rom with the bytes starting at 0x100 and load the rom into the GameBoy
 */
void Instrs_CBC0_CBFF::loadRom(std::vector<byte> bytes) const {
    word length = bytes.size() + 0x100;

    for(word i = 0x100; i < length; i++) {
        rom[i] = bytes[i - 0x100];
    }

    gb->loadRom(rom);
    gb->cpu->resetFlags(ZERO | SUB | HALF | CARRY);
}

#pragma region rCBC0_CBCF

// set 0, b
void Instrs_CBC0_CBFF::test_0xCBC0(){
    loadRom({
                0xCB,
                0xC0 // set 0, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x01, "B should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 0, c
void Instrs_CBC0_CBFF::test_0xCBC1(){
    loadRom({
                0xCB,
                0xC1 // set 0, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x01, "C should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 0, d
void Instrs_CBC0_CBFF::test_0xCBC2(){
    loadRom({
                0xCB,
                0xC2 // set 0, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x01, "D should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 0, e
void Instrs_CBC0_CBFF::test_0xCBC3(){
    loadRom({
                0xCB,
                0xC3 // set 0, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x01, "E should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 0, h
void Instrs_CBC0_CBFF::test_0xCBC4(){
    loadRom({
                0xCB,
                0xC4 // set 0, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x01, "H should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 0, l
void Instrs_CBC0_CBFF::test_0xCBC5(){
    loadRom({
                0xCB,
                0xC5 // set 0, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x01, "L should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 0, (hl)
void Instrs_CBC0_CBFF::test_0xCBC6(){
    loadRom({
                0xCB,
                0xC6 // set 0, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x01, "the value pointed to by HL should be 0x01");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 0, a
void Instrs_CBC0_CBFF::test_0xCBC7(){
    loadRom({
                0xCB,
                0xC7 // set 0, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x01, "A should be 0x01");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, b
void Instrs_CBC0_CBFF::test_0xCBC8() {
    loadRom({
                0xCB,
                0xC8 // set 1, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x02, "B should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, c
void Instrs_CBC0_CBFF::test_0xCBC9() {
    loadRom({
                0xCB,
                0xC9 // set 1, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x02, "C should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, d
void Instrs_CBC0_CBFF::test_0xCBCA() {
    loadRom({
                0xCB,
                0xCA // set 1, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x02, "D should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, e
void Instrs_CBC0_CBFF::test_0xCBCB() {
    loadRom({
                0xCB,
                0xCB // set 1, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x02, "E should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, h
void Instrs_CBC0_CBFF::test_0xCBCC() {
    loadRom({
                0xCB,
                0xCC // set 1, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x02, "H should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, l
void Instrs_CBC0_CBFF::test_0xCBCD() {
    loadRom({
                0xCB,
                0xCD // set 1, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x02, "L should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 1, (hl)
void Instrs_CBC0_CBFF::test_0xCBCE() {
    loadRom({
                0xCB,
                0xCE // set 1, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x02, "the value pointed to by HL should be 0x02");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 1, a
void Instrs_CBC0_CBFF::test_0xCBCF() {
    loadRom({
                0xCB,
                0xCF // set 1, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x02, "A should be 0x02");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCBD0_CBDF

// set 2, b
void Instrs_CBC0_CBFF::test_0xCBD0(){
    loadRom({
                0xCB,
                0xD0 // set 2, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x04, "B should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 2, c
void Instrs_CBC0_CBFF::test_0xCBD1(){
    loadRom({
                0xCB,
                0xD1 // set 2, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x04, "C should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 2, d
void Instrs_CBC0_CBFF::test_0xCBD2(){
    loadRom({
                0xCB,
                0xD2 // set 2, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x04, "D should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 2, e
void Instrs_CBC0_CBFF::test_0xCBD3(){
    loadRom({
                0xCB,
                0xD3 // set 2, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x04, "E should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 2, h
void Instrs_CBC0_CBFF::test_0xCBD4(){
    loadRom({
                0xCB,
                0xD4 // set 2, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x04, "H should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 2, l
void Instrs_CBC0_CBFF::test_0xCBD5(){
    loadRom({
                0xCB,
                0xD5 // set 2, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x04, "L should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 2, (hl)
void Instrs_CBC0_CBFF::test_0xCBD6(){
    loadRom({
                0xCB,
                0xD6 // set 2, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x04, "the value pointed to by HL should be 0x04");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 2, a
void Instrs_CBC0_CBFF::test_0xCBD7(){
    loadRom({
                0xCB,
                0xD7 // set 2, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x04, "A should be 0x04");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, b
void Instrs_CBC0_CBFF::test_0xCBD8() {
    loadRom({
                0xCB,
                0xD8 // set 3, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x08, "B should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, c
void Instrs_CBC0_CBFF::test_0xCBD9() {
    loadRom({
                0xCB,
                0xD9 // set 3, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x08, "C should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, d
void Instrs_CBC0_CBFF::test_0xCBDA() {
    loadRom({
                0xCB,
                0xDA // set 3, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x08, "D should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, e
void Instrs_CBC0_CBFF::test_0xCBDB() {
    loadRom({
                0xCB,
                0xDB // set 3, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x08, "E should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, h
void Instrs_CBC0_CBFF::test_0xCBDC() {
    loadRom({
                0xCB,
                0xDC // set 3, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x08, "H should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, l
void Instrs_CBC0_CBFF::test_0xCBDD() {
    loadRom({
                0xCB,
                0xDD // set 3, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x08, "L should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 3, (hl)
void Instrs_CBC0_CBFF::test_0xCBDE() {
    loadRom({
                0xCB,
                0xDE // set 3, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x08, "the value pointed to by HL should be 0x08");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 3, a
void Instrs_CBC0_CBFF::test_0xCBDF() {
    loadRom({
                0xCB,
                0xDF // set 3, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x08, "A should be 0x08");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCBE0_CBEF

// set 4, b
void Instrs_CBC0_CBFF::test_0xCBE0(){
    loadRom({
                0xCB,
                0xE0 // set 4, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x10, "B should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 4, c
void Instrs_CBC0_CBFF::test_0xCBE1(){
    loadRom({
                0xCB,
                0xE1 // set 4, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x10, "C should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 4, d
void Instrs_CBC0_CBFF::test_0xCBE2(){
    loadRom({
                0xCB,
                0xE2 // set 4, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x10, "D should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 4, e
void Instrs_CBC0_CBFF::test_0xCBE3(){
    loadRom({
                0xCB,
                0xE3 // set 4, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x10, "E should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 4, h
void Instrs_CBC0_CBFF::test_0xCBE4(){
    loadRom({
                0xCB,
                0xE4 // set 4, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x10, "H should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 4, l
void Instrs_CBC0_CBFF::test_0xCBE5(){
    loadRom({
                0xCB,
                0xE5 // set 4, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x10, "L should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 4, (hl)
void Instrs_CBC0_CBFF::test_0xCBE6(){
    loadRom({
                0xCB,
                0xE6 // set 4, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x10, "the value pointed to by HL should be 0x10");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 4, a
void Instrs_CBC0_CBFF::test_0xCBE7(){
    loadRom({
                0xCB,
                0xE7 // set 4, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x10, "A should be 0x10");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, b
void Instrs_CBC0_CBFF::test_0xCBE8() {
    loadRom({
                0xCB,
                0xE8 // set 5, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x20, "B should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, c
void Instrs_CBC0_CBFF::test_0xCBE9() {
    loadRom({
                0xCB,
                0xE9 // set 5, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x20, "C should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, d
void Instrs_CBC0_CBFF::test_0xCBEA() {
    loadRom({
                0xCB,
                0xEA // set 5, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x20, "D should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, e
void Instrs_CBC0_CBFF::test_0xCBEB() {
    loadRom({
                0xCB,
                0xEB // set 5, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x20, "E should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, h
void Instrs_CBC0_CBFF::test_0xCBEC() {
    loadRom({
                0xCB,
                0xEC // set 5, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x20, "H should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, l
void Instrs_CBC0_CBFF::test_0xCBED() {
    loadRom({
                0xCB,
                0xED // set 5, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x20, "L should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 5, (hl)
void Instrs_CBC0_CBFF::test_0xCBEE() {
    loadRom({
                0xCB,
                0xEE // set 5, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x20, "the value pointed to by HL should be 0x20");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 5, a
void Instrs_CBC0_CBFF::test_0xCBEF() {
    loadRom({
                0xCB,
                0xEF // set 5, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x20, "A should be 0x20");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion

#pragma region rCBF0_CBFF

// set 6, b
void Instrs_CBC0_CBFF::test_0xCBF0(){
    loadRom({
                0xCB,
                0xF0 // set 6, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x40, "B should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 6, c
void Instrs_CBC0_CBFF::test_0xCBF1(){
    loadRom({
                0xCB,
                0xF1 // set 6, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x40, "C should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 6, d
void Instrs_CBC0_CBFF::test_0xCBF2(){
    loadRom({
                0xCB,
                0xF2 // set 6, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x40, "D should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 6, e
void Instrs_CBC0_CBFF::test_0xCBF3(){
    loadRom({
                0xCB,
                0xF3 // set 6, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x40, "E should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 6, h
void Instrs_CBC0_CBFF::test_0xCBF4(){
    loadRom({
                0xCB,
                0xF4 // set 6, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x40, "H should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 6, l
void Instrs_CBC0_CBFF::test_0xCBF5(){
    loadRom({
                0xCB,
                0xF5 // set 6, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x40, "L should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 6, (hl)
void Instrs_CBC0_CBFF::test_0xCBF6(){
    loadRom({
                0xCB,
                0xF6 // set 6, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x40, "the value pointed to by HL should be 0x40");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 6, a
void Instrs_CBC0_CBFF::test_0xCBF7(){
    loadRom({
                0xCB,
                0xF7 // set 6, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x40, "A should be 0x40");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, b
void Instrs_CBC0_CBFF::test_0xCBF8() {
    loadRom({
                0xCB,
                0xF8 // set 7, b
            });

    gb->cpu->registers.B = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.B, 0x80, "B should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, c
void Instrs_CBC0_CBFF::test_0xCBF9() {
    loadRom({
                0xCB,
                0xF9 // set 7, c
            });

    gb->cpu->registers.C = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.C, 0x80, "C should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, d
void Instrs_CBC0_CBFF::test_0xCBFA() {
    loadRom({
                0xCB,
                0xFA // set 7, d
            });

    gb->cpu->registers.D = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.D, 0x80, "D should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, e
void Instrs_CBC0_CBFF::test_0xCBFB() {
    loadRom({
                0xCB,
                0xFB // set 7, e
            });

    gb->cpu->registers.E = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.E, 0x80, "E should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, h
void Instrs_CBC0_CBFF::test_0xCBFC() {
    loadRom({
                0xCB,
                0xFC // set 7, h
            });

    gb->cpu->registers.H = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.H, 0x80, "H should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, l
void Instrs_CBC0_CBFF::test_0xCBFD() {
    loadRom({
                0xCB,
                0xFD // set 7, l
            });

    gb->cpu->registers.L = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.L, 0x80, "L should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

// set 7, (hl)
void Instrs_CBC0_CBFF::test_0xCBFE() {
    loadRom({
                0xCB,
                0xFE // set 7, (hl)
            });

    gb->memory->writeByte(0xC000, 0x00);
    gb->cpu->registers.HL = 0xC000;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->memory->readByte(0xC000), 0x80, "the value pointed to by HL should be 0x80");
    expect(gb->cpu->cycles, 16, "should take 16 cycles");
}

// set 7, a
void Instrs_CBC0_CBFF::test_0xCBFF() {
    loadRom({
                0xCB,
                0xFF // set 7, a
            });

    gb->cpu->registers.A = 0x00;

    gb->cpu->tick();

    expect(gb->cpu->registers.PC, 0x102, "PC should be 0x102");
    expect(gb->cpu->registers.A, 0x80, "A should be 0x80");
    expect(gb->cpu->cycles, 8, "should take 8 cycles");
}

#pragma endregion
