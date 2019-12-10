/*********************************************************************************
author: Nicholas Damiano
filename: garbage_bin.cpp
date: 8 Dec 19
description: Inherits from Space class and pops out the can
*********************************************************************************/
#include "garbage_bin.hpp"
#include <queue>

GarbageBin::GarbageBin()
{
    proximity_option1 = "Throw away all your garbage";
}

Space* GarbageBin::doStuff(std::queue<Space*>&inventory)
{
    if(inventory.empty())
    {
        std::cout << "\n\nYou don't have any cans to throw away.\n\n";
    }
    else
    {
        inventory.pop();
        std::cout << "\n\nYOU THREW A BEER CAN AWAY. YOUR INVENTORY IS EMPTY!\n\n";
    }
    
    return this;
}