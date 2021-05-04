#include "includes/timers.h"
#include "includes/globals.h"

Timers::Timers(Memory* memory) {
    this->memory = memory;
}

void Timers::reset() {
    TIMER_TIMA_COUNTER = 0;
    TIMER_SYSTEM_COUNTER = 0xABCC;
    TIMER_STATE = TIMER_STATE_COUNTING;
    TIMER_IS_TIMA_CHANGED = false;
    TIMER_IS_FLAGS_CHANGED = false;
    TIMER_FLAG_VALUE = 1;
    TIMER_TIMA_GLITCH = false;
}

int Timers::getFrequency(int freq) {
    switch(freq) {
        case 0b00:
            return TAC_CLOCK0;
        case 0b01:
            return TAC_CLOCK1;
        case 0b10:
            return TAC_CLOCK2;
        case 0b11:
            return TAC_CLOCK3;
    }
}

void Timers::tick(int cycles) {
    incrementSystemCounter(cycles);

    switch(TIMER_STATE) {
        case TIMER_STATE_COUNTING: {
            byte tac = memory->readIO(IO_TAC);
            bool isEnabled = (tac & 0x04) == 0x04;

            if(isEnabled) {
                TIMER_TIMA_COUNTER += cycles;
                int tacFreq = getFrequency(tac & 0x03);
                int tacClocks = CPU_FREQUENCY / tacFreq;

                // check if TIMA has passed the max amount of clocks
                if(TIMER_TIMA_COUNTER >= tacClocks) {
                    int result = memory->readIO(IO_TIMA) + 1;

                    if(result > 0xFF) {
                        // when TIMA overflows its value is 0 for 4 cycles and the interrupt is also delayed during this time
                        memory->writeIO(IO_TIMA, 0x00);

                        // keep track of the delay
                        TIMER_STATE = TIMER_STATE_OVERFLOW;
                    } else {
                        memory->writeIO(IO_TIMA, result);
                    }

                    TIMER_TIMA_COUNTER = TIMER_TIMA_COUNTER - tacClocks;
                }
            }

            break;
        }
        case TIMER_STATE_OVERFLOW: {
            // if a value is written to TIMA during the overflow period the new value will override the TMA load
            if(!TIMER_IS_TIMA_CHANGED) {
                // set TIMA to the value of TMA
                byte tma = memory->readIO(IO_TMA);
                memory->writeIO(IO_TIMA, tma);
            }

            TIMER_STATE = TIMER_STATE_LOADING_TMA;
            TIMER_IS_TIMA_CHANGED = false;
            TIMER_IS_FLAGS_CHANGED = false;

            break;
        }
        case TIMER_STATE_LOADING_TMA: {
            // If a value is written to TIMA during the period when TMA is being loaded, the write will be ignored.
            // There's another scenario to take into account. When TMA is written during this period, TIMA will also
            //   be loaded with that value. However, since the timer ticks after the CPU does TMA should already have
            //   the new value and TIMA will receive it without us doing anything.
            if(TIMER_IS_TIMA_CHANGED && !TIMER_TIMA_GLITCH) {
                // set TIMA to the value of TMA
                byte tma = memory->readIO(IO_TMA);
                memory->writeIO(IO_TIMA, tma);
            }

            // If IF is written during this period, the written value will overwrite the automatic flag set to 1.
            // If a 0 is written during this cycle, the interrupt won't happen.
            // The TIMA glitch prevents this from happening regardless of other conditions.
            if(TIMER_IS_FLAGS_CHANGED && TIMER_FLAG_VALUE == 1 && !TIMER_TIMA_GLITCH) {
                // request interrupt
                byte flags = memory->readIO(IO_INTERRUPT_FLAGS) | INTERRUPT_TIMER;
                memory->writeIO(IO_INTERRUPT_FLAGS, flags);
            }

            TIMER_IS_TIMA_CHANGED = false;
            TIMER_IS_FLAGS_CHANGED = false;
            TIMER_TIMA_GLITCH = false;
            TIMER_STATE = TIMER_STATE_COUNTING;

            break;
        }
    }
}

void Timers::incrementSystemCounter(int cycles) {
    int result = (TIMER_SYSTEM_COUNTER + cycles);

    if(result >= 0xFFFF) {
        TIMER_SYSTEM_COUNTER = 0;
    } else {
        TIMER_SYSTEM_COUNTER = result;
    }

    memory->updateDiv(TIMER_SYSTEM_COUNTER >> 8);
}
