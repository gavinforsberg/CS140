//
//  Deck.cpp
//  Card Deck
//
//  Created by Gavin Forsberg on 10/31/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Deck.hpp"
#include <iostream>
using namespace std;

void Deck::addCard(Card myCard1)
{
    Card* temp = new Card(myCard1);
    
    if(isEmpty())
        topCardPtr = temp;
    else
    {
        temp->nextCard = topCardPtr;
        topCardPtr = temp;
    }
    
    cout << "adding: " << topCardPtr->rankedSuit(topCardPtr->getRank(), topCardPtr->getSuit()) << endl;
}

void Deck::removeCard()
{
    if(isEmpty())
        return;
    else
    {
        cout << "removing: ";
        cout << topCardPtr->rankedSuit(topCardPtr->getRank(), topCardPtr->getSuit()) << endl;
        Card* temp = topCardPtr;
        topCardPtr = topCardPtr->nextCard;
        delete temp;
    }
}

Deck::~Deck()
{
    while(topCardPtr != nullptr)
    {
        removeCard();
    }
}

void Deck::addAllCards()
{
    for(int i = 1; i <= 4; ++i)
    {
        for(int j = 1; j <= 13; ++j)
        {
            Card myCard(i, j);
            addCard(myCard);
        }
    }
}

bool Deck::isEmpty()
{
    return topCardPtr == nullptr;
}

void Deck::print()
{
    if(isEmpty())
        cout << "Empty Deck" << endl << endl;
    else
    {
        cout << "\nDeck: " << endl;
        
        Card* currentPtr = topCardPtr;
        
        while(currentPtr != nullptr)
        {
            cout << currentPtr->rankedSuit(currentPtr->getRank(), currentPtr->getSuit()) << endl;
            
            currentPtr = currentPtr->nextCard;
        }
        
        cout << endl;
        
    }
}
