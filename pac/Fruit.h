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

public:

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

	void move(char prevCoor);
};
#endif