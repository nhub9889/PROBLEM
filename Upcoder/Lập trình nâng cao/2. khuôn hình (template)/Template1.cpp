//http://www.upcoder.xyz/'index.php/0f453faae37af44f416a07d510026b14b58c50cbb959fe095aa1dcfb6f8a9b19/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'-8'l_2N99d872~796-L8.hMa_9-E898@_-8'Ph0C2q@m1?pi$A3/7457000c0908d7d3be91a13458fa41e8d71e9ee35369ac2671ca42b3f3030cad
#include <iostream>
#include <cmath>
#include <algorithm>
#include <math.h>

using namespace std;

int gcd (int a, int b)
{
    
    while (b)
    {
        int r = a%b;
        a = b;
        b= r;
    }
    if (a>0)
    return  a;
    else return  -a;
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
void max (T a, T b, T c, T &res)
{
    if (b<a&&c<a)
    res = a;
    if (c<b&&a<b)
    res =  b;
    if (a<c&&b<c)
    res =c ;
};

int main()
{
    char s;
    cin>>s;
    if (s=='a')
    {
        int a, b, c;
        cin>>a>>b>>c;
        int res;
        max(a,b,c,res);
        cout<<res;
    }
    if (s=='b')
    {
        double a,b,c,res;
        cin>>a>>b>>c;
        max (a,b,c,res);
        cout<<res;
    }
    if (s=='c')
    {
        fraction a, b, c, res;
        cin>>a>>b>>c;
        max(a,b,c,res);
        res.print();
    }
    return 0;
}