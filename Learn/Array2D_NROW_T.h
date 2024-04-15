#ifndef _ARRAY2D_NROW_H
#define _ARRAY2D_NROW_H
#include <malloc.h>
#include <stdio.h>


template <class T>
bool arr2D_alloc (T* a[], int m, int n)
{
    T* buffer=(T*)calloc(m*(size_t)n,sizeof(T));
    if (buffer==nullptr)
    {
        a[0]=nullptr;
        return false;
    }
    a[0]=buffer;
    for (int i =1; i<m ;i++)
    {
        buffer+=n;
        a[i]=buffer;
    }
    return true;
}

template <class T>
void arr2D_free (T*a[])
{
    if (a[0]!= nullptr)
    {
        free(a[0]);
        a[0]= nullptr;
    }
}

#include <iostream>
using namespace std;

template <class T>
void arr2D_input ( T* a[], int m ,int n)
{
    for (int i =0 ;i<m;i++)
    {
        for (int j= 0; j< n;j++)
        {
            cin>>a[i][j];
        }
    }
}

template <class T>
void arr2D_output (T* a[], int m ,int n)
{
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
#endif