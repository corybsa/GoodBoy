#ifndef GOODBOY_TEST_MEMORY_H
#define GOODBOY_TEST_MEMORY_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"

class MemoryTest : public Test {
public:
    GameBoy* gb;

    explicit MemoryTest(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void romRange();
    void vramRange();
    void sramRange();
    void wramRange();
    void eramRange();
    void oamRange();
    void fea0_feffRange();
    void ioRange();
    void ff4c_ff7fRange();
    void hramRange();
    void ieRangeTest();

    // TODO: test bank switching
};

#endif
