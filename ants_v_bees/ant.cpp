//
// Created by Miguel on 11/2/2020.
//

#include "ant.h"

Ant::Ant() {
	this->armor = 1;
}

Ant::Ant(Ant &orig) {

}

Ant::~Ant() {

}

void Ant::attack(Insect &other) {
	other.damaged(1);
}

void Ant::damaged(int damage) {
	this->armor -= damage;
}