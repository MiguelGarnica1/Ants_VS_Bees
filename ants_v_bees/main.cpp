#include <iostream>
#include "game.h"

/*** main method
 * you know what it is, we run the game
 * @return int - 0
 */
int main() {
	std::cout << "Hello, World!" << std::endl;

	Game *g = new Game();
	g->gameLoop();
	return 0;
}
