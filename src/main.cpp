#include <SDL2/SDL.h>
#include <iostream>

#include "system/gameboy.h"

int main(int argc, char* args[]) {
    GameBoy* gameboy = new GameBoy();

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;

    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        window = SDL_CreateWindow("GoodBoy", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 256, 256, SDL_WINDOW_SHOWN);

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
    SDL_Quit();



    // printf("A: %04X\n", gameboy->cpu->registers.A);
    // printf("F: %04X\n", gameboy->cpu->registers.F);
    // printf("AF: %04X\n", gameboy->cpu->registers.AF);

    // printf("B: %04X\n", gameboy->cpu->registers.B);
    // printf("C: %04X\n", gameboy->cpu->registers.C);
    // printf("BC: %04X\n", gameboy->cpu->registers.BC);

    // printf("D: %04X\n", gameboy->cpu->registers.D);
    // printf("E: %04X\n", gameboy->cpu->registers.E);
    // printf("DE: %04X\n", gameboy->cpu->registers.DE);

    // printf("H: %04X\n", gameboy->cpu->registers.H);
    // printf("L: %04X\n", gameboy->cpu->registers.L);
    // printf("HL: %04X\n", gameboy->cpu->registers.HL);

    // printf("SP: %04X\n", gameboy->cpu->registers.SP);
    // printf("PC: %04X\n", gameboy->cpu->registers.PC);
    
    delete gameboy;

    return 0;
}
