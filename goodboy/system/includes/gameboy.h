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
    Timers* timers;
    CPU* cpu;
    GPU* gpu;
    LCD* lcd;

    bool isCartLoaded = false;
    bool isCartChanged = false;
    bool isRunning = true;

    std::vector<word> breakpoints;
    std::vector<word> memoryWatchList;

    GameBoy();
    ~GameBoy();

    void reset() const;
    void loadRom(byte* rom);
    void run();
    void pause();
    void tick() const;
    void addBreakpoint(word pc);
    void removeBreakpoint(word pc);
    void addMemoryWatch(word addr);
    void removeMemoryWatch(word addr);
    void quit();
};

#endif
