#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "space.hpp"
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
        
        
        

    public:
        Gameboard();
        ~Gameboard();
        void createBoard(string level_name);
        void createMatrix(string level_name);
};
#endif