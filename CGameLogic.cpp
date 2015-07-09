//
//  CGameLogic.cpp
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CGameLogic.h"

bool CGameLogic::loadMedia(string fileSnake, string fileUsualFood, string fileBonusFood)
{
    bool success = true;
    
    if (!(snake->getSnakeTexture())->loadFromFile(fileSnake)) {
        cout << "Failed to load head texture" << endl;
        success = false;
    }
    if (!(usualFood->getTextureFood())->loadFromFile(fileUsualFood)) {
        cout << "Failed to load usualFood texture" << endl;
        success = false;
    }
    if (!(bonusFood->getTextureFood())->loadFromFile(fileBonusFood)) {
        cout << "Failed to load bonusFood texture" << endl;
        success = false;
    }
    return success;
}

void CGameLogic::logicGame(const Uint8 *keyState)
{
    int bodyLen = snake->getBodyLen();
    int headX = snake->getSnakeHeadX();
    int x = headX;
    int headY = snake->getSnakeHeadY();
    int y = headY;
    int velSnakeX = snake->getSnakeVelX();
    int velSnakeY = snake->getSnakeVelY();
    EDirection direction = snake->getSnakeDirection();
    
    snake->handleEvent(keyState);
    snake->moveBody();
    switch(direction) {
        case UP:
            headY -= velSnakeY;
            break;
        case DOWN:
            headY += velSnakeY;
            break;
        case LEFT:
            headX -= velSnakeX;
            break;
        case RIGHT:
            headX += velSnakeX;
            break;
        case STOP:
            break;
    }
    if (headX < 0) {
        headX = SCREEN_WIDTH - snake->getSnakeTexture()->getWidth();
    }
    if (headX + snake->getSnakeTexture()->getWidth() > SCREEN_WIDTH) {
        headX = 0;
    }
    if (headY < 0) {
        headY = SCREEN_HEIGHT - snake->getSnakeTexture()->getHeight();
    }
    if (headY + snake->getSnakeTexture()->getWidth() > SCREEN_HEIGHT) {
        headY = 0;
    }
    snake->setSnakeHeadCoord(headX, headY);
    if (snake->checkCollisionHeadWithBody()) {
        gameOver = true;
    }
    if (checkCollision(usualFood)) {
        usualFood->newRandFood();
        while(checkNewFood(usualFood)) {
            usualFood->newRandFood();
        }
        snake->setBodyLen(++bodyLen);
        snake->pushNewBodyItem(x, y);
    }
}
