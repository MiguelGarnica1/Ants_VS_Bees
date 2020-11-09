//
// Created by Miguel Garnica and Ky Phan on 11/2/2020.
//

#ifndef ANTS_V_BEES_HARVESTER_H
#define ANTS_V_BEES_HARVESTER_H

#include "ant.h"


class Harvester : public Ant{

public:
	// constructor
	Harvester();

	// copy constructor
	Harvester(Harvester &other);

	// destructor
	~Harvester();
};


#endif //ANTS_V_BEES_HARVESTER_H
