#include "Square.h"


int Square::getX()
{
	return this->x;
}

int Square::getY()
{
	return this->y;
}

string Square::getValue()
{
	return this->value;
}	

void Square::setValue(int x, int y, string value)
{
	this->x = x;
	this->y = y;
	this->value = value;
}

