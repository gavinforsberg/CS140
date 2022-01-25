//
//  Savings.cpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/18/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Savings.hpp"
#include <iomanip>

void Savings::setInterestRate(double interest)
{
    interestRate = interest;
}

void Savings::display() const
{
    Account::display();
    std::cout << "Interest Rate: " << std::fixed << std::setprecision(2) << interestRate << std::endl << std::endl;
}
