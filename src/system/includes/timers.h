#ifndef GOODBOY_TIMERS_H
#define GOODBOY_TIMERS_H

#include "types.h"
#include "memory.h"

/**
 * Class for timer information
 *
 * For the TAC (Timer Control - 0xFF07) register, bit 2 determines if it is active or not and
 * bits 0 and 1 combine to determine the frequency:
 * 00:  4194304/4096 = 1024 clock cycles
 * 01:  4194304/262144 = 16 clock cycles
 * 10:  4194304/65536 =  64 clock cycles
 * 11:  4194304/16384 = 256 clock cycles
 */
class Timers {
private:
    Memory* memory;

public:
    Timers(Memory* memory);

    void reset();
    void tick(int cycles);
    int getFrequency(int freq);
    void incrementSystemCounter(int cycles);
};

#endif
