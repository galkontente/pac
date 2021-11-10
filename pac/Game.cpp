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
				ghosts[0].setDirection(ghosts[0].PickDirection());
				ghosts[1].setDirection(ghosts[1].PickDirection());
			}
		}
		if(canMove(ghosts[0].getDir(), ghosts[0].getPoint(),board)){
			char coorState = currCoorState(ghosts[0].getPoint(), board);
			ghosts[0].move(coorState);
		}
		else {
			while(!canMove(ghosts[0].getDir(), ghosts[0].getPoint(), board))
			{
					ghosts[0].setDirection(ghosts[0].PickDirection());	
			}
			char coorState = currCoorState( ghosts[0].getPoint(), board);
			ghosts[0].move(coorState);
		}
		if (canMove(ghosts[1].getDir(), ghosts[1].getPoint(), board)) {
			char coorState = currCoorState( ghosts[1].getPoint(), board);
			ghosts[1].move(coorState);
			

		}
		else {
			while (!canMove(ghosts[1].getDir(), ghosts[1].getPoint(), board))
			{
				ghosts[1].setDirection(ghosts[1].PickDirection());
			}
			char coorSaver = currCoorState( ghosts[1].getPoint(), board);
			ghosts[1].move(coorSaver);
		}
		
		if (canMove(p.getDir(),p.getPoint(), board)) {
			int x = p.getPoint().getX();
			int y = p.getPoint().getY();
			board.setBreadCrumbCoor(y, x, 0);
			p.move();
		}

		Sleep(200);
	} while (key != ESC);
	//post run
	setTextColor(Color::WHITE);
	clear_screen();
}

bool Game::canMove(int dir, Point coor, Board board) {
	int x = coor.getX();
	int y = coor.getY();
	switch (dir) {
	case 0: // UP
		if (y <= 1 || board.getBoardCoor(--y,x)=='#') {
			return false;
		}
		else return true;
		break;
	case 1: // DOWN
		
		if (y >= 23 || board.getBoardCoor(++y , x) == '#') {
			return false;
		}
		else return true;
		break;
	case 2: // LEFT
		if (x <= 2 || board.getBoardCoor(y, --x) == '#') {
			return false;
		}
		else return true;
		break;
	case 3: // RIGHT
		
		if (x >= 77 || board.getBoardCoor(y , ++x) == '#') {
			return false;
		}
		else return true;
		break;
	}
}

char Game::currCoorState( Point coor, Board board) {
	int x = coor.getX();
	int y = coor.getY();

	return board.getBreadCrumbCoor(y, x) ? '.' : ' ';
}