//
//  MASC.hpp
//  Monoalphabetic Substitution Cipher
//
//  Created by Gavin Forsberg on 10/21/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef MASC_hpp
#define MASC_hpp
#include <stdio.h>
#include <string>

class MASC
{
public:
    std::string key();
    std::string encrypt(std::string plaintext);
    std::string decrypt(std::string ciphered);
private:
    std::string keyword;
    char spaceSelection;
};

#endif /* MASC_hpp */
