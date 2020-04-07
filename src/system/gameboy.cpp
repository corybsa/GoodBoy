#include "includes/gameboy.h"
#include "includes/types.h"

GameBoy::GameBoy() {
    memory = new Memory();
    timers = new Timers(memory);
    lcd = new LCD(memory);
    gpu = new GPU(memory, lcd);
    cpu = new CPU(memory, gpu, timers);

    memory->setGpuCallback([this](word address, byte byte1, byte byte2) -> void {
        gpu->updateTiles(address, byte1, byte2);
    });
}

GameBoy::~GameBoy() {
    delete memory;
    delete timers;
    delete lcd;
    delete gpu;
    delete cpu;
}

void GameBoy::reset() {
    cpu->reset();
    gpu->reset();
}

void GameBoy::loadRom(byte* rom) {
    reset();
    cartridge = new Cartridge(rom);
    memory->loadRom(rom);
    isCartLoaded = true;
    cartChanged = true;
}

void GameBoy::run() {
    if(cartChanged) {
        reset();
        cartChanged = false;
    }

    cpu->run();
}
