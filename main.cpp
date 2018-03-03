//
//  main.cpp
//  Chemistry
//
//  Created by Семен Пьянков on 01.03.2018.
//  Copyright © 2018 sepy. All rights reserved.
//

#include <cstdio>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

/*map <string, int> mappify (string const& s)
{
    string copys;
    copys.append(s);
    
    int stringSize = s.size();
    for (int i = 0; i < stringSize; i++)
    {
        while (copys[i] >= '0' && copys[i] <= '9') i++;
        while (copys[i] < '0' || copys[i] > '9')
        {
            i++;
            if (i >= stringSize) break;
        }
        copys.insert(i-1, 1, ';');
        stringSize++;
        i++;
    }
    map<string, int> m;
    cout << copys;
    
    return m;
}*/

int main(int argc, const char * argv[])
{
    /*string sample;
    cin >> sample;
    
    map <string, int> mend = mappify (sample);
    
    int numOfStrings;
    cin >> numOfStrings;
    
    for (int i = 0; i < numOfStrings; i++)
    {
        
    }*/
    
    int numWords = 0;
    cin >> numWords;
    
    map <int, vector<string> > dict;
    
    for (int i = 0; i < numWords; i++)
    {
        string input;
        cin >> input;
        reverse(input.begin(), input.end());
        
        int len = input.size();
        auto search = dict.find(len);
        if (search != dict.end())
        {
            search->second.push_back(input);
        }
        else
        {
            vector<string> tmp;
            tmp.push_back(input);
            dict.insert( pair<int, vector<string> > (len, tmp) );
        }
    }
    
    for (auto it = dict.begin(); it != dict.end(); it++)
    {
        sort(it->second.begin(), it->second.end());
    }
    
    for (auto it = dict.begin(); it != dict.end(); it++)
    {
        cout << it->first << endl;
        for (int i = 0; i < it->second.size(); i++)
        {
            string reversedString = it->second[i];
            string ordString = it->second[i];
            reverse(ordString.begin(), ordString.end());
            cout << reversedString << " " << ordString << endl;
        }
        
    }
    
}
