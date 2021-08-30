#include "Game.h"

int main()
{
	Game* MyGame = new Game();
	MyGame->SampleGame();
	MyGame->PlayGame();
	delete MyGame;
	return 0;
}