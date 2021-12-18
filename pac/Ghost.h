#ifndef _GHOST_H_
#define _GHOST_H_

#include "Point.h"
#include "Color.h"
#include "Creature.h"

class Ghost:public Creature
{
private:
	static int ghostAmount;
	char trail;

public:
	static int getGhostAmount() { return ghostAmount; }
	static void resetGhostAmount() { ghostAmount = 0;; }

	static void addGhost();
	void setTrail(char new_trail) {
		trail = new_trail;
	}
	char getTrail()const {
		return trail;
	}
	int chasePacman(Point pacman);
	int PickDirection() {
	
		int dir = rand() % 4;
		return dir;
	}

	void move(char prevCoor, int limits[]);

};
#endif

