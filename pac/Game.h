#ifndef THEPACGAME_H
#define THEPACGAME_H

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"
#include"PathFinder.h"
#include"Menu.h"
#include"Fruit.h"

#include"Ghost.h"



class Game {
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56, EXIT = 57, QUIT = 113 };
	enum { BEST = 49, GOOD = 50, NOVICE = 51 };
	unsigned int score = 0;
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
	bool canMove(int dir, Point coor, Board board, bool isPacman);
	char currCoorState(Point coor, Board board);
	void drawScore() {
		stats.draw(score);
	}
	void init(bool isColored);
	void addToScore(int i);
	void run(int level);


	//void printMainMenu()const;
	void gameFlow();
	void setIsColored(bool res) { isColored = res; };
	//void printInstructions()const;
	bool getIsColored()const { return isColored; };
	void setScore(int newScore);
	bool doesGhostMeetsFruit(int i);
	bool doesPacMeetsFruit();
	void youWon()const;
	void gameOver()const;



};

#endif