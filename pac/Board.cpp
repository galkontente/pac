#include "Board.h"



void Board::initlayOut() {

	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 80; j++)
			layout[i][j] = 1;

	for (int r = 0; r<50; r++) {
		layout[0][r] = 0;
		layout[24][r] = 0;

	}
		for (int c = 0; c < 79; c++)
			layout[24][c] = 0;


}

void Board::Print(){
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if(initBoard[i][j]== '0')
				cout << '#';
			if (initBoard[i][j] == '1')
				cout << '.';
		}

	cout << endl;
	}
}