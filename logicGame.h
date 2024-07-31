#pragma once
#include <iostream>
#include  "map.h"

class LogicGame : public Matrix
{
public:
	LogicGame();
	
	void checkHorizontal();

	void checkVertical();

	void checkwin*()
private:
	int Horizontal;
	int Vertical;
};
