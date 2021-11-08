#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"

using namespace std;

class Point {
	int x = 1, y = 1;
	int stepable;

public:
	void setPoint(int x_point, int y_point);
	int getIsStepable();
	void draw(char ch);
	//void move();
	void move(int direction);
};

#endif