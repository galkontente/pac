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


void Point::movePoint(int dir,int limit[]) {
	int upLimit = limit[0];
	int downLimit = limit[1];
	int leftLimit = limit[2];
	int rightLimit = limit[3];
	switch (dir) {
	case 0: // UP
		if (y == 1)
			break;
		--y;
		if (y < upLimit) {
			y = downLimit;
		}
		break;
	case 1: // DOWN
		if (y == 80)
			break;
		++y;
		if (y > downLimit) {
			y = upLimit;
		}
		break;
	case 2: // LEFT
		if (x == 0)
			break;
		--x;
		if (x < leftLimit) {
			x = rightLimit;
		}
		break;
	case 3: // RIGHT
		if (x == 80)
			break;
		++x;
		if (x > rightLimit) {
			x = leftLimit;
		}
		break;
	case 4://STAND
		break;
	}
}