//
//  CSnake.cpp
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CSnake.h"


CSnake::CSnake() :
direction(STOP),
snakeTexture(new CTexture()),
snakeHeadX(320),
snakeHeadY(464),
snakeVelX(16),
snakeVelY(16)
{}

CSnake::~CSnake()
{
    delete snakeTexture;
}

void CSnake::drawSnake()
{
    snakeTexture->drawTexture(snakeHeadX, snakeHeadY);
    for (int i = 0 ; i < bodyLen; i++) {
        snakeBody[i]->drawBody();
    }
}

void CSnake::handleEvent(const Uint8 *keyState)
{
    if (keyState[SDL_SCANCODE_UP]) {
        if (direction != DOWN) {
            direction = UP;
        }
    }
    if (keyState[SDL_SCANCODE_DOWN]) {
        if (direction != UP) {
            direction = DOWN;
        }
    }
    if (keyState[SDL_SCANCODE_LEFT]) {
        if (direction != RIGHT) {
            direction = LEFT;
        }
    }
    if (keyState[SDL_SCANCODE_RIGHT]) {
        if (direction != LEFT) {
            direction = RIGHT;
        }
    }
}

void CSnake::setSnakeHeadCoord(int x, int y)
{
    snakeHeadX = x;
    snakeHeadY = y;
}

void CSnake::setBodyLen(int length)
{
    bodyLen = length;
}

void CSnake::pushNewBodyItem(int x, int y)
{
    snakeBody.push_back(new CBodyItem(x, y));
}

void CSnake::moveBody()
{
    int prevX = 0, prevY = 0;
    int prev2X = 0, prev2Y = 0;
    if (bodyLen > 0) {
        prevX = snakeBody[0]->getX();
        prevY = snakeBody[0]->getY();
        snakeBody[0]->setBodyXY(snakeHeadX, snakeHeadY);
        for (int i = 1; i < bodyLen; i++) {
            prev2X = snakeBody[i]->getX();
            prev2Y = snakeBody[i]->getY();
            snakeBody[i]->setBodyXY(prevX, prevY);
            prevX = prev2X;
            prevY = prev2Y;
        }
    }
}

bool CSnake::checkCollisionHeadWithBody()
{
    vector<CBodyItem*>::iterator it;
    for (it = snakeBody.begin(); it != snakeBody.end(); it++) {
        if ((*it)->getX() == snakeHeadX && (*it)->getY() == snakeHeadY) {
            return true;
        }
    }
    return false;
}

CTexture *CSnake::getSnakeTexture()
{
    return snakeTexture;
}

int CSnake::getSnakeHeadX()
{
    return snakeHeadX;
}

int CSnake::getSnakeHeadY()
{
    return snakeHeadY;
}

int CSnake::getSnakeVelX()
{
    return snakeVelX;
}

int CSnake::getSnakeVelY()
{
    return snakeVelY;
}

int CSnake::getBodyLen()
{
    return bodyLen;
}

vector<CBodyItem*> CSnake::getBodySnake()
{
    return snakeBody;
}

EDirection CSnake::getSnakeDirection()
{
    return direction;
}

