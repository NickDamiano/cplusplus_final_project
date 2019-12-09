#ifndef SPACE_HPP
#define SPACE_HPP

#include <string>
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
        virtual void doStuff(){};
        string get_proximity_option1();
        string get_proximity_option2();
};

#endif