#include "gameboard.hpp"

Gameboard::Gameboard()
{
}

Gameboard::~Gameboard()
{

}

void Gameboard::createMatrix(string level_name)
{
    
}

void Gameboard::createBoard(string level_name)
{
    infile.open(level_name);
    while(std::cin >> value)
    {
        if(value == 0)
        {
            temp_space = new Empty;
        }
        for(int i = 0;i<4; i++)
        {
            for(int j = 0;j<9; j++)
            {
                gameboard[i][j] = temp_space;
            }
        }
    }

}