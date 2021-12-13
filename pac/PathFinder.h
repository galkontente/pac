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
    void map_to_coordinate(int & cur_x, int & cur_y, int cur_place) {
        cur_x = cur_place / 20;
        cur_y= cur_place % 20;
    }

    int map_to_number(int x, int y) {
        return y*(20)+x;
    }

    int findBestDir(Point target,Board board) {
        int limits[4] = { board.getBoardLimit(0),board.getBoardLimit(1),board.getBoardLimit(2),board.getBoardLimit(3) };

        int x = target.getX();
        int y = target.getY();
        int min=0;
        int dx[] = { 0, 0, -1, 1 };
        int dy[] = { -1,1, 0, 0 };
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

	void bfs(Point target, Ghost* ghosts,Board board) {
        int limits[4] = { board.getBoardLimit(0),board.getBoardLimit(1),board.getBoardLimit(2),board.getBoardLimit(3) };

        int ghostAmount = Ghost::getGhostAmount();
        int dx[] = { 0, 1, 0, -1 };
        int dy[] = { 1, 0, -1, 0 };
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
                    if (trailMap[cur_y + dy[i]][cur_x + dx[i]] ==4700 && cur_x + dx[i] >= limits[2] && cur_x + dx[i] <= limits[3] && cur_y + dy[i] <= limits[1] && cur_y + dy[i] >= limits[0] && board.getBoardCoor(cur_y ,cur_x )!='#') {
                        queue.push(map_to_number(cur_y + dy[i], cur_x + dx[i]));

                     
                      trailMap[cur_y + dy[i]][cur_x + dx[i]] = cur_distance + 1;
                       /*target.setPoint(cur_x, cur_y);
                        if (board.getBoardCoor(cur_y, cur_x) != '&' && board.getBoardCoor(cur_y, cur_x) != '@')
                            target.drawInt(trailMap[cur_y ][cur_x ]>9? 9: trailMap[cur_y][cur_x]);*/
                    }
                }
            }
      
            // now grid is filled, so now you should find out for each ghost how to move
        
	}
};

