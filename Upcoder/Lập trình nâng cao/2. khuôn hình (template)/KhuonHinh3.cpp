//http://www.upcoder.xyz/'index.php/b325542ab8f67127f8b66728b1f0c3b57280a1b1af778ca51e60d21e6bfa43c8/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'E4?%27P5ej6j08M-ggOa..7_gN7lED7-91PM5E%27veRSmgvO_zl2EB&s?C2E@RhrC29/cca9f2511716adc81cc0ed65ae98aaea304bccc77ec267e99c18d796817fa358
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>

using namespace std;

int gcd (int a, int b)
{
    int m =b;
    while (b)
    {
        int r = a%b;
        a = b;
        b= r;
    }
   
    return  a;
 

}
class fraction
{
    int numerator;
    int denominator;
    public:
    fraction()
    {
        numerator =1;
        denominator = 1;
    }
    void print()
    {
        cout<<numerator<<"/"<<denominator;
    }
    void reduce ()
    {
        int a = numerator;

        numerator/=gcd(numerator, denominator);
        denominator/=gcd(a,denominator);
        
    }
    bool operator < (fraction b)
    {
        fraction a =*this;
        
        
        return a.numerator*b.denominator<a.denominator*b.numerator;
    }
    friend istream& operator >> (istream& in , fraction& a)
    {
        in>>a.numerator>>a.denominator;
        return in;
    }

};

template <class T>
void min (T a[],int n, T &res)
{
    res = a[0];
   for (int i = 1 ;i< n ; i++)
   {
    if (a[i]<res)
    res = a[i];
   }
};

int main()
{
    char s;
    int an =0, bn = 0, cn =0;
    int arr[100];
    double brr[100];
    fraction crr[100];
    while (cin>>s)
    {
        if (s=='a')
        {
            cin>>arr[an];
            an++; 
        }
        if (s=='b')
        {
            cin>>brr[bn];
            bn++;
        }
        if (s=='c')
        {
            cin>>crr[cn];
            cn++;
        }
    }
    if (an!=0)
    {
        int res;
        min(arr, an , res);
        cout<<res<<endl;
    }
    else cout<<"khong co"<<endl;
    if (bn!=0)
    {
        double res;
        min(brr, bn, res);
        cout<<res<<endl;
    }
    else cout<<"khong co"<<endl;
    if (cn!=0)
    {
        fraction res;
        min(crr,cn,res);

        res.print();
    }
    else cout<<"khong co";
    return 0;
}