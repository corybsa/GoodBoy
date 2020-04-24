#include "includes/memory.h"

MemoryTest::MemoryTest(GameBoy* gameBoy) {
    gb = gameBoy;

    Test::addTest([this]() -> void { romRange(); });
    Test::addTest([this]() -> void { vramRange(); });
    Test::addTest([this]() -> void { sramRange(); });
    Test::addTest([this]() -> void { wramRange(); });
    Test::addTest([this]() -> void { eramRange(); });
    Test::addTest([this]() -> void { oamRange(); });
    Test::addTest([this]() -> void { fea0_feffRange(); });
    Test::addTest([this]() -> void { ioRange(); });
    Test::addTest([this]() -> void { ff4c_ff7fRange(); });
    Test::addTest([this]() -> void { hramRange(); });
    Test::addTest([this]() -> void { ieRangeTest(); });
}

void MemoryTest::beforeAll() {
    printf("\nMemory Tests running...");
}

void MemoryTest::beforeEach() {

}

void MemoryTest::tearDown() {
    
}

void MemoryTest::romRange() {
    byte* rom = new byte[0x800000];
    rom[0x0000] = 0xBE;
    rom[0x7FFF] = 0xEF;

    gb->loadRom(rom);

    expect(gb->memory->readByte(0x0000), 0xBE, "The value at 0x0000 should be 0xBE.");
    expect(gb->memory->readByte(0x7FFF), 0xEF, "The value at 0x7FFF should be 0xEF.");

    delete[] rom;
}

void MemoryTest::vramRange() {
    gb->memory->writeByte(0x8000, 0xBE);
    gb->memory->writeByte(0x9FFF, 0xEF);

    expect(gb->memory->readByte(0x8000), 0xBE, "The value at 0x8000 should be 0xBE.");
    expect(gb->memory->readByte(0x9FFF), 0xEF, "The value at 0x9FFF should be 0xBE.");
}

void MemoryTest::sramRange() {
    gb->memory->writeByte(0xA000, 0xBE);
    gb->memory->writeByte(0xBFFF, 0xEF);

    expect(gb->memory->readByte(0xA000), 0xBE, "The value at 0x9000 should be 0xBE.");
    expect(gb->memory->readByte(0xBFFF), 0xEF, "The value at 0xBFFF should be 0xEF.");
}

void MemoryTest::wramRange() {
    gb->memory->writeByte(0xC000, 0xBE);
    gb->memory->writeByte(0xDFFF, 0xEF);

    expect(gb->memory->readByte(0xC000), 0xBE, "The value at 0xC000 should be 0xBE.");
    expect(gb->memory->readByte(0xDFFF), 0xEF, "The value at 0xDFFF should be 0xEF.");
}

void MemoryTest::eramRange() {
    gb->memory->writeByte(0xE000, 0xBE);
    gb->memory->writeByte(0xFDFF, 0xEF);

    expect(gb->memory->readByte(0xE000), 0xBE, "The value at 0xE000 should be 0xBE.");
    expect(gb->memory->readByte(0xFDFF), 0xEF, "The value at 0xFDFF should be 0xEF.");
}

void MemoryTest::oamRange() {
    gb->memory->writeByte(0xFE00, 0xBE);
    gb->memory->writeByte(0xFE9F, 0xEF);

    expect(gb->memory->readByte(0xFE00), 0xBE, "The value at 0xFE00 should be 0xBE.");
    expect(gb->memory->readByte(0xFE9F), 0xEF, "The value at 0xFE9F should be 0xEF.");
}

void MemoryTest::fea0_feffRange() {
    gb->memory->writeByte(0xFEA0, 0xBE);
    gb->memory->writeByte(0xFEFF, 0xEF);

    expect(gb->memory->readByte(0xFEA0), 0x00, "The value at 0xFEA0 should be 0x00.");
    expect(gb->memory->readByte(0xFEFF), 0x00, "The value at 0xFEFF should be 0x00.");
}

void MemoryTest::ioRange() {
    gb->memory->writeByte(0xFF00, 0xBE);
    gb->memory->writeByte(0xFF48, 0xEF);

    expect(gb->memory->readByte(0xFF00), 0xFE, "The value at 0xFF00 should be 0xFE.");
    expect(gb->memory->readByte(0xFF48), 0xEF, "The value at 0xFF48 should be 0xEF.");
}

void MemoryTest::ff4c_ff7fRange() {
    gb->memory->writeByte(0xFF4C, 0xBE);
    gb->memory->writeByte(0xFF7F, 0xEF);

    expect(gb->memory->readByte(0xFF4C), 0xFF, "The value at 0xFF4C should be 0xFF.");
    expect(gb->memory->readByte(0xFF7F), 0xFF, "The value at 0xFF7F should be 0xFF.");
}

void MemoryTest::hramRange() {
    gb->memory->writeByte(0xFF80, 0xBE);
    gb->memory->writeByte(0xFFFE, 0xEF);

    expect(gb->memory->readByte(0xFF80), 0xBE, "The value at 0xFF80 should be 0xBE.");
    expect(gb->memory->readByte(0xFFFE), 0xEF, "The value at 0xFFFE should be 0xEF.");
}

void MemoryTest::ieRangeTest() {
    gb->memory->writeByte(0xFFFF, 0xBE);

    expect(gb->memory->readByte(0xFFFF), 0xBE, "The value at 0xFFFF should be 0xBE.");
}
