#ifndef GOODBOY_LCD_H
#define GOODBOY_LCD_H

#include "types.h"
#include "memory.h"

class LCD {
private:
    Memory* memory;

public:
    LCD(Memory* memory);
};

#endif
