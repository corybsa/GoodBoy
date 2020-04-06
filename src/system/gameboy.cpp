#include "includes/gameboy.h"
#include "includes/types.h"

GameBoy::GameBoy() {
    memory = new Memory();
    timers = new Timers(memory);
    lcd = new LCD(memory);
    gpu = new GPU(memory, lcd);
    cpu = new CPU(memory, gpu, timers);

    memory->setGpuCallback([this](word address) -> void {
        gpu->updateTiles(address);
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
