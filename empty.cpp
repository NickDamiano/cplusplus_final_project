#include "empty.hpp"
#include <queue>

Empty::Empty()
{
    proximity_option1 = "move";
    proximity_option2 = "nothing";
}

Empty::~Empty()
{

}

Space* Empty::doStuff(std::queue<Space*>&inventory)
{
    // swap with player
    return this;

}