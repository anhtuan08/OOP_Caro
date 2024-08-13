#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <iostream>
#include <windows.h>

using namespace std;

class Console
{
public:
	void gotoXY(int x, int y);

	void moveCursor(int x, int y);

	void drawBoard(int rows, int cols);

private:

};

#endif // GRAPHICS_H
