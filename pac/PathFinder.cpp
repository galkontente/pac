#include "PathFinder.h"


int PathFinder::stupiedGhosts(int i, int &counter,Ghost  ghosts[])
{
	int dir;
    if (counter < 20)
    {
		counter++;
		dir = ghosts[i].getDir();
		return dir;
    }
    if (counter == 20)
    {
        ghosts[i].PickDirection();
        counter = 0;
		dir = ghosts[i].getDir();
		return dir;

    }
    
}


char PathFinder::currCoorState(Point coor, Board board) {
    int x = coor.getX();
    int y = coor.getY();
    return board.getBreadCrumbCoor(y, x) ? '.' : ' ';
}


bool PathFinder::canMove(int dir, Point coor, Board board) {
    int x = coor.getX();
    int y = coor.getY();
    switch (dir) {
    case 0: // UP
        if ((y <= board.getBoardLimit(0)) || board.getBoardCoor(--y, x) == '#') {
            return false;
        }

        else return true;
        break;
    case 1: // DOWN

        if ((y >= board.getBoardLimit(1) ) || board.getBoardCoor(++y, x) == '#') {
            return false;
        }

        else return true;
        break;
    case 2: // LEFT
        if ((x <= board.getBoardLimit(2)) || board.getBoardCoor(y, --x) == '#') {
            return false;
        }
        else return true;
        break;
    case 3: // RIGHT

        if ((x >= board.getBoardLimit(3)) || board.getBoardCoor(y, ++x) == '#') {
            return false;
        }

        else return true;
        break;
    }

    return false;
}


int PathFinder::goodGhosts(Point pacman, Ghost ghost[], int i, int &counter) {
	int x1 = pacman.getX();
	int y1 = pacman.getY();
	int x2 = ghost[i].getPoint().getX();
	int y2 = ghost[i].getPoint().getY();
	if (counter < 20)
	{
		if (x1 == x2 && y1 == y2) {
			return 4;
		}
		//same row
		if (x1 == x2) {
			//pacman is on my upperside
			if (y1 < y2) {
				return 0;
			}
			//pacman is on my downerside
			else {
				return 1;
			}
		}
		//same colum
		else if (y1 == y2) {
			//pacman is on my right side
			if (x1 < x2) {
				return 2;
			}
			//pacman is on my left side
			else {
				return 3;
			}
		}
		//not on the same row or column
		else {
			//pacman somewhere right to me
			if (x1 < x2) {
				//right and higer then me
				if (y1 < y2) {
					return 2;
				}
				//right and lower then me
				else {
					return 3;
				}
			}
			//pacman somewhere left to me
			else {
				//left and higer then me
				if (y1 < y2) {
					return 0;
				}
				//left and lower then me
				else {
					return 1;
				}
			}
		}
	}
	else if (counter < 20)
	{
		int dir = rand() % 4;
		counter = 0;
	}
	
	counter++;
	
}