#ifndef _PAC_H_
#define _PAC_H_

#include <cstring>

#include "Color.h"
#include "Ghost.h"

class Pac {
	Point body;
	int direction = 4;
	char arrowKeys[5];
	Color color;
	int lives = 3;
	char figure;
	int initPostion[2];

public:
	void setLives(int newlives) {
		lives = newlives;
	}
	int getLives()const {
		return lives;
	}
	void setArrowKeys(const char* keys) { 
		arrowKeys[0] = keys[0];
		arrowKeys[1] = keys[1];
		arrowKeys[2] = keys[2];
		arrowKeys[3] = keys[3];
		arrowKeys[4] = keys[4];
	}
	void setColor(Color c) {
		color = c;
	}
	void setInitPostion(int x,int y) {
		initPostion[0] = x;
		initPostion[1] = y;

	}
	int getInitPostionX() {
		return initPostion[0];

	}
	int getInitPostionY() {
		return initPostion[1];

	}
	void setFigure(const char c) {
		figure = c;
	}
	void move( int limit[]);
	int getDirection(char key);
	void setDirection(int dir) {
		direction = dir;
	}

	Point getPoint()const {
		return body;
	}
	Point& getPointByRef() {
		return body;
	}
	int getDir()const {
		return direction;
	}

};

#endif
