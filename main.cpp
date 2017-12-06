//
//  main.cpp
//  SoccerSeasons
//
//  Created by Jacob Burritt, Peter Valentine, & Calen Bender on 12/2/17.
//  Copyright © 2017 Jacob Burritt, Peter Valentine, & Calen Bender. All rights reserved.
//

#include <iostream>
using std::cout;
using std::cin;
#include "Player.h"
#include "Season.h"

int main() {
    
    Season s;
    s.start_new_season();
    s.display();
    
    return 0;
}

