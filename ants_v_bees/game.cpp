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

game::game() {


	this-> gameBoard = vector<vector<Insect>> (1);


	this-> gameBoard[0] = vector<Insect>(10);

	// Initializing the Queen
	//gameBoard[0][0] = null;

	/**
	 *  [Q], [], [], [], [], [], [], [], [Fire], [Bee, Bee]
	 */

	gameLoop();
}

game::~game() {

}

#include "game.h"
void game::gameLoop() {

	printGameBoard();

	do {

		// 1) A bee is generated on the right side of the board

		// 2) The player can generate an ant and place it anywhere on the board

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

void game::printGameBoard() {

	for(int i = 0; i < gameBoard[0].size(); i++) {

		string squareBugs = "";
		for(int j = 0; j < gameBoard.size(); j++) {

//			string str = gameBoard[j][i].symbol;
//			squareBugs.append(str);
//
//			if(str != "" && j != gameBoard.size()-1) {
//				squareBugs.append(", ");
//			}
		}

		cout << "[" << i+1 << ": "<< squareBugs << " ] ";
	}
}

bool game::queenDead() {

	for(int j = 0; j < gameBoard.size(); j++) {

//		if(gameBoard[j][0].symbol == "Bee") {
//			return true;
//		}
	}

	return false;
}

int game::checkBeeCount() {
	int beeCount = 0;

	for(int i = 0; i < gameBoard.size(); i++) {

		for(int j = 0; j < gameBoard[i].size(); j++) {

//			if(i > 0 && gameBoard[i][j].symbol == "Bee") {
//				beeCount++;
//			}
		}
	}

	return beeCount;
}

int game::menu() {
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

int game::placeAnt() {
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

int game::placeAntLocation() {
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