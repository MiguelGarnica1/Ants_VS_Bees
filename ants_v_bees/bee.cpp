//
// Created by Miguel Garnica and Ky Phan on  11/2/2020.
//
#include "bee.h"

/*** constructor
 * create a new bee
 */
Bee::Bee() {
    this->name = "Bee";
    this->armor = 3;
}

/*** copy constructor
 *
 * @param orig - Bee to be copied from
 */
Bee::Bee(Bee &orig) {
    this->name = orig.name;
    this->armor = orig.armor;
    this->isDead = orig.isDead;
}

/*** assignment operator overload
 *
 * @param right - Bee right of the '=' operator that will be copied
 * @return Bee - new Bee copied from Bee on the right
 */
Bee & Bee::operator=(const Bee &right) {
	if (&right == this) {
		return (*this);
	} else {
		this->name = right.name;
		this->armor = right.armor;
		this->isDead = right.isDead;
		return (*this);
	}
}

/*** destructor
 * all fields are primitive
 */
Bee::~Bee() {}