//
//  Scrambler.hpp
//  Scrambler
//
//  Created by Gavin Forsberg on 10/1/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Scrambler_hpp
#define Scrambler_hpp
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>

class scrambled
{
public:
    void switcher(std::string myStr)
    {
        std::random_device rnd;
        const auto seed = rnd.entropy() ? rnd() : time(nullptr);
        std::mt19937_64 rng(static_cast<std::mt19937_64::result_type>(seed));
        std::uniform_int_distribution<int> dist{1, 9};

        while(std::cin >> myStr)
        {
            shuffle(myStr.begin(), myStr.end(), rnd);
            std::cout << myStr << ' ' ;
        }
        std::cout << std::endl << std::endl;
    }
};

#endif /* Scrambler_hpp */
