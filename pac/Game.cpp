#include "Game.h"

using std::filesystem::directory_iterator;



void Game::gameFlow()
{
    int key = menu.printMainMenu();
    if (key == START_GAME)
    { 
        this->setLevel( menu.gameLevel());
        setIsColored(menu.isColorfull());
        clear_screen();
        Game::init(isColored,true);
        Game::run();
    }
    else if (key == INSTRUCTIONS)
    {
        clear_screen();
        menu.printInstructions();

    }
    else if (key == PICKBOARD)
    {
        clear_screen();

        string boardFileName = menu.askBoardFile(boardNames);
        boardNames.clear();
        boardNames.push_back(boardFileName);
        int level = menu.gameLevel();
        
        setIsColored(menu.isColorfull());
        clear_screen();
        bool flag = false;
        this->init(isColored, flag);
        this->run();

    }
    else if (key == EXIT)
    {
        clear_screen();
        cout << "\nThank you and goodbye!\n";
        exit(-1);
    }
    return;
}




void Game::init(bool isColored,bool readFiles)
{
    if (readFiles) {
        string path = "../";

        for (const auto& file : directory_iterator(path)) {
            path = file.path().filename().string();
            if (file.path().extension().compare(".screen") == 0) {
                boardNames.push_back(file.path().string());
            }
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
    else
    {
        p.setColor(Color::WHITE);
    }


}

bool Game::doesGhostMeetsFruit(int i)
{
    if (fruit.getPoint().getX() == ghosts[i].getPoint().getX() &&
        fruit.getPoint().getY() == ghosts[i].getPoint().getY())
        return true;
    return false;


}

bool Game::doesPacMeetsFruit()
{
    if (fruit.getPoint().getX() == p.getPoint().getX() &&
        fruit.getPoint().getY() == p.getPoint().getY())
        return true;
    else
        return false;
}

void Game::run()
{
    //pre run
    int counter = 0;
    bool killGameFlag = false;
    int PacmanDir;
    bool moveGhost = true;
    for (int i = 0; i < boardNames.size(); i++)
    {
        if (killGameFlag) {
            break;
        }
        bool flagwalk = true;

        char key = 0;
        int flag = 0;
        board.initBoardFromFile(boardNames[i]);
        board.Print(isColored, ghosts, p.getPointByRef());
        int limits[4] = { board.getBoardLimit(0),board.getBoardLimit(1),board.getBoardLimit(2),board.getBoardLimit(3) };
        p.setInitPostion(p.getPoint().getX(), p.getPoint().getY());
        int slowFruit = 0;

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
                menu.gameOver();
                p.setLives(3);
                flag = 1;
                killGameFlag = true;
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

            for (int i = 0; i < p.getLives() * 2; i += 2)
            {
                stats.setPoint(17 + i, 20);
                stats.draw('<');
                stats.setPoint(18 + i, 20);

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
                cout<<  "***** Game paused, press ESC/q to continue/quit. *****\n";
                cout << endl;
                char escape = 'n';
                while (escape != ESC && escape != QUIT) {
                    escape = _getch();
                }
                if (escape == QUIT) {
                    p.setLives(3);
                    p.getPointByRef().setPoint(1, 1);
                    flag = 1;
                    killGameFlag = true;
  
                   
                    break;
                }
                gotoxy(0, 21);
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
        if (fruit.getWaitUntill() == 0) {
            
            if (flagwalk) {
                int fruitRow, fruitCol;
                do{
                 fruitRow = rand() % (limits[1] - limits[0] + 1) + limits[0] - 1;
                 fruitCol = rand() % (limits[3] - limits[2] + 1) + limits[2] - 1;
                }while (board.getBoardCoor(fruitRow, fruitCol) == '#');
               
                fruit.getPointByRef().setPoint(fruitCol, fruitRow);
                fruit.setLifeDur(((rand() % 50 + 15)));
                fruit.setFigure('0' + (rand() % 5) + 5);
                fruit.getPointByRef().draw(fruit.getFigure());

                flagwalk = false;
            }

            if (fruit.getLifeDur() > 0) {


                if (canMove(fruit.getDir(), fruit.getPoint(), board, false)) {
                    if (slowFruit % 3 == 0)
                    {
                        char coorState = currCoorState(fruit.getPoint(), board);
                        fruit.move(coorState, limits);
                    }

                    slowFruit++;
                }
                else {
                    while (!canMove(fruit.getDir(), fruit.getPoint(), board, false))
                    {
                        fruit.setDirection(fruit.PickDirection());
                    }
                    if (slowFruit % 3 == 0)//so the fruit will move slow
                    {
                        char coorState = currCoorState(fruit.getPoint(), board);
                        fruit.move(coorState, limits);
                    }
                    slowFruit++;
                }
                int fruitNewLifeDur = fruit.getLifeDur() - 1;
                fruit.setLifeDur(fruitNewLifeDur);
                if (this->doesPacMeetsFruit())
                {
                    int fig = fruit.getFigure() - '0';
                    setScore((int)fig+score);
                    stats.drawInt(score);
                    fruit.setLifeDur(-1);
                    flagwalk = true;

                    fruit.setWaitUntill((rand() % 50 + 5));

                }
            }
            else {
                fruit.setWaitUntill((rand() % 50 + 5));
                char prevCoorState = currCoorState(fruit.getPoint(), board);
                fruit.getPointByRef().draw(prevCoorState);
                flagwalk = true;
            }
        }
       
        
        if (moveGhost && Ghost::getGhostAmount() >0)
        {
            int level = this->getLevel();
            if (level == BEST)
                ghostLogic.bfs(p.getPointByRef(), ghosts, board);

            for (int i = 0; i < Ghost::getGhostAmount(); i++)
            {
                int bestOption;
                //sets direction and checks if the ghost can move there (means its not a wall or a tunnel)
                if (level == BEST) {
                    bestOption = ghostLogic.findBestDir(ghosts[i].getPoint(), board);

                }
                else if (level == GOOD) {
                    if (15 < counter && counter < 20)
                    {
                        int stam = ghostLogic.goodGhosts(p.getPoint(), ghosts, i, counter);
                        int bestOption = ghosts[i].getDir();
                    }
                    else
                        bestOption = ghostLogic.goodGhosts(p.getPoint(), ghosts, i, counter);
                }
                else if (level == NOVICE) {
                    bestOption = ghostLogic.stupiedGhosts(i, counter, ghosts);
                }

                ghosts[i].setDirection(bestOption);
                char coorState = currCoorState(ghosts[i].getPoint(), board);

                if (canMove(ghosts[i].getDir(), ghosts[i].getPoint(), board, false)) {
                    char coorState = currCoorState(ghosts[i].getPoint(), board);
                    ghosts[i].move(coorState, limits);
                }
                else {
                    while (!canMove(ghosts[i].getDir(), ghosts[i].getPoint(), board, false))
                    {


                        ghosts[i].setDirection(ghosts[i].PickDirection());
                    }
                    char coorState = currCoorState(ghosts[i].getPoint(), board);
                    ghosts[i].move(coorState, limits);
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
            
            p.move(limits);
            if (board.checkIfBoardCompleted())
            {
                menu.youWon();
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
    Ghost::resetGhostAmount();
    setTextColor(Color::WHITE);
    clear_screen();
    }
    Game::gameFlow();

}

bool Game::canMove(int dir, Point coor, Board board, bool isPacman = false) {
    int x = coor.getX();
    int y = coor.getY();
    switch (dir) {
    case 0: // UP
        if ((y <= board.getBoardLimit(0) && !isPacman) || board.getBoardCoor(--y, x) == '#') {
            return false;
        }

        else return true;
        break;
    case 1: // DOWN

        if ((y >= board.getBoardLimit(1) && !isPacman) || board.getBoardCoor(++y, x) == '#') {
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

        if ((x >= board.getBoardLimit(3) && !isPacman) || board.getBoardCoor(y, ++x) == '#') {
            return false;
        }

        else return true;
        break;
    }

    return false;
}

char Game::currCoorState(Point coor, Board board) {
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