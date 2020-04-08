#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>

#include "system/util/includes/window.h"
#include "system/includes/gameboy.h"

byte* openFile(char* name);

int main(int argc, char* args[]) {
    Window mainWindow;
    Window debugWindow;
    bool success = true;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    } else {
        if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            printf("Warning: Linear texture filtering not enabled!");
        }

        if(!mainWindow.init("GoodBoy", LCD_WIDTH * 2, LCD_HEIGHT * 2)) {
            printf("Main window could not be created!\n");
            success = false;
        }
    }

    if(!success) {
        printf("Failed to initialize!");
    } else {
        debugWindow.init("Debugger", 600, 480);

        bool quit = false;

        SDL_Event e;

        while(!quit) {

            // handle events on queue
            while(SDL_PollEvent(&e) != 0) {

                // user requests quit
                if(e.type == SDL_QUIT) {
                    quit = true;
                    break;
                }

                mainWindow.handleEvent(e);
                debugWindow.handleEvent(e);

                if(e.type == SDL_KEYDOWN) {
                    switch(e.key.keysym.sym) {
                        case SDLK_q:
                            quit = true;
                    }
                }
            }

            // update windows
            mainWindow.render();
            debugWindow.render();

            // check windows
            bool allWindowsClosed = !mainWindow.isShown && !debugWindow.isShown;
            
            if(allWindowsClosed) {
                quit = true;
            }
        }
    }

    // byte* rom = openFile("./resources/roms/tests/mooneye/acceptance/instr/daa.gb");
    byte* rom = openFile("./resources/roms/tests/blargg/cpu_instrs/cpu_instrs.gb");

    GameBoy* gb = new GameBoy();
    gb->loadRom(rom);
    std::cout << gb->cartridge->toString();
    // gb->run();
    
    // gb->loadRom(rom);
    // printf("%s", gb->cartridge->toString());

    /* printf("A: %04X\n", gb->cpu->registers.A);
    printf("F: %04X\n", gb->cpu->registers.F);
    printf("AF: %04X\n", gb->cpu->registers.AF);

    printf("B: %04X\n", gb->cpu->registers.B);
    printf("C: %04X\n", gb->cpu->registers.C);
    printf("BC: %04X\n", gb->cpu->registers.BC);

    printf("D: %04X\n", gb->cpu->registers.D);
    printf("E: %04X\n", gb->cpu->registers.E);
    printf("DE: %04X\n", gb->cpu->registers.DE);

    printf("H: %04X\n", gb->cpu->registers.H);
    printf("L: %04X\n", gb->cpu->registers.L);
    printf("HL: %04X\n", gb->cpu->registers.HL);

    printf("SP: %04X\n", gb->cpu->registers.SP);
    printf("PC: %04X\n", gb->cpu->registers.PC); */
    
    delete gb;
    mainWindow.free();
    debugWindow.free();
    SDL_Quit();

    return 0;
}

byte* openFile(char* name) {
    std::ifstream file(name);
    file.seekg(0, std::ios::end);
    size_t length = file.tellg();
    char* ret = new char[length];
    file.seekg(0, std::ios::beg);
    file.read(ret, length);
    file.close();

    byte* rom = new byte[0x800000];

    for(int i = 0; i < length; i++) {
        rom[i] = (byte)ret[i];
    }

    return rom;
}
