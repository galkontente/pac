#include "Ghost.h"

void Ghost::move(char prevCoor)
{
	setTextColor(Color::WHITE);
	body.draw(prevCoor);
	body.move(direction);
	setTextColor(color);
	body.draw(figure);
	setTextColor(Color::WHITE);
}

int Ghost:: chasePacman(Point pacman) {
	int x1 = pacman.getX();
	int y1 = pacman.getY();
	int x2 = body.getX();
	int y2 = body.getY();
	if (x1 == x2 && y1 == y2) {
		return 4;
	}
	//same row
	if (x1 == x2) {
		//pacman is on my upperside
		if (y1 < y2) {
			return 0;
		}
		//pacman is on my downerside
		else {
			return 1;
		}
	}
	//same colum
	else if (y1 == y2) {
		//pacman is on my right side
		if (x1 < x2) {
			return 2;
		}
		//pacman is on my left side
		else {
			return 3;
		}
	}
	//not on the same row or column
	else {
		//pacman somewhere right to me
		if (x1 < x2) {
			//right and higer then me
			if (y1 < y2) {
				return 2;
			}
			//right and lower then me
			else {
				return 3;
			}
		}
		//pacman somewhere left to me
		else {
			//left and higer then me
			if (y1 < y2) {
				return 0;
			}
			//left and lower then me
			else {
				return 1;
			}
		}
	}
}