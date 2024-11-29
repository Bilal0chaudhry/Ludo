#include "Piece.h"
#include"Board.h"
#include <iostream>
using namespace std;

Piece::Piece(Board* _b, int _r, int _c, color co, int dicevalue)
{
    this->b = _b;
    this->r = _r;
    this->c = _c;
    this->pieceColor = co;
    this->dv = dicevalue;
}

color Piece::getcolor()
{
    return pieceColor;
}

void Piece::setColor(color color) 
{
    this->pieceColor = color;
}
