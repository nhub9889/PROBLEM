//http://www.upcoder.xyz/'index.php/a9f5a4b6943f3e1616750d24a69217740b43f37e730b726f004ba55cd5693429/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'CA78'c9f9E9@1if6M9?cF69_5?f-i-7ehdO56%27A_1@!IOC&LwQE$_&S?C2$Rm1?Cd7/b2dc5ad23cf3f871e61b7a6c0a333cb7869511a44d4760df3d2040274439ca24

#include <iostream>
#include <iomanip>
#include <cmath>
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


    void Modulus ()
    {
        int a = this->re;
        int b= this->im;
        double result = sqrt(a*a+b*b) ;
        cout<<fixed<<setprecision(2)<<result;
    }

    friend ostream& operator<< (ostream& ou, const complex n)
    {
        if (n.re!=0)
        {
            ou<<n.re;
            if (n.im>0)
            if (n.im!=1)
                ou<<"+"<<n.im<<"i";
                else ou<<"+"<<"i";
            else if (n.im<0)
            if (n.im!=-1)
                ou<<n.im<<"i";
                else ou<<"-i";
        }
        else
        {
            if (n.im>0)
            if (n.im!=1)
                ou<<n.im<<"i";
                else ou<<"i";
            else if (n.im<0)
            if (n.im!=-1)
                ou<<n.im<<"i";
                else if (n.im==-1)
                ou<<"-i";
                else if (n.im==0)
                ou<<0;
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
    
    
    
    
};

int main()
{
    complex arr[10000];
    int n=0;
    while (cin>>arr[n])
    {
        cout<<"{"<<arr[n]<<"}"<<" ";
        n++;
    }
    cout<<endl;
    complex sum;
    for (int i=0;i<n;i++)
    {
        arr[i].Modulus();
        cout<<" ";
        sum = sum + arr[i];
    }
    cout<<endl<<"{"<<sum<<"}";
}