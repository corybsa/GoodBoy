#include "includes/instructions.h"
#include <algorithm>

InstructionsTest::InstructionsTest(GameBoy* gameBoy) {
    gb = gameBoy;
    instrs_00_3F = new Instrs_00_3F(gb);
    instrs_40_7F = new Instrs_40_7F(gb);
    instrs_80_BF = new Instrs_80_BF(gb);
    instrs_C0_FF = new Instrs_C0_FF(gb);
    instrs_CB00_CB3F = new Instrs_CB00_CB3F(gb);
    instrs_CB40_CB7F = new Instrs_CB40_CB7F(gb);
    instrs_CB80_CBBF = new Instrs_CB80_CBBF(gb);
    instrs_CBC0_CBFF = new Instrs_CBC0_CBFF(gb);
}

void InstructionsTest::run() const {
    printf("\nInstruction Tests running...");
    instrs_00_3F->run();
    instrs_40_7F->run();
    instrs_80_BF->run();
    instrs_C0_FF->run();
    instrs_CB00_CB3F->run();
    instrs_CB40_CB7F->run();
    instrs_CB80_CBBF->run();
    instrs_CBC0_CBFF->run();
}
