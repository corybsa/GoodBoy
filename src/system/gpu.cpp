#include "includes/gpu.h"
#include "includes/globals.h"
#include <iostream>

GPU::GPU(Memory* memory, LCD* lcd) {
    this->memory = memory;
    this->lcd = lcd;
    mode = GPU_MODE_HBLANK;
}

void GPU::reset() {
    mode = GPU_MODE_HBLANK;
    scanline = 0;
    ticks = 0;
    previousCycles = 0;
    // setLY(0);
}

void GPU::tick(unsigned long cycles) {
    /* ticks += cycles - previousCycles;
    previousCycles = cycles;

    switch(mode) {
        case GPU_MODE_HBLANK:
            if(ticks >= GPU_TIMING_HBLANK) {
                lcd->render(backgroundMap);
                scanline++;

                if(scanline == VBLANK_START) {
                    changeMode(GPU_MODE_VBLANK);
                } else {
                    changeMode(GPU_MODE_OAM);
                }

                ticks -= GPU_TIMING_HBLANK;
                setLY(scanline);
            }

            break;
        case GPU_MODE_VBLANK:
            if(ticks >= GPU_TIMING_VBLANK) {
                scanline++;

                if(scanline > VBLANK_END) {
                    scanline = 0;
                    changeMode(GPU_MODE_OAM);
                }

                ticks -= GPU_TIMING_VBLANK;
                setLY(scanline);
            }

            break;
        case GPU_MODE_OAM:
            if(ticks >= GPU_TIMING_OAM) {
                changeMode(GPU_MODE_VRAM);
                ticks -= GPU_TIMING_OAM;
            }

            break;
        case GPU_MODE_VRAM:
            if(ticks >= GPU_TIMING_VRAM) {
                changeMode(GPU_MODE_HBLANK);
                ticks -= GPU_TIMING_VRAM;
            }

            break;
    } */
}

void GPU::updateTiles(word address, byte byte1, byte byte2) {
    /* if(address >= 0x1800) {
        // updateBackgroundMap();
    }

    int tileIndex = address / 16;
    int rowIndex = (address % 16) / 2;
    int pixelIndex = 0;
    int pixelValue;

    for(; pixelIndex < 8; pixelIndex++) {
        int mask = 1 << (7 - pixelIndex);
        int msb = (byte1 & mask) >> (7 - pixelIndex);
        int lsb = (byte2 & mask) >> (7 - pixelIndex);
        pixelValue = (lsb << 1) | msb;

        // if(lsb == 1 && msb == 1) {
        //     pixelValue = PIXEL_BLACK; // 11
        // } else if(lsb == 1 && msb == 0) {
        //     pixelValue = PIXEL_DARK_GRAY; // 10
        // } else if(lsb == 0 && msb == 1) {
        //     pixelValue = PIXEL_LIGHT_GRAY; // 01
        // } else {
        //     pixelValue = PIXEL_WHITE; // 00
        // }

        tiles[tileIndex][rowIndex][pixelIndex] = pixelValue;
    } */
}
