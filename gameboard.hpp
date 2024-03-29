/*********************************************************************************
author: Nicholas Damiano
filename: gameboard.hpp
date: 8 Dec 19
description: Gameboard i responsible for creating a 2d array of integers based off
the level text file. It also displays the board and creates the linked list based off
the 2d array of space pointers. 
*********************************************************************************/

#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "space.hpp"
#include "player.hpp"
#include "empty.hpp"
#include "can.hpp"
#include "garbage_bin.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::vector;


class Gameboard
{
    private:
        int row = 0;
        int col = 0;
        int value;
        int counter;
        std::ifstream infile;
        Space* gameboard[4][9];
        Space* temp_space;
        int map[4][9];
        vector<Space*> all_spaces;
        string temp_string;
        string up_option = "";
        string right_option = "";
        string down_option = "";
        string left_option = "";
        
        
        

    public:
        Gameboard(string level_name);
        ~Gameboard();
        void createBoard(string level_name);
        void createMap(string level_name);
        Space* getSpaceType(int type);
        int listOptions();
        int get_player_row();
        int get_player_col();
        void displayBoard();
        Space* get_player();
        void update_linked_list();
        void set_new_mem(int row, int col, Space* space_pointer);
        void update_player_map(int row, int col);
        void replace_can_with_space(int row, int col);
        void add_space_to_vector(Space* space_loc);
        bool can_check(std::queue<Space*>&inventory);
};
#endif