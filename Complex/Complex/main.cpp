//
//  main.cpp
//  C
//
//  Created by Семен Пьянков on 20.02.2018.
//  Copyright © 2018 sepy. All rights reserved.
//

#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

class C
{
public:
    C (double, double);
    C (double);
    C (C*);
    C ();
    
    C operator+  (const C&);
    C operator+  (const double&);
    
    C operator-  (const C&);
    C operator-  (const double&);
    
    C operator*  (const C&);
    C operator*  (const double&);
    
    C operator/  (const C&);
    C operator/  (const double&);
    
    bool    operator== (const C&);
    
    bool    operator!= (const C&);
    
    friend ostream& operator<<(ostream& stream, const C& num)
    {
        stream << num.re << " " << num.im << endl;
        return stream;
    }
    
    friend C operator+ (const double& first, const C& second)
    {
        C firsttmp (first, 0);
        return firsttmp + second;
    }
    friend C operator- (const double& first, const C& second)
    {
        C firsttmp (first, 0);
        return firsttmp - second;
    }
    friend C operator* (const double& first, const C& second)
    {
        C firsttmp (first, 0);
        return firsttmp * second;
    }
    friend C operator/ (const double& first, const C& second)
    {
        C firsttmp (first, 0);
        return firsttmp / second;
    }
    
    double abs ();
    int    out ();

    double im = 0, re = 0;
};

C::C (double re, double im)
{
    this->re = re;
    this->im = im;
}

C::C (double re)
{
    this->re = re;
    this->im = 0;
}

C::C (C* from)
{
    this->re = from->re;
    this->im = from->im;
}

C::C ()
{
    this->re = 0;
    this->im = 0;
}

double C::abs ()
{
    return sqrt(this->re*this->re + this->im*this->im);
}

int C::out ()
{
    printf ("%f %f\n", this->re, this->im);
    return 0;
}

C C::operator+ (const C& add)
{
    C result (0,0);
    result.re = this->re + add.re;
    result.im = this->im + add.im;
    return result;
}
C C::operator+ (const double& add)
{
    C tmpadd (add,0);
    return (*this) + tmpadd;
}

C C::operator- (const C& add)
{
    C result (0,0);
    result.re = this->re - add.re;
    result.im = this->im - add.im;
    return result;
}
C C::operator- (const double& add)
{
    C tmpadd (add,0);
    return (*this) - tmpadd;
}

C C::operator* (const C& add)
{
    C result (0,0);
    result.re = this->re*add.re - this->im*add.im;
    result.im = this->im*add.re + this->re*add.im;
    return result;
}
C C::operator* (const double& add)
{
    C tmpadd (add,0);
    return (*this) * tmpadd;
}

C C::operator/ (const C& add)
{
    C result (0,0);
    result.re = (re*add.re + im*add.im)/(add.re*add.re + add.im*add.im);
    result.im = (im*add.re - re*add.im)/(add.re*add.re + add.im*add.im);
    return result;
}
C C::operator/ (const double& add)
{
    C tmpadd (add,0);
    return (*this) / tmpadd;
}

bool C::operator== (const C& comp)
{
    return ((re == comp.re) && (im == comp.im));
}

bool C::operator!= (const C& comp)
{
    return !((re == comp.re) && (im == comp.im));
}


template <typename T, typename U>
T summ_of_numbers (T first_number, U second_number ) {
    return first_number+second_number;
}

template <typename R, typename S, typename SUB, typename L, typename D = int>
void diff_of_arrays (R* reduced, S* substracted, SUB* substraction, L size, D def = 0)
{
    for (L i = 0; i < size; i++)
    {
        substraction[i] = reduced[i] - substracted[i] + def;
    }
}

template <typename F, typename L, typename S = int>
bool arrays_are_equal (F array1, L array2, S size = 0)
{
    for (S i = 0; i < size; i++)
    {
        if (array1[i] != array2[i]) return false;
    }
    return true;
}

template <typename F, typename T, typename S = int>
void copy_array (F from, T to, S size = 0)
{
    if (size == 0)
    {
        to[0] = from[0];
    }
    else
    {
        for (S i = 0; i < size; i++)
        {
            to[i] = from[i];
        }
    }
}

int main(int argc, const char * argv[])
{
    C first (0.72, 0.5);
    C second (&first);
    first = first + second;
    second = first / second;
    printf("%f %f\n", first.abs(), second.abs());
    C third (0,0);
    third = second - 5;
    if (first == second) printf ("good\n");
    if (first != second) printf ("bad\n");
    
    cout << third;
    
    //printf("%f %f %f\n", first.abs(), second.abs(), third.abs());
}
