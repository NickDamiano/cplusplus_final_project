/*********************************************************************************
author: Nicholas Damiano
filename: game_controller.cpp
date: 8 Dec 19
description: The game controller has the main loop for the game. Rounds can be tweaked
to make the game harder or easier. The main Run method lists options and handles the
user input on how to move as well as swapping spaces. 
*********************************************************************************/
#include "game_controller.hpp"
#include "gameboard.hpp"
#include <queue>

// Set rounds
GameController::GameController(string level_name)
{
    rounds = 20;
}

GameController::~GameController()
{

}

// Returns bool if player won or not. Takes level name for file to read in level
bool GameController::Run(string level_name)
{
    // Creates space pointer to store the returning memory location from doStuff call of the target
    // object
    Space* target_loc = nullptr;
    Space* temporary_space = nullptr;
    // player holds pointer to player
    Space* player = nullptr;
    // create gameboard
    Gameboard gb(level_name);
    
    // Loop through number of rounds set in constructor. Player has until end of this loop to finish game
    for(int i = 0; i<rounds; i++)
    {
        // Get the player row and column and player location (pointer)
        player_row = gb.get_player_row();
        player_col = gb.get_player_col();
        Space* player_object = gb.get_player();
        // output the board map to the user
        gb.displayBoard();

        // output the number of minutes/rounds left for the user. 
        cout << rounds - i - 1 << " minutes until Mom and Dad get home!!!\n";
        // list all the actions to be done by the 4 surrounding squares around the player
        action_choice = gb.listOptions();
        string target_action = "";
        // If the user selects 1 they're talking about the option that correspond to the top square/space
        if(action_choice == 1)
        {
            // Movement
            // If the player is on the first row, nothing is above them and they have selected do nothing.
            // and we actually do nothing
            if(player_row!=0)
            {
                // If it's an empty space
                if(player_object->up->proximity_option1 == "move")
                {
                    // have the target return it's memory location and perform other actions depending on type
                    target_loc = player_object->up->doStuff(inventory);
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row-1, player_col, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    // update player position on the map
                    gb.update_player_map(player_row-1, player_col);
                }

                // Can
                if(player_object->up->get_proximity_option1() == "Pick Up Beer Can")
                {
                    // we can only store 1 item at a time so if it's empty, we will store it
                    if(inventory.empty())
                    {
                        // in this case the can special action pushes it into the inventory container
                        target_loc = player_object->up->doStuff(inventory);
                        // We create a new empty space to put in place of the can
                        Space* new_space = new Empty();
                        // Push that new space into the vector of spaces to delete later
                        gb.add_space_to_vector(new_space);
                        // set the board's memory space to be that new space
                        gb.set_new_mem(player_row-1, player_col, new_space );
                        gb.replace_can_with_space(player_row-1, player_col);

                    }
                    // if player has a can in the inventory already they cannot pick up a can and get told so. 
                    else
                        cout << "Your inventory is full. You can only carry one can because you are so drunk still.\nPlease place the can in the garbage bin.\n";
                    
                }

                // Garbage bin
                // if the player is near a garbage bin, calling doStuff on the garbage can pops out the can and frees up the inventory
                if(player_object->up->get_proximity_option1() == "Throw away all your garbage")
                {
                    player_object->up->doStuff(inventory);
                }
            }
        }

        if(action_choice == 2)
        {
            if(player_col!=8)
            {
                // If it's an empty space
                if(player_object->right->proximity_option1 == "move")
                {
                    target_loc = player_object->right->doStuff(inventory);
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row, player_col+1, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row, player_col+1);
                }
                // Can
                if(player_object->right->get_proximity_option1() == "Pick Up Beer Can")
                {
                    if(inventory.empty())
                    {
                        target_loc = player_object->right->doStuff(inventory);
                        Space* new_space = new Empty();
                        // Push that new space into the vector of spaces to delete later
                        gb.add_space_to_vector(new_space);
                        // set the board's memory space to be that new space
                        gb.set_new_mem(player_row, player_col+1, new_space );
                        gb.replace_can_with_space(player_row, player_col+1);

                    }
                    else
                        cout << "Your inventory is full. You can only carry one can because you are so drunk still.\nPlease place the can in the garbage bin.\n";
                    
                }

                // Garbage bin
                if(player_object->right->get_proximity_option1() == "Throw away all your garbage")
                {
                    player_object->right->doStuff(inventory);
                }
            }
        }

        if(action_choice == 3)
        {
            if(player_row!=3)
            {
                // If it's an empty space
                if(player_object->down->proximity_option1 == "move")
                {
                    target_loc = player_object->down->doStuff(inventory);
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row+1, player_col, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row+1, player_col);
                }

                // Can
                if(player_object->down->get_proximity_option1() == "Pick Up Beer Can")
                {
                    if(inventory.empty())
                    {
                        target_loc = player_object->down->doStuff(inventory);
                        cout << "invnetory was empty.\n";
                        Space* new_space = new Empty();
                        // Push that new space into the vector of spaces to delete later
                        gb.add_space_to_vector(new_space);
                        // set the board's memory space to be that new space
                        gb.set_new_mem(player_row+1, player_col, new_space );
                        gb.replace_can_with_space(player_row+1, player_col);

                    }
                    else
                        cout << "Your inventory is full. You can only carry one can because you are so drunk still.\nPlease place the can in the garbage bin.\n";
                }

                // Garbage bin
                if(player_object->down->get_proximity_option1() == "Throw away all your garbage")
                {
                    player_object->down->doStuff(inventory);
                }
            }
        }

        if(action_choice == 4)
        {
            if(player_col!=0)
            {
                // If it's an empty space
                if(player_object->left->proximity_option1 == "move")
                {
                    target_loc = player_object->left->doStuff(inventory);
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row, player_col-1, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row, player_col-1);
                }
                // Can
                if(player_object->left->get_proximity_option1() == "Pick Up Beer Can")
                {
                    if(inventory.empty())
                    {
                        target_loc = player_object->left->doStuff(inventory);
                        cout << "invnetory was empty.\n";
                        Space* new_space = new Empty();
                        // Push that new space into the vector of spaces to delete later
                        gb.add_space_to_vector(new_space);
                        // set the board's memory space to be that new space
                        gb.set_new_mem(player_row, player_col-1, new_space );
                        gb.replace_can_with_space(player_row, player_col-1);

                    }
                    else
                        cout << "Your inventory is full. You can only carry one can because you are so drunk still.\nPlease place the can in the garbage bin.\n";
                }

                // Garbage bin
                if(player_object->left->get_proximity_option1() == "Throw away all your garbage")
                {
                    player_object->left->doStuff(inventory);
                }
            }
        }
        // At the end of the player movement action the positions hve changed and old up/down/left/right pointers are incorrect. 
        // This iterates through the 2d array of pointers and updates all of the spaces with the right addresses. 
        gb.update_linked_list();
        // We check if there are cans on the board or in inventory, if there are not, the player wins
        no_cans = gb.can_check(inventory);  
        if(no_cans)
        {
            cout << "\n\nYOU GOT THE PARTY CLEANED UP. You're totally NOT busted and Mom and Dad are none the wiser! You win!";
            return true;
        }
    }
    return false;
    
}

