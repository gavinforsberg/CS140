//
//  Account.cpp
//  Part A (3.9-5.2)
//
//  Created by Gavin Forsberg on 9/21/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Account.hpp"
#include <iostream>
using namespace std;

int main()
{
    Account account1{"Jane Green", 50};
    Account account2{"John Blue", -7};
    
    cout << "\nAccount1: " << account1.getName() << " balance is $"
    << account1.getBalance();
    
    cout << "\nAccount2: " << account2.getName() << " balance is $"
    << account2.getBalance();
    
    cout << "\n\nEnter withdraw amount for account1: ";
    int withdrawAmount;
    cin >> withdrawAmount;
    cout << "Removing $" << withdrawAmount << " from account1 balance ";
    account1.withdraw(withdrawAmount);
    cout << "\nBalance: " << account1.getBalance();
    
    cout <<"\n\nEnter deposit amount for account1: ";
    int depositAmount;
    cin >> depositAmount;
    cout << "Adding " << depositAmount << " to account1 balance";
    account1.deposit(depositAmount);
    
    cout << "\n\naccount1: " << account1.getName() << " balance is $"
    << account1.getBalance();
    cout << "\naccount2: " << account2.getName() << "balance is $"
    << account2.getBalance() << endl;
    
    
}
