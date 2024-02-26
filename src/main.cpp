#include "Game.h"


Game* game = nullptr;


int main(int argc, char* argv[])
{
	game = new Game();

	game->ini("Snake and Ladder", 800, 600, 0);

	

	while (game->isRunning())
	{
		game->eventHandler();
		game->update();
		game->render();
	}
	
	game->clean();

	return 0;
}
//initialisation ch
//isrunning ch
//update ch
//render ch
//clean ch
//eventhandler ch


//texturemanager: creates the texture, renders the texture;

//winning animation
//fix dice roll
//delay at snakes and ladders before going up or down