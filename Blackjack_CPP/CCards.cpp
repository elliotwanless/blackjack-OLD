#include <iostream>
#include "CCards.h"

using namespace std;

string Cards::determine_face(int pcard)
{
    
    switch (pcard){
        case 13:
            temp = "KING";
            total = total + 10;
            break;
        case 12:
            temp = "QUEEN";
            total = total + 10;
            break;
        case 11:
            temp = "JACK";
            total = total + 10;
            break;
        case 10:
            temp = "10";
            total = total + pcard;
            break;
        case 9:
            temp = "9";
            total = total + pcard;
            break;
        case 8:
            temp = "8";
            total = total + pcard;
            break;
        case 7:
            temp = "7";
            total = total + pcard;
            break;
        case 6:
            temp = "6";
            total = total + pcard;
            break;
        case 5:
            temp = "5";
            total = total + pcard;
            break;
        case 4:
            temp = "4";
            total = total + pcard;
            break;
        case 3:
            temp = "3";
            total = total + pcard;
            break;
        case 2:
            temp = "2";
            total = total + pcard;
            break;
        case 1:
            temp = "ACE";
            total = total + 11;
            break;
    }
    
    return temp;
}

int Cards::generate_card_number()
{
    return rand() % 12 + 1;
}
