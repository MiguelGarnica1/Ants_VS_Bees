//
// Created by Miguel on 11/2/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include "game.h"
#include "insect.h"
#include "ant.h"
#include "harvester.h"
#include "thrower.h"
#include "fire.h"
#include "long_thrower.h"
#include "short_thrower.h"
#include "ninja.h"
#include "wall.h"
#include "bodyguard.h"
#include "bee.h"


using namespace std;

/*** constructor
 *  initialize gameboard, turn counter, and initial food.
 */
Game::Game()  {
    // initialize game board with 11 'Place's. The 10 spaces, and 1 at the beginning (left
    // most) to represent the queen ant dead.
    this-> gameBoard = vector<Place>(11);

    // initialize 'turn_counter' to 1 (first turn).
    this->turn_counter = 1;

    // initialize 'food' to 50 starting food.
    this->food = 50;
}

/***
 * destructor
 */
Game::~Game() {}


/*** gameloop
 *  handles user input and turn based attack of ant and bees
 */
void Game::gameLoop() {
    do {

        // 1) A bee is generated on the right side of the board
        generateBee();
//        for (int i = 0; i < 99999999; i++) {
//            generateBee();
//            for(int j = 0; j < gameBoard[10].bees->size(); j++) {
//                // delete moved/dead bee, cannot use number to erase
//                delete (gameBoard[10].bees->at(j));
//                gameBoard[10].bees->erase(gameBoard[10].bees->begin() + j);
//                // 'Bee' erased from vector. Other 'Bee's in vector is shifted.
//                // Take into account this shift by offsetting 'j' counter.
//                j--;
//            }
//        }


        printGameBoard();

        // 2) The player can generate an ant and place it anywhere on the board if food count permits.
        // if not, auto-end turn.
        int option = menu();
        if (option == 2) {this->placeAnt();}

        // 3) The ants attack the bees. (Order of ant attacks occur left to right)

        antAttack();


        /**
        * 4) The bees either attack an ant (order of attack is left to right) which is blocking
        * them or pass through to the next square on the board if they are not blocked by an ant
        */

        beesAttack();

        /**
         * 5) Check to see if the bees have reached the queen or if there are any bees left in play,
         * declare a winner and end the game if either condition is true
         */

		this->turn_counter ++;
		cout << "TURN ENDED." << endl;

    } while(!queenDead() && checkBeeCount() != 0);

    if(queenDead()) {
        cout << "\n" << "The queen is dead! The bees win!" << endl;
    }
    else {
        cout << "\n" << "All bees are dead! The ants win!" << endl;
    }
}

/*** place a user selected ant on a user selected square if available
 *
 */
void Game::placeAnt() {
    int option = pickAnt();
    switch (option) {
        case 1: placeHarvester(pickAntLocation(option));
            break;
        case 2: placeThrower(pickAntLocation(option));
            break;
        case 3: placeFire(pickAntLocation(option));
            break;
        case 4: placeLongThrower(pickAntLocation(option));
            break;
        case 5: placeShortThrower(pickAntLocation(option));
            break;
        case 6: placeWall(pickAntLocation(option));
            break;
        case 7: placeNinja(pickAntLocation(option));
            break;
        case 8: placeBodyguard(pickAntLocation(option));
            break;
    }
}

/*** Place a harvester ant on the game board
 *
 * @param location - int - square on which to place the ant [1-10]
 */
void Game::placeHarvester(int location) {
	Harvester *harvester = new Harvester();
    if ((this->food - harvester->foodCost) >= 0) {
        gameBoard[location].ant = harvester;
        cout << "Added Harvester Ant" << endl;
        this->food -= harvester->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete harvester;
    }
}

