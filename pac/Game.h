#ifndef _THEPACGAME_H_
#define _THEPACGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"
#include"Ghost.h"



class Game {
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56, EXIT = 57};
	unsigned int score=0;
	Point stats;
	Board board;
	bool isColored = false;
	Ghost ghosts[2];
	Pac p;

public:
	bool canMove(int dir, Point coor, Board board,bool isPacman);
	char currCoorState( Point coor, Board board);
	void drawScore() {
		stats.draw(score);
	}
	void init(bool isColored);
	void addToScore();
	void run();
	void printMainMenu();//how do i make it const?$
	void menu();
	void printInstructions();
	bool getIsColored() { return isColored; };
	
};

#endif