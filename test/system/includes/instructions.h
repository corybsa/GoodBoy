#ifndef GOODBOY_TEST_INSTRUCTIONS_H
#define GOODBOY_TEST_INSTRUCTIONS_H

#include "../../../src/system/includes/gameboy.h"
#include "instrs_00_3F.h"
#include "instrs_40_7F.h"
#include "instrs_80_BF.h"
#include "instrs_C0_FF.h"

class InstructionsTest {
public:
    GameBoy* gb;
    Instrs_00_3F* instrs_00_3F;
    Instrs_40_7F* instrs_40_7F;
    Instrs_80_BF* instrs_80_BF;
    Instrs_C0_FF* instrs_C0_FF;

    explicit InstructionsTest(GameBoy* gameBoy);

    void run() const;
};

#endif
