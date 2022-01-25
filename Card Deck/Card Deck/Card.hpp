//
//  Card Deck.hpp
//  Card Deck
//
//  Created by Gavin Forsberg on 10/31/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Card_Deck_hpp
#define Card_Deck_hpp
#include <stdio.h>
#include <string>

class Card
{
    friend class Deck;

public:
    Card(int s = 0, int r = 0);
    void setSuit(int s);
    void setRank(int r);
    int getSuit() const;
    int getRank() const;
    std::string rankedSuit(int rank, int suit);
    std::string suitString(int suit);
    std::string rankString(int rank);
    
private:
    int suit;
    int rank;
    Card* nextCard{nullptr};
    
};

#endif /* Card_Deck_hpp */
