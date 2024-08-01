#pragma once
#include <iostream>
#include <stdbool.h>
#include  "map.h"

const int numberWins = 5;

class LogicGame
{
public:
	LogicGame();
	
	bool checkHorizontal(Matrix board, int rows, int cols);

	bool checkVertical(Matrix board, int rows, int cols);

	bool checkDiagonalLeft(Matrix board, int rows, int cols);

	bool checkDiagonalLeftBottom(Matrix board, int rows, int cols);

	bool checkDiagonalRight(Matrix board, int rows, int cols);

	bool checkDiagonalRightBottom(Matrix board, int rows, int cols);

	friend bool checkArray(string array[numberWins]);

	void logicControl(Matrix board, int& x, int& y, int& posX, int& posY, string playerCurrent);

	void logicTurn(Matrix board, int posX, int posY, string playerCurrent);

	void switchPlayer(string &playerCurrent);

private:

};
