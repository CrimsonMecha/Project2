//
//  Player.h
//  SoccerSeasons
//
//  Created by Jacob Burritt, Peter Valentine, & Calen Bender on 12/2/17.
//  Copyright © 2017 Jacob Burritt, Peter Valentine, & Calen Bender. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player{
    
public:
    Player() : name_("None"), yob_(0), category_("None"), registration_status_("None") {}
    Player(std::string n, int y, std::string c, std::string r) : name_(n), yob_(y), category_(c),
        registration_status_(r) {}
    
    std::string name() { return name_; }
    int yob() { return yob_; }
    std::string category() { return category_; }
    std::string registration_status() { return registration_status_; }
    
    void set_name(const std::string & name) { name_ = name; }
    void set_yob(int yob) { yob_ = yob; }
    void set_category(const std::string & category) { category_ = category; }
    void set_registration_status(const std::string & reg) { registration_status_ = reg; }
    
    void display();
    
private:
    std::string name_;
    int yob_;
    std::string category_;
    std::string registration_status_;
};

inline void Player::display(){
    std::cout << name_ << std::endl;
    std::cout << yob_ << std::endl;
    std::cout << category_ << std::endl;
    std::cout << registration_status_ << std::endl;
}

#endif /* EXECUTE_CHOICE_H */
