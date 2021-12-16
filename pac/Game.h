#ifndef _THEPACGAME_H_
#define _THEPACGAME_H_

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"
#include"PathFinder.h"
#include"Menu.h"
#include"Fruit.h"

#include"Ghost.h"



class Game {
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56, EXIT = 57, QUIT = 113 };
	unsigned int score=0;
	Point stats;
	Board board;
	bool isColored = false;
	Ghost ghosts[4];
	vector<string> boardNames;
	PathFinder ghostLogic;
	Pac p;
	Menu menu;
	Fruit fruit;

public:
	bool canMove(int dir, Point coor, Board board,bool isPacman);
	char currCoorState( Point coor, Board board);
	void drawScore() {
		stats.draw(score);
	}
	void init(bool isColored);
	void addToScore();
	void run();


	//void printMainMenu()const;
	void gameFlow();
	void setIsColored(bool res) { isColored = res; };
	//void printInstructions()const;
	bool getIsColored()const { return isColored; };
	void setScore(int newScore);

};

#endif