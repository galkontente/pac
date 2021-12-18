#ifndef THEPACGAME_H
#define THEPACGAME_H

#include "io_utils.h"
#include "Pacman.h"
#include "Board.h"
#include"PathFinder.h"
#include"Fruit.h"
#include <filesystem>

#include"Menu.h"
#include"Ghost.h"



class Game {
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56, PICKBOARD = 52, EXIT = 57, QUIT = 113 };
	enum { BEST = 49, GOOD = 50, NOVICE = 51 };

	unsigned int score=0;
	int level= GOOD;
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
	void init(bool isColored, bool readFiles);
	void addToScore();
	void run();

	int getLevel()const{
		return level;
	}
	void setLevel(int newLevel){
		level = newLevel;
	}
	//void printMainMenu()const;
	void gameFlow();
	void setIsColored(bool res) { isColored = res; };
	//void printInstructions()const;
	bool getIsColored()const { return isColored; };
	void setScore(int newScore);
	bool doesGhostMeetsFruit(int i);
	bool doesPacMeetsFruit();

};

#endif