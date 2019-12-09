#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include "space.hpp"

class Player : public Space
{
    private:
        

    public:
        Player();
        void listOptions();
        void doStuff();
};
#endif