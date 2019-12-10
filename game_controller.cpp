#include "game_controller.hpp"
#include "gameboard.hpp"
#include <queue>


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
        string target_action = "";
        if(action_choice == 1)
        {
            // Can
            if(player_object->up->get_proximity_option1() == "Pick Up Beer Can")
            {
                cout << "in beer can." << endl;
                if(inventory.empty())
                {
                    target_loc = player_object->up->doStuff(inventory);
                    cout << "invnetory was empty.\n";
                    Space* new_space = new Empty();
                    // Push that new space into the vector of spaces to delete later
                    gb.add_space_to_vector(new_space);
                    // set the board's memory space to be that new space
                    gb.set_new_mem(player_row-1, player_col, new_space );
                    gb.replace_can_with_space(player_row-1, player_col);

                }
                else
                    cout << "Your inventory is full. You can only carry one can because you are so drunk still.\nPlease place the can in the garbage bin.\n";
            }
            
            
    
            // Movement
            if(player_row!=0)
            {
                target_loc = player_object->up->doStuff(inventory);
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
                target_loc = player_object->right->doStuff(inventory);
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
                target_loc = player_object->down->doStuff(inventory);
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
                target_loc = player_object->left->doStuff(inventory);
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

