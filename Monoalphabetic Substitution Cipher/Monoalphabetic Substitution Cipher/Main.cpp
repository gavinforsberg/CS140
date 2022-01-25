//
//  Main.cpp
//  Monoalphabetic Substitution Cipher
//
//  Created by Gavin Forsberg on 10/22/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <stdio.h>
#include "MASC.hpp"
#include <iostream>
using namespace std;

int main()
{
    cout << "Testing Monoalphabetic Substitution Cipher (MASC) Program: " << endl << endl;
       
    MASC cipher;
    cipher.key();
    
    cin.clear(); cin.ignore(10000, '\n'); cout << endl;
    string plaintext = " ";
    cout << "\nEnter the plaintext: " << endl;
    getline(cin, plaintext);
    
    string ciphered = cipher.encrypt(plaintext);
    
    cout << ciphered << endl << endl;
    cout << cipher.decrypt(ciphered);
    
    cout << endl << endl;
}
