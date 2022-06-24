//
//  CPlayerInfo.h
//  Blackjack_CPP
//
//  Created by Elliot Wanless on 09/10/2018.
//  Copyright © 2018 Elliot Wanless. All rights reserved.
//

#pragma once

using namespace std;

class Money
{
protected:
    float temp;
public:
    void print_balance(float &balance, float &bet);
    float setBet(float &balance);
    
};
