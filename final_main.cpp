/*********************************************************************************
author: Nicholas Damiano
filename: final_main.cpp
date: 8 Dec 19
description: This program is a game where your parents are about to come home early
from a trip and you have 20 minutes to clean up from the party you had while they 
were gone. You have to pick up beer cans and wake up drunk people to leave. The program
imports from .txt files and has two levels with that design that allows the user
to make their own levels too by editing those files. 
*********************************************************************************/
#include <iostream>
#include <string>
#include "space.hpp"
#include "menu.hpp"
#include "empty.hpp"
#include "gameboard.hpp"
#include "player.hpp"
#include "game_controller.hpp"


using std::endl;
using std::cout;
using std::cin;
using std::string;

int main()
{
    // Create a new menu instance for getting and checking user input for integers
    Menu menu;
    bool victory = false;
    string first_message = "\n\n\nSomewhere in suburban America at 6AM.\n.`RING RING`. `RING RING`. <Hello?>, <Hi Honey! We got an early flight back from Europe and we'll be home in 20 MINUTES.\nSEE YOU SOON!\n";
    string second_message = "You look around. Last night was a RAGING PARTY BRUH. But you got 30 minutes to clean up these beer cans and get your\n friends out the door pronto amigo. GET TO WORK or you're TOTALLY BUSTED.\n\n";
    string ask_to_play = "Do you want to play 'Dont get busted!' ?\n1 - Play\n2 - Quit: ";
    string first_beat = "You've beat the first level. Play level 2?\n1 - Yes\n2 - Quit: ";
    // For user option if they want to play next level after beating the first. 
    int next_level_play = 0;
    cout << first_message;
    cout << second_message;
    // Get if the user wants to play
    int user_choice = menu.full_int_check(ask_to_play, 1,2);

    // If the user wants to play, create a new game controller and run it. It returns true or false if the player beat the first level
    while(user_choice != 2)
    {
        GameController gc("level_1.txt");
        victory = gc.Run("level_1.txt");

        // If the player beat the first level we offer them the choice to play the second level
        if(victory)
        {
            next_level_play = menu.full_int_check(first_beat, 1, 2);
            if(next_level_play == 1)
            {
                // Create a game controller and run it for level 2
                GameController gc2("level_2.txt");
                victory = gc2.Run("level_2.txt");

                // handle victory or failure
                if(victory)
                {
                    cout << "\nYou beat the game! You are the ultimate party dude/dudette!\n\n";
                }
                else
                {
                    cout << "\n\n\nYOU. ARE. TOTALLY. BUSTEDDDDDDDD!\nGrounded for the summer! oh no!\n\nGAME OVER!\n";
                }
            }
        }
        // If player loses first level they get a message telling them they lost
        else
        {
            cout << "\n\n\nYOU. ARE. TOTALLY. BUSTEDDDDDDDD!\nGrounded for the summer! oh no!\n\nGAME OVER!\n";
        }
        user_choice = menu.full_int_check(ask_to_play, 1,2);
    }
    return 0;

}