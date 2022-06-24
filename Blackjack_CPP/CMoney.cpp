#include <iostream>
#include "CMoney.h"

using namespace std;

void Money::print_balance(float &balance, float &bet)
{
    cout << "\n-------------------------------" << endl;
    cout << "\nYour balance: £" << balance << "          Current bet: £" << bet << endl;
}

float Money::setBet(float &balance)
{
    cout << "\nPlease place your bet (MIN. bet = £2.00)" << endl;
    cout << "Your bet: £";
    cin >> temp;
    
    while ((temp < 2) || (temp > 50))
    {
        cout << "Please enter a valid bet: £";
        cin >> temp;
    }
    
    return temp;
}
