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

    explicit DebugWindow(GameBoy* gameBoy);

    bool init(char* title, int w, int h) override;
    void free() override;
    void render();
    void askForBreakpoint();
    static char* wordToHex(char* info, word value);
    static char* byteToHex(char* info, byte value);
    static char* boolToHex(char* info, bool value);
    static char* intToString(char* info, int value);
    static char* floatToString(char* info, float value);
};

#endif
