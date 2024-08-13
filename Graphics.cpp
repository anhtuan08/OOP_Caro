#include "Graphics.h"


void Console::gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::moveCursor(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos = { x, y };
	SetConsoleCursorPosition(hConsole, pos);
}

void Console::drawBoard(int rows, int cols)
{
	for (int i = 0; i < rows * 2; i++) {
		for (int j = 0; j < cols * 2; j++) {
			if (j % 2 == 0)
			{
				gotoXY((j + 1), i);
				cout << "-";
			}
			if (i % 2 == 1 && (j % 2 == 0))
			{
				gotoXY((j + 1), (i - 1));
				cout << "| ";
			}
		}
	}
}
