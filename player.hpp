/*********************************************************************************
author: Nicholas Damiano
filename: player.hpp
date: 8 Dec 19
description: Inherits from Space class. Represents the player. 
*********************************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "space.hpp"
#include <queue>

class Player : public Space
{
    private:
        

    public:
        Player();
        void listOptions();
        Space* doStuff(std::queue<Space*>&inventory);
};
#endif