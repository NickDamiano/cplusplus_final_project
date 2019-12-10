/*********************************************************************************
author: Nicholas Damiano
filename: empty.hpp
date: 8 Dec 19
description: Inherits from Space class. Represents a beer can. special ability pushes
beer can into user inventory. User can only hold one beer can at a time. 
*********************************************************************************/

#include "empty.hpp"
#include <queue>

Empty::Empty()
{
    proximity_option1 = "move";
    proximity_option2 = "nothing";
}

Empty::~Empty()
{

}

Space* Empty::doStuff(std::queue<Space*>&inventory)
{
    // swap with player
    return this;

}