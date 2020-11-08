//
// Created by Miguel on 11/3/2020.
//

#include "fire.h"

/*** constructor
 * creates a new Fire Ant
 */
Fire::Fire() {
	this->name = "Fire";
	this->foodCost = 3;
}

/*** copy constructor
 *
 * @param other - Fire ant to be copied from
 */
Fire::Fire(Fire &other) {
	this->name = other.name;
	this->foodCost = other.foodCost;
	this->armor = other.armor;
	this->isDead = other.isDead;
}

/*** destructor
 *  all fields are primitive
 */
Fire::~Fire() {}