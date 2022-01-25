//
//  main.cpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/11/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Account.hpp"
#include "Checking.hpp"
#include "Savings.hpp"
#include <iostream>
#include <vector>
#include <random>
#include <ctime> 
using namespace std;

//Global enum class, vector of account pointers
enum class AccountType {Checking = 1, Savings};
AccountType type;
vector<Account*> ptrVec;

//Prototype
void createAccounts(AccountType type, const vector<string>& fName, const vector<string>& lName);

int main()
{
    //Vectors of first and last names
    vector<string> fNames = {"Austin", "Bill", "Alison", "Blake", "Carol", "Bryce", "Dana", "Hannah", "Jay", "Melissa"};
    vector<string> lNames = {"Smith", "Johnson", "Williams", "Jones", "Jones", "Brown", "Davis", "Miller", "Wilson", "Moore"};
    
    int selection = {0};
    int userAmount = {0};
    
    //while the user doesn't want to quit
    while(selection != 3)
    {   //Takes user selection for creating savings/checking accounts
        cout << "MENU: \n1. Create Checking Accounts \n2. Create Savings Accounts \n3. Quit \n\n";
        cout << "Selection: ";
        cin.clear();
        cin >> selection;
        cout << "Choice " << selection;
        
        //Taking in how many accounts to create
        if(selection == 1)
        {
            type = AccountType::Checking;
            
            cout << "\n\nHow many accounts would you like to create? " ;
            cin.clear();
            cin >> userAmount;
        }
        else if(selection == 2)
        {
            type = AccountType::Savings;
            
            cout << "\n\nHow many accounts would you like to create? " ;
            cin.clear();
            cin >> userAmount;
        }
        else //if user inputs 3, quits
        {
            cout << "\nGoodbye\n";
        }
        
        if(selection != 3)  //if user didn't quit, creates accounts desired and displays
        {
            for(; userAmount > 0; --userAmount)
            {
                createAccounts(type, fNames, lNames);
            }
            
            cout << "\nDisplaying all accounts: ";
            for(Account* accPtr : ptrVec)
            {
                accPtr->display();
            }
        }
    }
}
                    
void createAccounts(AccountType type, const vector<string>& fName, const vector<string>& lName)
{   //random number engine with distributions for each random variable
    random_device rnd;
    const auto seed = rnd.entropy() ? rnd() : time(nullptr);
    mt19937_64 eng(static_cast<mt19937::result_type>(seed));
    
    normal_distribution<double> balanceDist{1000.0, 3.0};
    normal_distribution<double> interestDist{5.0, 1.0};
    uniform_int_distribution<int> randomNames{0, 9};
    uniform_int_distribution<int> randomMonth{1, 12};
    uniform_int_distribution<int> randomDay {1, 28};
    uniform_int_distribution<int> randomYear {1980, 2019};
    uniform_int_distribution<int> oneOrZero {1, 0};
    
    //switch depending on what the user chose
    switch(type)
    {
        case AccountType::Checking:
        {
            //new account ptr storing on the heap, fills with random values
            Account* checkingPtr = new Checking;
            checkingPtr->setDate(randomMonth(eng), randomDay(eng), randomYear(eng));
            checkingPtr->setBalance(balanceDist(eng));
            checkingPtr->setFName(fName[randomNames(eng)]);
            checkingPtr->setLName(lName[randomNames(eng)]);
            
            //Downcast pointer
            Checking* newCheckingPtr = dynamic_cast<Checking*>(checkingPtr);
            newCheckingPtr->setOverdraftProtection(oneOrZero(eng));
            
            ptrVec.push_back(newCheckingPtr);
        }   break;
        case AccountType::Savings:
        {   //does the same as above, with savings account instead
            Account* savingsPtr = new Savings;
            savingsPtr->setDate(randomMonth(eng), randomDay(eng), randomYear(eng));
            savingsPtr->setBalance(balanceDist(eng));
            savingsPtr->setFName(fName[randomNames(eng)]);
            savingsPtr->setLName(lName[randomNames(eng)]);
            
            Savings* newSavingsPtr = dynamic_cast<Savings*>(savingsPtr);
            newSavingsPtr->setInterestRate(interestDist(eng));
            
            ptrVec.push_back(newSavingsPtr);
        }   break;
        default:
            break;
    }
}
