#include "gameboard.hpp"

Gameboard::Gameboard(string level_name)
{
    createMap(level_name);
    createBoard(level_name);

}

Gameboard::~Gameboard()
{

}

void Gameboard::createMap(string level_name)
{
    infile.open(level_name);
    for(int i = 0;i<4;i++)
    {
        for(int j = 0; j<9;j++)
        {
            infile >> temp_string;
            map[i][j] = std::stoi(temp_string);
        }
    }
    infile.close();
    for(int i = 0;i<4;i++)
    {
        for(int j = 0; j<9;j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
}

Space* Gameboard::getSpaceType(int type)
{
    Space* spaceType = nullptr;
    if(type == 0)
    {
        spaceType = new Empty;
        all_spaces.push_back(spaceType);
        return spaceType;
    }
    else if(type == 1)
    {
        spaceType = new Player;
        all_spaces.push_back(spaceType);
        return spaceType;
    }
}

void Gameboard::createBoard(string level_name)
{

    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            temp_space = getSpaceType(map[i][j]);
            gameboard[i][j] = temp_space;
        }
    }

    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            string option = gameboard[i][j]->get_proximity_option1();
            cout << option;
        }
        cout << endl;
    }

}