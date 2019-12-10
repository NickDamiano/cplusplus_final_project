#include <iostream>
#include <string>
#include "space.hpp"
#include "menu.hpp"
#include "empty.hpp"
#include "gameboard.hpp"
#include "player.hpp"
#include "game_controller.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;

int main()
{
    GameController gc("level_1.txt");
    gc.Run("level_1.txt");
    return 0;
}