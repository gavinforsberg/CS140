//
//  Binomial Coefficients.hpp
//  Binomial Coefficients
//
//  Created by Gavin Forsberg on 9/20/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Binomial_Coefficients_hpp
#define Binomial_Coefficients_hpp

#include <stdio.h>
#include <iostream>

unsigned long long factorial(unsigned long long number)
{
    long long factorial = 1;
    
    if(number < 0)
        std::cerr << "Integer n must be positive." << std::endl;
    
    for(int i = 1; i <= number; ++i)
        factorial *= i;
    
    return factorial;
}

unsigned long long coefficient(unsigned long long n, unsigned long long k)
{
    unsigned long long coefficient = 0;
    
    coefficient = {((factorial(n) / ((factorial(k)) * (factorial(n - k)))))};
    
    return coefficient;
}

#endif /* Binomial_Coefficients_hpp */
