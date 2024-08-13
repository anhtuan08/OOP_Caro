#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "map.h"
#include "Square.h"
#include "logicGame.h"
#include "Graphics.h"
#include "AIplayer.h"

using namespace std;

class Game
{
public:

	void gameLoad(Matrix board);

	void gameStart(Matrix board);

	void gamePlayerWithComputer(Matrix board);

	int gameWon(Matrix board, LogicGame g1, int turn);

private:

};

#endif



