//
// Created by Miguel on 11/3/2020.
//

#include "place.h"

Place::Place() {
	ant = NULL;
	bodyguard = NULL;
	bees = new vector<Bee*>();
}

Place::~Place() {

}