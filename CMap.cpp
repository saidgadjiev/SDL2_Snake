//
//  CMap.cpp
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CMap.h"

CMap::CMap() :
snake(new CSnake()),
usualFood(new CUsualFood()),
bonusFood(new CBonusFood())
{}

CMap::~CMap()
{
    delete snake;
    delete usualFood;
    delete bonusFood;
}

CSnake *CMap::getSnake()
{
    return snake;
}

CUsualFood *CMap::getUsualFood()
{
    return usualFood;
}

void CMap::drawMap()
{
    snake->drawSnake();
    usualFood->drawFood();
}

bool CMap::checkNewFood(CUsualFood *food)
{
    vector<CBodyItem*> body = snake->getBodySnake();
    for (int i = 0; i < snake->getBodyLen(); i++) {
        if (body[i]->getX() == food->getFoodX() && body[i]->getY() == food->getFoodY()) {
            return true;
        }
    }
    return false;
}

bool CMap::checkCollision(CFood *food)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    leftA = food->getFoodX();
    rightA = food->getFoodX() + food->getTextureFood()->getWidth();
    topA = usualFood->getFoodY();
    bottomA = food->getFoodY() + food->getTextureFood()->getHeight();
    
    leftB = snake->getSnakeHeadX();
    rightB = snake->getSnakeHeadX() + snake->getSnakeTexture()->getWidth();
    topB = snake->getSnakeHeadY();
    bottomB = snake->getSnakeHeadY() + snake->getSnakeTexture()->getHeight();
    
    if( bottomA <= topB ) {
        return false;
    }
    if( topA >= bottomB ) {
        return false;
    }
    if( rightA <= leftB ) {
        return false;
    }
    if( leftA >= rightB ) {
        return false;
    }
    return true;
}
