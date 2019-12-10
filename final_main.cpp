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
    Menu menu;
    bool victory = false;
    string first_message = "\n\n\nSomewhere in suburban America at 6AM.\n.`RING RING`. `RING RING`. <Hello?>, <Hi Honey! We got an early flight back from Europe and we'll be home in 20 MINUTES.\nSEE YOU SOON!\n";
    string second_message = "You look around. Last night was a RAGING PARTY BRUH. But you got 30 minutes to clean up these beer cans and get your\n friends out the door pronto amigo. GET TO WORK or you're TOTALLY BUSTED.\n\n";
    string ask_to_play = "Do you want to play 'Dont get busted!' ?\n1 - Play\n2 - Quit: ";
    string first_beat = "You've beat the first level. Play level 2?\n1 - Yes\n2 - Quit: ";
    int next_level_play = 0;
    cout << first_message;
    cout << second_message;
    int user_choice = menu.full_int_check(ask_to_play, 1,2);
    while(user_choice != 2)
    {
        GameController gc("level_1.txt");
        victory = gc.Run("level_1.txt");
        if(victory)
        {
            next_level_play = menu.full_int_check(first_beat, 1, 2);
            if(next_level_play == 1)
            {
                GameController gc2("level_2.txt");
                victory = gc2.Run("level_2.txt");
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
        else
        {
            cout << "\n\n\nYOU. ARE. TOTALLY. BUSTEDDDDDDDD!\nGrounded for the summer! oh no!\n\nGAME OVER!\n";
        }
        user_choice = menu.full_int_check(ask_to_play, 1,2);
    }
    return 0;

}