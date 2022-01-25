//
//  Account.hpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/11/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Account_hpp
#define Account_hpp
#include <stdio.h>
#include "Date.hpp"
#include <string>

class Account
{
public:
    virtual void display() const;
    Account();
    void setFName(std::string fName);
    void setLName(std::string lName);
    void setDate(int mm, int dd, int yy);
    void setBalance(double bal);
    
protected:
    double balance;
    std::string firstName;
    std::string lastName;
    
    Date d;
    
    static unsigned int numAccounts;
    unsigned int accountNumber;
};


#endif /* Account_hpp */
