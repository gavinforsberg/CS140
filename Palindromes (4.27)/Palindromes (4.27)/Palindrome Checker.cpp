//
//  Palindrome Checker.cpp
//  Palindromes (4.27)
//
//  Created by Gavin Forsberg on 9/22/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int number, a, b, c, d, e;
    
    cout << "Enter a Five-Digit Number: ";
    cin >> number;
    
    if(to_string(number).length() != 5)
        cerr << "Input was NOT a Five-Digit Number." << endl;
    else
    {
        a = (number % 10);
        b = (number % 100) / 10;
        c = (number % 1000) / 1000;
        d = (number % 10000) / 1000;
        e = (number % 100000) / 10000;
        
        if(a == e && b == d)
            cout << number << " is a palindrome!" << endl;
        else
            cout << number << " is NOT a palindrome." << endl;
    }
    return 0;
}
