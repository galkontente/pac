#include "Game.h"

void Game::printMainMenu()
{
	cout << "********************************\n";
	cout << "*      Welcome to Pacman!      *\n";
	cout << "********************************\n";
	cout << "(1) Start a new game\n(8) Present instructions and keys\n(9) EXIT\n";
}

void Game::printInstructions()
{
	cout << "The pacman travels on screen and “eats the breadcrumbs”.\n"
		"Each eaten breadcrumb equals a point to be earned.\n"
		"Once all breadcrumbs on screen are eaten the game ends and you win!.\n"
		"In case a ghost eats the pacman,\n"
		"you loses one “life”.If all “lives” are gone you loose the game\n";
	cout << "You can move the pacman using the following keys from your keybord:\n"
		"w or W : up\n"
		"x or X : down\n"
		"a or A : left\n"
		"d or D : right\n"
		"s or S : stand\n";
	cout << "press any key to return to the main menu";
	//if (_kbhit())// $ why dosent it work??
		char key = _getch();
		system("CLS");
		Game::menu();



}

void Game::menu()
{
	Game::printMainMenu();
	int key;
	int flag = 0;
	key = _getch();
	while (flag == 0)
	{
		cin >> key;
		//key = _getch();
		if (key == START_GAME)
		{
			flag = 1;
			system("CLS");
			Game::init();
			Game::run();
		}
		else if (key == INSTRUCTIONS)
		{
			flag = 1;
			system("CLS");
			Game::printInstructions();
		}
		else if (key == EXIT)
		{
			system("CLS");
			flag = 1;
			
			cout << "\nThank you and goodbye!\n";
		}
		else 
		{
			system("CLS");
			cout << "\nThe numer you pressed is not an option, Please try again:\n";
			Game::printMainMenu();
		}
	}
	

}



void Game::init()
{
	p.setArrowKeys("wxads");
	board.initlayOut();
	p.setColor(Color::YELLOW);
	p.setFigure('@');
	stats.setPoint(6,25);
	ghosts[0].setColor(Color::CYAN);
	ghosts[1].setColor(Color::MAGENTA);
	ghosts[0].getPoint().setPoint(20,20);
	ghosts[1].getPoint().setPoint(20, 20);

	ghosts[0].setFigure('&');
	ghosts[1].setFigure('&');

}


void Game::run()
{
	//pre run
	char key = 0;
	char hearts;
	int PacmanDir, ghost1Dir, ghost2Dir;

	board.Print();
	//while run
	do {
		for (int i = 0; i < 2; i++)
		{
			if (
				p.getPoint().getX() == ghosts[i].getPoint().getX() &&
				p.getPoint().getY() == ghosts[i].getPoint().getY()
				)
				p.setLives(p.getLives() + 1);
		}
		
		for (int i = 0; i < p.getLives()*2; i+=2)
		{
			stats.setPoint(17 + i, 25);
			stats.draw('<');
			stats.setPoint(18+i, 25);
			
			stats.draw('3');
			stats.setPoint(19 + i, 25);

		}
		stats.setPoint(6, 25);
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
		if(canMove(ghosts[0].getDir(), ghosts[0].getPoint(),board, false)){
			char coorState = currCoorState(ghosts[0].getPoint(), board);
			ghosts[0].move(coorState);
		}
		else {
			while(!canMove(ghosts[0].getDir(), ghosts[0].getPoint(), board, false))
			{
					ghosts[0].setDirection(ghosts[0].PickDirection());	
			}
			char coorState = currCoorState( ghosts[0].getPoint(), board);
			ghosts[0].move(coorState);
		}
		if (canMove(ghosts[1].getDir(), ghosts[1].getPoint(), board, false)) {
			char coorState = currCoorState( ghosts[1].getPoint(), board);
			ghosts[1].move(coorState);
			

		}
		else {
			while (!canMove(ghosts[1].getDir(), ghosts[1].getPoint(), board,false))
			{
				ghosts[1].setDirection(ghosts[1].PickDirection());
			}
			char coorSaver = currCoorState( ghosts[1].getPoint(), board);
			ghosts[1].move(coorSaver);
		}
		
		if (canMove(p.getDir(),p.getPoint(), board,true)) {
			int x = p.getPoint().getX();
			int y = p.getPoint().getY();
			if (board.getBreadCrumbCoor(y, x)) {
				board.setBreadCrumbCoor(y, x, 0);
				addToScore();
				stats.drawInt(score);
			}
			
			p.move();
		}
	
		Sleep(200);
	} while (key != ESC);
	//post run
	setTextColor(Color::WHITE);
	clear_screen();
}

bool Game::canMove(int dir, Point coor, Board board, bool isPacman=false) {
	int x = coor.getX();
	int y = coor.getY();
	switch (dir) {
	case 0: // UP
		if ((y <= 1 && !isPacman) || board.getBoardCoor(--y,x)=='#') {
			return false;
		}
		
		else return true;
		break;
	case 1: // DOWN
		
		if ((y >= 23 && !isPacman) || board.getBoardCoor(++y , x) == '#') {
			return false;
		}
		
		else return true;
		break;
	case 2: // LEFT
		if ((x <= 2 && !isPacman) || board.getBoardCoor(y, --x) == '#') {
			return false;
		}
		else return true;
		break;
	case 3: // RIGHT
		
		if ((x >= 77 && !isPacman) || board.getBoardCoor(y , ++x) == '#') {
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

void Game::addToScore() {
	score = score+1;
}