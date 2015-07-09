//
//  CBodyItem.h
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CTexture.h"
#include "Header.h"
#ifndef SDL2_Desctop_Header_h
#define SDL2_Desctop_Header_h

class CBodyItem {
public:
    CBodyItem() {};
    CBodyItem(int x, int y);
    ~CBodyItem();
    int getX();
    int getY();
    void setBodyXY(int x, int y);
    bool loadImgBody();
    void drawBody();
private:
    CTexture *bodyTexture;
    int bodyX;
    int bodyY;
};

#endif
