//
//  ExecuteHeader.cpp
//  SoccerSeasons
//
//  Created by Jacob Burritt, Peter Valentine, & Calen Bender on 12/2/17.
//  Copyright © 2017 Jacob Burritt, Peter Valentine, & Calen Bender. All rights reserved.
//

#ifndef Season_h
#define Season_h

#include <map>
#include <string>

#include "Player.h"

typedef std::map<std::string, Player> PlayerMap;

class Season{
  
public:
    void start_new_season(int year);
    void add_player(std::string name, int yob, std::string registration_status);
    bool look_up_player(std::string name);
    void edit_player(std::string name);
    void delete_player(std::string name);
    void produce_file(std::string category);
    void display(int year);
    bool execute_choice(int user_choice);
private:
    PlayerMap player_map;
    PlayerMap::iterator current_player = player_map.begin();
    
};

#endif /* Season_h */
