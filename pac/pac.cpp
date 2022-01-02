#include <windows.h>
#include <iostream>
using namespace std;

#include "./Game.h"

int main(int argc, char* argv[])
{
	Game game;
	game.loadMode("../pacman_1.steps");
	//game.gameFlow();
	// \\\
//	game.readMovesFromFile("../pacman_1.steps");
	return 0;
}