/*** Place a thrower ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeThrower(int location) {
	Thrower *thrower = new Thrower();
    if ((this->food - thrower->foodCost) >= 0) {
        gameBoard[location].ant = thrower;
        cout << "Added Thrower Ant" << endl;
        this->food -= thrower->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete thrower;
    }
}

/*** Place a fire ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeFire(int location) {
	Fire *fire = new Fire();
    if ((this->food - fire->foodCost) >= 0) {
        gameBoard[location].ant = fire;
        cout << "Added Fire Ant" << endl;
        this->food -= fire->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete fire;
    }
}

/*** Place a long thrower ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeLongThrower(int location) {
	Long_thrower *longThrower = new Long_thrower();
    if ((this->food - longThrower->foodCost) >= 0) {
        gameBoard[location].ant = longThrower;
        cout << "Added Long Thrower Ant" << endl;
        this->food -= longThrower->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete longThrower;
    }
}

/*** Place a short thrower ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeShortThrower(int location) {
	Short_thrower *shortThrower = new Short_thrower();
    if ((this->food - shortThrower->foodCost) >= 0) {
        gameBoard[location].ant = shortThrower;
        cout << "Added Short Thrower Ant" << endl;
        this->food -= shortThrower->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete shortThrower;
    }
}

/*** Place a wall ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeWall(int location) {
	Wall *wall = new Wall();
    if ((this->food - wall->foodCost) >= 0) {
        gameBoard[location].ant = wall;
        cout << "Added Wall Ant" << endl;
        this->food -= wall->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete wall;
    }
}

/*** Place a ninja ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeNinja(int location) {
	Ninja *ninja = new Ninja();
    if ((this->food - ninja->foodCost) >= 0) {
        gameBoard[location].ant = ninja;
        cout << "Added Ninja Ant" << endl;
        this->food -= ninja->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete ninja;
    }
}

/*** Place a bodygaurd ant on the game board
 *
 * @param location - int - the location on the game board to place the ant
 */
void Game::placeBodyguard(int location) {
	Bodyguard *bodyguard = new Bodyguard();
    if ((this->food - bodyguard->foodCost) >= 0) {
        gameBoard[location].bodyguard = bodyguard;
        cout << "Added Body Guard Ant" << endl;
        this->food -= bodyguard->foodCost;
    }
    else {
        cout << "Not enough food.";
        delete bodyguard;
    }
}

/*** Perform all the ant attack on bees if applicable
 *  (depends on type of ant)
 */
void Game::antAttack() {
    for(int i = 1; i < gameBoard.size(); i++) {
        if (gameBoard[i].ant == NULL) continue;

        string antName = gameBoard[i].ant->name;
        // 'switch' and 'case' doesn't work with string.
        // If ant is Harvester, get food
        if (antName.compare("Harvester") == 0) {this->food++;}
        else if (antName.compare("Thrower") == 0) {this->doThrower(i);}
        else if (antName.compare("Long Thrower") == 0) {this->doLongThrower(i);}
        else if (antName.compare("Short Thrower") == 0) {this->doShortThrower(i);}
    }
}

/*** Perform the thrower ant's attack
 *  (any bee sharing the same square as ant)
 * @param location - int - location of the thrower on the game board
 */
void Game::doThrower(int location) {
    // If there are bees damage the 1st bee.
    if (!gameBoard[location].bees->empty()) {
        gameBoard[location].bees->front()->damaged(1);

        // Remove bee if it is dead.
        if (gameBoard[location].bees->front()->isDead) {
            delete  gameBoard[location].bees->at(0);
            gameBoard[location].bees->erase(gameBoard[location].bees->begin());
        }
    }
}

/*** Perform the long thrower ant's attack
 * (the closest bee to any but at least 4 squares away)
 * @param location - int - location of the long thrower ant on the game board
 */
void Game::doLongThrower(int location) {
    // Initialize 'minDist', 'distFromLoc' to max.
    int minDist = INT_MAX;
    int distFromLoc = INT_MAX;

    // Trying to go through the game board to find good target.
    for (int i = 1; i < gameBoard.size(); i++) {
        // Valid target must be at least 4 squares away.
        if (abs(i - location) < 4) continue;

        // Find the distance to the closest valid bee target.
        if (!gameBoard[i].bees->empty()) {
            distFromLoc = abs(i - location);
            if (distFromLoc < minDist) {minDist = distFromLoc;}
        }
    }

    // ASSUMPTION: Long Thrower hurts each bee which is closest to it, but at least 4 squares
    // away. So if  there are bees to the left and right of Long Thrower, and the bees are at
    // same minimum distance (and at least 4 squares away) from the Long Thrower, bees from
    // both places takes damage.

    // If 'minDist' is changed, then a valid target was found.
    if (minDist != INT_MAX) {
        // Handles closest bees to left (same 'minDist' as right) if valid.
        if ((location - minDist) >= 1) {
            damageAllBeesAt(location - minDist,1);
        }

        // Handles closest bees to right, that are at the same distance as the closest bees
        // to the left, if valid.
        if ((location + minDist) <= 10) {
            damageAllBeesAt(location + minDist,1);
        }
    }
}

