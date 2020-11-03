//
// Created by Miguel on 11/2/2020.
//


#include "bee.h"

Bee::Bee() {
    this->name = "Bee";
    this->armor = 3;
    this->location = 10;
}

Bee::Bee(Bee &orig) {
    this->name = orig.name;
    this->armor = orig.armor;
    this->location = orig.location;
}

Bee::~Bee() {}