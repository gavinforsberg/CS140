//
//  Expansion.cpp
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

vector<vector<unsigned long long>> Expansion::pascalsTriangle(unsigned long long n)
{
    vector<vector<unsigned long long>> coefficients;
    vector<unsigned long long> rows;
    
    for(int k = 0; k <= n; ++k)
    {
        for(int j = 0; j <= k; ++j)
        {
            if(k == j || j == 0)
                rows.push_back(1);
            else
                rows.push_back(coefficients[k - 1][j - 1] + coefficients[k - 1][j]);
        }
        
        coefficients.push_back(rows);
        rows.clear();
    }
    return coefficients;
}

std::ostream& operator<<(std::ostream& os, const vector<vector<unsigned long long>>& ex)
{
    for(auto i: ex)
    {
        for(unsigned long long j : i)
        {
            os << setw(5) << j << " ";
        }
        os << endl;
    }
    return os;
}
