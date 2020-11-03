//
// Created by Miguel on 11/2/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "insect.h"
#include "ant.h"
#include "bee.h"


using namespace std;

Game::Game()  {

	// intialize the gameboard of Places with 10 spaces
	this-> gameBoard = vector<Place>(10);

	// initialize the queen
	this-> gameBoard[0].ant = new Ant();

	/**
	 *  [Q], [], [], [], [], [], [], [], [Fire], [Bee, Bee]
	 */

	gameLoop();
}

Game::~Game() {

}

#include "game.h"
void Game::gameLoop() {

	printGameBoard();

	do {

		// 1) A bee is generated on the right side of the board
		generateBee();

		// 2) The player can generate an ant and place it anywhere on the board
		int option = menu();

		if(option == 1){
			cout << " TURN ENDED " << endl;
			continue;
		}
		if (option == 2){
			option = placeAnt();
		}

		switch (option) {
			case 1:
				cout << "Add Harvester Ant" << endl;
				break;
			case 2:
				cout << "Add Thrower Ant" << endl;
				break;
			case 3:
				cout << "Add Fire Ant" << endl;
				break;
			case 4:
				cout << "Add Long Thrower Ant" << endl;
				break;
			case 5:
				cout << "Add Short Thrower Ant" << endl;
				break;
			case 6:
				cout << "Add Wall Ant" << endl;
				break;
			case 7:
				cout << "Add Ninja Ant" << endl;
				break;
			case 8:
				cout << "Add Bodyg2aurd Ant" << endl;
				break;
		}


		// 3) The ants attack the bees. (Order of ant attacks occur left to right)

		/**
		* 4) The bees either attack an ant (order of attack is left to right) which is blocking
		* them or pass through to the next square on the board if they are not blocked by an ant
		*/

		/**
		 * 5) Check to see if the bees have reached the queen or if there are any bees left in play,
		 * declare a winner and end the game if either condition is true
		 */

	} while(!queenDead() || checkBeeCount() != 0);

	if(queenDead()) {
		cout << "\n" << "The queen is dead! The bees win!" << endl;
	}

	else {
		cout << "\n" << "All bees are dead! The ants win!" << endl;
	}
}

void Game::generateBee() {
	this->gameBoard.at(8).bees->push_back(new Bee());
}

void Game::printGameBoard() {
	for(int i = 0; i < gameBoard.size(); i++){
		cout << "Square " << i << endl;
		if(gameBoard[i].ant != NULL){
			cout << "Ant IS HERE" << endl;
		}

		if(gameBoard.at(i).bees != NULL) {
			cout << "SO MANY BEES, THIS MANY BEES #" << gameBoard[i].bees->size() << endl;
		}

	}

}

bool Game::queenDead() {

	for(int i = 0; i < gameBoard.size(); i++) {

		if(!gameBoard[i].bees->empty()){
			return true;
		}
	}

	return false;
}

int Game::checkBeeCount() {
	int beeCount = 10;

	for(int i = 0; i < gameBoard.size(); i++) {
		if(!gameBoard[i].bees->empty()){
			beeCount += gameBoard[i].bees->size();
		}
	}

	return beeCount;
}

int Game::menu() {
    cout << "\n1. End turn" << endl;
    cout << "2. Place ant." << endl;
    cout << "Hit Enter to confirm selection. Select:";

    string choice;
    getline(cin, choice);
    int option = stoi(choice);
    while (option < 1 || option > 2) {
        cout << "\nBad input, try again.";
        getline(cin, choice);
        option = stoi(choice);
    }

    return option;
}

int Game::placeAnt() {
    cout << "\nPlacing ant. Which ant?" << endl;
    cout << "1. Harvester       5. Short Thrower" << endl;
    cout << "2. Thrower         6. Wall" << endl;
    cout << "3. Fire            7. Ninja" << endl;
    cout << "4. Long Thrower    8. Bodyguard" << endl;
    cout << "Hit Enter to confirm selection. Select:";

    string choice;
    getline(cin, choice);
    int option = stoi(choice);
    while (option < 1 || option > 8) {
        cout << "\nBad input, try again.";
        getline(cin, choice);
        option = stoi(choice);
    }

    return option;
}

int Game::placeAntLocation() {
    cout << "\nAt which square? [2-9]" << endl;
    cout << "Hit Enter to confirm selection. Select:";

    string choice;
    getline(cin, choice);
    int option = stoi(choice);
    while (option < 2 || option > 9) {
        cout << "\nBad input, try again.";
        getline(cin, choice);
        option = stoi(choice);
    }

    return option;
}