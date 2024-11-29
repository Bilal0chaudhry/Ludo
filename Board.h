#pragma once
#include"Utility.h"
class Piece;
class Board
{
    Piece*** p;
    int backgroundColors[15][15];
public:
    Board();
    void print();
    Piece* getpiece(int r, int c);
    void movePiece(int startRow, int startCol, int destRow, int destCol);
    void updatePosition(int srow, int scol, int drow, int dcol);
    void printDice(int number, int row, int col);
};


