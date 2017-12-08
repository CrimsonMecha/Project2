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
#include <fstream>
using std::ofstream;
using std::ifstream;

#include "Season.h"

void Season::display() {
    string seperator(50, '=');
    int user_choice;
    bool running = true;

    while (running) {
        cout << year_ << endl;

        cout << seperator << endl;
        if (want_stats) {
            display_stats();
        } else {
            current_player->second.display();
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
            display();
        } else {
            running = execute_choice(user_choice);
        }
    }
}

void Season::start_new_season()
{
    
    char confirmation;
    
    bool is_int = false;
    while(!is_int){
        cout << "Enter the year: ";
        cin >> year_;
        if(!cin){
            cout<<"Please enter an integer" << endl;
            cin.clear();
            cin.ignore(256,'\n');
        } else {
            is_int = true;
        }
    }
    
    cout << "Are you sure you want to delete the " << year_ << " season? (y/n)";
    cin >> confirmation;
    if(confirmation == 'y'){
        PlayerMap new_map;
        player_map = new_map;
    }
    
}

void Season::add_player()
{
    string name, category, registration_status;
    int yob;
    
    cout << "Enter name: ";
    getline(cin, name);
    cout << "year of birth: ";
    cin >> yob;
    cout << "registration_status (paid / unpaid): ";
    cin >> registration_status;
    
    int age = year_ - yob;
    if(age < 4) {
        cout << "Player is too young to participate." << endl;
    } else if(age >= 4 && age < 6){
        category = "U6";
    } else if(age >=6 && age < 8){
        category = "U8";
    } else if (age >= 8 && age < 10){
        category = "U10";
    } else if(age >= 10 && age < 12){
        category = "U12";
    } else if (age >= 12 && age < 14){
        category = "U14";
    } else if(age >=14 && age <= 16){
        category = "U17";
    } else {
        cout << "Player is too old to participate." << endl;
    }
    Player new_player(name,yob,category,registration_status);
    player_map.insert(std::pair<std::string,Player>(name,new_player));
    
    look_up_player(name);
}

bool Season::look_up_player(const string & name){
    
    auto previous_location = current_player;
    current_player = player_map.find(name);
    if(current_player==player_map.end()){
        cout << "Player was not found." << endl;
        current_player = previous_location;
        return false;
    } else {
        return true;
    }
}

void Season::delete_player(const string & name)
{
    bool found;

    found = look_up_player(name);
    if(found == true){
        char confirmation;
        cout << "Are you sure you want to delete this player? [y/n] :  ";
        cin >> confirmation;
        if(confirmation == 'y'){
            player_map.erase(name);
        } else {
            return;
        }
        
    }
    
}

bool Season::execute_choice(int user_choice) {
    switch (user_choice) {
        case 1:
        {
            start_new_season();
            return true;
        }
        case 2:
        {
            add_player();
            return true;
        }
        case 3:
        {
            cout << "Enter the name of the player you would like to edit: ";
            string name;
            getline(cin, name);
            look_up_player(name);
            return true;
        }
        case 4:
        {
            cout << "Enter the name of the player you would like to edit: ";
            string name;
            getline(cin, name);
            edit_player(name);
            return true;
        }
        case 5:
        {
            cout << "Enter the name of the player you would like to delete: ";
            string name;
            getline(cin, name);
            delete_player(name);
            return true;
        }
        case 6:
        {
            produce_file();
            return true;
        }
        case 7:
        {
            want_stats=true;
            return true;
        }
        case 8:
        {
            return false;
        }
    
    }
    return true;
}

void Season::produce_file()
{
    string file_category;
    cout << "Enter the category (Ux or all) : ";
    getline(cin,file_category);
    
    string file_name = file_category + "-" +  std::to_string(year()) + ".txt";
    
    ofstream out;
    out.open(file_name);
    if(!out){
        cout << "Could not open file.\n";
        return;
    }
    
    if(file_category == "all"){
        for(auto itr = player_map.begin(); itr != player_map.end(); ++itr){
            out << itr->second.name() << endl;
            out << itr->second.yob() << endl;
            out << itr->second.category() << endl;
            out << itr->second.registration_status() << endl << endl;
        }
    } else if (file_category == "U6" || file_category == "U8" ||
               file_category == "U10" || file_category == "U12" ||
               file_category == "U14" || file_category == "U17") {
        
        PlayerMap temp;
        
        for (auto itr = player_map.begin(); itr != player_map.end(); itr++) {
            if (itr->second.category()==file_category) {
                temp.insert(*itr);
            }
        }
        
        for(auto itr = temp.begin(); itr != temp.end(); ++itr){
            out << itr->second.name() << endl;
            out << itr->second.yob() << endl;
            out << itr->second.category() << endl;
            out << itr->second.registration_status() << endl << endl;
        }
        
    } else {
        cout << "Invalid entry, please enter a valid category" << endl;
    }
}

