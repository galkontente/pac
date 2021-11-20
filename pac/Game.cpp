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
    cout << "The pacman travels on screen and ?eats the breadcrumbs?.\n"
        "Each eaten breadcrumb equals a point to be earned.\n"
        "Once all breadcrumbs on screen are eaten the game ends and you win!.\n"
        "In case a ghost eats the pacman,\n"
        "you loses one ?life?.If all ?lives? are gone you loose the game\n";
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
        Game::printMainMenu();
}

void Game::menu()
{
    Game::printMainMenu();
    int key=0;
    int flag = 0;
    do
    {

            key = _getch();

        //cin >> key;
        //
        if (key == START_GAME)
        {
            char ch;
            system("CLS");
            cout << "Do you want the game will be colorfull?\nPress Y or y for colorfull game\n"
                "Press N or n for black and while game";
            do
            {
                (_kbhit());
                ch = _getch();
                if (ch == 'Y' || ch == 'y')//$why does it work only with hebrew keyboard???????
                    isColored = true;
                else if (ch == 'N' || ch == 'n')
                    isColored = false;
                else
                    cout << ch << "\nThe key you pressed is not an option, Please try again:\n";

            } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
            system("CLS");
            Game::init(isColored);
            Game::run();
        }
        else if (key == INSTRUCTIONS)
        {
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
            if(key!=0)
            system("CLS");

            Game::printMainMenu();
            cout << key << endl;

            key = 0;
          /*  system("CLS");
            cout << "\nThe numer you pressed is not an option, Please try again:\n";*/
        }
       
    } while (!flag);

    return;
}




void Game::init(bool isColored)
{
    p.setArrowKeys("wxads");
    p.setFigure('@');
    ghosts[0].setFigure('&');
    ghosts[0].getPointByRef().setPoint(16, 14);
    
    ghosts[1].setFigure('v');
    ghosts[1].getPointByRef().setPoint(2,14);

    if (isColored == true)
    {
        p.setColor(Color::YELLOW);
        ghosts[0].setColor(Color::CYAN);
        ghosts[1].setColor(Color::MAGENTA);
    }
    else
    {
        p.setColor(Color::WHITE);
        ghosts[0].setColor(Color::WHITE);
        ghosts[1].setColor(Color::WHITE);
    }

}

void Game::run()
{
    //pre run
    char key = 0;
    char hearts;
    int flag = 0;
    int PacmanDir, ghost1Dir, ghost2Dir;
    bool moveGhost = true;

    board.Print(Game::isColored);


    //while run
    do {
    for (int i = 0; i < 2; i++)
        {
        int currLives = p.getLives();
        if (
            p.getPoint().getX() == ghosts[i].getPoint().getX() &&
            p.getPoint().getY() == ghosts[i].getPoint().getY()
            ) {
            p.setLives(currLives - 1);
            p.getPointByRef().setPoint(1, 1);
            }
            if (currLives == 0)
            {
                system("CLS");
                setTextColor(Color::WHITE);
                cout << "*************************\n";
                cout << "*      GAME OVER!       *\n";
                cout << "*************************\n";
                cout << "press any key to return to the main menu\n";
                //if (_kbhit())// $ why dosent it work??
                char key = _getch();
                p.setLives(3);
                flag = 1;
                break;
            }
        }
    if (flag) break;
    for (int i = 0; i < 6; i += 2)
    {
        stats.setPoint(17 + i, 20);
        stats.draw('-');
        stats.setPoint(18 + i, 20);

        stats.draw('-');
        stats.setPoint(19 + i, 20);

    }
        
        for (int i = 0; i < p.getLives()*2; i+=2)
        {
            stats.setPoint(17 + i, 20);
            stats.draw('<');
            stats.setPoint(18+i, 20);
            
            stats.draw('3');
            stats.setPoint(19 + i, 20);

        }

        
        stats.setPoint(6, 20);
        if (_kbhit())
        {
            key = _getch();
            if (key == ESC) {
                gotoxy(0, 21);
                setTextColor(Color::WHITE);
                cout << "*********************************************\n";
                cout << "* Game paused, press ESC again to continue. *\n";
                cout << "*********************************************\n";
                char escape = 'n';
                while (escape != ESC) {
                    escape = _getch();
                }
                gotoxy(0, 21);
                cout << "                                             \n";
                cout << "                                             \n";
                cout << "                                             \n";
            }
            if ((PacmanDir = p.getDirection(key)) != -1)
            {
                p.setDirection(PacmanDir);
              
            }
        }
        if (moveGhost)
        {
            for (int i = 0; i < 2; i++)
            {
                ghosts[i].setDirection(ghosts[i].chasePacman(p.getPoint()));
                if (canMove(ghosts[i].getDir(), ghosts[i].getPoint(), board, false)) {
                    char coorState = currCoorState(ghosts[i].getPoint(), board);
                    ghosts[i].move(coorState);
                }
                else {
                    while (!canMove(ghosts[i].getDir(), ghosts[i].getPoint(), board, false))
                    {
                        ghosts[i].setDirection(ghosts[i].PickDirection());
                    }
                    char coorState = currCoorState(ghosts[i].getPoint(), board);
                    ghosts[i].move(coorState);
                }

            }
        }
        moveGhost = !moveGhost;
        
        if (canMove(p.getDir(),p.getPoint(), board,true)) {
            int x = p.getPoint().getX();
            int y = p.getPoint().getY();
            if (board.getBreadCrumbCoor(y, x)) {
                board.setBreadCrumbCoor(y, x, 0);
                addToScore();
                stats.drawInt(score);
            }
            
            p.move();
            if (score == board.maxScore())
            {
                system("CLS");
                setTextColor(Color::WHITE);
                cout << "*******************************\n";
                cout << "*      YOU WON THE GAME!      *\n";
                cout << "*******************************\n";
                cout << "press any key to return to the main menu\n";
                //if (_kbhit())// $ why dosent it work??
                char key = _getch();
                system("CLS");
                flag = 1;
                Game::printMainMenu();
                break;
            }


            
        }

        Sleep(100);
    } while (flag!=1);
    //post run

    setTextColor(Color::WHITE);
    system("CLS");
    printMainMenu();

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