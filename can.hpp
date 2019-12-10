#ifndef CAN_HPP
#define CAN_HPP

#include <string>
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
        Space* doStuff();

};

#endif