#ifndef AI_PLAYER 
#define AI_PLAYER

#include <iostream>
#include "map.h"
#include "Graphics.h"
#include "game.h"

#define aiPlayer "o"
#define humanPlayer "x"

class AIplayer
{
public:

	void checkAvailable(int rows, int cols, Matrix board, Console g1);

	void showAIMove(int posX, int posY, Console g1);

	void bestMove(Matrix board);

	int miniMax(Matrix board, int dept, bool isMinimaxing);

private:

};


#endif  




