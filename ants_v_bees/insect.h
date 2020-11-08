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

	// copy constructor
	Insect(Insect &orig);

	// equals operator overload
	Insect & operator=( const Insect &right);

	// destructor
	~Insect();

	// get damaged
	void damaged(int damage);

	/***
	 * fields
	 */
	int armor;
	string name;
	bool isDead;
};


#endif //ANTS_V_BEES_INSECT_H
