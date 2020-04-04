#ifndef GOODBOY_TIMERS_H
#define GOODBOY_TIMERS_H

#include "types.h"
#include "memory.h"

class Timers {
private:
    Memory* memory;

public:
    Timers(Memory* memory);

    void reset();
    void tick(int cycles);
};

#endif