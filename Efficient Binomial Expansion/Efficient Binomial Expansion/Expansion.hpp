//
//  Expansion.hpp
//  Efficient Binomial Expansion
//
//  Created by Gavin Forsberg on 11/2/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Expansion_hpp
#define Expansion_hpp
#include <vector>
#include <stdio.h>

class Expansion
{
public:
    std::vector<std::vector<unsigned long long>> pascalsTriangle(unsigned long long n);
    friend std::ostream& operator<<(std::ostream& os, const Expansion& ex);
};

#endif /* Expansion_hpp */
