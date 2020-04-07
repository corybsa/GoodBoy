#ifndef GOODBOY_GLOBALS_H
#define GOODBOY_GLOBALS_H

#include "types.h"
#include "constants.h"

// lcd
static int BG_PALETTE_DATA = 0x00;

// timer
// The DIV counter is part of a 16 bit system counter, with DIV being the upper 8 bits. The default for the system clock is 0xABCC.
static word TIMER_SYSTEM_COUNTER = 0xABCC;
static int TIMER_TIMA_COUNTER = 0;
static int TIMER_STATE = TIMER_STATE_COUNTING;
static bool TIMER_IS_TIMA_CHANGED = false;
static bool TIMER_IS_FLAGS_CHANGED = false;
static int TIMER_FLAG_VALUE = 1;
static bool TIMER_TIMA_GLITCH = false;

#endif
