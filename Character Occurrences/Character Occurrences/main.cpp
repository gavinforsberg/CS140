//
//  main.cpp
//  Character Occurrences
//
//  Created by Gavin Forsberg on 12/1/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
using namespace std;

int main()
{   //Test file
    ifstream inputFile("/Users/Gavin/Xcode/CS140/Homework/Character\ Occurrences/inputTest.txt", ios::in);
    
    //Tests test file input
    if(!inputFile)
    {
        cerr << "PROBLEM" << endl;
        return -1;
    }
        
    //maps for character, bigram, and trigram
    map<char, int> characterMap;
    map<string, int> bigramMap;
    map<string, int> trigramMap;
    
    char char1 = 0, char2 = 0, char3 = 0;
    
    //loop to continue until the end of input file
    for(int i = 0; !inputFile.eof(); ++i)
    {
        string bigramString = "", trigramString = "";
      
        //special cases for first and second characters
        if(i == 0)
        {
            //adds first character to char1
            inputFile >> char1;
            //initially sets character to lowercase
            char1 = tolower(char1);
            //adds char1 to the character map
            auto insertChar = characterMap.insert({char1, 1});
            if(!insertChar.second)
                characterMap[char1]++;
        }
        else if(i == 1)
        {
            char2 = char1;
            inputFile >> char1;
            char1 = tolower(char1);
            auto insertChar = characterMap.insert({char1, 1});
            if(!insertChar.second)
                characterMap[char1]++;
            
            //adds characters to bigram string
            bigramString.append(1, char2);
            bigramString.append(1, char1);
            
            //adds string to bigram map
            auto insertBi = bigramMap.insert({bigramString, 1});
            if(!insertBi.second)
                bigramMap[bigramString]++;
        }
        else if(i >= 2)
        {   //default case for the rest of input file characters
            char3 = char2;
            char2 = char1;
            inputFile >> char1;
            char1 = tolower(char1);
            
            auto insertChar = characterMap.insert({char1, 1});
            if(!insertChar.second)
                characterMap[char1]++;
            
            bigramString.append(1, char2);
            bigramString.append(1, char1);
            
            auto insertBi = bigramMap.insert({bigramString, 1});
            if(!insertBi.second)
                bigramMap[bigramString]++;
            
            //adds third character and the bigram string (for the other two characters) to trigram string
            trigramString.append(1, char3);
            trigramString += bigramString;
            
            //adds string to trigram map
            auto insertTri = trigramMap.insert({trigramString, 1});
            if(!insertTri.second)
                trigramMap[trigramString]++;
        }
    }
    
    //multimaps to sort the original maps
    multimap<int, char, greater<>> sortedCharMap;
    multimap<int, string, greater<>> sortedBiMap;
    multimap<int, string, greater<>> sortedTriMap;
    
    for(const auto& kv : characterMap)
        sortedCharMap.insert(make_pair(kv.second, kv.first));
    
    for(const auto& kv : bigramMap)
        sortedBiMap.insert(make_pair(kv.second, kv.first));
    
    for(const auto& kv : trigramMap)
        sortedTriMap.insert(make_pair(kv.second, kv.first));
    
    //iterators for the sorted maps
    auto charIt = sortedCharMap.begin();
    auto bigramIt = sortedBiMap.begin();
    auto trigramIt = sortedTriMap.begin();
    
    cout << "*** Top ten occurrences in the ciphertext and the English language ***";
    cout << "\nRanking:     1  2  3  4  5  6  7  8  9  10";
    cout << "\nCiphertext:  ";
    
    //prints the character, bigram, and trigram maps with the iterators for each
    for(int i = 0; i < 10; ++i)
    {
        cout << charIt->second << "  ";
        
        advance(charIt, 1);
    }

    cout << "\nEnglish:     e  t  a  o  i  n  s  h  r  d";
    cout << endl << endl;
    
    /*----------------------------------------------------------------------------*/
    
    cout << "*** Top ten occurrences in the ciphertext and the English language ***";
    cout << "\nRanking:     1   2   3   4   5   6   7   8   9   10";
    cout << "\nCiphertext:  ";
    
    for(int i = 0; i < 10; ++i)
    {
        cout << bigramIt->second << "  ";
        
        advance(bigramIt, 1);
    }
    
    cout << "\nEnglish:     th  he  in  er  an  re  nd  at  on  nt";
    cout << endl << endl;
    
    /*----------------------------------------------------------------------------*/
    
    cout << "*** Top ten occurrences in the ciphertext and the English language ***";
    cout << "\nRanking:     1    2    3    4    5    6    7    8    9    10";
    cout << "\nCiphertext:  ";
    
    for(int i = 0; i < 10; ++i)
    {
        cout << trigramIt->second << "  ";
        
        advance(trigramIt, 1);
    }
    
    cout << "\nEnglish:     the  and  tha  ent  ing  ion  tio  for  nde  has";
    cout << endl << endl;
}
