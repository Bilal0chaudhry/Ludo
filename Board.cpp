#include<iostream>
#include"Board.h"
#include"Piece.h"
#include"Sprite.h"
#include <windows.h>
#include"utility.h"
#include <stdio.h>
#include<iomanip>
using namespace std;

Piece* Board::getpiece(int r, int c)
{
    return p[r][c];
}

Board::Board()
{
    p = new Piece * *[15];
    for (int i = 0; i < 15; i++)
    {
        p[i] = new Piece * [15];
        for (int j = 0; j < 15; j++)
        {
            if ((i == 1||i==4)&&(j==1||j==4))
            {
                p[i][j] = new Sprite(this, i, j, BLUE,1);
            }
            else if ((i == 1 || i == 4) && (j == 10 || j == 13))
            {
                p[i][j] = new Sprite(this, i, j, GREEN,1);
            }
            else if ((i == 10 || i == 13) && (j == 1 || j == 4))
            {
                p[i][j] = new Sprite(this, i, j, RED,1);
            }
            else if ((i == 10 || i == 13) && (j == 10 || j == 13))
            {
                p[i][j] = new Sprite(this, i, j, YELLOW,1);
            }
            else if (((i >= 6 && i <= 8) && !(j >= 6 && j <= 8))||(!(i >= 6 && i <= 8) && (j >= 6 && j <= 8)))
            {
                p[i][j] = new Sprite(this, i, j, PATH,1);
            }
            else if ((i>=6&&i<=8)&&(j>=6&&j<=8))
            {
                p[i][j] = new Sprite(this, i, j, HOME,1);
            }
            else
            {
                p[i][j] = nullptr;
            }
        }

    }
}

void Board::print() 
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++) 
        {
            if ((p[i][j] == nullptr) && ((i >= 0 && i <= 5) && (j >= 0 && j <= 5)))
            {
                cout << "\033[44m\033[37m"; 
                cout << setw(3) << left << " ";
            }
            else if ((p[i][j] == nullptr) && ((i >= 9 && i <= 14) && (j >= 0 && j <= 5)))
            {
                cout << "\033[41m\033[37m";
                cout << setw(3) << left << " ";
            }
            else if ((p[i][j] == nullptr) && ((i >= 0 && i <= 5) && (j >= 9 && j <= 14)))
            {
                cout << "\033[42m\033[37m";
                cout << setw(3) << left << " ";
            }
            else if ((p[i][j] == nullptr) && ((i >= 9 && i <= 14) && (j >= 9 && j <= 14)))
            {
                cout << "\033[43m\033[37m";
                cout << setw(3) << left << " ";
            }
            else 
            {
                if (p[i][j]->getcolor() == PATH && ((i == 7 && (j > 0 && j <= 5)) || i == 6 && j == 1))
                {
                    cout << "\033[44m\033[30m";
                }
                else if (p[i][j]->getcolor() == PATH && ((j == 7 && (i > 0 && i <= 5)) || j == 8 && i == 1))
                {
                    cout << "\033[42m\033[30m";
                }
                else if (p[i][j]->getcolor() == PATH && ((i == 7 && (j >=9 && j <= 13)) || j == 13 && i == 8))
                {
                    cout << "\033[43m\033[30m";
                }
                else if (p[i][j]->getcolor() == PATH && ((j == 7 && (i >= 9 && i <= 13)) || j == 6 && i == 13))
                {
                    cout << "\033[41m\033[30m";
                }
                else if (p[i][j]->getcolor() == PATH) 
                {
                    cout << "\033[47m\033[30m"; 
                }
                else if (p[i][j]->getcolor() == BLUE)
                {
                    cout << "\033[47m\033[34m";
                }
                else if (p[i][j]->getcolor() == GREEN)
                {
                    cout << "\033[47m\033[32m";
                }
                else if (p[i][j]->getcolor() == YELLOW)
                {
                    cout << "\033[47m\033[33m";
                }
                else if (p[i][j]->getcolor() == RED)
                {
                    cout << "\033[47m\033[31m";
                }
                else 
                {
                    cout << "\033[40m\033[37m"; 
                }
                p[i][j]->display();
            }
            cout << "\033[0m"; 
        }
        cout << endl;
    }
}

