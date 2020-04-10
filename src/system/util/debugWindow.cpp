#include "includes/debugWindow.h"
#include "includes/texture.h"
#include <iostream>
#include <string>

DebugWindow::DebugWindow(GameBoy* gameBoy) {
    gb = gameBoy;
}

bool DebugWindow::init(char* title, int w, int h) {
    count = 0;
    bool success = Window::init(title, w, h);

    if(success == false) {
        return false;
    }

    if(TTF_Init() < 0) {
        printf("TTF failed to initialize! TTF Error: %s\n", TTF_GetError());
        success = false;
    } else {
        TTF_Font* font = TTF_OpenFont("./resources/fonts/consolasb.ttf", 18);
        texture = new Texture(font, renderer);
    }

    return success;
}

void DebugWindow::askForBreakpoint() {
    if(isKeyboardFocused) {
        printf("testing\n");
    }
}

void DebugWindow::render() {
    if(!isMinimized) {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        texture->renderText(intToHex("AF: ", gb->cpu->registers.AF), 5, 5);
        texture->renderText(intToHex("BC: ", gb->cpu->registers.BC), 5, 25);
        texture->renderText(intToHex("DE: ", gb->cpu->registers.DE), 5, 45);
        texture->renderText(intToHex("HL: ", gb->cpu->registers.HL), 5, 65);
        texture->renderText("Add breakpoint: B", 5, 440);
        texture->renderText("Add memory watch: M", 5, 460);

        SDL_RenderPresent(renderer);
        count++;
    }
}

char* DebugWindow::intToHex(char* info, word value) {
    int length = strlen(info);
    char* result = new char[length + 6];
    char* digits = "0123456789ABCDEF";
    auto hex_len = (sizeof(value) << 1) + length + 2;
    std::string rc(hex_len, '0');
    rc[length + 1] = 'x';
    
    for(int i = (length + 2), j = (hex_len - (length + 3)) * 4; i < hex_len; ++i, j -= 4) {
        rc[i] = digits[(value >> j) & 0x0f];
    }

    strncpy(result, rc.c_str(), hex_len + 1);
    strncpy(result, info, length);

    return result;
}
