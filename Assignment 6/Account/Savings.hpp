//
//  Savings.hpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/18/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Savings_hpp
#define Savings_hpp
#include "Account.hpp"
#include <stdio.h>

class Savings : public Account
{
    
public:
    void setInterestRate(double interest);
    void display() const override;
    
private:
    double interestRate = {0};
    
};

#endif /* Savings_hpp */
