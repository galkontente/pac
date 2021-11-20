#include "Game.h"

void Game::printMainMenu()const
{
    cout << "********************************\n";
    cout << "*      Welcome to Pacman!      *\n";
    cout << "********************************\n";
    cout << "(1) Start a new game\n(8) Present instructions and keys\n(9) EXIT\n"; 
    cout<< endl;
}

void Game::printInstructions()const
{
    cout << "The pacman travels on screen and eats the breadcrumbs.\n"
        "Each eaten breadcrumb equals a point to be earned.\n"
        "Once all breadcrumbs on screen are eaten the game ends and you win!.\n"
        "In case a ghost eats the pacman,\n"
        "you loses one life.If all lives are gone you loose the game\n";
    cout << "You can move the pacman using the following keys from your keybord:\n"
        "w or W : up\n"
        "x or X : down\n"
        "a or A : left\n"
        "d or D : right\n"
        "s or S : stand\n";
    cout << "press any key to return to the main menu";
    cout << endl;
        char key = _getch();
        clear_screen();
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
        if (key == START_GAME)
        {
            char ch;
            clear_screen();
            cout << "Do you want the game will be colorfull?\nPress Y or y for colorfull game\n"
                "Press N or n for black and while game"; 
            cout << endl;
            do
            {
                (_kbhit());
                ch = _getch();
                if (ch == 'Y' || ch == 'y')
                    isColored = true;
                else if (ch == 'N' || ch == 'n')
                    isColored = false;
                else
                {
                    cout << ch << "\nThe key you pressed is not an option, Please try again:\n";
                    cout << endl;
                }

            } while (ch != 'Y' && ch != 'y' && ch != 'N' && ch != 'n');
            clear_screen();
            Game::init(isColored);
            Game::run();
        }
        else if (key == INSTRUCTIONS)
        {
            clear_screen();
            Game::printInstructions();

        }
        else if (key == EXIT)
        {
            clear_screen();
            cout << "\nThank you and goodbye!\n";
          
        }
        else
        {
            if(key!=0)
            clear_screen();

            Game::printMainMenu();

            key = 0;
            clear_screen();
            cout << "\nThe numer you pressed is not an option, Please try again:\n";
            cout << endl;
        }
       
    } while (!flag);

    return;
}




void Game::init(bool isColored)
{
    p.setArrowKeys("wxads");
    p.setFigure('@');
    ghosts[0].setFigure('&');
    ghosts[0].getPointByRef().setPoint(22, 10);
    
    ghosts[1].setFigure('&');
    ghosts[1].getPointByRef().setPoint(55,5);

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
    int flag = 0;
    int PacmanDir;
    bool moveGhost = true;

    board.Print(Game::isColored);

    
    //while run
    p.move();

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
            p.setDirection(4);
            p.move();

            }
            if (currLives == 0)
            {
                clear_screen();
                setTextColor(Color::WHITE);
                cout << "*************************\n";
                cout << "*      GAME OVER!       *\n";
                cout << "*************************\n";
                cout << "press any key to return to the main menu\n";
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
                cout << "***** Game paused, press ESC/q to continue/quit. *****\n";
                cout << endl;
                char escape = 'n';
                while (escape != ESC && escape != QUIT) {
                    escape = _getch();
                }
                if (escape == QUIT) {
                    p.setLives(3);
                    p.getPointByRef().setPoint(1, 1);
                    flag = 1;
                    break;
                }
                gotoxy(0, 21);
                //delets the messege:
                cout << "                                                           \n";
                cout << endl;
                
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
                //sets direction and checks if the ghost can move there (means its not a wall or a tunnel)
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
        moveGhost = !moveGhost;// to make the pacman move x2 faster than the ghosts
        
        //checks if the pacman can move there (means its not a wall) and updates the score
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
                clear_screen();
                setTextColor(Color::WHITE);
                cout << "*******************************\n";
                cout << "*      YOU WON THE GAME!      *\n";
                cout << "*******************************\n";
                cout << "press any key to return to the main menu\n";
                cout << endl;
                char key = _getch();
                clear_screen();
                flag = 1;
                Game::printMainMenu();
                break;
            }
        }

        Sleep(100);
    } while (flag!=1);
    //post run

    setTextColor(Color::WHITE);
    clear_screen();
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
        if ((x <= 1 && !isPacman) || board.getBoardCoor(y, --x) == '#') {
            return false;
        }
        else return true;
        break;
    case 3: // RIGHT
        
        if ((x >= 78 && !isPacman) || board.getBoardCoor(y , ++x) == '#') {
            return false;
        }
        
        else return true;
        break;
    }
    
    return false;
}

char Game::currCoorState( Point coor, Board board) {
    int x = coor.getX();
    int y = coor.getY();

    return board.getBreadCrumbCoor(y, x) ? '.' : ' ';
}

void Game::addToScore() {
    score = score+1;
}