#include "Sprite.h"
#include <iostream>
#include"Board.h"
#include"Ludo.h"

using namespace std;

Sprite::Sprite(Board* b, int r, int c, color _C, int diceValue) : Piece(b, r, c, _C, diceValue)
{

}

void Sprite::display()
{
    if ((r == 1 || r == 4) && (c == 1 || c == 4))
    {
        cout << " " << 'B' << " ";
    }
    else if ((r == 1 || r == 4) && (c == 10 || c == 13))
    {
        cout << " " << 'G' << " ";
    }
    else if ((r == 10 || r == 13) && (c == 1 || c == 4))
    {
        cout << " " << 'R' << " ";
    }
    else if ((r == 10 || r == 13) && (c == 10 || c == 13))
    {
        cout << " " << 'Y' << " ";
    }
    else if (((r >= 6 && r <= 8) && !(c >= 6 && c <= 8))||((c >= 6 && c <= 8) && !(r >= 6 && r <= 8)))
    {
        cout << " " << '*' << " ";
    }
    else if ((r >= 6 && c <= 8) && (r >= 6 && c <= 8))
    {
        cout << " " << "H" << " ";
    }
}

char Sprite::getSymbol()
{
    if (pieceColor == RED)
    {
        return 'R';
    }
    else if (pieceColor == GREEN)
    {
        return 'G';
    }
    else if (pieceColor == YELLOW)
    {
        return 'Y';
    }
    else if (pieceColor == RED)
    {
        return 'R';
    }
    else if (pieceColor == PATH)
    {
        return '*';
    }
    else if (pieceColor == HOME)
    {
        return 'H';
    }
    else
    {
        return '-';
    }
}

bool Sprite::ismovevalid(int startrow, int startcol, int destrow, int destcol, int diceValue) 
{
    const auto& path = Ludo::getInstance().getPathForPlayer(getcolor());
    auto startIter = find(path.begin(), path.end(), make_pair(startrow, startcol));
    auto destIter = find(path.begin(), path.end(), make_pair(destrow, destcol));

    if (diceValue == 6 && startIter == path.end() && destIter == path.begin()) 
    {
        return true;
    }

    if (startIter == path.end() || destIter == path.end()) 
    {
        return false;
    }

    int startPos = distance(path.begin(), startIter);
    int destPos = distance(path.begin(), destIter);
    int pathDiff = abs(destPos - startPos);

    return pathDiff == diceValue;
}
