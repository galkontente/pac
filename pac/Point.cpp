#include "Point.h"

void Point::draw(char ch) {
	gotoxy(x, y);
	cout << ch << endl;
}

char Point::pointBefore(int dir) {
	char ch;
	switch (dir) {
	case 0: // UP
		gotoxy(x, ++y);
		cin >> &ch;
		gotoxy(x, --y);
		return ch;
	case 1: // DOWN
		gotoxy(x, --y);
		cin >> &ch;
		gotoxy(x, ++y);
		return ch;
	case 2: // LEFT
		gotoxy(++x, y);
		cin >> &ch;
		gotoxy(--x, y);
		return ch;
	case 3: // RIGHT
		gotoxy(--x, y);
		cin >> &ch;
		gotoxy(++x, y);
		return ch;
	}
}



void Point::setPoint(int x_point, int y_point) {
	this->x = x_point;
	this->y = y_point;
}

//void Point::move() {
//	int dir = rand() % 4;
//	move(dir);
//}

int Point::getIsStepable() {
	return this->stepable;
}

void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		
		if (y > 1) {
			--y;
		}
		break;
	case 1: // DOWN
		
		if (y < 24) {
			++y;
		}
		break;
	case 2: // LEFT
		
		if (x > 1) {
			--x;
		}
		break;
	case 3: // RIGHT
		
		if (x <79) {
			++x;
		}
		break;
	case 4://STAND
		break;
	}

	


}