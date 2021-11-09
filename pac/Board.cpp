#include "Board.h"



void Board::initlayOut() {


}

void Board::Print(){
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if (initBoard[i][j] == '#')
			{
				setTextColor(Color::BLUE);
				cout << '#';
			}
			if (initBoard[i][j] == '.')
			{
				setTextColor(Color::WHITE);
				cout << '.';
			}
			if (initBoard[i][j] == ' ')
			{
				cout << ' ';
			}
		}

	cout << endl;
	}
}