//http://www.upcoder.xyz/'index.php/e998ee106aa504dc44f5a6491bc77e9da097425befdc91e8bea1748e6b2608b5/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'668'jcN8K8b859_5j8M9lCKMeM0_M2MAOaiM'VROriwpv4:0/7d669db0c89c1d2627493cac0b83fbb572cc22602180b6f006fb145dd90cc990
#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;


class fraction
{
    int num, den;
    public:
    fraction()
    {
        num = 0;
        den = 1;
    }
    fraction (int a, int b)
    {
        num = a;
        den =b;
    }
    friend istream& operator >> (istream& in, fraction &a)
    {
        in>>a.num>>a.den;
        return in;
    }
    friend ostream& operator<< (ostream& ou, fraction b)
    {
        ou<<b.num<<"/"<<b.den;
        return ou;
    }
    void reduce()
    {
        
        int m = num, n=den;
        while (m!=n)
        {
            if (m>n)
            m-=n;
           else
            n-=m;
            
        }
       num/=m;
       den/=m;
    }
    bool operator < (fraction b)
    {
        fraction a = *this;
        a.reduce();
        b.reduce();
        return a.num*b.den<a.den*b.num;
    }
    void swap (fraction &a, fraction &b)
    {
        fraction c = a;
        a.den=b.den;
        a.num=b.num;
        b.den=c.den;
        b.num=c.num;
    }
};
int main()
{
    int n,m; 
    cin>>n;
    m=n;
    fraction arr[10000];
    while (n)
    {
        cin>>arr[n];
        n--;
    }
    for (int i=1;i<m;i++)
    {
        for (int j = i+1;j<=m;j++)
        {
            if (arr[j]<arr[i])
            swap(arr[i],arr[j]);
        }
    }


  
    for (int i=1;i<=m;i++)
    {
       arr[i].reduce();
        cout<<arr[i]<<" ";
    }
    return 0;
}