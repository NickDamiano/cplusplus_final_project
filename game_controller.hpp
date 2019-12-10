/*********************************************************************************
author: Nicholas Damiano
filename: game_controller.hpp
date: 8 Dec 19
description: The game controller has the main loop for the game. Rounds can be tweaked
to make the game harder or easier. The main Run method lists options and handles the
user input on how to move as well as swapping spaces. 
*********************************************************************************/
#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <iostream>
#include <string>
#include "gameboard.hpp"
#include <vector>
#include <queue>

using std::queue;
using std::vector;

class GameController
{
    private:
        string level_name;
        int rounds;
        int action_choice = 0;
        bool no_cans = false;
        int player_col;
        int player_row;
        queue<Space*> inventory;

    public:
        GameController(string level_name);
        ~GameController();
        bool Run(string level_name);

};

#endif