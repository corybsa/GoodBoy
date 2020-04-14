#ifndef GOODBOY_TEST_INSTRUCTIONS_H
#define GOODBOY_TEST_INSTRUCTIONS_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"
#include <vector>

class InstructionsTest : public Test {
public:
    GameBoy* gb;
    byte* rom;

    InstructionsTest(GameBoy *gameBoy);

    void beforeAll();
    void beforeEach();
    void tearDown();

    void loadRom(std::vector<byte> bytes);

    void test_0x00();
    void test_0x01();
    void test_0x02();
    void test_0x03();
    void test_0x04();
    void test_0x04_half();
    void test_0x04_zero_half();
    void test_0x05();
    void test_0x05_zero_sub();
    void test_0x05_sub_half();
    void test_0x05_sub_half2();
    void test_0x06();
    void test_0x07();
    void test_0x08();
    void test_0x09_half();
    void test_0x09_carry();
    void test_0x0A();
    void test_0x0B();
    void test_0x0C();
    void test_0x0C_half();
    void test_0x0C_zero_half();
    void test_0x0D();
    void test_0x0D_zero();
    void test_0x0D_half();
    void test_0x0D_half2();
    void test_0x0E();
    void test_0x0F();
    void test_0x0F_clear_carry();

    void test_0x10();
    void test_0x11();
    void test_0x12();
    void test_0x13();
    void test_0x14();
    void test_0x14_half();
    void test_0x14_zero_half();
    void test_0x15();
    void test_0x15_zero();
    void test_0x15_half();
    void test_0x15_half2();
    void test_0x16();
    void test_0x17();
    void test_0x18();
    void test_0x18_backwards();
    void test_0x19();
    void test_0x1A();
    void test_0x1B();
    void test_0x1C();
    void test_0x1C_half();
    void test_0x1C_zero_half();
    void test_0x1D();
    void test_0x1D_zero();
    void test_0x1D_half();
    void test_0x1D_half2();
    void test_0x1E();
    void test_0x1F();

    void test_0x20();
    void test_0x21();
    void test_0x22();
    void test_0x23();
    void test_0x24();
    void test_0x25();
    void test_0x26();
    void test_0x27();
    void test_0x28();
    void test_0x29();
    void test_0x2A();
    void test_0x2B();
    void test_0x2C();
    void test_0x2D();
    void test_0x2E();
    void test_0x2F();

    void test_0x30();
    void test_0x31();
    void test_0x32();
    void test_0x33();
    void test_0x34();
    void test_0x35();
    void test_0x36();
    void test_0x37();
    void test_0x38();
    void test_0x39();
    void test_0x3A();
    void test_0x3B();
    void test_0x3C();
    void test_0x3D();
    void test_0x3E();
    void test_0x3F();
};

#endif
