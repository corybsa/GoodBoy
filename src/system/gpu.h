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
    GPU(Memory* memory, LCD* lcd);

    void reset();
    void tick(unsigned long cycles);
    void updateTiles(word address);
};

#endif
