#ifndef _GHOST_H_
#define _GHOST_H_
#include <cstring>
#include "Point.h"
#include "Color.h"
class Ghost
{
private:
	Point body;
	int direction = rand() % 4;
	Color color;
	char figure;
	char trail;

public:
	void setTrail(char new_trail) {
		trail = new_trail;
	}
	char getTrail() {
		return trail;
	}
	Point getPoint() {
		return body;
	}

	//Point setPoint(Point _body) {
	//	body = _body;
	//}

	int getDir() {
		return direction;
	}
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
	void move(char prevCoor);

};
#endif

