#ifndef GOODBOY_GPU_H
#define GOODBOY_GPU_H

#include "types.h"
#include "memory.h"
#include "lcd.h"
#include "constants.h"

class GPU {
private:
    Memory* memory;
    LCD* lcd;

public:
    int mode;
    int scanline = 0;
    unsigned long ticks = 0;
    unsigned long previousCycles = 0;
    byte tiles[384][8][8] = {};
    byte backgroundMap[BG_HEIGHT][BG_WIDTH][8] = {};
    int frames = 0;
    unsigned long long lastFrameTime = 0;

    GPU(Memory* memory, LCD* lcd);

    void reset();
    void tick(unsigned long cycles);
    void requestInterrupt(int interrupt);
    void changeMode(int mode);
    void updateTiles(word address, byte byte1, byte byte2);
};

#endif
