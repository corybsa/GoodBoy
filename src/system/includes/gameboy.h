#ifndef GOODBOY_GAMEBOY_H
#define GOODBOY_GAMEBOY_H

#include "types.h"
#include "memory.h"
#include "timers.h"
#include "cpu.h"
#include "gpu.h"
#include "lcd.h"
#include "cartridge.h"

class GameBoy {
public:
    Cartridge* cartridge;
    Memory* memory;
    CPU* cpu;
    GPU* gpu;
    LCD* lcd;
    Timers* timers;

    bool isCartLoaded = false;
    bool isCartChanged = false;
    bool isRunning = true;

    GameBoy();
    ~GameBoy();

    void reset();
    void loadRom(byte* rom);
    void run();
    void tick();
    void quit();
};

#endif
