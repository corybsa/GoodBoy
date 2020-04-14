#include <iostream>
#include "../src/system/includes/gameboy.h"
#include "system/includes/cpu.h"
#include "system/includes/memory.h"
#include "system/includes/instructions.h"

int main(int argc, char* args[]) {
    GameBoy* gb = new GameBoy();

    CPUTest cpuTest(gb);
    cpuTest.run();

    MemoryTest memoryTest(gb);
    memoryTest.run();

    InstructionsTest instrTest(gb);
    instrTest.run();

    delete gb;
    gb = NULL;

    return 0;
}
