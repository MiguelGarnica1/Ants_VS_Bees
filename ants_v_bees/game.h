//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_GAME_H
#define ANTS_V_BEES_GAME_H


#include <vector>
#include <string>
#include "insect.h"
#include "place.h"
using namespace std;

class Game {

public:

	// Constructor
	Game();

	// Destructor
	~Game();

	void gameLoop();

	// Utility Functions
	void printGameBoard();
	void addRow();
	void removeRow();

	void generateBee();
	void antAttack();
	void beesAttack();

	int checkBeeCount();
	bool queenDead();

	int menu();
	int placeAnt();
    int placeAntLocation();

	// Game board 2D Vector
	vector<Place> gameBoard;

};


#endif //ANTS_V_BEES_GAME_H
