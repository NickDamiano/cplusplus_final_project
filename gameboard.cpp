/*********************************************************************************
author: Nicholas Damiano
filename: gameboard.hpp
date: 8 Dec 19
description: Gameboard i responsible for creating a 2d array of integers based off
the level text file. It also displays the board and creates the linked list based off
the 2d array of space pointers. 
*********************************************************************************/
#include "gameboard.hpp"
#include <queue>
#include "menu.hpp"

// constructor creates the game map from the level file, sets up the gameboard, and links all 
// spaces together
Gameboard::Gameboard(string level_name)
{
    createMap(level_name);
    createBoard(level_name);
    update_linked_list();
}

// destructor iterates through container holding dynamically created memory and deletes them
Gameboard::~Gameboard()
{
    for (int i = 0;i< all_spaces.size(); i++)
    {
        delete all_spaces[i];
        all_spaces[i] = nullptr;
    }
}

// Creates the map by opening the file and iterating through putting integers
// into a 2d array of ints
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
}

// This creates the actual spaces based off the integer on the 2d array
// it then pushes them into our all_spaces container to be deleted later 
// and returns the pointer to the newly created space. 
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
    else if(type == 2)
    {
        spaceType = new Can;
        all_spaces.push_back(spaceType);
        return spaceType;
    }

    else if(type == 3)
    {
        spaceType = new GarbageBin;
        all_spaces.push_back(spaceType);
        return spaceType;
    }
}

// Creates the board of 2d pointers that is used for reference when
// linking spaces together
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

}

// lists all options for the player based off surrounding tiles
int Gameboard::listOptions()
{
    Menu menu;
    // iterate through surrounding items in array and list proximity options
    //
    int space_holder;
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {   
            space_holder = map[i][j];
            // if we find the player
            if(space_holder == 1)
            {
                // if we are top row we can't see up option
                if(i != 0) 
                { 
                    up_option = gameboard[i-1][j]->get_proximity_option1();
                    if(up_option == "move")
                        up_option = "Move Up";
                }
                else if(i == 0)
                    up_option = "Do Nothing";
                if(j != 8) 
                { 
                    right_option = gameboard[i][j+1]->get_proximity_option1();
                    if(right_option == "move")
                        right_option = "Move Right";
                }
                else if(j == 8)
                    right_option = "Do Nothing";
                if(i != 3) 
                { 
                    down_option = gameboard[i+1][j]->get_proximity_option1();
                    if(down_option == "move")
                        down_option = "Move Down";
                }
                else if(i == 3) { down_option = "Do Nothing";}
                if(j != 0) 
                { 
                    left_option = gameboard[i][j-1]->get_proximity_option1();
                    if(left_option == "move")
                        left_option = "Move Left";
                }
                else if(j == 0){ left_option = "Do Nothing";}
            }
        }
    }
    string user_choice_message = "Please select from an option below\n1 - " + up_option + "\n2 - " + right_option + "\n3 - " + down_option + "\n4- " + left_option + ": ";
    int user_choice = menu.full_int_check(user_choice_message, 1, 4);
    return user_choice;
    
}

// Returns the row number of player
int Gameboard::get_player_row()
{
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            if(map[i][j] == 1)
            {
                return i;
            }
        }
    }
}

// returns column number of player
int Gameboard::get_player_col()
{
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            if(map[i][j] == 1)
            {
                return j;
            }
        }
    }
}

// displays the board visually for the player
void Gameboard::displayBoard()
{
    cout << "PL = player; BC = Beer Can; GB = Garbage Bin\n";
    cout << "__________________" << endl;
    for(int i = 0;i<4; i++)
    {
        cout << "|";
        for(int j = 0;j<9; j++)
        {
            if(map[i][j] == 0)
            {
                cout << "  ";
            }
            if(map[i][j] == 1)
            {
                cout << "PL";
            }
            if(map[i][j] == 2)
            {
                cout << "BC";
            }
            if(map[i][j] == 3)
            {
                cout << "GB";
            }
        }
        cout << "|\n";
    }
    cout << "------------------\n" << endl;
}

// returns pointer for space of player
Space* Gameboard::get_player()
{
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            if(map[i][j] == 1)
            {
                return gameboard[i][j];
            }
        }
    }
}

// uses the 2d pointer array to update all gameboard neighboring space memory locations
void Gameboard::update_linked_list()
{
    // set left link to nullptr for first row and right link to null for last
    for(int i = 0;i<4; i++)
    {
        gameboard[i][0]->left = nullptr;
        gameboard[i][8]->right = nullptr;
    }
    for(int j = 0;j<9; j++)
    {
        gameboard[0][j]->up = nullptr;
        gameboard[3][j]->down = nullptr;
    }
    for(int i = 0;i<4; i++)
    {
        // Set right for all 
        for(int j = 0;j<8; j++)
        {
            gameboard[i][j]->right = gameboard[i][j+1];
        }
        // Set left for all
        for(int k = 1;k<9; k++)
        {
            gameboard[i][k]->left = gameboard[i][k-1];
        }
    }
    // set all down
    for(int i = 0;i<3; i++)
    {
        for(int j = 0;j<9; j++)
        {
            gameboard[i][j]->down = gameboard[i+1][j];
        }
    }
    // set all up
    for(int i = 1;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            gameboard[i][j]->up = gameboard[i-1][j];
        }
    }
}

// updates the gameboard 2d array of pointers with a new pointer after the player moves
// or a can is picked up
void Gameboard::set_new_mem(int row, int col, Space* space_pointer)
{
    gameboard[row][col] = space_pointer;
}

// updates the player map after the player moves, or can is picked up
void Gameboard::update_player_map(int row, int col)
{
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            if(map[i][j] == 1)
            {
                map[i][j] = 0;
                map[row][col] = 1;
            }
        }
    }
}

// simply puts a 0 representing a space on the 2d array of integers used
// to display game map
void Gameboard::replace_can_with_space(int row, int col)
{
    map[row][col] = 0;
}
// if we pick up a can we have to replace it's location with an empty space. We have to be able
// to delete that empty space later so all spaces to delete are in all_spaces
void Gameboard::add_space_to_vector(Space* space_loc)
{
    all_spaces.push_back(space_loc);
}

// iterates through all spaces and inventory to see if all cans have been thrown away and returns
// true if they have triggering victory conditions
bool Gameboard::can_check(std::queue<Space*>&inventory)
{
    bool result = true;
    if(!inventory.empty())
        result = false;
    for(int i = 0;i<4; i++)
    {
        for(int j = 0;j<9; j++)
        {
            if(map[i][j] == 2)
            {
                result = false;
            }
        }
    }
    return result;
}