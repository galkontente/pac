#ifndef _PAC_H_
#define _PAC_H_

#include <cstring>
#include "Point.h"
#include "Color.h"

class Pac {
	Point body;
	int direction = 3;
	char arrowKeys[4];
	Color color;
	char figure;
public:
	void setArrowKeys(const char* keys) { // "wzad"
		arrowKeys[0] = keys[0];
		arrowKeys[1] = keys[1];
		arrowKeys[2] = keys[2];
		arrowKeys[3] = keys[3];
	}
	void setColor(Color c) {
		color = c;
	}
	void setFigure(const char c) {
		figure = c;
	}
	void move();
	int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}

};

#endif
