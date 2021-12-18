#ifndef MENU_H
#define MENU_H
#include <string>
#include <vector>
#include "Point.h"

using namespace std;


class Menu
{
private:
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56,PICKBOARD=52, EXIT = 57, QUIT = 113 };
	enum { BEST = 49, GOOD = 50, NOVICE = 51 };

	bool isColored;
public:

	int printMainMenu()const;
	int menu();
	string askBoardFile(vector<string>  boardNames);

	bool exists(vector<string>  words, int count, const string check);
	void printInstructions()const;
	void gameOver()const;
	void youWon()const;
	bool isColorfull()const;
	int gameLevel();

};


#endif