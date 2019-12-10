/*********************************************************************************
author: Nicholas Damiano
filename: space.hpp
date: 8 Dec 19
description: Virtual class for space on the board. Empty, Garbage_bin, Player, and 
can all inherit from this. 
*********************************************************************************/

#include "space.hpp"

Space::Space()
{

}

Space::~Space()
{
    
}

string Space::get_proximity_option1()
{
    return proximity_option1;
}
string Space::get_proximity_option2()
{
    return proximity_option2;
}



