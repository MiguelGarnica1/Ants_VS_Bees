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


	// attack a bee
	void attack(Insect &other);

	// get damaged
	void damaged(int damage);

	// move
	void move();

	/***
	 * fields
	 */

	int foodCost;
};


#endif //ANTS_V_BEES_ANT_H
