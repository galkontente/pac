#ifndef _PAC_H_
#define _PAC_H_

#include <cstring>
#include "Point.h"
#include "Color.h"

class Pac {
	Point body;
	int direction;
	char arrowKeys[4];
	Color color;
	int lives = 3;
	char figure;
public:
	void setLives(int newlives) {
		lives = newlives;
	}
	int getLives() {
		return lives;
	}
	void setArrowKeys(const char* keys) { 
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

	Point getPoint() {
		return body;
	}
	int getDir() {
		return direction;
	}

};

#endif
