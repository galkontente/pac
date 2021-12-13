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
			if (initBoard[i][j] == '&') {
				setLenged(i, i + 12);
			}
			else if (initBoard[i][j] == '$' && Ghost::getGhostAmount() <4)
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
		}
		std::cout << endl;
	}
	for (int i = 0; i < 81; i++)
	{
		std::cout << initBoard[19][i];
	}
}