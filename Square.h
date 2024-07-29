#pragma once

#include <iostream>
#include <string>	

using namespace std;

class Square
{
public:
	void setValue(int x, int y, string value);
	void setX(int X);

	int getX();
	int getY();
	string getValue();
	
private:

	int x;
	int y;
	string value;
};

