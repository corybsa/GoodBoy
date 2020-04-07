#ifndef GOODBOY_LCD_H
#define GOODBOY_LCD_H

#include "types.h"
#include "memory.h"
#include "globals.h"

class LCD {
private:
    Memory* memory;

public:
    LCD(Memory* memory);

    void render(byte backgroundMap[BG_HEIGHT][BG_WIDTH][8]);
};

#endif
