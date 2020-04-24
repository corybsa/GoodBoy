#ifndef GOODBOY_TEXTURE_H
#define GOODBOY_TEXTURE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "../../includes/types.h"

class Texture {
public:
    int width;
    int height;
    SDL_Texture* texture;
    TTF_Font* font;
    SDL_Renderer* renderer;

    Texture(TTF_Font* f, SDL_Renderer* r);
    ~Texture();

    void free();
    void renderText(char* text, int x, int y);
    void render(int x, int y, SDL_Rect* clip = nullptr, double angle = 0.0, SDL_Point* center = nullptr, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif
