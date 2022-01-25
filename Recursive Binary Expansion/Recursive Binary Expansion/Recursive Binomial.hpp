//
//  Recursive Binomial.hpp
//  Recursive Binary Expansion
//
//  Created by Gavin Forsberg on 10/1/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Recursive_Binomial_hpp
#define Recursive_Binomial_hpp
#include <stdio.h>

unsigned long long coefficient(unsigned long long n, unsigned long long k)
{
    if(k == 0 || k == n)
        return 1;
    else
        return coefficient(n - 1, k - 1) + coefficient(n-1, k);
}

#endif /* Recursive_Binomial_hpp */
