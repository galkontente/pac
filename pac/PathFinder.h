#pragma once
#include "Point.h"
#include "Ghost.h"
#include "Board.h"

#include <queue> 

class PathFinder
{
private:
	int trailMap[20][80];
public:
    void map_to_coordinate(int& cur_x, int& cur_y, int cur_place);
    int map_to_number(int x, int y);
    int findBestDir(Point target, Board board);
    void bfs(Point target, Ghost* ghosts, Board board);
    int goodGhosts(Point pacman, Ghost ghost[], int i, int& counter);
    bool canMove(int dir, Point coor, Board board);
    char currCoorState(Point coor, Board board);
    int stupiedGhosts(int i, int& counter, Ghost  ghosts[]);
};

