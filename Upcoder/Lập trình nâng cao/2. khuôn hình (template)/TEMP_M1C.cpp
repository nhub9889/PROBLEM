#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

template <class T>
struct M1C
{
    T arr[1000];
};

M1C <int>  arr;
int size = 0;

void nhap(int n)
{
    arr.arr[size] = n;
    size++;
}

void xuat()
{
    for (int i =0;i<size; i++)
    {
        cout<<arr.arr[i]<<" ";
    }
}

int tong ()
{
    int sum = 0 ;
    for (int i =0 ;i < size ;i++)
    {
        sum+=arr.arr[i];
    }
    return sum;
}
int main()
{
    int s;
    while (cin>>s)
    {
        nhap(s);
    }
    cout<<tong();
    return 0;
}
   