void Season::edit_player(const string & name){
    
    cout << "What would you like to edit [1]name, [2]year of birth, [3] registration status: ";
    int user_choice;
    cin >> user_choice;
    if (user_choice == 1)
    {
        cout << "What would you like to change the name to: ";
        string new_name;
        getline(cin,new_name);
        //current_player->first = new_name;
        
        string new_reg_statsu = current_player->second.registration_status(); //animu ftw
        string new_cat = current_player->second.category();
        int new_yob = current_player->second.yob();
        Player new_player(new_name, new_yob, new_cat, new_reg_statsu);
        player_map.erase(current_player);
        player_map.insert(std::pair<string,Player>(new_name,new_player));
        
        current_player->second.set_name(new_name);
    }
    else if (user_choice == 2)
    {
        cout << "What is the new year of birth? ";
        int new_yob;
        cin >> new_yob;
        
        int age = year_ - new_yob;
        string category;
        if(age < 4) {
            cout << "Player is too young to participate." << endl;
            return;
        } else if(age >= 4 && age < 6){
            category = "U6";
        } else if(age >=6 && age < 8){
            category = "U8";
        } else if (age >= 8 && age < 10){
            category = "U10";
        } else if(age >= 10 && age < 12){
            category = "U12";
        } else if (age >= 12 && age < 14){
            category = "U14";
        } else if(age >=14 && age <= 16){
            category = "U17";
        } else {
            cout << "Player is too old to participate." << endl;
            return;
        }
        
        current_player->second.set_yob(new_yob);
        current_player->second.set_category(category);
    }
    else if (user_choice == 3)
    {
        cout << "What would you like to change the registration status to: ";
        string new_reg_status;
        getline(cin, new_reg_status);
        if(new_reg_status == "paid" || new_reg_status == "unpaid"){
            current_player->second.set_registration_status(new_reg_status);
        }
        else{
            cout << "invalid registration status" << endl;
        }
    }
    
}

void Season::display_stats()
{
    int num_players = 0, u6_num = 0, u8_num = 0, u10_num = 0, u12_num = 0, u14_num = 0, u17_num = 0;
    int total_paid = 0, u6_paid = 0, u8_paid = 0, u10_paid = 0, u12_paid = 0, u14_paid = 0, u17_paid = 0;
    int total_unpaid = 0, u6_unpaid = 0, u8_unpaid = 0, u10_unpaid = 0, u12_unpaid = 0, u14_unpaid = 0, u17_unpaid = 0;
    
    for(auto itr = player_map.begin(); itr != player_map.end(); ++itr){
        
        num_players+=1;
        
        if(itr->second.category()=="U6"){
            u6_num+=1;
            if(itr->second.registration_status()=="paid"){
                u6_paid+=1;
                total_paid+=1;
            } else {
                u6_unpaid+=1;
                total_unpaid+=1;
            }
        }
        
        if(itr->second.category()=="U8"){
            u8_num+=1;
            if(itr->second.registration_status()=="paid"){
                u8_paid+=1;
                total_paid+=1;
            } else {
                u8_unpaid+=1;
                total_unpaid+=1;
            }
        }
        
        if(itr->second.category()=="U10"){
            u10_num+=1;
            if(itr->second.registration_status()=="paid"){
                u10_paid+=1;
                total_paid+=1;
            } else {
                u10_unpaid+=1;
                total_unpaid+=1;
            }
        }
        
        if(itr->second.category()=="U12"){
            u12_num+=1;
            if(itr->second.registration_status()=="paid"){
                u12_paid+=1;
                total_paid+=1;
            } else {
                u12_unpaid+=1;
                total_unpaid+=1;
            }
        }
        
        if(itr->second.category()=="U14"){
            u14_num+=1;
            if(itr->second.registration_status()=="paid"){
                u14_paid+=1;
                total_paid+=1;
            } else {
                u14_unpaid+=1;
                total_unpaid+=1;
            }
        }
        
        if(itr->second.category()=="U17"){
            u6_num+=1;
            if(itr->second.registration_status()=="paid"){
                u17_paid+=1;
                total_paid+=1;
            } else {
                u17_unpaid+=1;
                total_unpaid+=1;
            }
        }
        
    }
    
    cout << "Total Players: " << num_players << " U6: " << u6_num << " U8: " << u8_num
    << " U10: " << u10_num << " U12: " << u12_num << " U14: " << u14_num
    << " U17: " << u17_num << endl;
    cout << "Total Paid: " << total_paid << " U6: " << u6_paid << " U8: " << u8_paid
    << " U10: " << u10_paid << " U12: " << u12_paid << " U14: " << u14_paid
    << " U17: " << u17_paid << endl;
    cout << "Total Unpaid: " << total_unpaid << " U6: " << u6_unpaid << " U8: " << u8_unpaid
    << " U10: " << u10_unpaid << " U12: " << u12_unpaid << " U14: " << u14_unpaid
    << " U17: " << u17_unpaid << endl;
    
}
