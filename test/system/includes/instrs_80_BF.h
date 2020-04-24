#ifndef GOODBOY_TEST_INSTRS_80_BF_H
#define GOODBOY_TEST_INSTRS_80_BF_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_80_BF : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_80_BF(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0x80();
    void test_0x81();
    void test_0x82();
    void test_0x83();
    void test_0x84();
    void test_0x85();
    void test_0x86();
    void test_0x87();
    void test_0x88();
    void test_0x89();
    void test_0x8A();
    void test_0x8B();
    void test_0x8C();
    void test_0x8D();
    void test_0x8E();
    void test_0x8F();

    void test_0x90();
    void test_0x91();
    void test_0x92();
    void test_0x93();
    void test_0x94();
    void test_0x95();
    void test_0x96();
    void test_0x97();
    void test_0x98();
    void test_0x99();
    void test_0x9A();
    void test_0x9B();
    void test_0x9C();
    void test_0x9D();
    void test_0x9E();
    void test_0x9F();

    void test_0xA0();
    void test_0xA1();
    void test_0xA2();
    void test_0xA3();
    void test_0xA4();
    void test_0xA5();
    void test_0xA6();
    void test_0xA7();
    void test_0xA8();
    void test_0xA9();
    void test_0xAA();
    void test_0xAB();
    void test_0xAC();
    void test_0xAD();
    void test_0xAE();
    void test_0xAF();

    void test_0xB0();
    void test_0xB1();
    void test_0xB2();
    void test_0xB3();
    void test_0xB4();
    void test_0xB5();
    void test_0xB6();
    void test_0xB7();
    void test_0xB8();
    void test_0xB9();
    void test_0xBA();
    void test_0xBB();
    void test_0xBC();
    void test_0xBD();
    void test_0xBE();
    void test_0xBF();
};

#endif
