#include "Ludo.h"
#include"Player.h"
#include"Board.h"
#include"Piece.h"
#include<time.h>
#include<string.h>
#include<iostream>
#include <chrono> 
#include <thread> 

using namespace std;

Ludo::Ludo()
{
    initializePlayerPaths(); 
    p[0] = new Player("Blue", BLUE);
    p[1] = new Player("Green", GREEN);
    p[2] = new Player("Yellow", YELLOW);
    p[3] = new Player("Red", RED);
    b = new Board();
    srand(time(0));
    t = rand() % 4;
}

void Ludo::displayturnmsg(Player* Ap)
{
    cout << Ap->getname() << "'s Turn\nClick Dice!!\n";
}

void Ludo::selectpiece()
{
    cin >> sr >> sc;
}

void Ludo::selectdestination()
{
    cin >> dr >> dc;
}

bool Ludo::validstartselection(Player* Ap, int r, int c)
{
    if ((r < 0 || r >= 15) || (c < 0 || c >= 15))
    {
        return false;
    }
    Piece* p = b->getpiece(r, c);

    return p != nullptr && p->getcolor() == Ap->getcolor();
}

Ludo& Ludo::getInstance() 
{
    static Ludo instance;
    return instance;
}

void Ludo::initializePlayerPaths() 
{
    playerPaths[BLUE] = { {6, 1}, {6, 2}, {6, 3},{6, 4}, {6, 5}, {5, 6}, {4, 6},{3, 6}, {2, 6}, {1, 6}, {0, 6},{0, 7}, {0, 8}, {1, 8}, {2, 8},{3, 8}, {4, 8}, {5, 8}, {6, 9},{6, 10}, {6, 11}, {6, 12}, {6, 13},{6, 14}, {7, 14}, {8, 14}, {8, 13},{8, 12}, {8, 11}, {8, 10}, {8, 9},{9, 8}, {10, 8}, {11, 8}, {12, 8},{13, 8}, {14, 8}, {14, 7}, {14, 6},{13, 6}, {12, 6}, {11, 6}, {10, 6},{9, 6}, {8, 5}, {8, 4}, {8, 3},{8, 2}, {8, 1}, {8, 0}, {7, 0},{7, 1}, {7, 2}, {7, 3}, {7, 4},{7, 5}, {7, 6} };
    playerPaths[GREEN] = { {1, 8}, {2, 8},{3, 8}, {4, 8}, {5, 8}, {6, 9},{6, 10}, {6, 11}, {6, 12}, {6, 13},{6, 14}, {7, 14}, {8, 14}, {8, 13},{8, 12}, {8, 11}, {8, 10}, {8, 9},{9, 8}, {10, 8}, {11, 8}, {12, 8},{13, 8}, {14, 8}, {14, 7}, {14, 6},{13, 6}, {12, 6}, {11, 6}, {10, 6},{9, 6}, {8, 5}, {8, 4}, {8, 3},{8, 2}, {8, 1}, {8, 0}, {7, 0},{6, 0}, {6, 1}, {6, 2}, {6, 3},{6, 4}, {6, 5}, {5, 6}, {4, 6},{3, 6}, {2, 6}, {1, 6}, {0, 6},{0, 7},{1, 7}, {2, 7}, {3, 7}, {4, 7},{5, 7}, {6, 7} };
    playerPaths[YELLOW] = { {8, 13},{8, 12}, {8, 11}, {8, 10}, {8, 9},{9, 8}, {10, 8}, {11, 8}, {12, 8},{13, 8}, {14, 8}, {14, 7}, {14, 6},{13, 6}, {12, 6}, {11, 6}, {10, 6},{9, 6}, {8, 5}, {8, 4}, {8, 3},{8, 2}, {8, 1}, {8, 0}, {7, 0},{6, 0}, {6, 1}, {6, 2}, {6, 3},{6, 4}, {6, 5}, {5, 6}, {4, 6},{3, 6}, {2, 6}, {1, 6}, {0, 6},{0, 7},{0, 8}, {1, 8}, {2, 8},{3, 8}, {4, 8}, {5, 8}, {6, 9},{6, 10}, {6, 11}, {6, 12}, {6, 13},{6, 14}, {7, 14},{7, 13}, {7, 12}, {7, 11},{7, 10}, {7, 9}, {7, 8} };
    playerPaths[RED] = { {13, 6}, {12, 6}, {11, 6}, {10, 6},{9, 6}, {8, 5}, {8, 4}, {8, 3},{8, 2}, {8, 1}, {8, 0}, {7, 0},{6, 0}, {6, 1}, {6, 2}, {6, 3},{6, 4}, {6, 5}, {5, 6}, {4, 6},{3, 6}, {2, 6}, {1, 6}, {0, 6},{0, 7},{0, 8}, {1, 8}, {2, 8},{3, 8}, {4, 8}, {5, 8}, {6, 9},{6, 10}, {6, 11}, {6, 12}, {6, 13},{6, 14}, {7, 14},{8, 14}, {8, 13},{8, 12}, {8, 11}, {8, 10}, {8, 9},{9, 8}, {10, 8}, {11, 8}, {12, 8},{13, 8}, {14, 8}, {14, 7},{13, 7}, {12, 7},{11, 7}, {10, 7}, {9, 7}, {8, 7} };
}

