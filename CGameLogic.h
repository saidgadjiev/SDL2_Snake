//
//  CGameLogic.h
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//
#include "Header.h"
#include "CMap.h"
#ifndef SDL2_Desctop_CGameLogic_h
#define SDL2_Desctop_CGameLogic_h

class CGameLogic : public CMap {
public:
    CGameLogic() : CMap(), gameOver(false) {}
    bool getStatusGame() { return gameOver; }
    bool loadMedia(string fileSnake, string fileUsualFood, string fileBonusFood);
    void logicGame(const Uint8 *keyState);
private:
    bool gameOver;
};

#endif
