#ifndef FRUIT_H
#define FRUIT_H
#include <cstring>
#include "Point.h"
#include "Color.h"
#include "creature.h"

class Fruit : public Creature
{
private:
	char trail;
	int lifeDur = 0;
	int waitUntill = 0;

public:
	void setLifeDur(int time) {
		lifeDur = time;
	}
	int getLifeDur()const {
		return lifeDur;
	}
	void setWaitUntill(int time) {
		waitUntill = time;
	}
	int  getWaitUntill()const {
		return waitUntill;
	}
	void setTrail(char new_trail) {
		trail = new_trail;
	}
	char getTrail()const {
		return trail;
	}
	int PickDirection() {

		int dir = rand() % 4;
		return dir;
	}

	void move(char prevCoor, int limits[]);
};
#endif