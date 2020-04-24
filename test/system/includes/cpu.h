#ifndef GOODBOY_TEST_CPU_H
#define GOODBOY_TEST_CPU_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"

class CPUTest : public Test {
public:
    GameBoy* gb;

    explicit CPUTest(GameBoy* gameBoy);

    void beforeAll() override;
    void beforeEach() override;
    void tearDown() override;

    void setFlags();
    void resetFlags();
    void complexFlagLogic();
    void manipulateRegisters();
    void nestedInterrupt();
};

#endif
