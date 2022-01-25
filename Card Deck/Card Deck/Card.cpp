//
//  Card Deck.cpp
//  Card Deck
//
//  Created by Gavin Forsberg on 10/31/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Card.hpp"
#include <iostream>
using namespace std;

Card::Card(int s, int r)
{
    suit = s;
    rank = r;
}

void Card::setSuit(int s)
{   suit = s;   }

void Card::setRank(int r)
{   rank = r;   }

int Card::getSuit() const
{   return suit;    }

int Card::getRank() const
{   return rank;    }

string Card::suitString(int suit)
{
    switch(suit)
    {
        case 1:
            return "hearts";
        case 2:
            return "diamonds";
        case 3:
            return "clubs";
        case 4:
            return "spades";
        default:
            return "error";
    }
}

string Card::rankString(int rank)
{
    switch(rank)
    {
        case 1:
            return "ace";
        case 2:
            return "2";
        case 3:
            return "3";
        case 4:
            return "4";
        case 5:
            return "5";
        case 6:
            return "6";
        case 7:
            return "7";
        case 8:
            return "8";
        case 9:
            return "9";
        case 10:
            return "10";
        case 11:
            return "jack";
        case 12:
            return "queen";
        case 13:
            return "king";
        default:
            return "error";
    }
}

string Card::rankedSuit(int rank, int suit)
{   return rankString(rank) + " of " + suitString(suit);  }
