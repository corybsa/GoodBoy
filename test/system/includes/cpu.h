#ifndef GOODBOY_TEST_CPU_H
#define GOODBOY_TEST_CPU_H

#include "../../../src/system/includes/gameboy.h"
#include "../../../src/system/includes/globals.h"
#include "test.h"

class CPUTest : public Test {
public:
    GameBoy* gb;

    CPUTest(GameBoy* gameBoy);

    void beforeAll();
    void beforeEach();

    void setFlags();
    void resetFlags();
    void complexFlagLogic();
    void manipulateRegisters();
    void nestedInterrupt();
};

#endif
