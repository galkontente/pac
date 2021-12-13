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