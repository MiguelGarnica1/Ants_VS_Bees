//
// Created by Miguel on 11/2/2020.
//

#include "ant.h"

/*** constructor
 *  create an ant, "Queen" ant by default
 */
Ant::Ant() {
	this->name = "Queen";
	this->armor = 1;
}

/*** copy constructor
 *
 * @param orig - Ant to be copied from
 */
Ant::Ant(Ant &orig) {
	this->name = orig.name;
	this->armor = orig.armor;
	this->foodCost = orig.foodCost;
	this->isDead = orig.isDead;
}

/*** assignment overload operator
 *
 * @param right - Ant on the right of '=' operator to be copied to left side
 * @return Ant - copied over from Ant on the right
 */
Ant & Ant::operator=(const Ant &right) {
	if (&right == this) {
		return (*this);
	} else {
		this->name = right.name;
		this->armor = right.armor;
		this->foodCost = right.foodCost;
		this->isDead = right.isDead;
		return (*this);
	}
}

/*** destructor
 *  all fields are primitive
 */
Ant::~Ant() {

}

