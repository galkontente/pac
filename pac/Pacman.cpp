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

bool Pac::canPass(Board b, int x, int y)
{
	if ((direction == 0 && (b.getCharInCoor(body.getX(), body.getY() - 1) == '#')) || //UP
		(direction == 1 && (b.getCharInCoor(body.getX(), body.getY() + 1) == '#')) || //DOWN
		(direction == 2 && (b.getCharInCoor(body.getX() - 1, body.getY()) == '#')) || //LEFT
		(direction == 3 && (b.getCharInCoor(body.getX() + 1, body.getY()) == '#')))  //RIGHT
		return false;

	return true;
}