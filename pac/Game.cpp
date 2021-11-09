#include "Game.h"

void Game::init()
{
	p.setArrowKeys("wsad");
	board.initlayOut();
	p.setColor(Color::YELLOW);
	p.setFigure('@');
	ghosts[0].setColor(Color::CYAN);
	ghosts[1].setColor(Color::MAGENTA);
	ghosts[0].setFigure('&');
	ghosts[1].setFigure('&');

}


void Game::run()
{
	//pre run
	char key = 0;
	int PacmanDir, ghost1Dir, ghost2Dir;

	board.Print();
	//while run

	do {
		if (_kbhit())
		{
			key = _getch();
			if ((PacmanDir = p.getDirection(key)) != -1)
			{
				p.setDirection(PacmanDir);
				
				ghost1Dir = ghosts[0].PickDirection();
				//ghosts[0].
				ghosts[0].setDirection(ghost1Dir);
				if (ghosts[0].b)
				ghost2Dir = ghosts[1].PickDirection();
				ghosts[1].setDirection(ghost2Dir);
			}
		}
		
		ghosts[0].move();
		ghosts[1].move();

		p.move();
		p.move();

		Sleep(200);
	} while (key != ESC);
	//post run
	setTextColor(Color::WHITE);
	clear_screen();
}