//
//  Account.cpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/11/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Account.hpp"
#include <iomanip>

unsigned int Account::numAccounts = {1};

//Default constructor
Account::Account()
{
    accountNumber = numAccounts;
    ++numAccounts;
}

//Setters
void Account::setFName(std::string fName)
{
    firstName = fName;
}

void Account::setLName(std::string lName)
{
    lastName = lName;
}

void Account::setDate(int mm, int dd, int yy)
{
    d.setDate(mm, dd, yy);
}

void Account::setBalance(double bal)
{
    balance = bal;
}

//General display function
void Account::display() const
{    
    std::cout << "Balance: " << std::fixed << std::setprecision(2) << balance << "\nAccount: " << accountNumber
        << "\nFirst Name: " << firstName << "\nLast Name: " << lastName << "\nOpened: " << d << std::endl;
}
