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
//		= {
////   0123456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
//	"################################################################################",
//	"#..............................#...............#...............................#",
//	" .............................................................................. ",
//	"#..............................###################.............................#",
//	"###########............................##.............................##########",
//	"###########............................##.............................##########",
//	"###########........##..................##...................##........##########",
//	"###########........##..................##...................##........##########",
//	" ..................##...####.........................#####..##................. ",
//	"###########........##...####.........................#####..##........##########",
//	"###########........##.......................................##........##########",
//	"###########........##..................##...................##........##########",
//	"###########............................##.............................##########",
//	"###########............................##.............................##########",
//	"#......................................##......................................#",
//	"#.............................###################..............................#",
//	" ........##..........................................................##........ ",
//	"#........##...................#.................#....................##........#",
//	"################################################################################",
//	"score:0----lives:---------------------------------------------------------------"
//	};

	enum type{WALL,PATH,PATH_BC};
public:
	void findBoardBorders(const char* filePath) {
		bool findBorderFlag = false;
		char tmpBoard[20][81];
		int topBorder = 0, bottomBorder = 0, leftBorder = 0, rightBorder = 0;
		ifstream infile;
		infile.open(filePath);

	
		if (!infile) {
			cout << "bad name" << filePath << endl;
			exit(0);
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 81; ++j) {
				char next = infile.get();
					tmpBoard[i][j] = next;
					cout << next;
			}
		
		}

		for (int i = 0; i < 20; i++)
		{
			if (tmpBoard[i][20] == '#') {
				BoardLimits[0] = i;
				break;
			}
		}
		for (int i = 19; i > 0; i--)
		{
			if (tmpBoard[i][20] == '#') {
				BoardLimits[1] = i;
				break;
			}
		}
		for (int i =0; i <80; i++)
		{
			if (tmpBoard[topBorder][i] == '#') {
				BoardLimits[2] = i;
				break;
			}
		}
		for (int i = 80; i>0; i--)
		{
			if (tmpBoard[topBorder][i] == '#') {
				BoardLimits[3] = i;
				break;
			}
		}
		cout << endl;
		cout <<"top" << topBorder << "bottom" << bottomBorder << "left" << leftBorder << "right" << rightBorder << endl;

	}

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
	int maxScore();

	void initBoardFromFile(const char * filePath) {
		ifstream infile;
		infile.open(filePath);
		char tmpBoard[20][81];

		if (!infile) {
			cout << "bad name" << filePath << endl;
			exit(0);
		}
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < 81; ++j) {
				char next = infile.get();
				tmpBoard[i][j] = next;
				initBoard[i][j] = next;

			}
		}

		for (int i = 0; i < 20; i++)
		{
			if (tmpBoard[i][20] == '#') {
				BoardLimits[0] = i;
				break;
			}
		}
		for (int i = 19; i > 0; i--)
		{
			if (tmpBoard[i][20] == '#') {
				BoardLimits[1] = i;
				break;
			}
		}
		for (int i = 0; i < 80; i++)
		{
			if (tmpBoard[BoardLimits[0]][i] == '#') {
				BoardLimits[2] = i;
				break;
			}
		}
		for (int i = 79; i > 0; i--)
		{
			if (tmpBoard[BoardLimits[0]][i] == '#') {
				BoardLimits[3] = i;
				break;
			}
		}
	}

};
#endif