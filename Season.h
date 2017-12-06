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
    void start_new_season();
    void add_player();
    bool look_up_player(const std::string & name);
    void edit_player(const std::string & name);
    void delete_player(const std::string & name);
    void produce_file();
    void display();
    bool execute_choice(int user_choice);
    void display_stats();
    
    int year() { return year_; }
private:
    PlayerMap player_map;
    PlayerMap::iterator current_player = player_map.begin();
    int year_;
    bool want_stats = false;
};

#endif /* Season_h */
