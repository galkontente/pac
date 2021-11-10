#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"
#include"Ghost.h"

class Game {
	enum { ESC = 27 };
	int score;
	Board board;
	Ghost ghosts[2];
	Pac p;
public:
	bool canMove(int dir, Point coor, Board board);
	char currCoorState( Point coor, Board board);
	void init();
	void run();
	
};

#endif