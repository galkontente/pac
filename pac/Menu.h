#ifndef MENU_H
#define MENU_H

#include <cstring>

class Menu
{
private:
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56, EXIT = 57, QUIT = 113 };
	enum { BEST = 49, GOOD = 50, NOVICE = 51};
	bool isColored;
public:

	int printMainMenu()const;
	int menu();
	void printInstructions()const;
	void gameOver()const;
	void youWon()const;
	bool isColorfull()const;
	int gameLevel();

};


#endif