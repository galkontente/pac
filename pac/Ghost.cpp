#include "Ghost.h"

void Ghost::move(char prevCoor)
{
	//char pointBefore = body.pointBefore(direction);
	body.draw(prevCoor);
	body.move(direction);
	setTextColor(color);
	body.draw(figure);
	setTextColor(Color::WHITE);
}

