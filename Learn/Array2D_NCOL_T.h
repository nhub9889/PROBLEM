#ifndef _ARRAY2D_NCOL_H
#define _ARRAY2D_NCOL_H
#include <stdio.h>
#include <malloc.h>
#define NCOL 4 // be modified

template <class T>
struct array1D
{
    T data[NCOL+1];
    T& operator[] (int i)
    {
        if (i>=0&&i<NCOL)
        {
            return data[i];
        }
        return data[NCOL];
    }
};

template <class T>
void arr2D_free (array1D<T> * a)
{
    if (a!= nullptr)
    {
        free(a);
    }
}

#include <iostream>
using namespace std;

template <class T> 
void arr2D_input (array1D<T>* a, int m, int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0 ;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

template <class T>
void arr2D_output(array1D<T>* a, int m ,int n)
{
    for (int i =0 ;i<m;i++)
    {
        for (int j=0 ;j< n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

template <class T>
void arr2D_alloc (array1D <T>*&a ,int m)
{
    a= (array1D<T>*)calloc(m, sizeof(array1D<T>));
}
#endif