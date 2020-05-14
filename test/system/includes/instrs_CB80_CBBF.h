#ifndef GOODBOY_INSTRS_CB80_CBBF_H
#define GOODBOY_INSTRS_CB80_CBBF_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_CB80_CBBF : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_CB80_CBBF(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0xCB80();
    void test_0xCB81();
    void test_0xCB82();
    void test_0xCB83();
    void test_0xCB84();
    void test_0xCB85();
    void test_0xCB86();
    void test_0xCB87();
    void test_0xCB88();
    void test_0xCB89();
    void test_0xCB8A();
    void test_0xCB8B();
    void test_0xCB8C();
    void test_0xCB8D();
    void test_0xCB8E();
    void test_0xCB8F();

    void test_0xCB90();
    void test_0xCB91();
    void test_0xCB92();
    void test_0xCB93();
    void test_0xCB94();
    void test_0xCB95();
    void test_0xCB96();
    void test_0xCB97();
    void test_0xCB98();
    void test_0xCB99();
    void test_0xCB9A();
    void test_0xCB9B();
    void test_0xCB9C();
    void test_0xCB9D();
    void test_0xCB9E();
    void test_0xCB9F();

    void test_0xCBA0();
    void test_0xCBA1();
    void test_0xCBA2();
    void test_0xCBA3();
    void test_0xCBA4();
    void test_0xCBA5();
    void test_0xCBA6();
    void test_0xCBA7();
    void test_0xCBA8();
    void test_0xCBA9();
    void test_0xCBAA();
    void test_0xCBAB();
    void test_0xCBAC();
    void test_0xCBAD();
    void test_0xCBAE();
    void test_0xCBAF();

    void test_0xCBB0();
    void test_0xCBB1();
    void test_0xCBB2();
    void test_0xCBB3();
    void test_0xCBB4();
    void test_0xCBB5();
    void test_0xCBB6();
    void test_0xCBB7();
    void test_0xCBB8();
    void test_0xCBB9();
    void test_0xCBBA();
    void test_0xCBBB();
    void test_0xCBBC();
    void test_0xCBBD();
    void test_0xCBBE();
    void test_0xCBBF();
};

#endif //GOODBOY_INSTRS_CB80_CBBF_H