const vector<pair<int, int>>& Ludo::getPathForPlayer(color color) const 
{
    return playerPaths[color];
}

bool Ludo::validendselection(Player* Ap, int r, int c, int diceValue) {
    if ((r < 0 || r >= 15) || (c < 0 || c >= 15)) {
        return false;
    }

    Piece* endPiece = b->getpiece(r, c);

    if (!b->getpiece(sr, sc)->ismovevalid(sr, sc, r, c, diceValue)) {
        return false;
    }

    const vector<pair<int, int>>& path = playerPaths[t];
    bool isValidPath = false;
    for (const auto& position : path) {
        if (position.first == r && position.second == c) {
            isValidPath = true;
            break;
        }
    }

    if (!isValidPath)
    {
        return false;
    }

    return true;
}


void Ludo::rollDice() {
    int roll = rand() % 6 + 1; 
    diceRolls.push_back(roll);
    b->printDice(roll, 5, 60);
 
}

static void clearMessage()
{
    cout << "\033[16;0H";
    cout << "\033[J";
}

bool Ludo::anyPieceOnPath(Player* player)
{
    const auto& path = getPathForPlayer(player->getcolor());
    for (const auto& pos : path)
    {
        int row = pos.first;
        int col = pos.second;
        Piece* piece = b->getpiece(row, col);
        if (piece != nullptr && piece->getcolor() == player->getcolor())
        {
            return true;
        }
    }
    return false;
}

void Ludo::play()
{
    b->print();
    b->printDice(1, 5, 60);
    int consecutiveSixes = 0;

    while (true)
    {
        cout << "\033[40m\033[37m";
        int clickRow, clickCol;
        gotoRowCol(16, 0);
        clearMessage();
        displayturnmsg(p[t]);
        getrowcolbyleftclick(clickRow, clickCol);

        if ((clickRow >= 5 && clickRow <= 9) && (clickCol >= 20 && clickCol <= 22))
        {
            rollDice();
            int lastRoll = diceRolls.back();
            b->printDice(lastRoll, 5, 60);

            if (lastRoll != 6 && !anyPieceOnPath(p[t]))
            {
                t = (t + 1) % 4;
                continue;
            }

            if (lastRoll == 6)
            {
                consecutiveSixes++;
                if (consecutiveSixes == 3)
                {
                    t = (t + 1) % 4;
                    consecutiveSixes = 0;
                    continue;
                }
            }
            else
            {
                consecutiveSixes = 0;
            }

            int startRow, startCol;
            do {
                gotoRowCol(16, 0);
                clearMessage();
                cout << "Select a piece (row column): " << endl;
                getrowcolbyleftclick(startRow, startCol);
            } while (!validstartselection(p[t], startRow, startCol));

            sr = startRow;
            sc = startCol;

            int destRow, destCol;
            do {
                gotoRowCol(16, 0);
                clearMessage();
                cout << "Select a destination (row column): " << endl;
                getrowcolbyleftclick(destRow, destCol);
            } while (!validendselection(p[t], destRow, destCol, lastRoll));

            b->movePiece(startRow, startCol, destRow, destCol);
            b->updatePosition(startRow, startCol, destRow, destCol);

            if (lastRoll != 6)
            {
                t = (t + 1) % 4;
            }
        }
    }
}








