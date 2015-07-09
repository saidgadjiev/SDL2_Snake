//  CTexture.cpp
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CTexture.h"


CTexture::CTexture() :
texture(NULL),
width(0),
height(0)
{}

CTexture::~CTexture()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
        texture = NULL;
        width = 0;
        height = 0;
    }
}

bool CTexture::loadFromFile(string filename)
{
    SDL_Texture *newTexture = NULL;
    SDL_Surface *loadedSurface = IMG_Load(filename.c_str());
    
    if (loadedSurface == NULL) {
        cout << "IMG_Load Error: " << SDL_GetError() << endl;
    } else {
        newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (newTexture == NULL) {
            cout << "SDL_CreateTextureFromSurface Error :" << SDL_GetError() << endl;
        } else {
            width = loadedSurface->w;
            height = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }
    this->texture = newTexture;
    return texture != NULL;
}

void CTexture::drawTexture(int x, int y, SDL_Rect* clip,
                           double angle, SDL_Point* center, SDL_RendererFlip flip)
{
    SDL_Rect renderQuad = { x, y, width, height };
    if(clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    SDL_RenderCopyEx(renderer, texture, clip, &renderQuad, angle, center, flip);
}

void CTexture::setTexture(SDL_Texture *loadTexture)
{
    texture = loadTexture;
}

int CTexture::getHeight()
{
    return height;
}

int CTexture::getWidth()
{
    return width;
}

SDL_Texture *CTexture::getTexture()
{
    return texture;
}