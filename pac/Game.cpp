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
	int PacmanDir, ghost1Dir = 3, ghost2Dir = 3;

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
				ghosts[0].setDirection(ghost1Dir);	
				ghost2Dir = ghosts[1].PickDirection();
				ghosts[1].setDirection(ghost2Dir);
			}
		}
		if (!ghosts[1].canPass(board, ghost1Dir, p.getX(), p.getY())) {
			for (int i = 0; i < 4; i++)
			{
				if (ghosts[0].canPass(board, i, p.getX(), p.getY())) {
					ghosts[0].setDirection(i);

					break;

				}
			}
		}
		ghosts[0].move();
	//	while (ghosts[0].canPass(board, p.getX(), p.getY()) == false)
		//{
		//	int saver1 = ghost1Dir;
		//	ghost1Dir = ghosts[0].PickDirection();
		//	while (ghost1Dir == saver1)
		//		ghost1Dir = ghosts[0].PickDirection();
		//}
		//ghosts[0].setDirection(ghost1Dir);
		if(!ghosts[1].canPass(board, ghost1Dir, p.getX(), p.getY())){
		for (int i = 0; i < 4; i++)
		{
			if (ghosts[1].canPass(board, i, p.getX(), p.getY())) {
				ghosts[1].setDirection(i);
				break;
			}
		}
		}
		ghosts[1].move();

		//while (ghosts[1].canPass(board, p.getX(), p.getY()) == false)
		//{
			//int saver2 = ghost2Dir;
			//ghost2Dir = ghosts[1].PickDirection();
			// (ghost2Dir == saver2) {
			//	ghost2Dir = ghosts[1].PickDirection();
			//}
		//}
		//ghosts[1].setDirection(ghost2Dir);
		

		//if (p.canPass(board, p.getX(), p.getY()) == false)
		//{
		//	PacmanDir = 4;
		///	p.setDirection(PacmanDir);
		//}
		p.move();
		p.move();

		Sleep(200);
	} while (key != ESC);
	//post run
	setTextColor(Color::WHITE);
	clear_screen();
}