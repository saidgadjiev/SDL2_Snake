//
//  CBodyItem.cpp
//  SDL2_Desctop
//
//  Created by Саид on 09.07.15.
//  Copyright (c) 2015 Саид. All rights reserved.
//

#include "CBodyItem.h"

CBodyItem::CBodyItem(int x, int y) :
bodyTexture(new CTexture()),
bodyX(x),
bodyY(y)
{}

CBodyItem::~CBodyItem()
{
    delete bodyTexture;
}

int CBodyItem::getX()
{
    return bodyX;
}

int CBodyItem::getY()
{
    return bodyY;
}

void CBodyItem::setBodyXY(int x, int y)
{
    bodyX = x;
    bodyY = y;
}

bool CBodyItem::loadImgBody()
{
    bool success = true;
    
    if (!bodyTexture->loadFromFile("/Users/said/Desktop/SDL2_Desctop/piece.png")) {
        cout << "Failed to load body texture" << endl;
        success = false;
    }
    return success;
}

void CBodyItem::drawBody()
{
    loadImgBody();
    bodyTexture->drawTexture(bodyX, bodyY);
}

