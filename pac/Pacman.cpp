#include "Pacman.h"

void Pac::move(int limits[])
{
	body.draw(' ');
	body.movePoint(this->getDir(),limits);
	setFigure(this->getFigure());
	setTextColor(this->getColor());
	body.draw(this->getFigure());
}



int Pac::getDirectionInput(char key)
{
	if (key == 'w' || key == 'W')//up
		return 0;
	else if (key == 'x' || key == 'X')//down
		return 1;
	else if (key == 'a' || key == 'A')//left
		return 2;
	else if (key == 'd' || key == 'D')//right
		return 3;
	else if (key == 's' || key == 'S')//right
		return 4;

	else
	return -1;
}