//
//  CFood.cpp
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CFood.h"

CFood::CFood() :
foodTexture(new CTexture()),
foodX(0),
foodY(0)
{}

CFood::~CFood()
{
    delete foodTexture;
}

void CFood::drawFood()
{
    foodTexture->drawTexture(foodX, foodY);
}

void CFood::newRandFood()
{
    int px = rand() % 40;
    int py = rand() % 30;
    foodX = px * foodTexture->getWidth();
    foodY = py * foodTexture->getHeight();
}

int CFood::getFoodX()
{
    return foodX;
}

int CFood::getFoodY()
{
    return foodY;
}

CTexture *CFood::getTextureFood()
{
    return foodTexture;
}
