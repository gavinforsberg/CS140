//
//  Euclidean Algorithm.cpp
//  Euclidean Algorithm
//
//  Created by Gavin Forsberg on 9/10/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    char stop{' '};
    
    while(stop != 'q')
    {
        int a, b;

        cout << "Enter two positive integers: ";
        cin >> a >> b;
        
        int u = 1, g = a, x = 0, y = b, q = 0, t = 0, s = 0, v = 0;
        
        if(a <= 0 || b <= 0)
        {
            cout << "Error: Required two positive integers" << endl;
        }
        else
        {
            while(y != 0)
            {
                q = g / y;
                t = g % y;
                s = u - q * x;
                u = x;
                g = y;
                x = s;
                y = t;
                v = (g - a * u) / b;
            }
          
            cout << "\nThe greatest common divisor of " << a << " and " << b << " is " << g << endl;
            cout << "As an equation: \n"
                            << a << " * " << u << " + " << b << " * " << v << " = " << g << endl;
        }
        
        cout << "\nPress 'q' to stop...\nPress anything else to continue... " << endl;
        cin >> stop;
        
        if(stop == 'Q' || stop == 'q')
            stop = 'q';
    }
        return 0;
}
