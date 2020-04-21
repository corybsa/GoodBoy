#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <thread>

#include "system/util/includes/window.h"
#include "system/util/includes/debugWindow.h"
#include "system/includes/gameboy.h"

byte* openFile(char* name);

int main(int argc, char* args[]) {
    GameBoy* gb = new GameBoy();
    Window mainWindow;
    DebugWindow debugWindow(gb);
    bool success = true;

    byte* rom = openFile("./resources/roms/tests/mooneye/acceptance/instr/daa.gb");
    gb->loadRom(rom);

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
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

        debugWindow.init("Debugger", 600, 480);
    }

    if(!success) {
        printf("Failed to initialize!");
    } else {
        bool quit = false;
        SDL_Event e;
        std::thread gameThread([gb]() -> void {
            gb->run();
        });

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
                            if(mainWindow.isKeyboardFocused) {
                                quit = true;
                            }

                            // TODO: remove this when the debugger is done
                            quit = true;

                            break;
                        case SDLK_b:
                            debugWindow.askForBreakpoint();

                            break;
                        case SDLK_F12:
                            if(debugWindow.window == NULL) {
                                if(!debugWindow.init("Debugger", 600, 480)) {
                                    printf("Debug window could not be created!\n");
                                    quit = true;
                                }
                            }

                            break;
                    }
                }
            }

            // update windows
            mainWindow.render();

            if(debugWindow.window != NULL) {
                debugWindow.render();
            }

            // check windows
            bool allWindowsClosed = !mainWindow.isShown && !debugWindow.isShown;
            
            if(allWindowsClosed) {
                quit = true;
            }
        }

        gb->quit();
        gameThread.join();
    }
    
    delete[] rom;
    rom = NULL;

    delete gb;
    gb = NULL;
    
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
