#ifndef GOODBOY_TEST_INSTRS_40_7F_H
#define GOODBOY_TEST_INSTRS_40_7F_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_40_7F : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_40_7F(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0x40();
    void test_0x41();
    void test_0x42();
    void test_0x43();
    void test_0x44();
    void test_0x45();
    void test_0x46();
    void test_0x47();
    void test_0x48();
    void test_0x49();
    void test_0x4A();
    void test_0x4B();
    void test_0x4C();
    void test_0x4D();
    void test_0x4E();
    void test_0x4F();

    void test_0x50();
    void test_0x51();
    void test_0x52();
    void test_0x53();
    void test_0x54();
    void test_0x55();
    void test_0x56();
    void test_0x57();
    void test_0x58();
    void test_0x59();
    void test_0x5A();
    void test_0x5B();
    void test_0x5C();
    void test_0x5D();
    void test_0x5E();
    void test_0x5F();

    void test_0x60();
    void test_0x61();
    void test_0x62();
    void test_0x63();
    void test_0x64();
    void test_0x65();
    void test_0x66();
    void test_0x67();
    void test_0x68();
    void test_0x69();
    void test_0x6A();
    void test_0x6B();
    void test_0x6C();
    void test_0x6D();
    void test_0x6E();
    void test_0x6F();

    void test_0x70();
    void test_0x71();
    void test_0x72();
    void test_0x73();
    void test_0x74();
    void test_0x75();
    void test_0x76();
    void test_0x77();
    void test_0x78();
    void test_0x79();
    void test_0x7A();
    void test_0x7B();
    void test_0x7C();
    void test_0x7D();
    void test_0x7E();
    void test_0x7F();
};

#endif
