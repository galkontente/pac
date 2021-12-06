#ifndef _MENU_H_
#define _MENU_H_

#include <cstring>

class Menu
{
private:
	enum { ESC = 27, START_GAME = 49, INSTRUCTIONS = 56, EXIT = 57, QUIT = 113 };
	bool isColored;
public:

	void printMainMenu()const;
	////void menu();
	void printInstructions()const;
	
};


#endif

