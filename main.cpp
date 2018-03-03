//
//  main.cpp
//  Time
//
//  Created by Семен Пьянков on 22.02.2018.
//  Copyright © 2018 sepy. All rights reserved.
//

#include <iostream>
#include <sys/types.h>
#include <sys/time.h>
using namespace std;


#define MAXMINS 59
#define MINHOURS 1
#define MAXHOURS 12
class Time
{
public:
    Time (int hours, int mins)
    {
        if (hours <= MAXHOURS && hours >= MINHOURS && mins <= MAXMINS)
        {
            this->totalMins = (MAXMINS + 1) * hours + mins;
        }
    }
    
    bool operator== (const Time& with)
    {
        return (totalMins %((MAXHOURS)*(MAXMINS+1)) == with.totalMins %((MAXHOURS)*(MAXMINS+1)));
    }
    
    Time operator+ (const Time& with)
    {
        int sumMins = totalMins + with.totalMins;
        Time result (0,0);
        result.totalMins = sumMins;
        return result;
    }
    
    friend ostream& operator<<(ostream& stream, const Time& outTime)
    {
        int mins = outTime.totalMins%(MAXMINS+1);
        int hours = (outTime.totalMins/(MAXMINS+1))%MAXHOURS;
        if (hours == 0 && outTime.totalMins != 0) hours = 12;
        stream << hours << ".";
        if (mins < 10) stream << "0";
        stream << mins << endl;
        return stream;
    }
    
private:
    int totalMins = 0;
};

class A {
private:
    
    A ()
    {
        
    }
    
    A (const A&)
    {
        
    }
    
    static A* body;
    
    static int64_t creation_time;
    
public:
    
    static A* getA ()
    {
        if (!body)
        {
            body = new (A);
            //body = this;
            //(*body) = A();
            timeval time;
            gettimeofday (&time, NULL);
            creation_time = time.tv_sec*1000000+time.tv_usec;
        }
        return body;
    }
    
    int64_t time () const
    {
        return creation_time;
    }
 
};

A* A::body = NULL;
int64_t A::creation_time = 0;

int main(int argc, const char * argv[])
{
    
    A* tmp;
    tmp = A::getA(); //->getA();
    
    /*
    Time good  (10, 15);
    Time bad   (100, 15);
    Time bad2  (100, 68);
    Time bad3  (5, 1);
    Time good2 (4, 57);
    Time bad4  (12, 4);
    //bad4 = bad4 + good2;
    
    cout << bad4 << good2 << bad4+good2  << endl;
    bad2 = bad4+good2;
    if (bad3 == bad2) printf("good");
    
    printf("%%% !");*/
}
