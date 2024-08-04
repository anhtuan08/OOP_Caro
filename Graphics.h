#pragma once
#include <iostream>
#include <Windows.h>
#include "Square.h"

class Graphics : public Square
{
public:
	void gotoXY(int x, int y);

	void drawBoard(int rows, int cols);

private:
	Square **graphicsCell;
};


