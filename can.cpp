#include "can.hpp"
#include <queue>

Can::Can()
{
    proximity_option1 = "Pick Up Beer Can";
}
Space* Can::doStuff(std::queue<Space*>&inventory)
{
    inventory.push(this);
    return this;
}