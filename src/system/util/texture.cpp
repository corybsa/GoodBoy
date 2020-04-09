#include "includes/texture.h"

Texture::Texture() {
    texture = NULL;
    width = 0;
    height = 0;
    font = TTF_OpenFont("../../../resources/fonts/consolas.ttf", 28);

    if(font == NULL) {
        printf("Failed to load font! SDLttf Error: %s\n", TTF_GetError());
    }
}

bool Texture::loadFromRenderedText(char* text, SDL_Color color) {
    // get rid of pre-existing texture
    free();

    // render text surface
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);

    if(surface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        // create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, surface);

        if(texture == NULL) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            // get image dimensions
            width = surface->w;
            height = surface->h;
        }

        SDL_FreeSurface(surface);
    }

    return texture != NULL;
}

void Texture::free() {
    if(texture != NULL) {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

void Texture::setColor(byte red, byte green, byte blue) {
    SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setBlendMode(SDL_BlendMode blending) {
    SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(byte alpha) {
    SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    // set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };

    // set clip rendering dimensions
    if(clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // render to the screen
    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}
