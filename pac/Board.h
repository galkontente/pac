#ifndef _BOARD_H_
#define _BOARD_H_

#include "Point.h"
class Board
{
public:
	void Print();
	void initlayOut();

private:
	Point layout[80][25];


};
#endif