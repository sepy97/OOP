//
//  main.cpp
//  Matrix
//
//  Created by Семен Пьянков on 22.02.2018.
//  Copyright © 2018 sepy. All rights reserved.
//

#include <cstdio>
#include <iostream>
using namespace std;

class Matrix
{
public:
    int rows = 0, columns = 0;
    double* data;
    
    Matrix ();
    Matrix (int, int);
    Matrix (Matrix*);
    
    friend ostream& operator<<(ostream& stream, const Matrix& sample)
    {
        if (!(sample.rows == 0 && sample.columns == 0))
        {
            for (int i = 0; i < sample.rows; i++)
            {
                for (int j = 0; j < sample.columns; j++)
                {
                    stream << sample.data[i*sample.columns+j] << " ";
                    //printf ("%f ", sample.data[i*sample.columns+j]);
                }
                stream << endl;
            }
        }
        return stream;
    }
};

Matrix::Matrix ()
{
    this->rows    = 0;
    this->columns = 0;
}

Matrix::Matrix (int rows, int columns)
{
    this->rows    = rows;
    this->columns = columns;
    this->data    = new double [rows*columns]();
}

Matrix::Matrix (Matrix* from)
{
    this->rows    = from->rows;
    this->columns = from->columns;
    this->data    = new double [rows*columns]();
    
    for (int i = 0; i < rows*columns; i++)
    {
        this->data[i] = from->data[i];
    }
}

int main(int argc, const char * argv[])
{
    Matrix tmp (2,3);
    tmp.data[0] = 0;
    tmp.data[1] = 1;
    tmp.data[2] = 2;
    tmp.data[3] = 3;
    tmp.data[4] = 4;
    tmp.data[5] = 5;
    
    Matrix tmp2 (tmp);
    
    Matrix tmp3 ();
    /*for (int i = 0; i < tmp2.rows; i++)
    {
        for (int j = 0; j < tmp2.columns; j++)
        {
            printf ("%f ", tmp2.data[i*tmp2.columns+j]);
        }
        printf ("\n");
    }*/
    cout << tmp3 << endl;
}
