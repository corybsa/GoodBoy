#ifndef GOODBOY_TEST_INSTRS_80_BF_H
#define GOODBOY_TEST_INSTRS_80_BF_H

#include "../../../system/includes/gameboy.h"
#include "../../../system/includes/globals.h"
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

    void test_0x90_zero();
    void test_0x90_half();
    void test_0x90_carry();
    void test_0x91_zero();
    void test_0x91_half();
    void test_0x91_carry();
    void test_0x92_zero();
    void test_0x92_half();
    void test_0x92_carry();
    void test_0x93_zero();
    void test_0x93_half();
    void test_0x93_carry();
    void test_0x94_zero();
    void test_0x94_half();
    void test_0x94_carry();
    void test_0x95_zero();
    void test_0x95_half();
    void test_0x95_carry();
    void test_0x96_zero();
    void test_0x96_half();
    void test_0x96_carry();
    void test_0x97();
    void test_0x98();
    void test_0x98_zero();
    void test_0x98_half_carry();
    void test_0x99();
    void test_0x99_zero();
    void test_0x99_half_carry();
    void test_0x9A();
    void test_0x9A_zero();
    void test_0x9A_half_carry();
    void test_0x9B();
    void test_0x9B_zero();
    void test_0x9B_half_carry();
    void test_0x9C();
    void test_0x9C_zero();
    void test_0x9C_half_carry();
    void test_0x9D();
    void test_0x9D_zero();
    void test_0x9D_half_carry();
    void test_0x9E();
    void test_0x9E_zero();
    void test_0x9E_half_carry();
    void test_0x9F_zero();
    void test_0x9F_half_carry();

    void test_0xA0_half();
    void test_0xA0_zero_half();
    void test_0xA1_half();
    void test_0xA1_zero_half();
    void test_0xA2_half();
    void test_0xA2_zero_half();
    void test_0xA3_half();
    void test_0xA3_zero_half();
    void test_0xA4_half();
    void test_0xA4_zero_half();
    void test_0xA5_half();
    void test_0xA5_zero_half();
    void test_0xA6_half();
    void test_0xA6_zero_half();
    void test_0xA7_half();
    void test_0xA7_zero_half();
    void test_0xA8();
    void test_0xA8_zero();
    void test_0xA9();
    void test_0xA9_zero();
    void test_0xAA();
    void test_0xAA_zero();
    void test_0xAB();
    void test_0xAB_zero();
    void test_0xAC();
    void test_0xAC_zero();
    void test_0xAD();
    void test_0xAD_zero();
    void test_0xAE();
    void test_0xAE_zero();
    void test_0xAF();

    void test_0xB0();
    void test_0xB0_zero();
    void test_0xB1();
    void test_0xB1_zero();
    void test_0xB2();
    void test_0xB2_zero();
    void test_0xB3();
    void test_0xB3_zero();
    void test_0xB4();
    void test_0xB4_zero();
    void test_0xB5();
    void test_0xB5_zero();
    void test_0xB6();
    void test_0xB6_zero();
    void test_0xB7();
    void test_0xB7_zero();
    void test_0xB8_zero();
    void test_0xB8_half();
    void test_0xB8_carry();
    void test_0xB9_zero();
    void test_0xB9_half();
    void test_0xB9_carry();
    void test_0xBA_zero();
    void test_0xBA_half();
    void test_0xBA_carry();
    void test_0xBB_zero();
    void test_0xBB_half();
    void test_0xBB_carry();
    void test_0xBC_zero();
    void test_0xBC_half();
    void test_0xBC_carry();
    void test_0xBD_zero();
    void test_0xBD_half();
    void test_0xBD_carry();
    void test_0xBE_zero();
    void test_0xBE_half();
    void test_0xBE_carry();
    void test_0xBF();
};

#endif
