#ifndef _GHOST_H_
#define _GHOST_H_
#include <cstring>
#include "Point.h"
#include "Color.h"
class Ghost
{
private:
	Point body;
	int direction;//$ we need to set the directions
	Color color;
	char figure;

public:
	void setColor(Color c) {
		color = c;
	}
	void setFigure(const char c) {
		figure = c;
	}
};
#endif

