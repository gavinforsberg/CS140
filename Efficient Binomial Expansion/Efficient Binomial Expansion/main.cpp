//
//  main.cpp
//  Efficient Binomial Expansion
//
//  Created by Gavin Forsberg on 11/2/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Expansion.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

std::ostream& operator<<(std::ostream& os, const vector<vector<unsigned long long>>& ex);

int main()
{
    Expansion ex;
    unsigned long long n;
    
    cout << "Let's compute binomial coefficients." <<
       "\nEnter a non-negative integer n: "<< endl;
    cin >> n;
    
    cout << "(x + y)^" << n << " = \n" << endl;
    
    vector<vector<unsigned long long>> triangle(ex.pascalsTriangle(n));
    
    int k = 0;
    for(auto i : triangle[n])
    {
        cout << i << " * x^" << n-k << " * y^" << k;

        if( k != i)
            cout << " + ";
        
        ++k;
    }
    
    cout << "\n\nPascal's Triangle: " << endl << endl << triangle;
}
