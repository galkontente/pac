#ifndef _CREATURE_H_
#define _CREATURE_H_
#include "Point.h"
#include "Color.h"
#include <cstring>

class Creature
{
private:
	
	Point body;
	Color color;
	char figure;
	int direction = rand() % 4;

public:

	void setColor(Color c) {
		color = c;
	}
	void setFigure(const char c) {
		figure = c;
	}

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
