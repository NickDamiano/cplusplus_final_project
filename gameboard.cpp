#include "gameboard.hpp"
#include "menu.hpp"

Gameboard::Gameboard(string level_name)
{
    createMap(level_name);
    createBoard(level_name);
    update_linked_list();
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
    // This should be called from a controller
    // returns the choice
    // if 1, performs action for space above, if 2, action for space right
    // 

    
}

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
    // for(int j = 0;j<8;j++)
    // {
    //     gameboard[0][j]->right = gameboard[0][j+1];
    //     gameboard[0][j]->down = gameboard[1][j];
    // }
    // for(int j = 1;j<9;j++)
    // {
    //     gameboard[0][j]->right = gameboard[0][j+1];
    //     gameboard[0][j]->down = gameboard[1][j];
    // }
}

void Gameboard::set_new_mem(int row, int col, Space* space_pointer)
{
    gameboard[row][col] = space_pointer;
}

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