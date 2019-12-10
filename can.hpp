/*********************************************************************************
author: Nicholas Damiano
filename: can.hpp
date: 8 Dec 19
description: Inherits from Space class. Represents a beer can. special ability pushes
beer can into user inventory. User can only hold one beer can at a time. 
*********************************************************************************/
#ifndef CAN_HPP
#define CAN_HPP

#include <string>
#include <queue>
#include <iostream>
#include "space.hpp"
using std::endl;
using std::cout;
using std::cin;
using std::string;

class Can : public Space 
{
    private:

    public:
        Can();
        Space* doStuff(std::queue<Space*>&inventory);

};

#endif