//
// Created by Miguel on 11/2/2020.
//

#include "bodyguard.h"

/*** constructor
 * creates a bodygaurd ant
 */
Bodyguard::Bodyguard() {
    this->name = "Bodyguard";
    this->armor = 2;
    this->foodCost = 4;
}

/*** destructor
 * all fields are primitive
 */
Bodyguard::~Bodyguard() {}