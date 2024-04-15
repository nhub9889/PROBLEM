
//http://www.upcoder.xyz/'index.php/e7bae006be9d486222272438aab16b2f52cf938f986de67b4468aad33a208bb9/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'7_6'3-LKLA@f86A8A-f~97~8j2@i7.4k6Oh5'J:1Sk~Lj:1?!BlA:1z8/f7d905e3e762f9ae3671624ab53061553481fc62f933dc1243e7d4a8940701cd
#include <iostream>
using namespace std;


class HCN
{
    protected:
    double a,b;
    public:
    HCN()
    {
        a=0;
        b=0;
    }
    HCN(int m, int n)
    {
        a=m;
        b=n;
    }
    friend istream& operator >> (istream& in , HCN &a)
    {
        in>>a.a>>a.b;
        return in;
    }
    friend ostream& operator << (ostream& ou, HCN b)
    {
        ou<<"[HCN] "<<b.a<<","<<b.b;
        return ou;
    }
    double CV ()
    {
        return (a + b )*2;
    }
    bool operator < (HCN b)
    {
        HCN a= *this;
        return a.CV()<b.CV();
    }
    double operator + (double b)
    {
        HCN a =*this;
        return a.CV()+b;
    }
};

class HV : public HCN
{
    public:
    HV()
    {
        HCN();
    }
    HV(int b)
    {
        HCN(b,b);
    }
    friend istream& operator >>(istream& in, HV &a)
    {
        in>>a.a;
        a.b=a.a;
        return in;
    }
};

template < class T>
T Max(T a[], int n)
{
    T max= a[0];
    for (int i=1;i<n;i++)
    {
        if (max<a[i])
        {
            max=a[i];
        }
    }
    return max;
}

int main()
{
    string s;
    HCN hcn[1000];
    HV hv[1000];
    cin>>s;
    if (s=="HCN")
    {
        int n=0;
        while (cin>>hcn[n])
        {
            n++;
        }
        HCN max= Max(hcn,n);
        cout<<max.CV();
        
    }
    else
    {
       int n=0;
        while (cin>>hv[n])
        {
            n++;
        }
        HV max =  Max(hv,n);
         cout<<max.CV();
    }

    return 0;
}