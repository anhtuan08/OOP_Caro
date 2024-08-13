#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include <vector>
#include "Square.h"

using namespace std;


class Matrix
{
public:
	Matrix();

	Matrix(int rows, int cols);

	void setValueBoard(int rows, int cols);

	void setValueSquare(int x, int y, string value);

	string getValueSquare(int x, int y);

	int checkBoundaryRowsBottom(char key, int value, Matrix matrix);
	int checkBoundaryRowsTop(char key, int value, Matrix matrix);
	int checkBoundaryColsLeft(char key, int value, Matrix matrix);
	int checkBoundaryColsRight(char key, int value, Matrix matrix);

	void setRows(int rows);

	void setCols(int cols);

	int getRows();

	int getCols();

private:
	int rows;
	int cols;
	Square** squares;
};
			
