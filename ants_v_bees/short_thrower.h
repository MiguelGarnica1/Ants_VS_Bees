//
// Created by Miguel on 11/2/2020.
//

#ifndef ANTS_V_BEES_SHORT_THROWER_H
#define ANTS_V_BEES_SHORT_THROWER_H

#include "insect.h"
#include "ant.h"

class Short_thrower : public Ant {

public:
    // constructor
    Short_thrower();

    // destructor
    ~Short_thrower();

    // attack a bee
    void attack(Insect &other);

    // get damaged
    void damaged(int damage);

    // move
    void move();

    /***
     * fields
     */
};


#endif //ANTS_V_BEES_SHORT_THROWER_H
