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
    delete cartridge;
    delete memory;
    delete timers;
    delete lcd;
    delete gpu;
    delete cpu;

    cartridge = nullptr;
    memory = nullptr;
    timers = nullptr;
    lcd = nullptr;
    gpu = nullptr;
    cpu = nullptr;
}

void GameBoy::reset() {
    cpu->reset();
    gpu->reset();
}

void GameBoy::loadRom(byte* rom) {
    reset();
    cartridge = new Cartridge(rom);
    memory->loadRom(cartridge->rom);
    isCartLoaded = true;
    isCartChanged = true;
}

void GameBoy::run() {
    while(isRunning) {
        if(isCartChanged) {
            reset();
            isCartChanged = false;
        }

        cpu->tick();
        gpu->tick(cpu->cycles);
    }
}

void GameBoy::tick() {
    if(!isCartLoaded) {
        return;
    }

    cpu->tick();
    gpu->tick(cpu->cycles);
}

void GameBoy::quit() {
    isRunning = false;
}
