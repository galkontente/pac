#ifndef CREATURE_H
#define CREATURE_H
#include "Point.h"
#include "Color.h"
#include <cstring>

class Creature
{
private:
	char figure;
	int direction = rand() % 4;
	Color color;

protected:
	Point body;


public:

	void setColor(Color c) {
		color = c;
	}
	void setFigure(const char c) {
		figure = c;
	}

	char getFigure()
	{
		return figure;
	}

	void setDirection(int dir) {
		direction = dir;
	}

	Color getColor() {
		return color;
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