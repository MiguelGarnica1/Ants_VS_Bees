//
// Created by Miguel on 11/2/2020.
//

#include "insect.h"

Insect::Insect() {}

Insect::Insect(string newName, int newArmor, int newLocation) {
    this->name = newName;
    this->armor = newArmor;
    this->location = newLocation;
}

Insect::Insect(Insect &orig) {
    this->name = orig.name;
    this->armor = orig.armor;
    this->location = orig.location;
}

Insect::~Insect() {}

void Insect::damaged(int damage) {
    this->armor = this->armor - damage;
}