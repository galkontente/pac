#ifndef _BOARD_H_
#define _BOARD_H_
#include "Point.h"
#include "Ghost.h"
#include "Pacman.h"

#include <fstream>

class Board
{
private:
	int layout[20][81];
	char initBoard[20][81];
	int BoardLimits[4] = { 0,0,0,0 };
	int scoreLenged = 0;
	int lifeLenged = 0;
	

	enum type{WALL,PATH,PATH_BC};
public:
	void findBoardBorders(const char* filePath);
	int getBoardLimit(int limitNum) {
		return BoardLimits[limitNum];
	}
	void Print(bool isColored,Ghost * ghosts, Point & pacman);
	char getBoardCoor(int x, int y)const {
		return initBoard[x][y];
	}

	int getLifeLegendPost() {
		return lifeLenged;
	}
	int getScoreLegendPost() {
		return scoreLenged;
	}
	void setLenged(int life, int score) {
		lifeLenged = life;
		scoreLenged = score;
	}
	void setBreadCrumbCoor(int x, int y,int curr) {
		layout[x][y]=curr;
	}
	bool getBreadCrumbCoor(int x, int y)const {
		return layout[x][y];
	}
	bool checkIfBoardCompleted();
	int maxScore();
	void initBoardFromFile(const string filePath);
	

};
#endif