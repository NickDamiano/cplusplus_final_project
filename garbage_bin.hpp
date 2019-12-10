/*********************************************************************************
author: Nicholas Damiano
filename: garbage_bin.hpp
date: 8 Dec 19
description: Inherits from Space class and pops out the can
*********************************************************************************/
#ifndef GARBAGE_BIN_HPP
#define GARBAGE_BIN_HPP

#include "space.hpp"
#include <iostream>
#include <queue>
#include <string>

class GarbageBin : public Space 
{
    private:

    public:
        GarbageBin();
        Space* doStuff(std::queue<Space*>&inventory);
};

#endif