#pragma once
class Board;
class Piece;
class Player;
#include"Utility.h"
#include <vector>
#include <utility>
using namespace std;
class Ludo
{
	int sr, sc, dr, dc;
	int t;
	Player* p[4];
	Board* b;
	vector<pair<int, int>> playerPaths[4];
	vector<int> diceRolls; 
	void initializePlayerPaths();
public:
	Ludo();
	void play();
	void displayturnmsg(Player* Ap);
	void selectpiece();
	void selectdestination();
	bool validstartselection(Player* Ap, int r, int c);
	bool validendselection(Player* Ap, int r, int c, int dv);
	void rollDice();
	static Ludo& getInstance();
    const vector<pair<int, int>>& getPathForPlayer(color color) const;
	bool anyPieceOnPath(Player* player);
};