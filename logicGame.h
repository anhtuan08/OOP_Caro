#pragma once
#include <iostream>
#include <stdbool.h>
#include  "map.h"

const int numberWins = 3;

class LogicGame : public Matrix
{
public:
	LogicGame();
	
	bool checkHorizontal(Matrix board, int rows, int cols, string array[numberWins]);

	bool checkVertical(Matrix board, int rows, int cols, string array[numberWins]);

	bool checkDiagonalLeft(Matrix board, int rows, int cols, string array[numberWins]);

	bool checkDiagonalLeftBottom(Matrix board, int rows, int cols, string array[numberWins]);

	bool checkDiagonalRight(Matrix board, int rows, int cols, string array[numberWins]);

	bool checkDiagonalRightBottom(Matrix board, int rows, int cols, string array[numberWins]);


private:
	bool Horizontal;
	bool Vertical;
	bool DiagonalLeft;
	bool DiagonalRight;

	bool DiagonalLeftBottom;
	bool DiagonalRightBottom;

};
