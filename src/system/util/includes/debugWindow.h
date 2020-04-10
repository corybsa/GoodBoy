#ifndef GOODBOY_DEBUGWINDOW_H
#define GOODBOY_DEBUGWINDOW_H

#include "window.h"
#include "texture.h"
#include "../../../system/includes/types.h"
#include "../../../system/includes/gameboy.h"

class DebugWindow : public Window {
public:
    GameBoy* gb;
    Texture* texture;
    word count;

    DebugWindow(GameBoy* gameBoy);

    virtual bool init(char* title, int w, int h);
    void render();
    void askForBreakpoint();
    char* intToHex(char* info, word value);
};

#endif
