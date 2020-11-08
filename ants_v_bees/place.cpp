//
// Created by Miguel on 11/3/2020.
//

#include "place.h"

/*** constructor
 * create a new Place for the game board
 */
Place::Place() {
	ant = NULL;
	bodyguard = NULL;
	bees = new vector<Bee*>();
}


/*** destructor
 * destroy fields
 */
Place::~Place() {
	delete ant;
	delete bodyguard;

    for ( int i = 0; i < bees->size(); i++ ) { delete bees->at(i); }
    bees->clear();
	delete bees;
}