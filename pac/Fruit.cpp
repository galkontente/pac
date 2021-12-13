#include "Fruit.h"

void Fruit::move(char prevCoor)
{
	body.draw(' ');
	//body.movePoint(this->getDir());
	setFigure(this->getFigure());
	setTextColor(this->getColor());
}