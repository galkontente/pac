#ifndef _PAC_H_
#define _PAC_H_

#include <cstring>

#include "Color.h"
#include "Ghost.h"
#include "Creature.h"

class Pac:public Creature {
	char arrowKeys[5];
	int lives = 3;
	int initPostion[2];

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
	
	void setInitPostion(int x,int y) {
		initPostion[0] = x;
		initPostion[1] = y;

	}
	int getInitPostionX() {
		return initPostion[0];

	}
	int getInitPostionY() {
		return initPostion[1];

	}

	void move( int limit[]);
	int getDirectionInput(char key);
	

};

#endif
