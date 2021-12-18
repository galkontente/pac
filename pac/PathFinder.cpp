#include "PathFinder.h"


int PathFinder::stupiedGhosts(int i, int& counter, Ghost  ghosts[])
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

		if ((y >= board.getBoardLimit(1)) || board.getBoardCoor(++y, x) == '#') {
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


int PathFinder::goodGhosts(Point pacman, Ghost ghost[], int i, int& counter) {
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




void PathFinder:: map_to_coordinate(int& cur_x, int& cur_y, int cur_place) {
	cur_x = cur_place / 20;
	cur_y = cur_place % 20;
}

int PathFinder::map_to_number(int x, int y) {
	return y * (20) + x;
}

int PathFinder::findBestDir(Point target, Board board) {
	int limits[4] = { board.getBoardLimit(0),board.getBoardLimit(1),board.getBoardLimit(2),board.getBoardLimit(3) };

	int x = target.getX();
	int y = target.getY();

	int min = 0;
	int dx[] = { 0, 0, -1, 1 };
	int dy[] = { -1,1, 0, 0 };
	//find first legal dir
	for (int i = 0; i < 4; i++)
	{
		if (board.getBoardCoor(y + dy[i], x + dx[i]) != '#') {
			min = i;
			break;
		}
	}
	for (int i = 0; i < 4; i++)
	{

		if (x + dx[i] >= limits[2] && x + dx[i] <= limits[3] && y + dy[i] <= limits[1] && y + dy[i] >= limits[0] && board.getBoardCoor(y + dy[i], x + dx[i]) != '#') {
			if (trailMap[y + dy[min]][x + dx[min]] == trailMap[y + dy[i]][x + dx[i]]) {
				int ra = rand() % 2;
				min = (ra == 1) ? i : min;
			}

			if (trailMap[y + dy[min]][x + dx[min]] > trailMap[y + dy[i]][x + dx[i]]) {
				min = i;
			}
		}

	}
	return min;
}

void PathFinder::bfs(Point target, Ghost* ghosts, Board board) {
	int limits[4] = { board.getBoardLimit(0),board.getBoardLimit(1),board.getBoardLimit(2),board.getBoardLimit(3) };
	int ghostsLocations[4];
	int ghostAmount = Ghost::getGhostAmount();

	int dx[] = { 0, 1, 0, -1 };
	int dy[] = { 1, 0, -1, 0 };
	for (int i = 0; i < ghostAmount; i++)
	{
		ghostsLocations[i] = map_to_number(ghosts[i].getPointByRef().getX(), ghosts[i].getPointByRef().getY());
	}
	int foundGhost = 0;
	std::queue<int> queue;

	// initialize grid
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 80; j++)
		{
			trailMap[i][j] = 4700;
		}
	}
	queue.push(map_to_number(target.getY(), target.getX()));
	// add starting position of pacman to queue
	trailMap[target.getY()][target.getX()] = 0;
	while (!queue.empty() && foundGhost != ghostAmount) {
		// remove and access first element

		int cur_place = queue.front(); queue.pop();
		int cur_x;
		bool skip = false;
		int cur_y;
		map_to_coordinate(cur_x, cur_y, cur_place);

		for (int k = 0; k < ghostAmount; k++)
		{
			int ghostx = ghosts[k].getPointByRef().getX();
			int ghosty = ghosts[k].getPointByRef().getY();
			if (cur_x == ghostx && cur_y == ghosty) {
				foundGhost = foundGhost + 1;
				skip = true;
				break;
			}
		}
		/*if (skip)
			continue;*/
		int cur_distance = trailMap[cur_y][cur_x];
		for (int i = 0; i < 4; i++) {
			bool ghostConfilt = false;
			for (int j = 0; j < 4; j++)
			{
				int ghostX = ghosts[j].getPointByRef().getX();
				int ghostY = ghosts[j].getPointByRef().getY();
				if (ghostY == cur_y + dy[i] && ghostX == cur_x + dx[i]) {
					ghostConfilt = true;
				}

			}
			if (!ghostConfilt && trailMap[cur_y + dy[i]][cur_x + dx[i]] == 4700 && cur_x + dx[i] >= limits[2] && cur_x + dx[i] <= limits[3] && cur_y + dy[i] <= limits[1] && cur_y + dy[i] >= limits[0] && board.getBoardCoor(cur_y, cur_x) != '#') {
				queue.push(map_to_number(cur_y + dy[i], cur_x + dx[i]));


				trailMap[cur_y + dy[i]][cur_x + dx[i]] = cur_distance + 1;
				/*   target.setPoint(cur_x, cur_y);
					if (board.getBoardCoor(cur_y, cur_x) != '&' && board.getBoardCoor(cur_y, cur_x) != '@')
						target.drawInt(trailMap[cur_y ][cur_x ]>9? 9: trailMap[cur_y][cur_x]);*/
			}
		}
	}

	// now grid is filled, so now you should find out for each ghost how to move

}