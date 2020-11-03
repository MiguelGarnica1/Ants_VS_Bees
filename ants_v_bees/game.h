//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_GAME_H
#define ANTS_V_BEES_GAME_H


#include <vector>
#include <string>
#include "insect.h"

class game {

public:

	// Constructor
	game();

	// Destructor
	~game();

	void gameLoop();

	// Utility Functions
	void printGameBoard();
	void addRow();
	void removeRow();

	void generateBee();
	void buyAnt();
	void antAttack();
	void beesAttack();

	int checkBeeCount();
	bool queenDead();

	// Game board 2D Vector
	std::vector<std::vector<Insect>> gameBoard;



};


#endif //ANTS_V_BEES_GAME_H
