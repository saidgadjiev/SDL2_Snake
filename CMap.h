//
//  CMap.h
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//
#include "Header.h"
#include "CUsualFood.h"
#include "CBonusFood.h"
#include "CSnake.h"
#ifndef SDL2_Desctop_CMap_h
#define SDL2_Desctop_CMap_h

class CMap {
public:
    CMap();
    ~CMap();
    CSnake *getSnake();
    CUsualFood *getUsualFood();
    void drawMap();
    bool checkNewFood(CUsualFood*food);
    bool checkCollision(CFood *food);
protected:
    CSnake *snake;
    CUsualFood *usualFood;
    CBonusFood *bonusFood;
};


#endif
