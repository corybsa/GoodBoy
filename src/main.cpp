#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <array>

#include "system/includes/gameboy.h"

byte* openFile();

int main(int argc, char* args[]) {
    /* SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("GoodBoy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, LCD_WIDTH, LCD_HEIGHT, SDL_WINDOW_SHOWN);

        if(window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit(); */

    byte* rom = openFile();

    GameBoy* gb = new GameBoy();
    gb->loadRom(rom);
    std::cout << gb->cartridge->toString();
    
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

    return 0;
}

byte* openFile() {
    std::ifstream file("./resources/roms/tests/mooneye/acceptance/instr/daa.gb");
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
