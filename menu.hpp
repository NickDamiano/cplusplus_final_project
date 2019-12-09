/*********************************************************************************
author: Nicholas Damiano
filename: Menu.cpp
date: 29 Nov 19
description: Responsible for looping with messages for user and checking integers for input
*********************************************************************************/
#ifndef MENU_HPP
#define MENU_HPP

#include <string>

class Menu
{
    private: 
        std::string input_to_eval;
        int temp_int;
        bool in_range;
        std::string message;

    public: 
        Menu();
        bool check_int(std::string);
        bool check_double(std::string input_to_eval);
        bool check_int_range(int lower, int upper, int to_check);
        bool check_double_range(double lower, double upper, double to_check);
        int full_int_check(std::string message, int lower_limit, int upper_limit);
        double full_double_check(std::string message, double lower_limit, double upper_limit);
};

#endif