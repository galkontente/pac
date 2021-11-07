#include "Game.h"

void Game::init()
{
	p.setArrowKeys("wsad");
	board.initlayOut();
	//board.PrintLayout();
	p.setColor(Color::YELLOW);
	p.setFigure('@');
}
void Game::run()
{
	char key = 0;
	int dir;
	board.Print();
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

	setTextColor(Color::WHITE);
	clear_screen();
}