void Board::printDice(int number, int row, int col) {
    gotoRowCol(row, col);
    cout << "+-------+" << endl;
    gotoRowCol(row + 1, col);
    switch (number) {
    case 1:
        cout << "|       |" << endl;
        gotoRowCol(row + 2, col);
        cout << "|   *   |" << endl;
        gotoRowCol(row + 3, col);
        cout << "|       |" << endl;
        break;
    case 2:
        cout << "| *     |" << endl;
        gotoRowCol(row + 2, col);
        cout << "|       |" << endl;
        gotoRowCol(row + 3, col);
        cout << "|     * |" << endl;
        break;
    case 3:
        cout << "| *     |" << endl;
        gotoRowCol(row + 2, col);
        cout << "|   *   |" << endl;
        gotoRowCol(row + 3, col);
        cout << "|     * |" << endl;
        break;
    case 4:
        cout << "| *   * |" << endl;
        gotoRowCol(row + 2, col);
        cout << "|       |" << endl;
        gotoRowCol(row + 3, col);
        cout << "| *   * |" << endl;
        break;
    case 5:
        cout << "| *   * |" << endl;
        gotoRowCol(row + 2, col);
        cout << "|   *   |" << endl;
        gotoRowCol(row + 3, col);
        cout << "| *   * |" << endl;
        break;
    case 6:
        cout << "| *   * |" << endl;
        gotoRowCol(row + 2, col);
        cout << "| *   * |" << endl;
        gotoRowCol(row + 3, col);
        cout << "| *   * |" << endl;
        break;
    default:
        break;
    }
    gotoRowCol(row + 4, col);
    cout << "+-------+" << endl;
}

void Board::movePiece(int startRow, int startCol, int destRow, int destCol) {
    Piece* pieceToMove = p[startRow][startCol];
    p[startRow][startCol] = nullptr;
    p[destRow][destCol] = pieceToMove;
}

void Board::updatePosition(int srow, int scol, int drow, int dcol) {
    int startX = 0;
    int startY = 0;
    int boxWidth = 3;

    int consoleSX = startX + (scol * boxWidth);
    int consoleSY = startY + srow;

    int consoleDX = startX + (dcol * boxWidth);
    int consoleDY = startY + drow;

    gotoRowCol(consoleSY, consoleSX);
    if (p[srow][scol] == nullptr )
    {
        if (((srow == 7 && (scol > 0 && scol <= 5)) || (srow == 6 && scol == 1)))
        {
            cout << "\033[44m\033[30m * \033[0m";

        }
        else if (((scol == 7 && (srow > 0 && srow <= 5)) || (scol == 8 && srow == 1)))
        {
            cout << "\033[42m\033[30m * \033[0m";

        }
        else  if (((srow == 7 && (scol >= 9 && scol <= 13)) || (scol == 13 && srow == 8)))
        {
            cout << "\033[43m\033[30m * \033[0m";

        }
        else  if (((scol == 7 && (srow >= 9 && srow <= 13)) || (scol == 6 && srow == 13)))
        {
            cout << "\033[41m\033[30m * \033[0m";
        }
        else
        {
            cout << "\033[47m\033[30m * \033[0m";
        }
    }
    else
    {
        cout << "\033[47m\033[30m   \033[0m";
    }
    gotoRowCol(consoleDY, consoleDX);



    if (p[drow][dcol] == nullptr) 
    {
        cout << "   ";
    }
    else
    {
        switch (p[drow][dcol]->getcolor()) {
        case PATH:
            cout << "\033[47m\033[30m";
            break;
        case BLUE:
            if (((drow == 7 && (dcol > 0 && dcol <= 5)) || (drow == 6 && dcol == 1)))
            {
                cout << "\033[44m\033[30m";
            }
            else
            {
                cout << "\033[47m\033[34m";
            }
            break;
        case GREEN:
            if (((dcol == 7 && (drow > 0 && drow <= 5)) || (dcol == 8 && drow == 1)))
            {
                cout << "\033[42m\033[30m";
            }
            else 
            {
                cout << "\033[47m\033[32m";
            }
            break;
        case YELLOW:
            if (((drow == 7 && (dcol >= 9 && dcol <= 13)) || (dcol == 13 && drow == 8)))
            {
                cout << "\033[43m\033[30m";
            }
            else
            {
                cout << "\033[47m\033[33m";
            }
            break;
        case RED:
            if (((dcol == 7 && (drow >= 9 && drow <= 13)) || (dcol == 6 && drow == 13)))
            {
                cout << "\033[41m\033[30m";
            }
            else
            {
                cout << "\033[47m\033[31m";
            }
            break;
        default:
            cout << "\033[47m\033[30m";
        }
        p[drow][dcol]->display();
    }


    gotoRowCol(20, 0);
}
