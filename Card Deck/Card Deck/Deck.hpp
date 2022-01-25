//
//  Deck.hpp
//  Card Deck
//
//  Created by Gavin Forsberg on 10/31/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Deck_hpp
#define Deck_hpp
#include "Card.hpp"
#include <stdio.h>

class Deck : public Card
{
    
public: 
    void addCard(Card myCard1);
    void removeCard();
    void print();
    void addAllCards();
    ~Deck();
    bool isEmpty();
    
private:
    Card* topCardPtr = nullptr;
    
};

#endif /* Deck_hpp */
