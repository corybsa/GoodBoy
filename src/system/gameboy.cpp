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

    cartridge = NULL;
    memory = NULL;
    timers = NULL;
    lcd = NULL;
    gpu = NULL;
    cpu = NULL;
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
    cpu->tick();
}

void GameBoy::quit() {
    isRunning = false;
}

void GameBoy::tick() {
    cpu->tick();
}
