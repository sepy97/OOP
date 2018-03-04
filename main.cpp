//
//  main.cpp
//  Eratosphene
//
//  Created by Семен Пьянков on 04.03.2018.
//  Copyright © 2018 sepy. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

long long erat (long long N);
long long sum  (vector<bool>* sieve);

int main(int argc, const char * argv[])
{
    long long X = 0;
    cin >> X;
    /*vector<long long> sieve;
    sieve.resize(X);
    */
    long long result = erat (X+1);
    
    cout << result;
}


long long erat (long long N)
{
    vector <bool> sv;
    sv.resize(N);
    sv[0] = false;
    sv[1] = false;
    for (int i = 2; i < N; i++)
    {
        sv[i] = true;
    }
    
    for (int i = 2; i < N; i++)
    {
        if (sv[i])
        {
            for (int j = 2; j < (N/i+1); j++)
            {
                sv[j*i] = false;
            }
        }
    }
    
    long long result = sum (&sv);
    return result;
}

long long sum  (vector<bool>* sieve)
{
    long long result = 0;
    for (int i = 0; i < sieve->size(); i++)
    {
        if ((*sieve)[i] == true) result++;
    }
    return result;
}
