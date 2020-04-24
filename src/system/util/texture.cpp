#include "includes/texture.h"
#include <iostream>

Texture::Texture(TTF_Font* f, SDL_Renderer* r) {
    texture = nullptr;
    width = 0;
    height = 0;
    font = f;
    renderer = r;
}

Texture::~Texture() {
    TTF_CloseFont(font);
    TTF_Quit();
    font = nullptr;
    free();
}

void Texture::free() {
    if(texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
        width = 0;
        height = 0;
    }
}

void Texture::renderText(char* text, int x, int y) {
    // get rid of pre-existing texture
    free();

    if(font == nullptr) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        return;
    }

    //Set texture filtering to linear
    if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf( "Warning: Linear texture filtering not enabled!" );
    }

    // render text surface
    SDL_Color black = { 0x00, 0x00, 0x00 };
    SDL_Color white = { 0xFF, 0xFF, 0xFF }; 

    // the _Shaded suffix means anti-alias
    SDL_Surface* surface = TTF_RenderText_Shaded(font, text, black, white);

    if(surface == nullptr) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
    } else {
        // create texture from surface pixels
        texture = SDL_CreateTextureFromSurface(renderer, surface);

        if(texture == nullptr) {
            printf("Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError());
        } else {
            // get image dimensions
            width = surface->w;
            height = surface->h;
        }

        SDL_FreeSurface(surface);
    }

    if(texture == nullptr) {
        printf("Could not create texture!\n");
    } else {
        render(x, y);
    }
}

void Texture::render(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    // set rendering space and render to screen
    SDL_Rect renderQuad = { x, y, width, height };

    // set clip rendering dimensions
    if(clip != nullptr) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }

    // render to the screen
    if(SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip) < 0) {
        printf("Render error! SDL Error: %s\n", SDL_GetError());
    }
}
