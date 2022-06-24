//
//  main.cpp
//  Blackjack_CPP
//
//  Created by Elliot Wanless on 03/11/2018.
//  Copyright © 2018 Elliot Wanless. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "CCards.h"
#include "CMoney.h"
#include "CGameplay.h"

using namespace std;

int option = 0;
float balance = 50.00;
float bet = 0;
vector<string> Player;
vector<string> Dealer;
int lost = 1;

//Check for a winner or loser
void checkWinLose(int &a, int &b, int &option)
{
    if (a > 21)
    {
        cout << "\n\nYou have lost!!!\n";
        lost = 0;
    }
    if (a == 21)
    {
        cout << "\n\nYou have won!!!\n";
        lost = 2;
    }
    if (b > 21)
    {
        cout << "\n\nYou have won!!!\n";
        lost = 2;
    }
    if (b == 21)
    {
        cout << "\n\nYou have lost!!!\n";
        lost = 0;
    }
    if (a == b)
    {
        cout << "\n\nIt's a draw!!!\n";
        lost = 2;
    }
    if ((b > a) && (option == 3))
    {
        cout << "\n\nYou have lost!!!\n";
        lost = 0;
    }
    if ((b < a) && (option == 3))
    {
        cout << "\n\nYou have won!!!\n";
        lost = 2;
    }
}

// draws a card for the player and adds to vector
void playerCard(Cards &PlayerCards, Cards &DealerCards)
{
    Player.push_back(PlayerCards.determine_face(PlayerCards.generate_card_number()));
}

// draws a card for the dealer and adds to vector
void dealerCard(Cards &PlayerCards, Cards &DealerCards)
{
    Dealer.push_back(DealerCards.determine_face(DealerCards.generate_card_number()));
}

void dealerTurn(Cards &PlayerCards, Cards &DealerCards)
{
    while (DealerCards.total < 18)    {    dealerCard(PlayerCards, DealerCards);   }
}

void playerTurn( int &option, Cards &PlayerCards, Cards &DealerCards, Gameplay &Gameplay)
{
    switch(option){
        case 1:
            playerCard(PlayerCards, DealerCards);
            cout << "\nYour cards = ";
            for(int i = 0; i<Player.size(); i++)    {   cout << Player[i] << "/";    }
            cout << "       Total = " << PlayerCards.total;
            checkWinLose(PlayerCards.total, DealerCards.total, option);
            break;
        case 2:
            //run DOUBLE
            break;
        case 3:
            //do NOTHING
            break;
    }
}


void dealCards(Cards &PlayerCards, Cards &DealerCards)
{
    Player.push_back(PlayerCards.determine_face(PlayerCards.generate_card_number()));
    Player.push_back(PlayerCards.determine_face(PlayerCards.generate_card_number()));
    cout << "\nYour cards = ";
    for(int i = 0; i<Player.size(); i++)    {   cout << Player[i] << "/";    }
    cout << "       Total = " << PlayerCards.total;
    checkWinLose(PlayerCards.total, DealerCards.total, option);
    
    Dealer.push_back(DealerCards.determine_face(DealerCards.generate_card_number()));
    Dealer.push_back(DealerCards.determine_face(DealerCards.generate_card_number()));
    cout << "\nDealer's cards = ";
    for(int i = 0; i<Dealer.size(); i++)    {   cout << Dealer[i] << "/";    }
    cout << "       Total = " << DealerCards.total;
    checkWinLose(PlayerCards.total, DealerCards.total, option);
}


int main(int argc, const char * argv[])
{
    Cards PlayerCards, DealerCards;
    Money Money;
    Gameplay Gameplay;
    srand(static_cast<unsigned int>(time(0)));
    
    // print welcome message and balance
    Gameplay.welcome();
    Money.print_balance(balance, bet);
    
    // set the bet and remove from balance
    bet = Money.setBet(balance);
    balance = balance - bet;
    Money.print_balance(balance, bet);
    
    // deal a card to the player and dealer
    dealCards(PlayerCards, DealerCards);
    
    //get the option of the first round
    option = Gameplay.chooseOption();
    
    //using their option, keep the player turns going
    while ((lost != 0) && (lost != 2) && (option == 1))
    {
        playerTurn(option, PlayerCards, DealerCards, Gameplay);
        if (lost == 1)  {   option = Gameplay.chooseOption();   }
    }
    
    if (lost == 1)
    {
    dealerTurn(PlayerCards, DealerCards);
        cout << "   \nDealer's cards = ";
        for(int i = 0; i<Dealer.size(); i++)    {   cout << Dealer[i] << "/";    }
        cout << "       Total = " << DealerCards.total;
        checkWinLose(PlayerCards.total, DealerCards.total, option);
    }
    
    return 0;
}
