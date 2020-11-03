#include <iostream>
#include "game.h"

int main() {
	std::cout << "Hello, World!" << std::endl;

	Game *g = new Game();
	g->gameLoop();
	return 0;
}
