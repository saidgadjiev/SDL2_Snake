//
//  CTexture.h
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "Header.h"
#ifndef SDL2_Desctop_Header_h
#define SDL2_Desctop_Header_h

SDL_Renderer *renderer = NULL;
SDL_Window *window = NULL;

class CTexture {
public:
    CTexture();
    ~CTexture();
    bool loadFromFile(string filename);
    void drawTexture(int x, int y, SDL_Rect* clip = NULL,
                     double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
    void setTexture(SDL_Texture *texture);
    int getWidth();
    int getHeight();
    SDL_Texture *getTexture();
private:
    SDL_Texture *texture;
    int width;
    int height;
};


#endif
