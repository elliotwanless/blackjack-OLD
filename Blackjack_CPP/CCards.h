//
//  CPlayerInfo.h
//  Blackjack_CPP
//
//  Created by Elliot Wanless on 09/10/2018.
//  Copyright © 2018 Elliot Wanless. All rights reserved.
//

#pragma once

using namespace std;

class Cards
{
protected:
    string temp;
    

public:
    int total = 0;
    string determine_face(int pcard);
    int generate_card_number();

};
