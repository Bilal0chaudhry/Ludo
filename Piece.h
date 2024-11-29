#pragma once
#include"Utility.h"
class Board;

class Piece
{
protected:
    Board* b;
    int r, c;
    color pieceColor;
    int dv;
public:
    Piece(Board* _b, int _r, int _c, color co, int dv);
    virtual void display() = 0;
    color getcolor();
    virtual bool ismovevalid(int startrow, int startcol, int destrow, int destcol, int diceValue) = 0;
    virtual char getSymbol() = 0;
    void setColor(color color);
};