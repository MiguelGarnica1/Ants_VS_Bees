//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_SHORT_THROWER_H
#define ANTS_V_BEES_SHORT_THROWER_H

#include "insect.h"
#include "ant.h"

class short_thrower : public Ant {
    // constructor
    short_thrower();

    // destructor
    ~short_thrower();

    // attack a bee
    void attack(Insect &other);

    // get damaged
    void damaged(int damage);

    // move
    void move();

    /***
     * fields
     */

    int foodCost;
};


#endif //ANTS_V_BEES_SHORT_THROWER_H
