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