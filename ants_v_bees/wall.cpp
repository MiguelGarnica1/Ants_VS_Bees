//
// Created by Miguel on 11/2/2020.
//

#include "wall.h"

/*** constructor
 * create a new Wall ant
 */
Wall::Wall() {
    this->name = "Wall";
    this->armor = 4;
    this->foodCost = 4;
}

/*** destructor
 * all fields are primitive
 */
Wall::~Wall() {}