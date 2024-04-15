#ifndef _ARRAY2D_T_H
#define _ARRAY2D_T_H
#include <stdio.h>
#include <malloc.h>
#include <iostream>


static int mOffs = 0, nOffs =1;
static int headSize = 2*sizeof(int);

template <class T>
void alloc2D(T**&a, int m, int  n)
{
    void *buf = nullptr;
    int * bufStruct;
    T*data = nullptr;
    if (m<=0||n<=0)
    return;

    size_t szRow = n*(size_t)sizeof(T);
    size_t sz1 = m*sizeof(T*);
    size_t sz2 = m*szRow;
    buf = calloc(headSize + sz1 + sz2, 1);
    if (buf == nullptr)
    return;

    bufStruct = (int*)buf;
    bufStruct[mOffs]=m;
    bufStruct[nOffs]=n;

    a = (T**)((char*)buf + headSize);
    a[0]=data = (T*)((char*)a+sz1);
    for (int i= 1; i<m;i++)
    {
        data+=n;
        a[i]=data;
        
    }
    return;
}// end alloc2D() function

template <class T>
void free2D(T**a)
{
    if(a!=nullptr)
    {
        void*pmem = ((char*)a-headSize);
        free(pmem);
    }
}// end free2D() function


template <class T>
int nRow(T**a)
{
    int* bufStruct = (int*)((char*)a-headSize);
    return bufStruct[mOffs];
}// end nRow() function

template <class T>
int nCol(T**a)
{
    int*bufStruct = (int*)((char*)a-headSize);
    return bufStruct[nOffs];
}//end nColl() function

template <class T>
T** resize2D(T**a, int m, int n)
{
    int *bufStruct, m_old, n_old;
    T** a_new;
    if (m<=0||n<=0)
    {
        return nullptr;
    }
    if (a==nullptr)
    {
        alloc2D(a,m,n);
        return a;
    }
    bufStruct = (int*)((char*)a- headSize);
    m_old = bufStruct[mOffs];
    n_old = bufStruct[nOffs];
    if (m_old<=0|| n_old<=0)
    {
        return nullptr;
    }
    alloc2D(a_new, m ,n);
    if (a_new==nullptr)
    {
        return nullptr;
    }
    for (int i=0;i<m_old&&i<m;i++)
    {
        for (int j =0 ; j<n_old&&j<n;j++)
        {
            a_new[i][j] = a[i][j];
        }
    }
    free2D(a);
    return a_new;
}//end resize2D() function

template <class T>
void arr2D_input(T*a[])
{
    int m = nRow((void**)a);
    int n = nCol((void**)a);
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
}

template <class T>
void arr2D_output(T*a[])
{
    int m = nRow((void**)a);
    int n = nCol((void**)a);
    for (int i =0 ;i<m; i++)
    {
        for (int j =0 ;j< n ;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
#endif