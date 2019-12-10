#ifndef GARBAGE_BIN_HPP
#define GARBAGE_BIN_HPP

#include "space.hpp"
#include <iostream>
#include <string>

class GarbageBin : public Space 
{
    private:

    public:
        GarbageBin();
        Space* doStuff();
};

#endif