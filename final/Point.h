#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"

using namespace std;

class Point {
	int x = 1, y = 1;

public:
	void setPoint(int x_point, int y_point);
	void draw(char ch);
	void drawInt(int n) {
		gotoxy(x, y);
		cout << n << endl;
	}
	void move(int direction);
	char pointBefore(int direction);
	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
};

#endif