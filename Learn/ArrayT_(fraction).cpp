#include"ArrayT.h"
#include<iostream>
using namespace std;
typedef struct
{
    int numerator;
    int denominator;
}fraction;

fraction* fractionArrInput()
{
    fraction *a = nullptr, p;
    while (cin>>p.numerator>>p.denominator)
    {
        arrPushBack(a,p);
    }
    return a;
}

void PrintFraction (fraction p)
{
    if (p.numerator==0||p.denominator==1)
    cout<<p.numerator<<" ";
    else 
    cout<<p.numerator<<"/"<<p.denominator;
}

void PrintArrFraction (fraction* p)
{
    int n = arrSize(p);
    for (int i=0;i<n;i++)
    {
        PrintFraction(p[i]);
    }
}
int main()
{
    fraction *P, q;
    P = fractionArrInput();
    //----yêu cầu....//
    {
        PrintArrFraction(P);
        q = arrPopBack(P);
        PrintFraction(q);
    }
    //----giải phóng bộ nhớ--//
    arrFree(P);
    return 0;
}