//
//  CFood.h
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//
#include "Header.h"
#include "CTexture.h"
#ifndef SDL2_Desctop_CFood_h
#define SDL2_Desctop_CFood_h

class CFood {
public:
    CFood();
    ~CFood();
    void drawFood();
    void newRandFood();
    CTexture *getTextureFood();
    int getFoodX();
    int getFoodY();
private:
    CTexture *foodTexture;
    int foodX;
    int foodY;
};

#endif
