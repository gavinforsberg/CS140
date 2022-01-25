//
//  Checking.cpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/18/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Checking.hpp"

void Checking::setOverdraftProtection(bool protection)
{
    overdraftProtection = protection;
}

void Checking::display() const
{
    Account::display();
    std::cout << "Overdraft Protetion: " << std::boolalpha << overdraftProtection << std::endl << std::endl;
}
