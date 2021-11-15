#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"
#include"Ghost.h"

class Game {
	enum { ESC = 27, START_GAME = 1, INSTRUCTIONS = 8, EXIT = 9};
	int score;
	Board board;
	Ghost ghosts[2];
	bool isColored = false;
	Pac p;
public:
	bool canMove(int dir, Point coor, Board board, bool isGhost);
	char currCoorState( Point coor, Board board);
	void init(bool isColored);
	bool getIsColored() { return isColored; };
	void run();
	void printMainMenu();//how do i make it const?$
	void menu();
	void printInstructions();
	
};

#endif