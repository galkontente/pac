#include "Board.h"

void Board::Print(bool isColored) {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if (initBoard[i][j] == '#')
			{
				if (isColored == true)
					setTextColor(Color::BLUE);
				cout << '#';
			}
			if (initBoard[i][j] == '.')
			{
				setBreadCrumbCoor(i, j, 1);
				if (isColored == true)
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