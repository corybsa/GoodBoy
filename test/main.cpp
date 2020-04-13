#include <iostream>
#include "../src/system/includes/gameboy.h"
#include "system/includes/cpu.h"

int main(int argc, char* args[]) {
    GameBoy* gb = new GameBoy();

    CPUTest cpuTest(gb);
    cpuTest.run();

    delete gb;

    return 0;
}
