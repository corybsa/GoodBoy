#ifndef GOODBOY_INSTRS_CB40_CB7F_H
#define GOODBOY_INSTRS_CB40_CB7F_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"
#include <vector>

class Instrs_CB40_CB7F : public Test {
public:
    GameBoy* gb;
    byte* rom;

    explicit Instrs_CB40_CB7F(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void loadRom(std::vector<byte> bytes) const;

    void test_0xCB40();
    void test_0xCB41();
    void test_0xCB42();
    void test_0xCB43();
    void test_0xCB44();
    void test_0xCB45();
    void test_0xCB46();
    void test_0xCB47();
    void test_0xCB48();
    void test_0xCB49();
    void test_0xCB4A();
    void test_0xCB4B();
    void test_0xCB4C();
    void test_0xCB4D();
    void test_0xCB4E();
    void test_0xCB4F();

    void test_0xCB50();
    void test_0xCB51();
    void test_0xCB52();
    void test_0xCB53();
    void test_0xCB54();
    void test_0xCB55();
    void test_0xCB56();
    void test_0xCB57();
    void test_0xCB58();
    void test_0xCB59();
    void test_0xCB5A();
    void test_0xCB5B();
    void test_0xCB5C();
    void test_0xCB5D();
    void test_0xCB5E();
    void test_0xCB5F();

    void test_0xCB60();
    void test_0xCB61();
    void test_0xCB62();
    void test_0xCB63();
    void test_0xCB64();
    void test_0xCB65();
    void test_0xCB66();
    void test_0xCB67();
    void test_0xCB68();
    void test_0xCB69();
    void test_0xCB6A();
    void test_0xCB6B();
    void test_0xCB6C();
    void test_0xCB6D();
    void test_0xCB6E();
    void test_0xCB6F();

    void test_0xCB70();
    void test_0xCB71();
    void test_0xCB72();
    void test_0xCB73();
    void test_0xCB74();
    void test_0xCB75();
    void test_0xCB76();
    void test_0xCB77();
    void test_0xCB78();
    void test_0xCB79();
    void test_0xCB7A();
    void test_0xCB7B();
    void test_0xCB7C();
    void test_0xCB7D();
    void test_0xCB7E();
    void test_0xCB7F();
};

#endif //GOODBOY_INSTRS_CB00_CB3F_H
