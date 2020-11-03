//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_INSECT_H
#define ANTS_V_BEES_INSECT_H

#include "string"

using namespace std;

class Insect {

public:
	// constructor
    Insect();
	Insect(string newName, int newArmor, int newLocation);

	// copy constructor
	Insect(Insect &orig);

	// destructor
	~Insect();

	// attack other insect
	void attack(Insect &other);

	// get damaged
	void damaged(int damage);

	// make move
	void move();


	/***
	 * fields
	 */
	int armor;
	string name;
	int location;
};


#endif //ANTS_V_BEES_INSECT_H
