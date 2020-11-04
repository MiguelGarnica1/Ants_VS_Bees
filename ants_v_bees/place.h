//
// Created by Miguel on 11/3/2020.
//

#ifndef ANTS_V_BEES_PLACE_H
#define ANTS_V_BEES_PLACE_H

#include <vector>
#include <string>
#include "insect.h"
#include "ant.h"
#include "bodyguard.h"
#include "bee.h"

using namespace std;

class Place {

public:
	// constructor
	Place();

	// destructor
	~Place();

	Ant *ant;
	Bodyguard *bodyguard;
	vector<Bee*> *bees;
	int location;
};


#endif //ANTS_V_BEES_PLACE_H
