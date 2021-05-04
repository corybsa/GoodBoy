#ifndef GOODBOY_INSTRS_CB00_CB3F_H
#define GOODBOY_INSTRS_CB00_CB3F_H

#include "../../../system/includes/gameboy.h"
#include "../../../system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_CB00_CB3F : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_CB00_CB3F(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0xCB00_zero();
    void test_0xCB00_carry();
    void test_0xCB01_zero();
    void test_0xCB01_carry();
    void test_0xCB02_zero();
    void test_0xCB02_carry();
    void test_0xCB03_zero();
    void test_0xCB03_carry();
    void test_0xCB04_zero();
    void test_0xCB04_carry();
    void test_0xCB05_zero();
    void test_0xCB05_carry();
    void test_0xCB06_zero();
    void test_0xCB06_carry();
    void test_0xCB07_zero();
    void test_0xCB07_carry();
    void test_0xCB08_zero();
    void test_0xCB08_carry();
    void test_0xCB09_zero();
    void test_0xCB09_carry();
    void test_0xCB0A_zero();
    void test_0xCB0A_carry();
    void test_0xCB0B_zero();
    void test_0xCB0B_carry();
    void test_0xCB0C_zero();
    void test_0xCB0C_carry();
    void test_0xCB0D_zero();
    void test_0xCB0D_carry();
    void test_0xCB0E_zero();
    void test_0xCB0E_carry();
    void test_0xCB0F_zero();
    void test_0xCB0F_carry();

    void test_0xCB10();
    void test_0xCB10_zero_carry();
    void test_0xCB11();
    void test_0xCB11_zero_carry();
    void test_0xCB12();
    void test_0xCB12_zero_carry();
    void test_0xCB13();
    void test_0xCB13_zero_carry();
    void test_0xCB14();
    void test_0xCB14_zero_carry();
    void test_0xCB15();
    void test_0xCB15_zero_carry();
    void test_0xCB16();
    void test_0xCB16_zero_carry();
    void test_0xCB17();
    void test_0xCB17_zero_carry();
    void test_0xCB18();
    void test_0xCB18_zero_carry();
    void test_0xCB19();
    void test_0xCB19_zero_carry();
    void test_0xCB1A();
    void test_0xCB1A_zero_carry();
    void test_0xCB1B();
    void test_0xCB1B_zero_carry();
    void test_0xCB1C();
    void test_0xCB1C_zero_carry();
    void test_0xCB1D();
    void test_0xCB1D_zero_carry();
    void test_0xCB1E();
    void test_0xCB1E_zero_carry();
    void test_0xCB1F();
    void test_0xCB1F_zero_carry();

    void test_0xCB20_carry();
    void test_0xCB20_zero_carry();
    void test_0xCB21_carry();
    void test_0xCB21_zero_carry();
    void test_0xCB22_carry();
    void test_0xCB22_zero_carry();
    void test_0xCB23_carry();
    void test_0xCB23_zero_carry();
    void test_0xCB24_carry();
    void test_0xCB24_zero_carry();
    void test_0xCB25_carry();
    void test_0xCB25_zero_carry();
    void test_0xCB26_carry();
    void test_0xCB26_zero_carry();
    void test_0xCB27_carry();
    void test_0xCB27_zero_carry();
    void test_0xCB28();
    void test_0xCB28_zero_carry();
    void test_0xCB29();
    void test_0xCB29_zero_carry();
    void test_0xCB2A();
    void test_0xCB2A_zero_carry();
    void test_0xCB2B();
    void test_0xCB2B_zero_carry();
    void test_0xCB2C();
    void test_0xCB2C_zero_carry();
    void test_0xCB2D();
    void test_0xCB2D_zero_carry();
    void test_0xCB2E();
    void test_0xCB2E_zero_carry();
    void test_0xCB2F();
    void test_0xCB2F_zero_carry();

    void test_0xCB30();
    void test_0xCB30_zero();
    void test_0xCB31();
    void test_0xCB31_zero();
    void test_0xCB32();
    void test_0xCB32_zero();
    void test_0xCB33();
    void test_0xCB33_zero();
    void test_0xCB34();
    void test_0xCB34_zero();
    void test_0xCB35();
    void test_0xCB35_zero();
    void test_0xCB36();
    void test_0xCB36_zero();
    void test_0xCB37();
    void test_0xCB37_zero();
    void test_0xCB38_carry();
    void test_0xCB38_zero_carry();
    void test_0xCB39_carry();
    void test_0xCB39_zero_carry();
    void test_0xCB3A_carry();
    void test_0xCB3A_zero_carry();
    void test_0xCB3B_carry();
    void test_0xCB3B_zero_carry();
    void test_0xCB3C_carry();
    void test_0xCB3C_zero_carry();
    void test_0xCB3D_carry();
    void test_0xCB3D_zero_carry();
    void test_0xCB3E_carry();
    void test_0xCB3E_zero_carry();
    void test_0xCB3F_carry();
    void test_0xCB3F_zero_carry();
};

#endif //GOODBOY_INSTRS_CB00_CB3F_H
