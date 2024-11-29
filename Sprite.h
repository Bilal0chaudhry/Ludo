#pragma once
#include "Piece.h"
#include"Utility.h"
class Sprite : public Piece
{
public:
    Sprite(Board* b, int r, int c, color _C, int dv);
    virtual void display();
    virtual bool ismovevalid(int startrow, int startcol, int destrow, int destcol, int diceValue);
    virtual char getSymbol() ;
};