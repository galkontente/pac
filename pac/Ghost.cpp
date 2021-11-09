#include "Ghost.h"

void Ghost::move()
{
	//char pointBefore = body.pointBefore(direction);
	body.draw(' ');
	body.move(direction);
	setTextColor(color);
	body.draw(figure);
}
bool Ghost::canPass(Board b,int dir, int x, int y)
{
	switch (dir) {
	case 0: // UP
		
		if (y < 1 || b.getCharInCoor(body.getX(), body.getY()-1) == '#') {
			return false;
		}
		else return true;
		break;
	case 1: // DOWN
		
		if (y > 24 || b.getCharInCoor(body.getX() , body.getY()+1) == '#') {
			return false;
		}
		else return true;

		break;
	case 2: // LEFT
		
		if (x < 1 || b.getCharInCoor(body.getX() - 1, body.getY()) == '#') {
		return false;
		}
		else return true;

		break;
	case 3: // RIGHT
	
		if (x > 79 || b.getCharInCoor(body.getX() + 1, body.getY()) == '#') {
			return false;
		}
		else return true;

		break;
	case 4: // STAND
		
		break;

	}

	//if ((direction == 0 && b.getCharInCoor(body.getX(), body.getY() - 1) == '#') || //UP
		//(direction == 0 && b.getCharInCoor(body.getX(), body.getY() - 1) == ' ') || //UP
	//	(direction == 1 && b.getCharInCoor(body.getX(), body.getY() + 1) == '#') || //DOWN
	//	(direction == 1 && b.getCharInCoor(body.getX(), body.getY() + 1) == ' ') || //DOWN
		//(direction == 2 && b.getCharInCoor(body.getX() - 1, body.getY()) == '#') || //LEFT
	//	(direction == 2 && b.getCharInCoor(body.getX() - 1, body.getY()) == ' ') || //LEFT
		//(direction == 3 && b.getCharInCoor(body.getX() + 1, body.getY()) == '#') || //RIGHT
		//(direction == 3 && b.getCharInCoor(body.getX() + 1, body.getY()) == ' '))   //RIGHT
		//return false;

//	return true;
}
