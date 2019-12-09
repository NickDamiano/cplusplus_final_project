#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "space.hpp"
#include "player.hpp"
#include "empty.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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
        
        
        

    public:
        Gameboard(string level_name);
        ~Gameboard();
        void createBoard(string level_name);
        void createMap(string level_name);
        Space* getSpaceType(int type);
};
#endif