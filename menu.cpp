/*********************************************************************************
author: Nicholas Damiano
filename: Menu.cpp
date: 29 Nov 19
description: Responsible for looping with messages for user and checking integers for input
*********************************************************************************/
#include <stdio.h>
#include <ctype.h>
#include <cstring>
#include <string>
#include <iostream>
#include "menu.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::strcpy;

Menu::Menu()
{

}
// takes a string that is user input supposedly an integer and checks it for an integer using cstring parsing.
// returns true if it is an integer input and false otherwise
bool Menu::check_int(string input_to_eval)
{
    char input_char[input_to_eval.size() + 1];
    strcpy(input_char, input_to_eval.c_str());
  
    int alphabet = 0, number = 0, other = 0, possible_neg = 0, i; 
    for (i=0; input_char[i]!= '\0'; i++) 
    { 
        // check for alphabets 
        if (isalpha(input_char[i]) != 0) 
            alphabet++; 
        // check for decimal digits 
        else if (isdigit(input_char[i]) != 0) 
            number++; 
        else if (i == 0 && input_char[i] == '-')
            possible_neg++;
        else
            other++;
    } 
    // If there only numbers in the c string return true
    if(number > 0 && alphabet == 0 && other == 0)
    {
        return true;
    }
    return false;
}

// Takes a string, if it has only numbers and 1 or less period, returns true
// because that means it is a double.
bool Menu::check_double(string input_to_eval)
{

    char input_char[input_to_eval.size() + 1];
    strcpy(input_char, input_to_eval.c_str());
  
    int alphabet = 0, number = 0, other = 0, i, period = 0;
    for (i=0; input_char[i]!= '\0'; i++) 
    { 
        // check for alphabets 
        if (isalpha(input_char[i]) != 0) 
            alphabet++; 
  
        // check for decimal digits 
        else if (isdigit(input_char[i]) != 0) 
            number++; 
        else if(input_char[i] == '.')
            period++;
        else
            other++;
            
    } 
    // If there only numbers in the c string return true
    if(number > 0 && alphabet == 0 && other == 0 && period <= 1)
    {
        return true;
    }
    return false;
}

// checks that the number to_check is within the lower and upper limits. returns false if not and true if it is
// within the limits
bool Menu::check_int_range(int lower, int upper, int to_check)
{
    if(to_check > upper || to_check < lower)
    {
        return false;
    }
    return true;
}

// checks that the number to_check is within the lower and upper limits. returns false if not and true if it is
// within the limits
bool Menu::check_double_range(double lower, double upper, double to_check)
{
    if(to_check > upper || to_check < lower)
    {
        return false;
    }
    return true;
}

// combines the above methods with a loop displaying the message to get input from the user passed in,
// seeing if, first, the input is an integer, and second, if it is within range. if so, return that as 
// a converted integer. If not, continue to ask. 
int Menu::full_int_check(string message, int lower_limit, int upper_limit )
{
    bool bad_input = true;

    cout << message;
    getline(cin,input_to_eval);

    // if the input is an integer
    while(bad_input){
        bool is_integer = check_int(input_to_eval);
        if(is_integer)
        {
            // conver the string version of the int to an actual int
            temp_int = std::stoi( input_to_eval );
            // check the range
            in_range = check_int_range(lower_limit, upper_limit, temp_int);
            if(in_range)
            {
                bad_input = false;
                return temp_int;
            }else
            {
                cout << message;
                getline(cin,input_to_eval);
            }
        }else
        {
            cout << message;
            getline(cin,input_to_eval);
            
        }
    }
}
// Takes a string message to output to the user until they enter a valid double, a lower limit
// for doubles and an upper limit for doubles to check range.
double Menu::full_double_check(string message, double lower_limit, double upper_limit )
{
    // Set bad_input flag and clear it when verified good double entered.
    bool bad_input = true;

    cout << message;
    getline(cin,input_to_eval);

    // if the input is an double
    while(bad_input){
        bool is_double = check_double(input_to_eval);
        if(is_double)
        {
            // conver the string version of the double to an actual double
            double temp_double = std::stod( input_to_eval );
            // check the range
            in_range = check_double_range(lower_limit, upper_limit, temp_double);
            if(in_range)
            {
                bad_input = false;
                return temp_double;
            }else
            {
                cout << message;
                getline(cin,input_to_eval);
            }
        }else
        {
            cout << message;
            getline(cin,input_to_eval);
            
        }
    }
}
