#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <iostream>
#include <string>
#include "gameboard.hpp"

class GameController
{
    private:
        string level_name;
        int rounds;
        int action_choice = 0;
        bool no_cans = false;
        int player_col;
        int player_row;

    public:
        GameController(string level_name);
        ~GameController();
        void ExecuteRound();
        void Run(string level_name);

};

#endif