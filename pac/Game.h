#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"

class Game {
	enum { ESC = 27 };
	int score;
	Board board;
	//Ghost ghosts[2];
	//$ BreadCrumbs class and than make it an array here????????

	Pac p;
public:
	void init();
	void run();
};

#endif