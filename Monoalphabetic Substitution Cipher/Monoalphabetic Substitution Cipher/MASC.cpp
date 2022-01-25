//
//  MASC.cpp
//  Monoalphabetic Substitution Cipher
//
//  Created by Gavin Forsberg on 10/21/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "MASC.hpp"
#include <random>
#include <array>
#include <iostream>
#include <iomanip>
using namespace std;

MASC cipher;

string MASC::key()
{   //Prompts user for user or cpu generated key
    char keySelection = ' ';
    cout << "Please Make a selection: \n(1) Type in a key \n(2) Have a key generated for you" << endl << endl;
    cin >> keySelection;
    cout << "\nChoice: " << keySelection << endl << endl;
    
    if(keySelection == '2')
    {
        //Random number engine
        random_device rng;
        const auto seed = rng.entropy() ? rng() : time(NULL);
        mt19937_64 rnd(seed);
        uniform_int_distribution<int>dist{65,90};
        
        //Shuffles the alphabet
        string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        shuffle(alpha.begin(), alpha.end(), rnd);
        
        cipher.keyword = alpha;
        
        //Displays key
        cout << "Key is: " << cipher.keyword;
        return cipher.keyword;
    }
    else if(keySelection == '1')
    {
        string input = " ";
        //Prompts user to input key
        cout << "Enter a key to be used for encryption and decryption. Include each letter of the alphabet, none repeated: " << endl;
        cin >> input;
       
        //checks if input is correct length
        while(input.length() != 26)
        {
            cin.clear(); cin.ignore(10000, '\n'); cout << endl;
            cerr << "Incorrect key length. Must be 26 characters." << endl << endl;
            cout << "Enter a key to be used for encryption and decryption. Include each letter of the alphabet, none repeated: " << endl;
            cin >> input;
        }
        
        //Checks for duplicate characters from the input
        bool duplicates = true;
        
        while(duplicates == true)
        {
            string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

            for(int i = 0; i < input.length(); ++i)
            {
                for(int j = i + 1; j < input.length(); ++j)
                {
                    if(input[i] == input[j])
                    {
                        duplicates = true;
                        break;
                    }
                    else
                        duplicates = false;
                }
            }
            
            if(duplicates == true)
            {
                cin.clear(); cin.ignore(10000, '\n'); cout << endl;
                cerr << "Error: letters in key must be used only once." << endl << endl;
                cout << "Enter a key to be used for encryption and decryption. Include each letter of the alphabet, none repeated: " << endl;
                cin >> input;
            }
        }
       
        cipher.keyword = input;
        //Displays key
        cout << "Key is: " << cipher.keyword;
        
    }
    return cipher.keyword;
}

string MASC::encrypt(string plaintext)
{
    cipher.spaceSelection = ' ';
    cout << "Please make a selection: \n(1) Preserve spacing from plaintext when creating ciphertext \n(2) Disguise original spacing" << endl << endl;
    cin >> cipher.spaceSelection;
    cout << "Choice: " << cipher.spaceSelection;
    
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ciphered = plaintext;
    
    if(cipher.spaceSelection == '1')
    {
        for(int i = 0; i < plaintext.length(); ++i)
        {
            for(int j = 0; j < alpha.length(); ++j)
            {
                if(toupper(plaintext[i]) == alpha[j])
                {
                    ciphered[i] = cipher.keyword[j];
                    break;
                }
            }
        }
        
        cout << "\nNow encrypting plaintext..." << endl;
        cout << "Ciphertext is: " << endl;
        return ciphered;
    }
    else if(cipher.spaceSelection == '2')
    {
        int spacing;
        cout << "\n\nHow many letters should appear in each grouping? \nPlease Enter for default spacing of 5." << endl;
        cin >> spacing;
        string ciphered = plaintext;

        if(cin.peek() == '\n')
        {
            for(int i = 0; i < plaintext.length(); ++i)
            {
                if(i == ' ')
                    continue;
                else
                    plaintext.append(" ", 5);
                break;
            }
            
            for(int i = 0; i < plaintext.length(); ++i)
            {
                for(int j = 0; j < alpha.length(); ++j)
                {
                    if(toupper(plaintext[i]) == alpha[j])
                    {
                        ciphered[i] = cipher.keyword[j];
                        break;
                    }
                }
            }
        }

        cin >> spacing;
        cout << "Spacing: " << spacing << endl << endl;


        cout << "\nNow encrypting plaintext..." << endl;
        cout << "Ciphertext is: " << endl;
    }
    return ciphered;

}

string MASC::decrypt(string ciphered)
{
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string plaintxt = ciphered;
    
    if(cipher.spaceSelection == '1')
    { //cout << cipher.keyword;
        for(int i = 0; i < ciphered.length(); ++i)
        {
            for(int j = 0; j < alpha.length(); ++j)
            {
                //debugging
                //cout << ciphered[i] << " " << i << " " << cipher.keyword[j] << endl;
//                cout << "\ntouppervalue: " << toupper(ciphered[i]) << endl;
//                cout << "\ncipher.keyword[j]: " << cipher.keyword[j] << endl;
                
                if(toupper(ciphered[i]) == cipher.keyword[j])
                {
                    plaintxt[i] = alpha[j];
                    break;
                }
            }
        }
        cout << "\nNow decrypting ciphertext. \nPlaintext is: ";
        
    }
   // else if(cipher.spaceSelection == '2')

    return plaintxt;
}
