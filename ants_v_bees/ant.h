//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_ANT_H
#define ANTS_V_BEES_ANT_H

#include "insect.h"

class Ant : public Insect {

public:
	// constructor
	Ant();

	// copy constructor
	Ant(Ant &orig);

	// Assignment operator overload
	Ant & operator=( const Ant &right);

	// destructor
	~Ant();

	/***
	 * fields
	 */

	int foodCost;
};


#endif //ANTS_V_BEES_ANT_H
