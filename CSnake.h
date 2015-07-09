//
//  Header.h
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//
#include "Header.h"
#ifndef SDL2_Desctop_Header_h
#define SDL2_Desctop_Header_h

class CSnake {
public:
    CSnake();
    ~CSnake();
    void drawSnake();
    void handleEvent(const Uint8 *keyState);
    void setSnakeHeadCoord(int x, int y);
    void setBodyLen(int lenght);
    void pushNewBodyItem(int x, int y);
    void moveBody();
    bool checkCollisionHeadWithBody();
    CTexture *getSnakeTexture();
    int getSnakeHeadX();
    int getSnakeHeadY();
    int getSnakeVelX();
    int getSnakeVelY();
    int getBodyLen();
    vector<CBodyItem*> getBodySnake();
    EDirection getSnakeDirection();
private:
    EDirection direction;
    CTexture *snakeTexture;
    vector<CBodyItem*> snakeBody;
    int bodyLen;
    int snakeHeadX;
    int snakeHeadY;
    int snakeVelX;
    int snakeVelY;
};


#endif
