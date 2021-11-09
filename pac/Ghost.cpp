#include "Ghost.h"

void Ghost::move()
{
	//char pointBefore = body.pointBefore(direction);
	body.draw(' ');
	body.move(direction);
	setTextColor(color);
	body.draw(figure);
}

