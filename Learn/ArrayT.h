#ifndef _ARRAYT_H
#define _ARRAYT_H
#include <malloc.h>
#include <memory.h>
#include <stdio.h>
//--------hàm nội bộ trong tập tin-----------//
static int dummy_item;
static int sizeof_nitem = sizeof(dummy_item);
static int mOffs = 0, nOffs = 1;
static int headSize = 2*sizeof(int);

template <class T>
static void* origin_addr(T* aData)
{
    return (char*)aData - sizeof_nitem;
}

template <class T>
static T* data_addr(T* origin)
{
    return (T*)((char*)origin+sizeof_nitem);
}

template <class T>
static void set_nitem (T* aData, int nitem)
{
     *(int*)origin_addr(aData) = nitem;
}

template <class T>
static int get_nitem (T* aData)
{
    return *(int*)origin_addr(aData);
}


//--------cài đặt mã hàm--------//
template <class T>
bool arrResize(T* &aData, int nitem)
{
    int sz = sizeof_nitem + nitem*sizeof(T);
    T*aNew = nullptr;
    void *originAddr = nullptr;
    if (aData!=nullptr)
    {
        originAddr = origin_addr(aData);
    }
    aNew = (T*)realloc(originAddr,sz);
    if (aNew!=nullptr)
    {
        if (aData!=nullptr)
        {
            memset(aNew, 0 , sz);
        }
        aData = data_addr(aNew);
        set_nitem(aData,nitem);
        return true;
    }
    return false;
}

template <class T>
int arrSize (T*aData)
{
    if (aData!=nullptr)
    {
        return get_nitem(aData);
    }
    return 0;
}

template <class T>
void arrFree(T*aData)
{
    if (aData!=nullptr)
    {
        free(origin_addr(aData));
    }
}

template <class T>
bool arrPushBack (T* &aData, T x)
{
    int nitem = arrSize(aData);
    if (arrResize(aData, 1+nitem))
    {
        memset(&aData[nitem],0,sizeof(T));
        aData[nitem] = x;
        return true;
    }
    return false;
}

template <class T>
T arrPopBack (T* &aData)
{
    int nitem = arrSize(aData);
    T x;
    if (aData!= nullptr&&nitem>0)
    {
        nitem--;
        x = aData[nitem];
        set_nitem(aData,nitem);
    }
    return x;
}
#endif