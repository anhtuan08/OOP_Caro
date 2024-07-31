#pragma once
#include <iostream>
#include  "map.h"

class LogicGame : public Matrix
{
public:
	LogicGame();
	
	void checkHorizontal();

	void checkVertical();


private:
	int Horizontal;
	int Vertical;
};
