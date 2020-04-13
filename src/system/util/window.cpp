#include "includes/window.h"
#include "includes/texture.h"

Window::Window() {
    window = NULL;
    renderer = NULL;

    isMouseFocused = false;
    isKeyboardFocused = false;
    isFullScreen = false;
    isShown = false;
    windowId = -1;

    width = 0;
    height = 0;
}

bool Window::init(char* title, int w, int h) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if(window != NULL) {
        isMouseFocused = true;
        isKeyboardFocused = true;
        width = w;
        height = h;

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if(renderer == NULL) {
            printf("Rederer could not be created SDL Error: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            window = NULL;
        } else {
            // init renderer color
            SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

            // grab window identifier
            windowId = SDL_GetWindowID(window);

            // flag as opened
            isShown = true;
        }
    } else {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
    }

    return window != NULL && renderer != NULL;
}

void Window::free() {
    if(window != NULL) {
        SDL_DestroyWindow(window);
    }

    if(renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }

    isMouseFocused = false;
    isKeyboardFocused = false;
    width = 0;
    height = 0;
}

void Window::handleEvent(SDL_Event &e) {
    if(e.type == SDL_WINDOWEVENT && e.window.windowID == windowId) {
        switch(e.window.event) {
            case SDL_WINDOWEVENT_SHOWN: // window appeared
                isShown = true;

                break;
            case SDL_WINDOWEVENT_HIDDEN: // window disappeared
                isShown = false;

                break;
            case SDL_WINDOWEVENT_SIZE_CHANGED: // get new dimensions and repaint
                width = e.window.data1;
                height = e.window.data2;
                SDL_RenderPresent(renderer);

                break;
            case SDL_WINDOWEVENT_EXPOSED: // repaint on expose
                SDL_RenderPresent(renderer);

                break;
            case SDL_WINDOWEVENT_ENTER: // mouse enter
                isMouseFocused = true;

                break;
            case SDL_WINDOWEVENT_LEAVE: // mouse exit
                isMouseFocused = false;

                break;
            case SDL_WINDOWEVENT_FOCUS_GAINED: // keyboard focus gained
                isKeyboardFocused = true;

                break;
            case SDL_WINDOWEVENT_FOCUS_LOST: // keyboard focus lost
                isKeyboardFocused = false;

                break;
            case SDL_WINDOWEVENT_MINIMIZED: // window minimized
                isMinimized = true;

                break;
            case SDL_WINDOWEVENT_MAXIMIZED: // window maximized
                isMinimized = false;

                break;
            case SDL_WINDOWEVENT_RESTORED: // window restored
                isMinimized = false;

                break;
            case SDL_WINDOWEVENT_CLOSE: // hide on close
                SDL_HideWindow(window);

                break;
        }
    }
}

void Window::focus() {
    if(!isShown) {
        SDL_ShowWindow(window);
    }

    SDL_RaiseWindow(window);
}

void Window::render() {
    if(!isMinimized) {
        // clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // update screen
        SDL_RenderPresent(renderer);
    }
}
