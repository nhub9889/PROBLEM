//http://www.upcoder.xyz/'index.php/3c0e4a99d0f8190d341da3e3b2f4c2373344af4cc0e3af85ee43449af22e70bd/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'2~5:'~C28L86Of-9bj1_h3L89clh3:693O6K:'Gh?C2Eol_?@~Xw:1*t2EAn.*q2Ek&28/be7c57883a67a8308c22cee319608d002393ce4b32ad1fd69208a27a3e267868
#include <iostream>
using namespace std;

class complex 
{
    int re;
    int im;
    public:
    complex()
    {
        re = 0;
        im = 0;
    }
    complex (int a, int b)
    {
        re =a ;
        im =b;
    }

    friend istream& operator >> (istream& in , complex &n)
    {
        in>>n.re>>n.im;
        return in;
    }


    

    friend ostream& operator<< (ostream& ou, const complex n)
    {
        if (n.re!=0)
        {
            ou<<n.re;
            if (n.im>0)
                ou<<"+"<<n.im<<"*i";
            else if (n.im<0)
                ou<<n.im<<"*i";
        }
        else
        {
            if (n.im>0)
                ou<<n.im<<"*i";
            else if (n.im<0)
                ou<<n.im<<"*i";
        }
        return ou;       
     
    }
    const complex operator + ( complex b)
    {
        complex a = *this;
        complex result ;
        result.re = a.re + b.re;
        result.im = a.im +b.im;
        return result;
    }

    const complex operator- (const complex b)
    {
        complex a = *this;
        complex result;
        result.re=a.re-b.re;
        result.im=a.im-b.im;
        return result;
    }
    
    const complex operator* (const complex b)
    {
        complex a =*this;
        complex result;
        result.re = a.re*b.re - a.im*b.im;
        result.im = a.re*b.im + b.re*a.im;
        return result;
    }
    friend bool operator < (const complex a, const complex b)
    {
        if (a.re<b.re)
        return true;
        else if (a.re == b.re)
        {
            return a.im<b.im;
        }
        else return false;
    } 
    
};

int main()
{
    int n;
    cin>>n;
    complex arr[1000],sum,mul(1,0);
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum=arr[i] + sum;
        mul = arr[i]*mul;
    }
    complex max = arr[0], min =arr[0];
    for (int i=1;i<n;i++)
    {
        if (max<arr[i])
        max = arr[i];
        if (arr[i]<min)
        min=arr[i];
    }
    
    cout<<max<<endl<<sum<<endl<<mul<<endl<<max-min;
}