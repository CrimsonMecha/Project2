//
//  Season.cpp
//  SoccerSeasons
//
//  Created by Jacob Burritt, Peter Valentine, & Calen Bender on 12/2/17.
//  Copyright © 2017 Jacob Burritt, Peter Valentine, & Calen Bender. All rights reserved.
//

#include <stdio.h>
#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Season.h"

void Season::display(int year) {
    string seperator(50, '=');
    int user_choice;
    bool running = true;

    bool want_stats = false;
    while (running) {
        cout << year << endl;

        cout << seperator << endl;
        if (want_stats) {
            //display_stats();
        } else {
            //display_current_player();
        }
        cout << seperator << endl;
        cout << "[1]Start a new season [2]Add a player" << endl;
        cout << "[3]Look up a player   [4]Edit a player" << endl;
        cout << "[5]Delete a player    [6]Produce file" << endl;
        cout << "[7]Display statistics [8]Quit" << endl;
        cout << seperator << endl;
        cout << "Enter choice: ";
        cin >> user_choice;
        cin.get(); // '\n'

        if (user_choice < 1 || user_choice > 8) {
            cout << "Please enter a number (1-8)" << endl;
            display(year);
        } else {
            running = execute_choice(user_choice);
        }
    }
}

bool Season::execute_choice(int user_choice) {
    switch (user_choice) {
        case 1:
        {
            cout << "this is a test" << endl;
            //start_new_season(year);
            return true;
        }
        case 2:
        {
            //add_player(name, year_of_birth, registration_status);
            return true;
        }
        case 3:
        {
            cout << "Enter the name of the player you would like to edit: ";
            string name;
            getline(cin, name);
            //bool look_up_player(name);
            return true;
        }
        case 4:
        {
            cout << "Enter the name of the player you would like to edit: ";
            string name;
            getline(cin, name);
            //edit_player(name)
            return true;
        }
        case 5:
        {
            cout << "Enter the name of the player you would like to delete: ";
            string name;
            getline(cin, name);
            //delete_player(name);
            return true;
        }
        case 6:
        {
            cout << "Enter the category: ";
            string category;
            //produce_file();
            return true;
        }
        case 7:
        {
            //display_stats();
            return true;
        }
        case 8:
        {
            return false;
        }
    
    }
    return true;
}
