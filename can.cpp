/*********************************************************************************
author: Nicholas Damiano
filename: can.cpp
date: 8 Dec 19
description: Inherits from Space class. Represents a beer can. special ability pushes
beer can into user inventory. User can only hold one beer can at a time. 
*********************************************************************************/
#include "can.hpp"
#include <queue>

Can::Can()
{
    proximity_option1 = "Pick Up Beer Can";
}

// Takes the inventory object and returns the can's location.
// Inventory pushes can into it.
Space* Can::doStuff(std::queue<Space*>&inventory)
{
    inventory.push(this);
    return this;
}