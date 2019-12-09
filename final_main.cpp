#include <iostream>
#include <string>
#include "space.hpp"
#include "menu.hpp"
#include "empty.hpp"
#include "gameboard.hpp"
#include "player.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;

int main()
{
    Space space;
    cout << space.up;
    cout << space.right;
    cout << space.down;
    cout << space.left;
    cout << space.proximity_option1;
    cout << space.proximity_option2;

    Empty empty;
    cout << empty.up;
    cout << empty.right;
    cout << empty.left;
    cout << empty.down;
    cout << empty.proximity_option2;

    Player player;
    cout << player.up;
    Gameboard gb("level_1.txt");
    return 0;
}