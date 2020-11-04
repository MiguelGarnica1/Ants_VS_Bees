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

Game::Game()  {
    // initialize game board with 11 'Place's. The 10 spaces, and 1 at the beginning (left
    // most) to represent the queen ant dead.
    this-> gameBoard = vector<Place>(11);

    // initialize 'turn_counter' to 1 (first turn).
    this->turn_counter = 1;

    // initialize 'food' to 50 starting food.
    this->food = 50;

    /**
     *  [Q], [], [], [], [], [], [], [], [Fire], [Bee, Bee]
     */
}

Game::~Game() {}

#include "game.h"
void Game::gameLoop() {
    do {
        /*** NEED TO IMPLEMENT
         *  Ant attacks, fire ant, throwers
         *  food cost
         */

        if(queenDead()) break;

        // 1) A bee is generated on the right side of the board
        generateBee();
        printGameBoard();

        // 2) The player can generate an ant and place it anywhere on the board if food count permits.
        // if not, auto-end turn.
        int option = menu();
        if (option == 2) {this->placeAnt();}

        this->turn_counter ++;
        cout << "TURN ENDED." << endl;

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
    } while(!queenDead() || checkBeeCount() != 0);

    if(queenDead()) {
        cout << "\n" << "The queen is dead! The bees win!" << endl;
    }
    else {
        cout << "\n" << "All bees are dead! The ants win!" << endl;
    }
}

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

void Game::placeHarvester(int location) {
    if ((this->food - 2) >= 0) {
        gameBoard[location].ant = new Harvester();
        cout << "Added Harvester Ant" << endl;
        this->food -= 2;
    }
    else {cout << "Not enough food.";}
}
void Game::placeThrower(int location) {
    if ((this->food - 4) >= 0) {
        gameBoard[location].ant = new Thrower();
        cout << "Added Thrower Ant" << endl;
        this->food -= 4;
    }
    else {cout << "Not enough food.";}
}
void Game::placeFire(int location) {
    if ((this->food - 4) >= 0) {
        gameBoard[location].ant = new Fire();
        cout << "Added Fire Ant" << endl;
        this->food -= 4;
    }
    else {cout << "Not enough food.";}
}
void Game::placeLongThrower(int location) {
    if ((this->food - 3) >= 0) {
        gameBoard[location].ant = new Long_thrower();
        cout << "Added Long Thrower Ant" << endl;
        this->food -= 3;
    }
    else {cout << "Not enough food.";}
}
void Game::placeShortThrower(int location) {
    if ((this->food - 3) >= 0) {
        gameBoard[location].ant = new Short_thrower();
        cout << "Added Short Thrower Ant" << endl;
        this->food -= 3;
    }
    else {cout << "Not enough food.";}
}
void Game::placeWall(int location) {
    if ((this->food - 4) >= 0) {
        gameBoard[location].ant = new Wall();
        cout << "Added Wall Ant" << endl;
        this->food -= 4;
    }
    else {cout << "Not enough food.";}
}
void Game::placeNinja(int location) {
    if ((this->food - 6) >= 0) {
        gameBoard[location].ant = new Ninja();
        cout << "Added Ninja Ant" << endl;
        this->food -= 6;
    }
    else {cout << "Not enough food.";}
}
void Game::placeBodyguard(int location) {
    if ((this->food - 4) >= 0) {
        gameBoard[location].bodyguard = new Bodyguard();
        cout << "Added Body Guard Ant" << endl;
        this->food -= 4;
    }
    else {cout << "Not enough food.";}
}

void Game::antAttack() {
    for(int i = 1; i < gameBoard.size(); i++) {
        if (gameBoard[i].ant == NULL) continue;

        string antName = gameBoard[i].ant->name;
        // 'switch' and 'case' doesn't work with string.
        // If ant is Harvester, get food
        if (antName.compare("Harvester") == 0) {this->food++;}
        else if (antName.compare("Thrower") == 0) {this->doThrower(i);}
        else if (antName.compare("Long Thrower") == 0) {}
        else if (antName.compare("Short Thrower") == 0) {}
    }
}

void Game::doThrower(int location) {
    // If there are bees damage the 1st bee.
    if (!gameBoard[location].bees->empty())
        gameBoard[location].bees->front()->damaged(1);
    if (gameBoard[location].bees->front()->isDead) {
        gameBoard[location].bees->erase(gameBoard[location].bees->begin());
    }
}

void Game::doLongThrower(int location) {}

void Game::doShortThrower(int location) {}

void Game::beesAttack() {
    // Go through the game board.
    for(int i = 1; i < gameBoard.size(); i++){
        // Processing the bees in each game board.
        if(gameBoard[i].bees->empty()) continue;
        processBeesInBoard(i);
    }
}
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
                if (gameBoard[board].ant->name.compare("Fire") == 0) {gameBoard[board].bees->clear();}
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
            gameBoard[board].bees->erase(gameBoard[board].bees->begin() + j);
            // 'Bee' erased from vector. Other 'Bee's in vector is shifted.
            // Take into account this shift by offsetting 'j' counter.
            j--;
        }
    }
}


void Game::generateBee() {
    this->gameBoard.at(gameBoard.size()-1).bees->push_back(new Bee());
}

void Game::printGameBoard() {
    cout << "\nTurn #" << this->turn_counter << "  Food: " << this->food << endl;
    for(int i = 1; i < gameBoard.size(); i++){
        cout << "Square " << i;
        if(gameBoard[i].ant != NULL){
            cout << " " <<gameBoard[i].ant->name <<" Ant, Health:  " << gameBoard[i].ant->armor << ", DEade? " << gameBoard[i].ant->isDead;
        }

        if(!gameBoard.at(i).bees->empty()) {
            cout << " BEES" << gameBoard[i].bees->front()->armor << " #" << gameBoard[i].bees->size();
        }
        cout << endl;
    }
}

bool Game::queenDead() {
    if(!gameBoard[0].bees->empty()){
        return true;
    }

    return false;
}

int Game::checkBeeCount() {
    int beeCount = 0;

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

int Game::pickAnt() {
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
        cout << "Bad input, try again.";
        getline(cin, choice);
        option = stoi(choice);
    }

    return option;
}


// This function is > 20 lines to make it more readable.
// There's a shorter version of the same function right below this.
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
// The 'pickAntLocation' function, short version.
//int Game::pickAntLocation(int antChoice) {
//    cout << "Pick a square [1-10]" << endl;
//    cout << "Hit Enter to confirm selection. Select:";
//    string choice;
//    getline(cin, choice);
//
//    int position = stoi(choice);
//
//    while ((position < 1 || position > 10) || (antChoice != 8 && gameBoard[position].ant != NULL) || (antChoice == 8 && gameBoard[position].bodyguard != NULL)) {
//        cout << "Bad placement." << endl;
//        if ((position < 1 || position > 10)) {cout << "That's outside the board." << endl;}
//        if ((antChoice != 8 && gameBoard[position].ant != NULL)) {cout << "There's already an Ant there." << endl;}
//        if ((antChoice == 8 && gameBoard[position].bodyguard != NULL)) {cout << "There's already a bodyguard there." << endl;}
//
//        cout << "Pick a square [1-10]" << endl;
//        cout << "Hit Enter to confirm selection. Select:";
//        getline(cin, choice);
//        position = stoi(choice);
//    }
//
//    return position;
//}
