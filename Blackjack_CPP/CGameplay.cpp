#include <iostream>
#include "CGameplay.h"

using namespace std;

void Gameplay::welcome()
{
    cout << "---- WELCOME TO BLACKJACK ----\n\n";
    cout << "This a one player game that doesn't use real money! Perfect for children." << endl;
    cout << "\nAre you ready to play? Please press ENTER to continue...";
    getchar();
}

int Gameplay::chooseOption()
{
    cout << "\n\nWhat would you like to do?\n1: Hit   2. Double   3. Hold\nYour Option: ";
    cin >> option;
    cout << "\n";

    while ((option < 1) || (option > 3))
    {
        cout << "\nPlease enter a valid option: ";
        cin >> option;
    }
    cout << "\n-------------------------------" << endl;
    return option;
}
