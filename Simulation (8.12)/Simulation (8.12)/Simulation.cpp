//
//  Simulation.cpp
//  Simulation (8.12)
//
//  Created by Gavin Forsberg on 10/20/19.
//  Copyright © 2019 Gavin Forsberg. All rights reserved.
// 

#include <iostream>
#include <iomanip>
#include <ctime>
#include <random>
using namespace std;

void moveTortoise(int* tortoise);
void moveHare(int* hare);
void displayResults(int tortoise, int hare);



int main()
{
    const int finishLine = {70};
    int tortoise = {1};
    int hare = {1};
    int time = {0};
    
    cout << "BANG !!!!!" << "\nAND THEY'RE OFF !!!!!" << endl;
    
    while(tortoise <= finishLine && hare <= finishLine)
    {
        moveTortoise(&tortoise);
        moveHare(&hare);
        displayResults(tortoise, hare);
        ++time;
    }
    
    if(tortoise == finishLine && hare == finishLine)
        cout << "\nIt's a tie." << endl;
    else if(tortoise > hare)
        cout << "\nTORTOISE WINS!!! YAY!!!" << endl;
    else if(hare > tortoise)
        cout << "\nHare wins. Yuch." << endl;
    
    cout << "TIME ELAPSED = " << time  << " seconds" << endl << endl;
}

void moveHare(int *hare)
{
    random_device rng;
    const auto seed = rng.entropy() ? rng() : time(NULL);
    mt19937_64 rnd(seed);
    uniform_int_distribution<int> dist{1, 10};

    if(dist(rng) >= 1 && dist(rng) <= 2)
        *hare += 9;
    else if(dist(rng) == 5)
       *hare -= 12;
    else if(dist(rng) >= 6 && dist(rng) <= 8)
       ++(*hare);
    else if(dist(rng) >= 9 && dist(rng) <= 10)
       *hare -= 2;
   
    if(*hare < 1)
        *hare = 1;
}

void moveTortoise(int *tortoise)
{
   random_device rng;
   const auto seed = rng.entropy() ? rng() : time(NULL);
   mt19937_64 rnd(seed);
   uniform_int_distribution<int> dist{1, 10};
    
    if(1 <= dist(rng) && dist(rng) <= 5)
       *tortoise += 3;
   else if(6 <= dist(rng) && dist(rng) <= 7)
       *tortoise -= 6;
   else
       ++(*tortoise);
   
   if(*tortoise < 1)
       *tortoise = 1;
}

void displayResults(int tortoise, int hare)
{
   if(tortoise == hare)
       cout << "OUCH!!!" << endl;
   else if(tortoise < hare)
   {
       cout << setw(tortoise) << "T" << endl;
       cout << setw(hare - tortoise) << "H" << endl;
   }
   else if(hare < tortoise)
   {
       cout << setw (tortoise - hare) << "T" << endl;
       cout << setw (hare) << "H" << endl;
   }
}
