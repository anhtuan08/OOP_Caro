#pragma once
#include <iostream>
#include <stdbool.h>
#include  "map.h"
#include "Graphics.h"

const int numberWins = 3;

class LogicGame
{
public:
	LogicGame();
	
	int checkHorizontal(Matrix board, int rows, int cols);

	int checkVertical(Matrix board, int rows, int cols);

	int checkDiagonalLeft(Matrix board, int rows, int cols);

	int checkDiagonalLeftBottom(Matrix board, int rows, int cols);

	int checkDiagonalRight(Matrix board, int rows, int cols);

	int checkDiagonalRightBottom(Matrix board, int rows, int cols);

	friend int checkArray(string array[numberWins]);

	void logicControl(Matrix board, int& x, int& y, int& posX, int& posY, string playerCurrent);

	void logicTurn(Matrix board, int posX, int posY, string playerCurrent);

	void switchPlayer(string &playerCurrent);

	int moveLeft(Matrix board);

private:

};
