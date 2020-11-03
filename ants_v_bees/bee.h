//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_BEE_H
#define ANTS_V_BEES_BEE_H

#include "insect.h"

class Bee : public Insect {
	// constructor
    Bee();

	// copy constructor
	Bee(Bee &orig);

	// destructor
	~Bee();

	// attack an ant
	void attack(Insect &other);

	// move
	void move();
};


#endif //ANTS_V_BEES_BEE_H
