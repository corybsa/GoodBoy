#ifndef GOODBOY_TEST_INSTRS_C0_FF_H
#define GOODBOY_TEST_INSTRS_C0_FF_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_C0_FF : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_C0_FF(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0xC0();
    void test_0xC0_no_return();
    void test_0xC1();
    void test_0xC2();
    void test_0xC2_no_jump();
    void test_0xC3();
    void test_0xC4();
    void test_0xC4_no_call();
    void test_0xC5();
    void test_0xC6();
    void test_0xC7();
    void test_0xC8();
    void test_0xC8_no_return();
    void test_0xC9();
    void test_0xCA();
    void test_0xCA_no_jump();
    void test_0xCC();
    void test_0xCC_no_call();
    void test_0xCD();
    void test_0xCE();
    void test_0xCF();

    void test_0xD0();
    void test_0xD0_no_return();
    void test_0xD1();
    void test_0xD2();
    void test_0xD2_no_jump();
    void test_0xD3();
    void test_0xD4();
    void test_0xD4_no_call();
    void test_0xD5();
    void test_0xD6();
    void test_0xD7();
    void test_0xD8();
    void test_0xD8_no_return();
    void test_0xD9();
    void test_0xDA();
    void test_0xDA_no_jump();
    void test_0xDB();
    void test_0xDC();
    void test_0xDC_no_call();
    void test_0xDD();
    void test_0xDE();
    void test_0xDE_zero();
    void test_0xDE_half_carry();
    void test_0xDF();

    void test_0xE0();
    void test_0xE1();
    void test_0xE2();
    void test_0xE3();
    void test_0xE4();
    void test_0xE5();
    void test_0xE6_half();
    void test_0xE6_zero_half();
    void test_0xE7();
    void test_0xE8();
    void test_0xE8_negative();
    void test_0xE9();
    void test_0xEA();
    void test_0xEB();
    void test_0xEC();
    void test_0xED();
    void test_0xEE();
    void test_0xEE_zero();
    void test_0xEF();

    void test_0xF0();
    void test_0xF1();
    void test_0xF2();
    void test_0xF3();
    void test_0xF4();
    void test_0xF5();
    void test_0xF6();
    void test_0xF6_zero();
    void test_0xF7();
    void test_0xF8();
    void test_0xF9();
    void test_0xFA();
    void test_0xFB();
    void test_0xFC();
    void test_0xFD();
    void test_0xFE_zero();
    void test_0xFE_half();
    void test_0xFE_carry();
    void test_0xFF();
};

#endif
