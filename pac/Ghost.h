#ifndef _GHOST_H_
#define _GHOST_H_
#include <cstring>
#include "Point.h"
#include "Color.h"
#include "Board.h"
class Ghost
{
private:
	Point body;
	int direction = rand() % 4;
	Color color;
	char figure;
	//Board b;

public:
	void setColor(Color c) {
		color = c;
	}
	void setFigure(const char c) {
		figure = c;
	}
	int PickDirection() {
		int dir = rand() % 4;
		return dir;
	}
	void setDirection(int dir) {
		direction = dir;
	}
	void move();

	bool canPass(Board b,int dir, int x, int y);
};
#endif

