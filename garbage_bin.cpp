#include "garbage_bin.hpp"
#include <queue>

GarbageBin::GarbageBin()
{
    proximity_option1 = "Throw away all your garbage";
}

Space* GarbageBin::doStuff(std::queue<Space*>&inventory)
{
    inventory.pop();
    std::cout << "\n\nYOU THREW A BEER CAN AWAY. YOUR INVENTORY IS EMPTY!\n\n";
    return this;
}