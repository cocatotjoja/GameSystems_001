#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
using chrono::duration_cast;
using chrono::nanoseconds;
using chrono::system_clock;




int main()
{
    long long int addSum = 0;
    long long int multSum = 0;
    long long int bitSum = 0;
    long long int subSum = 0;
    long long int fourSum = 0;
    long long int ifSum = 0;
    
    int* a = new int[1000000];
    int* b = new int[1000000];

    const int halfRand = RAND_MAX / 2;


    for (int i = 0; i < 1000000; i++)
    {
        a[i] = rand();
        b[i] = rand();
    }


    //Start measuring
    // Add
    system_clock::time_point t1 = system_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        addSum += a[i] + b[i];
    }
    system_clock::time_point t2 = system_clock::now();
    auto tp1 = duration_cast<nanoseconds>(t2 - t1).count();
    
    // Add && Multiply && Bit shift && Subtract
    t1 = system_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        addSum += a[i] + b[i];
        multSum += a[i] * b[i];
        bitSum += a[i] >> 1;
        subSum += a[i] - b[i];
    }
    t2 = system_clock::now();
    auto tp2 = duration_cast<nanoseconds>(t2 - t1).count();
    
    // Multioperation
    t1 = system_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        fourSum = (a[i] + b[i]) * (a[i] - b[i]);
    }
    t2 = system_clock::now();
    auto tp3 = duration_cast<nanoseconds>(t2 - t1).count();
    
    //IF statement
    t1 = system_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        if (a[i] < halfRand)
        {
            ifSum = (a[i] + b[i]) * (a[i] - b[i]);
        }
    }
    t2 = system_clock::now();
    auto tp4 = duration_cast<nanoseconds>(t2 - t1).count();
    
    

    cout << "ADD: " << tp1 << endl;
    cout << "Four operations: " << tp2 << endl;
    cout << "Multi operation: " << tp3 << endl;
    cout << "If check: " << tp4 << endl;
}