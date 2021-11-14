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
				setBreadCrumbCoor(i, j, 1);
				setTextColor(Color::WHITE);
				cout << '.';
			}
			if (initBoard[i][j] == ' ')
			{
				setBreadCrumbCoor(i, j, 0);
				cout << ' ';
			}
		}

	cout << endl;
	}
	for (int i = 0; i < 81; i++)
	{
		cout << initBoard[25][i];
	}
}