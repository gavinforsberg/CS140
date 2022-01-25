//
//  main.cpp
//  Card Deck
//
//  Created by Gavin Forsberg on 10/31/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <iostream>
#include <string>
#include "Card.hpp"
#include "Deck.hpp"
using namespace std;

int main()
{
    Card myCard1{ 2, 4 };
    Card myCard2{ 4, 5 };
    
    {
        Deck myDeck;

        myDeck.addCard(myCard1);
        myDeck.addCard(myCard2);

        cout << endl << "Printing deck..." << endl;
        myDeck.print();

        myDeck.removeCard();
        myDeck.removeCard();

        cout << endl << "Printing deck..." << endl;
        myDeck.print();

        cout << "Adding all cards..." << endl << endl;
        myDeck.addAllCards();

        cout << endl << "Printing deck..." << endl;
        myDeck.print();
    }
}
