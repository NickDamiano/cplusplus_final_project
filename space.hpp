/*********************************************************************************
author: Nicholas Damiano
filename: space.cpp
date: 8 Dec 19
description: Virtual class for space on the board. Empty, Garbage_bin, Player, and 
can all inherit from this. 
*********************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
#include <queue>
using std::string;

class Space
{
    protected:
        

    public:
        Space* up       = nullptr;
        Space* right    = nullptr;
        Space* down     = nullptr;
        Space* left     = nullptr;
        string proximity_option1 = "";
        string proximity_option2 = "";
        string type;
        Space();
        ~Space();
        virtual Space* doStuff(std::queue<Space*>&inventory){};
        string get_proximity_option1();
        string get_proximity_option2();
};

#endif