//
// Created by Miguel on 11/2/2020.
//

#include "long_thrower.h"

/*** constructor
 * creates a new Long_thrower ant
 */
Long_thrower::Long_thrower() {
	this->name = "Long Thrower";
	this->foodCost = 3;
}

/*** copy constructor
 *
 * @param orig - Long_thrower to be copied from
 */
Long_thrower::Long_thrower(Long_thrower &orig) {

}

/*** destructor
 * all fields are primitive
 */
Long_thrower::~Long_thrower() {}