//
// Created by Miguel on 11/2/2020.
//

#include "ant.h"

Ant::Ant() {
	this->name = "Queen";
	this->armor = 1;
}

Ant::Ant(Ant &orig) {

}

Ant & Ant::operator=(const Ant &right) {
	if (&right == this) {
		return (*this);
	} else {
		this->name = right.name;
		this->armor = right.armor;
		return (*this);
	}
}

Ant::~Ant() {

}


void Ant::attack(Insect &other) {
	other.damaged(1);
}
