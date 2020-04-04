#ifndef GOODBOY_GAMEBOY_H
#define GOODBOY_GAMEBOY_H

#include "types.h"
#include "memory.h"
#include "timers.h"
#include "cpu.h"
#include "gpu.h"
#include "lcd.h"

class GameBoy {
public:
    Memory* memory;
    CPU* cpu;
    GPU* gpu;
    LCD* lcd;
    Timers* timers;

    GameBoy();
    ~GameBoy();

    void reset();
};

#endif
