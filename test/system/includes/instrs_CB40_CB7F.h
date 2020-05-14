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

    void test_0xCB40_half();
    void test_0xCB40_half_zero();
    void test_0xCB41_half();
    void test_0xCB41_half_zero();
    void test_0xCB42_half();
    void test_0xCB42_half_zero();
    void test_0xCB43_half();
    void test_0xCB43_half_zero();
    void test_0xCB44_half();
    void test_0xCB44_half_zero();
    void test_0xCB45_half();
    void test_0xCB45_half_zero();
    void test_0xCB46_half();
    void test_0xCB46_half_zero();
    void test_0xCB47_half();
    void test_0xCB47_half_zero();
    void test_0xCB48_half();
    void test_0xCB48_half_zero();
    void test_0xCB49_half();
    void test_0xCB49_half_zero();
    void test_0xCB4A_half();
    void test_0xCB4A_half_zero();
    void test_0xCB4B_half();
    void test_0xCB4B_half_zero();
    void test_0xCB4C_half();
    void test_0xCB4C_half_zero();
    void test_0xCB4D_half();
    void test_0xCB4D_half_zero();
    void test_0xCB4E_half();
    void test_0xCB4E_half_zero();
    void test_0xCB4F_half();
    void test_0xCB4F_half_zero();

    void test_0xCB50_half();
    void test_0xCB50_half_zero();
    void test_0xCB51_half();
    void test_0xCB51_half_zero();
    void test_0xCB52_half();
    void test_0xCB52_half_zero();
    void test_0xCB53_half();
    void test_0xCB53_half_zero();
    void test_0xCB54_half();
    void test_0xCB54_half_zero();
    void test_0xCB55_half();
    void test_0xCB55_half_zero();
    void test_0xCB56_half();
    void test_0xCB56_half_zero();
    void test_0xCB57_half();
    void test_0xCB57_half_zero();
    void test_0xCB58_half();
    void test_0xCB58_half_zero();
    void test_0xCB59_half();
    void test_0xCB59_half_zero();
    void test_0xCB5A_half();
    void test_0xCB5A_half_zero();
    void test_0xCB5B_half();
    void test_0xCB5B_half_zero();
    void test_0xCB5C_half();
    void test_0xCB5C_half_zero();
    void test_0xCB5D_half();
    void test_0xCB5D_half_zero();
    void test_0xCB5E_half();
    void test_0xCB5E_half_zero();
    void test_0xCB5F_half();
    void test_0xCB5F_half_zero();

    void test_0xCB60_half();
    void test_0xCB60_half_zero();
    void test_0xCB61_half();
    void test_0xCB61_half_zero();
    void test_0xCB62_half();
    void test_0xCB62_half_zero();
    void test_0xCB63_half();
    void test_0xCB63_half_zero();
    void test_0xCB64_half();
    void test_0xCB64_half_zero();
    void test_0xCB65_half();
    void test_0xCB65_half_zero();
    void test_0xCB66_half();
    void test_0xCB66_half_zero();
    void test_0xCB67_half();
    void test_0xCB67_half_zero();
    void test_0xCB68_half();
    void test_0xCB68_half_zero();
    void test_0xCB69_half();
    void test_0xCB69_half_zero();
    void test_0xCB6A_half();
    void test_0xCB6A_half_zero();
    void test_0xCB6B_half();
    void test_0xCB6B_half_zero();
    void test_0xCB6C_half();
    void test_0xCB6C_half_zero();
    void test_0xCB6D_half();
    void test_0xCB6D_half_zero();
    void test_0xCB6E_half();
    void test_0xCB6E_half_zero();
    void test_0xCB6F_half();
    void test_0xCB6F_half_zero();

    void test_0xCB70_half();
    void test_0xCB70_half_zero();
    void test_0xCB71_half();
    void test_0xCB71_half_zero();
    void test_0xCB72_half();
    void test_0xCB72_half_zero();
    void test_0xCB73_half();
    void test_0xCB73_half_zero();
    void test_0xCB74_half();
    void test_0xCB74_half_zero();
    void test_0xCB75_half();
    void test_0xCB75_half_zero();
    void test_0xCB76_half();
    void test_0xCB76_half_zero();
    void test_0xCB77_half();
    void test_0xCB77_half_zero();
    void test_0xCB78_half();
    void test_0xCB78_half_zero();
    void test_0xCB79_half();
    void test_0xCB79_half_zero();
    void test_0xCB7A_half();
    void test_0xCB7A_half_zero();
    void test_0xCB7B_half();
    void test_0xCB7B_half_zero();
    void test_0xCB7C_half();
    void test_0xCB7C_half_zero();
    void test_0xCB7D_half();
    void test_0xCB7D_half_zero();
    void test_0xCB7E_half();
    void test_0xCB7E_half_zero();
    void test_0xCB7F_half();
    void test_0xCB7F_half_zero();
};

#endif //GOODBOY_INSTRS_CB40_CB7F_H
