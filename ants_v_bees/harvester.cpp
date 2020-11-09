//
// Created by Miguel Garnica and Ky Phan on 11/2/2020.
//

#include "harvester.h"

/*** constructor
 * creates new Harvester ant
 */
Harvester::Harvester() {
	this->name = "Harvester";
	this->foodCost = 2;
}

/*** copy constructor
 *
 * @param other - Harvester to be copied
 */
Harvester::Harvester(Harvester &other) {
	this->name = other.name;
	this->foodCost = other.foodCost;
	this->armor = other.armor;
	this->isDead = other.isDead;
}

/*** destructor
 * all fields are primitive
 */
Harvester::~Harvester() {}

