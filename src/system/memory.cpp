#include "includes/memory.h"
#include "includes/globals.h"

#include <iostream>

Memory::Memory() {
    
}

byte Memory::getByteAt(word address) {
    return 0;
}

void Memory::setByteAt(word address, byte value) {

    if(address <= 0x7FFF) {

    } else if(address <= 0x9FFF) {
        gpuCallback(address);
    }
}

void Memory::setGpuCallback(std::function<void(word)> arg2) {
    gpuCallback = arg2;
}