/*** perform the short thrower ant's attack
 * (any bee that is 0-2 squares away from ant)
 * @param location - int - location of the ant on the game board
 */
void Game::doShortThrower(int location) {
	int higher = location + 2;
	if (higher >= gameBoard.size()) higher = gameBoard.size()-1;
	bool foundABee = false;

	for(int i = location; i <= higher; i++){

		if(!gameBoard[i].bees->empty()) foundABee = true;
		// attack bees in current location
		for(int j = 0; j < gameBoard[i].bees->size(); j++){
			gameBoard[i].bees->at(j)->damaged(1);
		}
		// delete all bees that died
		for(int j = 0; j < gameBoard[i].bees->size(); j++){
			if (gameBoard[i].bees->at(j)->isDead) {
				gameBoard[i].bees->erase(gameBoard[i].bees->begin()+j);
				j--;
			}
		}

		if(foundABee) break;
	}
}

/***
 * Damage all bees at a location by a value. Remove dead bees if needed.
 * @param location - int - location of the ant on the game board
 * @param damVal - int - damage value the bees will take
 */
void Game::damageAllBeesAt(int location, int damVal) {
    if (!gameBoard[location].bees->empty()) {
        // Go through the bees at location.
        for(int i = 0; i < gameBoard[location].bees->size(); i++) {
            // Damaging the bees.
            gameBoard[location].bees->at(i)->damaged(damVal);

            if (gameBoard[location].bees->at(i)->isDead) {
                // Delete dead bees, cannot use number to erase.
                delete gameBoard[location].bees->at(i);
                gameBoard[location].bees->erase(gameBoard[location].bees->begin()+i);

                // 'Bee' erased from vector. Other 'Bee's in vector is shifted.
                // Take into account this shift by offsetting 'j' counter.
                i--;
            }
        }
    }
}

/*** perform the bees action, either attack or move
 *  (most action handled in processBeesInBoard(int) method
 */
void Game::beesAttack() {
    // Go through the game board.
    for(int i = 1; i < gameBoard.size(); i++){
        // Processing the bees in each game board.
        if(gameBoard[i].bees->empty()) continue;
        processBeesInBoard(i);
    }
}

/*** process all the bees at a certain location in the board
 *
 * @param board - int - the location on the board to process the bees action
 */
void Game::processBeesInBoard(int board) {
    for(int j = 0; j < gameBoard[board].bees->size(); j++) {
        // If there's a bodyguard, bee attack it first.
        if (gameBoard[board].bodyguard != NULL) {
            gameBoard[board].bodyguard->damaged(1);
            if (gameBoard[board].bodyguard->isDead) {
                delete gameBoard[board].bodyguard;
                gameBoard[board].bodyguard = NULL; /// REMEMBER TO DELETE
            }
        }
        // If there's an non-Ninja ant, bee attack.
        else if (gameBoard[board].ant != NULL && (gameBoard[board].ant->name.compare("Ninja") != 0)) {
            gameBoard[board].ant->damaged(1);
            // When ant is killed.
            if(gameBoard[board].ant->isDead) {
                // If ant killed is "Fire" ant, kill all bees.
                if (gameBoard[board].ant->name.compare("Fire") == 0) { damageAllBeesAt(board, 3); }
                delete gameBoard[board].ant;
                gameBoard[board].ant = NULL; /// REMEMBER TO DELETE
            }
        }
        // Bee moving.
        else {
            // If there's Ninja ant, bee at j take damage.
            if (gameBoard[board].ant != NULL && (gameBoard[board].ant->name.compare("Ninja") == 0)) {
                gameBoard[board].bees->at(j)->damaged(1);
            }
            // If bee at j not dead.
            if (!gameBoard[board].bees->at(j)->isDead) {
                // move bee to new 'Place'.
                gameBoard[board-1].bees->push_back(gameBoard[board].bees->at(j));
            }
            // delete moved/dead bee, cannot use number to erase
            delete gameBoard[board].bees->at(j);
            gameBoard[board].bees->erase(gameBoard[board].bees->begin() + j);
            // 'Bee' erased from vector. Other 'Bee's in vector is shifted.
            // Take into account this shift by offsetting 'j' counter.
            j--;
        }
    }
}



