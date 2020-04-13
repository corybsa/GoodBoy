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
    void setColor(byte red, byte green, byte blue);
    void setBlendMode(SDL_BlendMode blending);
    void setAlpha(byte alpha);
    void render(int x, int y, SDL_Rect* clip = NULL, double andgle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
};

#endif
