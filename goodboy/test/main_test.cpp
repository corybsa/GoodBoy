#include <iostream>
#include "../system/includes/gameboy.h"
#include "system/includes/cpu_test.h"
#include "system/includes/memory_test.h"
#include "system/includes/instructions.h"

int main_test() {
    auto* gb = new GameBoy();
    std::string results;

    CPUTest cpuTest(gb);
    cpuTest.run(&results);

    MemoryTest memoryTest(gb);
    memoryTest.run(&results);

    InstructionsTest instrTest(gb);
    instrTest.run(&results);
    std::cout << results << std::endl;

    delete gb;

    return 0;
}
