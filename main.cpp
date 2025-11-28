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
    /*
    long long int multSum = 0;
    long long int bitSum = 0;
    long long int subSum = 0;
    */
    int* a = new int[1000000];
    int* b = new int[1000000];


    system_clock::time_point t1 = system_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        a[i] = rand();
        b[i] = rand();
    }
    system_clock::time_point t2 = system_clock::now();

    auto tp1 = duration_cast<nanoseconds>(t2 - t1).count();
    auto tp2 = duration_cast<nanoseconds>(t2 - t1).count();

    //Start measuring

    t1 = system_clock::now();
    for (int i = 0; i < 1000000; i++)
    {
        addSum += a[i] + b[i];
        /*
        multSum += a[i] * b[i];
        bitSum += a[i] << 1;
        subSum += a[i] - b[i];
        */
    }
    t2 = system_clock::now();
    tp2 = duration_cast<nanoseconds>(t2 - t1).count();
    
    /*
    cout << addSum << endl;
    cout << multSum << endl;
    cout << bitSum << endl;
    cout << subSum << endl;
    */

    cout << tp1 << endl;
    cout << tp2 << endl;
}