#ifndef EMPTY_HPP
#define EMPTY_HPP

#include <string>
#include "space.hpp"
using std::string;

class Empty : public Space 
{
    protected:
        

    public:
        Empty();
        ~Empty();
        // Space* up       = nullptr;
        // Space* right    = nullptr;
        // Space* down     = nullptr;
        // Space* left     = nullptr;
        // string proximity_option1 = "";
        // string proximity_option2 = "";
        // string type;
        // Space();
        // ~Space();
        // virtual string get_proximity_option1(){};
        // string get_proximity_option1();
        // string get_proximity_option2();
        void do_stuff();



};

#endif