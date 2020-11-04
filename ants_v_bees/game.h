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
    void placeAnt();
    void placeHarvester(int location);
    void placeThrower(int location);
    void placeFire(int location);
    void placeLongThrower(int location);
    void placeShortThrower(int location);
    void placeWall(int location);
    void placeNinja(int location);
    void placeBodyguard(int location);

    void generateBee();
    void antAttack();
    void doThrower(int location);
    void doLongThrower(int location);
    void doShortThrower(int location);

    void beesAttack();
    void processBeesInBoard(int boardLocation);

    int checkBeeCount();
    bool queenDead();

    int menu();
    int pickAnt();
    int pickAntLocation(int antChoice);

private:
    // Game board 2D Vector
    vector<Place> gameBoard;
    int turn_counter;
    int food;
};


#endif //ANTS_V_BEES_GAME_H
