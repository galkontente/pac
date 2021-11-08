#include "Game.h"

void Game::init()
{
	p.setArrowKeys("wsad");
	board.initlayOut();
	p.setColor(Color::YELLOW);
	p.setFigure('@');
}


void Game::run()
{
	//pre run
	char key = 0;
	int dir;
	board.Print();
	//run
	do {
		if (_kbhit())
		{
			key = _getch();
			if ((dir = p.getDirection(key)) != -1)
				p.setDirection(dir);

		}

			p.move();
		Sleep(200);
	} while (key != ESC);
	//post run
	setTextColor(Color::WHITE);
	clear_screen();
}