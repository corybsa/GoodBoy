#ifndef GOODBOY_TEST_INSTRUCTIONS_H
#define GOODBOY_TEST_INSTRUCTIONS_H

#include "../../../src/system/includes/gameboy.h"
#include "instrs_00_3F.h"
#include "instrs_40_7F.h"
#include "instrs_80_BF.h"
#include "instrs_C0_FF.h"
#include "instrs_CB00_CB3F.h"
#include "instrs_CB40_CB7F.h"
#include "instrs_CB80_CBBF.h"
#include "instrs_CBC0_CBFF.h"

class InstructionsTest {
public:
    GameBoy* gb;
    Instrs_00_3F* instrs_00_3F;
    Instrs_40_7F* instrs_40_7F;
    Instrs_80_BF* instrs_80_BF;
    Instrs_C0_FF* instrs_C0_FF;

    Instrs_CB00_CB3F* instrs_CB00_CB3F;
    Instrs_CB40_CB7F* instrs_CB40_CB7F;
    Instrs_CB80_CBBF* instrs_CB80_CBBF;
    Instrs_CBC0_CBFF* instrs_CBC0_CBFF;

    explicit InstructionsTest(GameBoy* gameBoy);

    void run() const;
};

#endif
