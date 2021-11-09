#include "Pacman.h"

void Pac::move()
{
	body.draw(' ');
	body.move(direction);
	setTextColor(color);
	body.draw(figure);
}
int Pac::getDirection(char key)
{
	for (int i = 0; i < 4; i++)
	{
		if (key == arrowKeys[i])
			return i;
	}
	return -1;
}