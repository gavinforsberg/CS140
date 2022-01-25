//
//  Pythagorean Triples.cpp
//  Pythagorean Triples (5.2)
//
//  Created by Gavin Forsberg on 9/22/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#include <iostream>
#include <string>

int main()
{
    int side1, side2, hypotenuse;
    
    for(side1 = 1; side1 < 500; ++side1)
    {
        for(side2 = side1; side2 < 500; ++side2)
        {
            for(hypotenuse = side2; hypotenuse < 500; ++hypotenuse)
            {
                if((side1 * side1) + (side2 * side2) == (hypotenuse * hypotenuse))
                   std::cout << side1 << " + " << side2 << " = " << hypotenuse << std::endl;
            }
        }
    }
}
