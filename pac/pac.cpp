#include <windows.h>
#include <iostream>
using namespace std;

#include "./Game.h"

int main(int argc, char* argv[])
{
	string loadMode = "-load";
	string silentMode = "-silent";
	string saveMode = "-save";
	Game game;
	bool silent = false, save = false, load = false;
	for (int i = 0; i < argc; i++)
	{
		string str = argv[i];
		if (str.compare(saveMode) == 0)
		{
			save = true;
		}
		else if (str.compare(silentMode) == 0)
		{
			silent = true;
		}
		else if (str.compare(loadMode) == 0)
		{
			load = true;
		}
	}

	if (silent == false && save == false && load == false)//game runs as usual- no special addition
	{
		game.init(game.getIsColored(), false);
		game.gameFlow();
	}
	else if (load == true)
	{
		if (silent == false)
		{
			game.init(game.getIsColored(), true);//load mode only
			game.loadMode("../pacman_1.steps", false);
		}
			
		else if (silent == true)
		{
			game.init(false, true);//load mode but silent
			game.loadMode("../pacman_1.steps", true);
		}
		
	}
	else if (save == true)
	{
		game.init(game.getIsColored(), true);
		game.gameFlow();
	}


	//Game game;
	//game.loadMode("../pacman_1.steps");
	//game.gameFlow();
	// \\\
	//	game.readMovesFromFile("../pacman_1.steps");
	//return 0;
	//Game game;
	//game.init(false, true);
	//game.loadMode("../pacman_1.steps");
	//game.gameFlow();
	// \\\
//	game.readMovesFromFile("../pacman_1.steps");
	return 0;
}

