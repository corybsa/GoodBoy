#include "gpu.h"
#include "globals.h"
#include <iostream>

GPU::GPU(Memory* memory, LCD* lcd) {
    this->memory = memory;
    this->lcd = lcd;
}

void GPU::reset() {

}

void GPU::tick(unsigned long cycles) {
    
}

void GPU::updateTiles(word address) {
    printf("%04X", address);
}
