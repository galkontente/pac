#ifndef _PAC_H_
#define _PAC_H_

#include <cstring>
#include "Point.h"
#include "Color.h"
#include "Board.h"

class Pac {
	Point body;
	int direction = 3;
	char arrowKeys[4];
	Color color;
	char figure;
	//Board b;

public:

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
		direction = dir;}
	
	int getX() {
		return body.getX();};

	int getY() {
		return body.getY();};

	bool canPass(Board b, int x, int y);
};

#endif
