#include "Graphics.h"


void Graphics::gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void Graphics::drawBoard(int rows, int cols) {
	for (int i = 0; i < rows * 2; i++) {
		for (int j = 0; j < cols * 2; j++) {
			cout << "|-";
		}
	}
}