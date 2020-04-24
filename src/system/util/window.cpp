#include "includes/window.h"
#include "includes/texture.h"

Window::Window() {
    window = nullptr;
    renderer = nullptr;

    isKeyboardFocused = false;
    isShown = false;
    isMinimized = false;
    windowId = -1;
}

bool Window::init(char* title, int w, int h) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

    if(window != nullptr) {
        isKeyboardFocused = true;

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

        if(renderer == nullptr) {
            printf("Rederer could not be created SDL Error: %s\n", SDL_GetError());
            SDL_DestroyWindow(window);
            window = nullptr;
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

    return window != nullptr && renderer != nullptr;
}

void Window::free() {
    if(window != nullptr) {
        SDL_DestroyWindow(window);
    }

    if(renderer != nullptr) {
        SDL_DestroyRenderer(renderer);
    }

    window = nullptr;
    renderer = nullptr;
    isKeyboardFocused = false;
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
            case SDL_WINDOWEVENT_EXPOSED: // repaint on expose
                SDL_RenderPresent(renderer);

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
            case SDL_WINDOWEVENT_RESTORED: // window restored
                isMinimized = false;

                break;
            case SDL_WINDOWEVENT_CLOSE: // hide on close
                SDL_HideWindow(window);

                break;
        }
    }
}

void Window::render() const {
    if(!isMinimized) {
        // clear screen
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);

        // update screen
        SDL_RenderPresent(renderer);
    }
}
