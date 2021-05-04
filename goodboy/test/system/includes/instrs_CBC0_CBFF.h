#ifndef GOODBOY_INSTRS_CBC0_CBFF_H
#define GOODBOY_INSTRS_CBC0_CBFF_H

#include "../../../system/includes/gameboy.h"
#include "../../../system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_CBC0_CBFF : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_CBC0_CBFF(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0xCBC0();
    void test_0xCBC1();
    void test_0xCBC2();
    void test_0xCBC3();
    void test_0xCBC4();
    void test_0xCBC5();
    void test_0xCBC6();
    void test_0xCBC7();
    void test_0xCBC8();
    void test_0xCBC9();
    void test_0xCBCA();
    void test_0xCBCB();
    void test_0xCBCC();
    void test_0xCBCD();
    void test_0xCBCE();
    void test_0xCBCF();

    void test_0xCBD0();
    void test_0xCBD1();
    void test_0xCBD2();
    void test_0xCBD3();
    void test_0xCBD4();
    void test_0xCBD5();
    void test_0xCBD6();
    void test_0xCBD7();
    void test_0xCBD8();
    void test_0xCBD9();
    void test_0xCBDA();
    void test_0xCBDB();
    void test_0xCBDC();
    void test_0xCBDD();
    void test_0xCBDE();
    void test_0xCBDF();

    void test_0xCBE0();
    void test_0xCBE1();
    void test_0xCBE2();
    void test_0xCBE3();
    void test_0xCBE4();
    void test_0xCBE5();
    void test_0xCBE6();
    void test_0xCBE7();
    void test_0xCBE8();
    void test_0xCBE9();
    void test_0xCBEA();
    void test_0xCBEB();
    void test_0xCBEC();
    void test_0xCBED();
    void test_0xCBEE();
    void test_0xCBEF();

    void test_0xCBF0();
    void test_0xCBF1();
    void test_0xCBF2();
    void test_0xCBF3();
    void test_0xCBF4();
    void test_0xCBF5();
    void test_0xCBF6();
    void test_0xCBF7();
    void test_0xCBF8();
    void test_0xCBF9();
    void test_0xCBFA();
    void test_0xCBFB();
    void test_0xCBFC();
    void test_0xCBFD();
    void test_0xCBFE();
    void test_0xCBFF();
};

#endif //GOODBOY_INSTRS_CBC0_CBFF_H
