//
//  Factorial.cpp
//  Factorial (5.13)
//
//  Created by Gavin Forsberg on 9/22/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    long factorial = 1;
    
    cout << "Int:" << "\t" << "Factorial:" << endl;
    for(int i = 1; i <= 20; ++i)
    {
        factorial *= i;
        cout << i << "\t\t" << factorial << endl;
    }
}