/*** Generate a new bee at the right end of the game board
 *
 */
void Game::generateBee() {
    this->gameBoard.at(gameBoard.size()-1).bees->push_back(new Bee());
}


/*** Print the status of the game board,
 * ants in square and health, bees in sqaure and health
 */
void Game::printGameBoard() {
    cout << "\nTurn #" << this->turn_counter << "  Food: " << this->food << endl;
    cout << "QUEEN ANT" << endl;
    for(int i = 1; i < gameBoard.size(); i++){
        cout << "Square " << i;
        if(gameBoard[i].ant != NULL){
            cout << " [" <<gameBoard[i].ant->name <<" Ant, Health: " << gameBoard[i].ant->armor <<"]";
        }

        if(gameBoard[i].bodyguard != NULL){
        	cout << ", [Bodygaurd Ant, Health: " << gameBoard[i].bodyguard->armor << "]";
        }

        if(!gameBoard.at(i).bees->empty()) {
        	for(int j = 0; j < gameBoard[i].bees->size(); j++){
        		cout << ", [BEE, Health: " << gameBoard[i].bees->at(j)->armor << "]";
        	}

//        	cout << " " << gameBoard.at(i).bees->size();
        }
        cout << endl;
    }
}

/** Check if the "Queen" ant is dead
 *
 * @return true if bees have reached the queen ant, false if otherwise
 */
bool Game::queenDead() {
    if(!gameBoard[0].bees->empty()){
        return true;
    }
    return false;
}

/*** Counts all bees on the game board
 *
 * @return int - the number of bees on the game board
 */
int Game::checkBeeCount() {
    int beeCount = 0;

    for(int i = 0; i < gameBoard.size(); i++) {
        if(!gameBoard[i].bees->empty()){
            beeCount += gameBoard[i].bees->size();
        }
    }

    return beeCount;
}

/*** prints the text menu,
 * giving user option to place ant, or end current turn
 * @return - int - the option user has chosen
 */
int Game::menu() {
    cout << "\n1. End turn" << endl;
    cout << "2. Place ant." << endl;
    cout << "Hit Enter to confirm selection. Select: ";

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

/*** prints all ant options for user to pick from
 *
 * @return int - the option user has chosen
 */
int Game::pickAnt() {
    cout << "\nPlacing ant. Which ant?" << endl;
    cout << "1. Harvester       5. Short Thrower" << endl;
    cout << "2. Thrower         6. Wall" << endl;
    cout << "3. Fire            7. Ninja" << endl;
    cout << "4. Long Thrower    8. Bodyguard" << endl;
    cout << "Hit Enter to confirm selection. Select: ";

    string choice;
    getline(cin, choice);
    int option = stoi(choice);
    while (option < 1 || option > 8) {
        cout << "Bad input, try again.";
        getline(cin, choice);
        option = stoi(choice);
    }

    return option;
}

/*** prompts user for a location on which to place their ant choice
 *
 * @param antChoice - int - the type of ant user has chosen
 * @return int - the location which user has decided to place an ant
 */
// This function is > 20 lines to make it more readable.
int Game::pickAntLocation(int antChoice) {
    cout << "Pick a square [1-10]" << endl;
    cout << "Hit Enter to confirm selection. Select:";
    string choice;
    getline(cin, choice);
    int position = stoi(choice);

    bool outOfBoard = (position < 1 || position > 10);
    bool antThere = (antChoice != 8 && gameBoard[position].ant != NULL);
    bool bodyguardThere = (antChoice == 8 && gameBoard[position].bodyguard != NULL);

    while (outOfBoard || antThere || bodyguardThere) {
        cout << "Bad placement." << endl;
        if (outOfBoard) {cout << "That's outside the board." << endl;}
        if (antThere) {cout << "There's already an Ant there." << endl;}
        if (bodyguardThere) {cout << "There's already a bodyguard there." << endl;}

        cout << "Pick a square [1-10]" << endl;
        cout << "Hit Enter to confirm selection. Select:";
        getline(cin, choice);
        position = stoi(choice);

        outOfBoard = (position < 1 || position > 10);
        antThere = (antChoice != 8 && gameBoard[position].ant != NULL);
        bodyguardThere = (antChoice == 8 && gameBoard[position].bodyguard != NULL);
    }

    return position;
}
