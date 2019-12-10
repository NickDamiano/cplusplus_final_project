/*********************************************************************************
author: Nicholas Damiano
filename: empty.hpp
date: 8 Dec 19
description: Inherits from Space class. Is an empty actual space that can be navigated to
*********************************************************************************/

#ifndef EMPTY_HPP
#define EMPTY_HPP

#include <string>
#include <queue>
#include "space.hpp"
using std::string;

class Empty : public Space 
{
    protected:
        

    public:
        Empty();
        ~Empty();
        Space* doStuff(std::queue<Space*>&inventory);

};

#endif