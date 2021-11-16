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
	x = x_point;
	y = y_point;
}

//void Point::move() {
//	int dir = rand() % 4;
//	move(dir);
//}



void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		if (y == 1)
			break;
		--y;
		if (y < 1) {
			y = 24;
		}
		break;
	case 1: // DOWN
		if (y == 80)
			break;
		++y;
		if (y > 24) {
			y = 1;
		}
		break;
	case 2: // LEFT
		if (x == 0)
			break;
		--x;
		if (x < 1) {
			x = 79;
		}
		break;
	case 3: // RIGHT
		if (x == 80)
			break;
		++x;
		if (x > 79) {
			x = 1;
		}
		break;
	case 4://STAND
		break;
	}
}