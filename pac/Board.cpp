#include "Board.h"

int Board::maxScore()
{
	int count = 0;
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if (initBoard[i][j] == '.')
				count++;
		}
	}
	return count;
}


void Board::Print(bool isColored, Ghost* ghosts, Point & pacman) {
	
	
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 81; j++) {
			/*if (initBoard[i][j] == '&') {
				setLenged(i, i + 12);
			}*/
			 if (initBoard[i][j] == '$' && Ghost::getGhostAmount() <4)
			{
				int ghostA = Ghost::getGhostAmount();
				ghosts[ghostA].setFigure('&');
				ghosts[ghostA].getPointByRef().setPoint(j, i);
				if (isColored) {
					ghosts[ghostA].setColor(Color(ghostA +2));//plus 2 to skip black and dark blue colors
				}
				else {
					ghosts[ghostA].setColor(Color::WHITE);
				}
				std::cout << '&';

				Ghost::addGhost();
				continue;

			}
			else if (initBoard[i][j] == '@') {
				pacman.setPoint(j, i);
				std::cout << '@';
				continue;
			}
		
			else if (initBoard[i][j] == '#')
			{
				if (isColored == true)
					setTextColor(Color::BLUE);
				std::cout << '#';
				continue;
			}
			else if (initBoard[i][j] == ' ' )
			{
				if(i<BoardLimits[1] && i>BoardLimits[0] && BoardLimits[3]>j && BoardLimits[2]<j){
				setBreadCrumbCoor(i, j, 1);
				if (isColored == true)
					setTextColor(Color::WHITE);
				std::cout << '.';
				continue;
				}
				else {
					std::cout << ' ';
					setBreadCrumbCoor(i, j, 0);
					continue;
				}
			}
			else if (initBoard[i][j] == '%')
			{
				setBreadCrumbCoor(i, j, 0);
				std::cout << ' ';
				continue;
			}
			else if (initBoard[i][j] == '&')
			{
				setLengedPos(i);

			}
		}
		std::cout << endl;
	}

}

bool Board::checkIfBoardCompleted() {
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 80; j++) {
			if (layout[i][j] == 1)
				return false;
		}
	}
	return true;
}

void Board:: initBoardFromFile(const string filePath) {
	ifstream infile;
	infile.open(filePath);
	char tmpBoard[20][81];

	if (!infile) {
		cout << "bad name" << filePath << endl;
		exit(0);
	}

	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 81; ++j) {
			initBoard[i][j]=' ';
			
		}
	}
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 81; ++j) {
			char next = infile.get();
			if (next == '\n') {
				break;
			}
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