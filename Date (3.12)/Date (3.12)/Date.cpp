//
//  Date.cpp
//  Date (3.12)
//
//  Created by Gavin Forsberg on 9/22/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
//
#include "Date.hpp"
#include <iostream>
using namespace std;

int main()
{
    
    int month, day, year;
    Date date;
    
    cout << "Enter a month: ";
    cin >> month;
    date.setMonth(month);
    cout << "\nEnter a day: ";
    cin >> day;
    date.setDay(day);
    cout << "\nEnter a year: ";
    cin >> year;
    date.setYear(year);
    
    date.displayDate(month, day, year);
    
    return 0;
}
