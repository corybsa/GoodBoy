#include <algorithm>

#include "includes/gameboy.h"
#include "includes/types.h"

GameBoy::GameBoy() {
    memory = new Memory();
    timers = new Timers(memory);
    lcd = new LCD(memory);
    gpu = new GPU(memory, lcd);
    cpu = new CPU(memory, gpu, timers);
    cartridge = new Cartridge();

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

void GameBoy::reset() const {
    cpu->reset();
    gpu->reset();
}

void GameBoy::loadRom(byte* rom) {
    // TODO: memory leak when loading roms
    reset();
    cartridge->changeCartridge(rom);
    memory->loadRom(cartridge->rom);
    isCartLoaded = true;
    isCartChanged = true;
}

void GameBoy::run() {
    isRunning = true;

    while(isRunning) {
        if(isCartChanged) {
            reset();
            isCartChanged = false;
        }

        cpu->tick();
        gpu->tick(cpu->cycles);

        for (auto it : breakpoints) {
            if (it == cpu->registers.PC) {
                isRunning = false;
            }
        }
    }
}

void GameBoy::pause() {
    isRunning = false;
}

void GameBoy::tick() const {
    if(!isCartLoaded) {
        return;
    }

    cpu->tick();
    gpu->tick(cpu->cycles);
}

void GameBoy::addBreakpoint(word pc) {
    bool alreadyWatching = false;

    for (auto it : breakpoints) {
        if (it == pc) {
            alreadyWatching = true;
        }
    }

    if (!alreadyWatching) {
        breakpoints.push_back(pc);
    }

    std::sort(breakpoints.begin(), breakpoints.end(), [](int i, int j) { return i < j; });
}

void GameBoy::removeBreakpoint(word pc) {
    breakpoints.erase(std::remove(breakpoints.begin(), breakpoints.end(), pc), breakpoints.end());
}

void GameBoy::addMemoryWatch(word addr) {
    bool alreadyWatching = false;

    for (auto it : memoryWatchList) {
        if (it == addr) {
            alreadyWatching = true;
        }
    }

    if (!alreadyWatching) {
        memoryWatchList.push_back(addr);
    }
}

void GameBoy::removeMemoryWatch(word addr) {
    memoryWatchList.erase(std::remove(memoryWatchList.begin(), memoryWatchList.end(), addr), memoryWatchList.end());
}

void GameBoy::quit() {
    isRunning = false;
}
