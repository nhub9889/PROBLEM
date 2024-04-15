//http://www.upcoder.xyz/'index.php/cab758b5659a80562dd08429ed747df6bf6bd7cf9413918b47fe886acd3749b0/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'A_99'A-.99@8KM5@58M2.hNe!-ej7@ciE6~CM'vC2E@XH?C2F@3/cbacb3f0288557863df826e15ce778d96dcf664e87a127662042c0f4cd347b88
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
                ou<<"+"<<n.im<<"i";
            else if (n.im<0)
                ou<<n.im<<"i";
        }
        else
        {
            if (n.im>0)
                ou<<n.im<<"i";
            else if (n.im<0)
                ou<<n.im<<"i";
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