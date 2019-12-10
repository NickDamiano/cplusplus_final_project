#include "game_controller.hpp"
#include "gameboard.hpp"


GameController::GameController(string level_name)
{
    rounds = 20;
}

GameController::~GameController()
{

}

void GameController::ExecuteRound()
{

}

void GameController::Run(string level_name)
{
    Space* target_loc = nullptr;
    Space* temporary_space = nullptr;
    Space* player = nullptr;
    Gameboard gb(level_name);
    

    for(int i = 0; i<rounds; i++)
    {
        player_row = gb.get_player_row();
        player_col = gb.get_player_col();
        Space* player_object = gb.get_player();
        gb.displayBoard();
        cout << rounds - i - 1 << " remaining turns\n";
        action_choice = gb.listOptions();
        if(action_choice == 1)
        {
            if(player_row!=0)
            {
                target_loc = player_object->up->doStuff();
                // If it's an empty space
                if(target_loc->proximity_option1 == "move")
                {
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row-1, player_col, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row-1, player_col);
                }
            }
        }

        if(action_choice == 2)
        {
            if(player_col!=8)
            {
                target_loc = player_object->right->doStuff();
                // If it's an empty space
                if(target_loc->proximity_option1 == "move")
                {
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row, player_col+1, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row, player_col+1);
                }
            }
        }

        if(action_choice == 3)
        {
            if(player_row!=3)
            {
                target_loc = player_object->down->doStuff();
                // If it's an empty space
                if(target_loc->proximity_option1 == "move")
                {
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row+1, player_col, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row+1, player_col);
                }
            }
        }

        if(action_choice == 4)
        {
            if(player_col!=0)
            {
                target_loc = player_object->left->doStuff();
                // If it's an empty space
                if(target_loc->proximity_option1 == "move")
                {
                    // change gameboard pointer for target space to point to player
                    gb.set_new_mem(player_row, player_col-1, player_object );
                    // change playerl ocation to old space
                    gb.set_new_mem(player_row, player_col, target_loc);
                    gb.update_player_map(player_row, player_col-1);
                }
            }
        }
            
        gb.update_linked_list();
                
        
            // execute top action
        // if action choice == 2
            // execute right action
        // if action choice == 3
            // execute bottom action
        // if action choice == 4
            // execute left action
        // increment counter
        // perform can check 
            // if no cans
                // trigger victory return exiting
            // level 2 might happen then
    }
    // out of rounds trigger parents home oh no
    
}

