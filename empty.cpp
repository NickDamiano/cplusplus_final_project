#include "empty.hpp"

Empty::Empty()
{
    proximity_option1 = "move";
    proximity_option2 = "nothing";
}

Empty::~Empty()
{

}

Space* Empty::doStuff()
{
    // swap with player
    return this;

}