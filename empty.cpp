/*********************************************************************************
author: Nicholas Damiano
filename: empty.cpp
date: 8 Dec 19
description: Inherits from Space class. Is an empty actual space that can be navigated to
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

// Returns it's memory location to be used with swapping the player and this square
Space* Empty::doStuff(std::queue<Space*>&inventory)
{
    return this;

}