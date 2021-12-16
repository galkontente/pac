#include "Fruit.h"

//void Fruit::move(char prevCoor,int limits[])
//{
//	body.draw(' ');
//	body.movePoint(this->getDir(),limits);
//	body.draw(this->getFigure());
//}


void Fruit::move(char prevCoor,int limits[])
{
	setTextColor(Color::WHITE);
	body.draw(prevCoor);
	body.movePoint(this->getDir(), limits);
	body.draw(this->getFigure());
}
