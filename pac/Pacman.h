#ifndef _PAC_H_
#define _PAC_H_

#include <cstring>
#include "Point.h"
#include "Color.h"
#include "creature.h"

class Pac : public Creature {
	char arrowKeys[5];
	int lives = 3;
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
	
	void move();
	int getDirection(char key);//to the crature?$
	

};

#endif
