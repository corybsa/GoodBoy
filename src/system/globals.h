#ifndef GOODBOY_GLOBALS_H
#define GOODBOY_GLOBALS_H

#include "types.h"
#include "constants.h"

// lcd
static int BG_PALETTET_DATA = 0x00;

// timer
static word SYSTEM_COUNTER = 0xABCC;
static int TIMA_COUNTER = 0;
static int TIMER_STATE = TIMER_STATE_COUNTING;

#endif
