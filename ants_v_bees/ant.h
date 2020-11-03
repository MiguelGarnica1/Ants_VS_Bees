//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_ANT_H
#define ANTS_V_BEES_ANT_H

#include "insect.h";

class Ant : public Insect {

public:
	// constructor
	Ant();

	// copy constructor
	Ant(Ant &orig);

	// destructor
	~Ant();

	// attack a bee
	void attack(Insect &other);

	// move
};


#endif //ANTS_V_BEES_ANT_H
