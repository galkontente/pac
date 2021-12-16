#include "Fruit.h"

void Fruit::move(char prevCoor, int limits[])
{
	body.draw(' ');
	body.movePoint(this->getDir(), limits);
	body.draw(this->getFigure());
}