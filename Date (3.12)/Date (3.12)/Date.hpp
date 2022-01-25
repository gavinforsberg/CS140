//
//  Date.hpp
//  Date (3.12)
//
//  Created by Gavin Forsberg on 9/23/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//

#ifndef Date_h
#define Date_h
#include <iostream>

class Date
{
    int month, day, year;
public:
    Date() {}
    
    void setMonth(int m)
    {
        if(m > 1 && m < 12)
            month = {m};
        
        if(m < 1 || m > 12)
            month = {1};
    }
    void setDay(int d) { day = d; }
    void setYear(int y) { year = y; }
    int getMonth() const { return month; }
    int getDay() const { return day; }
    int getYear() const { return year; }
    void displayDate(int m, int d, int y) const
    {
        std::cout << "\nThe date is: " << getMonth() << "/" << getDay() << "/"
        << getYear() << std::endl;
    }
};
#endif /* Date_h */
