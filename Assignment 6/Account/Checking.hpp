//
//  Checking.hpp
//  Assignment 6
//
//  Created by Gavin Forsberg on 11/18/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Checking_hpp
#define Checking_hpp
#include "Account.hpp"
#include <stdio.h>

class Checking : public Account
{
    
public:
    void setOverdraftProtection(bool protection);
    virtual void display() const override;
    
private:
    bool overdraftProtection = {false};;
    
};

#endif /* Checking_hpp */
