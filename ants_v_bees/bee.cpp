//
// Created by Miguel on 11/2/2020.
//


#include "bee.h"

Bee::Bee() {
    this->name = "Bee";
    this->armor = 3;
}

Bee::Bee(Bee &orig) {
    this->name = orig.name;
    this->armor = orig.armor;
}

Bee & Bee::operator=(const Bee &right) {
	if (&right == this) {
		return (*this);
	} else {
		this->name = right.name;
		this->armor = right.armor;
		return (*this);
	}
}

Bee::~Bee() {}