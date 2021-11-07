#include "Board.h"



void Board::initlayOut() {
	cout << "initBoard" << endl;
	for (int i = 0; i < 80; i++)
		for (int j = 0; j < 25; j++)
			layout[i][j].setPoint(i, j);
	
}

void Board::Print() {
	for (int i = 0; i < 80; i++)
		for (int j = 0; j < 25; j++)
			layout[i][j].draw('.');

}