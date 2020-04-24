#ifndef GOODBOY_WINDOW_H
#define GOODBOY_WINDOW_H

#include <SDL2/SDL.h>

class Window {
public:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int windowId;
    bool isKeyboardFocused;
    bool isMinimized;
    bool isShown;

    Window();
    
    virtual bool init(char* title, int w, int h);
    virtual void free();
    void handleEvent(SDL_Event &e);
    void render() const;
};

#endif
