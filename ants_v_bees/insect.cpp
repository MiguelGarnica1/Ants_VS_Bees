//
// Created by Miguel Garnica and Ky Phan on  11/2/2020.
//

#include "insect.h"

/*** constructor
 * all insects are not dead by default
 */
Insect::Insect() {
	this->isDead = false;
}


/*** copy constructor
 *
 * @param orig - Insect to be copied from
 */
Insect::Insect(Insect &orig) {
    this->name = orig.name;
    this->armor = orig.armor;
    this->isDead = orig.isDead;
}

/*** assignment operator overload
 *
 * @param right - Insect right of '=' operator that will be copied from
 * @return Insect - a new Insect copied from right Insect
 */
Insect &Insect::operator=(const Insect &right) {

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
Insect::~Insect() {}


/*** take damage to armor
 *
 * @param damage - int - the amount of damage to take from self
 */
void Insect::damaged(int damage) {
	this->armor = this->armor - damage;
	if(armor <= 0){
		this->isDead = true;
	}
}