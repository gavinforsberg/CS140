//
//  Account.hpp
//  Part A (3.9-5.2)
//
//  Created by Gavin Forsberg on 9/21/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

//Taken from Fig. 3.8 [Deitel]
#include <stdio.h>
#include <iostream>
using namespace std;

class Account
{   public:
    
    Account(string accountName, int initialBalance)
    :name{accountName}
    {
        if(initialBalance > 0)
            balance = initialBalance;
            
        if(initialBalance < 0)
            cout << "initialBalance cannot be negative." << endl;
    }
    
    void deposit(int depositAmount)
    {
        if(depositAmount > 0)
            balance += depositAmount;
    }
    
    int getBalance() const { return balance; }
    string getName() const { return name; }
    
    void setName(string accountName)
    {
        name = accountName;
    }
    
    //My withdrawal method
    void withdraw(int withdrawAmount)
    {
        if(balance > withdrawAmount)
            balance -= withdrawAmount;
        
        if(balance < withdrawAmount)
            cout << "Withdrawal amount exceeded account balance." << endl;
    }
    
private:
    string name;
    int balance{0};
};
