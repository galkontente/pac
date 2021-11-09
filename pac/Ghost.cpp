#include "Ghost.h"

void Ghost::move()
{
	//body.pointBefore('.');
	body.draw(' ');
	body.move(direction);
	setTextColor(color);
	body.draw(figure);
}

