//
// Created by Miguel on 11/2/2020.
//

#include "thrower.h"

/*** constructor
 * create a new Thrower ant
 */
Thrower::Thrower() {
	this->name = "Thrower";
	this->foodCost = 4;
}

/** copy constructor
 *
 * @param other - Thrower ant to be copied
 */
Thrower::Thrower(Thrower &other) {
	this->name = other.name;
	this->armor = other.armor;
	this->foodCost = other.foodCost;
	this->isDead = other.isDead;
}

/*** destructor
 * all fields are primitive
 */
Thrower::~Thrower() {}

