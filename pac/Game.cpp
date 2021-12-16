#include "Game.h"
#include <filesystem>

using std::filesystem::directory_iterator;



void Game::gameFlow()
{
    int key = menu.printMainMenu();

    if (key == START_GAME)
    {
        setIsColored(menu.isColorfull());
        clear_screen();
        Game::init(isColored);
        Game::run();
    }
    else if (key == INSTRUCTIONS)
    {
        clear_screen();
        menu.printInstructions();

    }
    else if (key == EXIT)
    {
        clear_screen();
        cout << "\nThank you and goodbye!\n";
        exit(-1);
    }
    return;
}




void Game::init(bool isColored)
{
    string path = "../";

    for (const auto& file : directory_iterator(path)) {
        path = file.path().filename().string();
         if(file.path().extension().compare(".screen")==0) {
             boardNames.push_back(file.path().string());
         }
    }
    p.setArrowKeys("wxads");
    p.setFigure('@');
    fruit.getPointByRef().setPoint(9, 9);
    fruit.setWaitUntill(5);
    char fruitFigure = (char)(rand() % 9 + 5);
    fruit.setFigure(fruitFigure);
    if (isColored == true)
    {
        p.setColor(Color::YELLOW);
    }
 /*   else
    {
        p.setColor(Color::WHITE);
    }*/

}

void Game::run()
{
    //pre run
   
    int PacmanDir;
    bool moveGhost = true;
    for (int i = 0; i < boardNames.size(); i++)
    {
        char key = 0;
        int flag = 0;
        board.initBoardFromFile(boardNames[i]);
        board.Print(isColored, ghosts, p.getPointByRef());
        int limits[4] = { board.getBoardLimit(0),board.getBoardLimit(1),board.getBoardLimit(2),board.getBoardLimit(3) };
        p.setInitPostion(p.getPoint().getX(), p.getPoint().getY());

        //while run
        p.move(limits);
    
   

    do {

    for (int i = 0; i < Ghost::getGhostAmount(); i++)
        {
        int currLives = p.getLives();
        if (
            p.getPoint().getX() == ghosts[i].getPoint().getX() &&
            p.getPoint().getY() == ghosts[i].getPoint().getY()
            ) {
            p.setLives(currLives - 1);

            p.getPointByRef().setPoint(p.getInitPostionX(), p.getInitPostionY());
            p.setDirection(4);
            p.move(limits);

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
    int scorePos = board.getScoreLegendPost();
    int lifePos = board.getLifeLegendPost();

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
                cout<< Ghost::getGhostAmount() << "***** Game paused, press ESC/q to continue/quit. *****\n";
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
            if ((PacmanDir = p.getDirectionInput(key)) != -1)
            {
                p.setDirection(PacmanDir);
              
            }
        }

        if (fruit.getWaitUntill() > 0) {
            fruit.setWaitUntill(fruit.getWaitUntill() - 1);
        }
        bool flagwalk = true;
        if (fruit.getWaitUntill() == 0){
            if (flagwalk) {
                fruit.setLifeDur(5);
                flagwalk = false;
            }
            fruit.setFigure('0' + (rand() % 5) + 5);

            if (fruit.getLifeDur() > 0) {


                if (canMove(fruit.getDir(), fruit.getPoint(), board, false)) {

                    char coorState = currCoorState(fruit.getPoint(), board);
                    fruit.move(coorState, limits);
                }
                else {
                    while (!canMove(fruit.getDir(), fruit.getPoint(), board, false))
                    {
                        fruit.setDirection(fruit.PickDirection());
                    }
                    char coorState = currCoorState(fruit.getPoint(), board);
                    fruit.move(coorState, limits);
                }
                int test = fruit.getLifeDur() - 1;
                fruit.setLifeDur(0);
            }
            else {
                fruit.setWaitUntill(5);
                flagwalk = true;

            }
        }
       
        
        if (moveGhost && Ghost::getGhostAmount() >0)
        {
            ghostLogic.bfs(p.getPointByRef(), ghosts, board);

            for (int i = 0; i < Ghost::getGhostAmount(); i++)
            {
                //sets direction and checks if the ghost can move there (means its not a wall or a tunnel)
                int bestOption = ghostLogic.findBestDir(ghosts[i].getPoint(), board);
                ghosts[i].setDirection(bestOption);
                char coorState = currCoorState(ghosts[i].getPoint(), board);
                ghosts[i].move(coorState, limits);
               /* if (canMove(ghosts[i].getDir(), ghosts[i].getPoint(), board, false)) {
                    char coorState = currCoorState(ghosts[i].getPoint(), board);
                    ghosts[i].move(coorState, limits);
                }
                else {
                    while (!canMove(ghosts[i].getDir(), ghosts[i].getPoint(), board, false))
                    {
                      

                        ghosts[i].setDirection(ghosts[i].PickDirection());
                    }
                    char coorState = currCoorState(ghosts[i].getPoint(), board);
                    ghosts[i].move(coorState,limits);
                }*/

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
            
            p.move(limits);
            if (score == 250)
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
                this->setScore(0);

                continue;
            }
        }

        Sleep(100);
    } while (flag!=1);
    //post run
    flag = 0;
    setTextColor(Color::WHITE);
    clear_screen();
    }
    Game::gameFlow();

}

bool Game::canMove(int dir, Point coor, Board board, bool isPacman=false) {
    int x = coor.getX();
    int y = coor.getY();
    switch (dir) {
    case 0: // UP
        if ((y <= board.getBoardLimit(0) && !isPacman) || board.getBoardCoor(--y,x)=='#') {
            return false;
        }
        
        else return true;
        break;
    case 1: // DOWN
        
        if ((y >= board.getBoardLimit(1) && !isPacman) || board.getBoardCoor(++y , x) == '#') {
            return false;
        }
        
        else return true;
        break;
    case 2: // LEFT
        if ((x <= board.getBoardLimit(2) && !isPacman) || board.getBoardCoor(y, --x) == '#') {
            return false;
        }
        else return true;
        break;
    case 3: // RIGHT
        
        if ((x >= board.getBoardLimit(3) && !isPacman) || board.getBoardCoor(y , ++x) == '#') {
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

void Game::setScore(int newScore) {
    score = newScore;
}