//
//  Recursive Binomial.cpp
//  Recursive Binary Expansion
//
//  Created by Gavin Forsberg on 10/1/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include "Recursive Binomial.hpp"
#include <iostream>
using namespace std;

int main()
{
    char stop{' '};
         
      while(stop != 'q')
      {
          unsigned long long n;
          cout << "Let's compute binomial coefficients." <<
             "\nEnter a non-negative integer n: "<< endl;
          cin >> n;
          
          cout << "(x + y)^" << n << " = \n" << endl;
    
    
    
    
          for(int k = 0; k <= n; ++k)
          {
            cout << coefficient(n, k) << " * x^" << n-k << " * y^" << k;
            
            if( k != n)
                cout << " + ";
                   
          }
               
        cout << endl;

        cout << "\nPress 'q' to stop...\nPress anything else to continue... " << endl;
        cin >> stop;
    
        if(stop == 'Q' || stop == 'q')
               stop = 'q';
      }
}
