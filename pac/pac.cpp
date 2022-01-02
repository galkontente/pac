#include <windows.h>
#include <iostream>
using namespace std;

#include "./Game.h"

int main(int argc, char* argv[])
{
	Game game;
	bool silent = false, save = false, load = false;
	for (int i = 1; i < argc; i++)
	{
		if (argv[i] == "-save")
		{
			save = true;
		}
		else if (argv[i] == "-silent")
		{
			silent = true;
		}
		else if (argv[i] == "-load")
		{
			load = true;
		}
	}

	if (silent == false && save == false && load == false)//game runs as usual- no special addition
	{
		game.gameFlow();
	}
	else if (load == true)
	{
		if (silent == false)
			game.loadMode("../pacman_1.steps");//load mode only
		else if(silent == true)
			//game.loadMode("../pacman_1.steps");//load mode bus also silent
	}
	else if (save == true)
	{
		//save mode
	}


	//Game game;
	//game.loadMode("../pacman_1.steps");
	//game.gameFlow();
	// \\\
//	game.readMovesFromFile("../pacman_1.steps");
	return 0;
}