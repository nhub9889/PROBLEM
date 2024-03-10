//http://www.upcoder.xyz/'index.php/a1298ab04f0843c206405bdd3fa0a04c5f00df74a64150db1c194a70eb94450b/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'-.~'if8L6j8PC6j9.2.MAiek5.L596M9?9d:%27Ph0C2q@m1?pi$A&T?C2T@x1?C~pA:1B9/62c1d0a896529efab53f3a99cb3b67e2ccbe97d3608dd61285afc76a0663c248
#include <iostream>
using namespace std;
class TapSoMoi
{
    int x,y,z,t;
    public:
    TapSoMoi()
    {
        x=0;
        y=0;
        z=0;
        t=0;
    }
    TapSoMoi (int a, int b,int c, int d)
    {
        x=a;
        y=b;
        z=c;
        t=d;
    }
    friend istream& operator >> (istream& in, TapSoMoi& s)
    {
        in>>s.x>>s.y>>s.z>>s.t;
        return in;
    }
    friend ostream& operator << (ostream& ou, const TapSoMoi s)
    {
        ou<<"[TapSoMoi] "<<s.x<<";"<<s.y<<";"<<s.z<<";"<<s.t;
        return ou;
    }

    TapSoMoi operator+ (TapSoMoi s)
    {
        TapSoMoi u =*this;
        TapSoMoi v;
        v.x=u.x+s.x;
        v.y=u.y + s.y;
        v.z = u.z+ s.z;
        v.t= u.t +s.t;
        return v;
    }
    friend bool operator < (const TapSoMoi a, const TapSoMoi b)
    {
        int m= a.x+a.y+a.z+a.t;
        int n=b.x+b.y+b.z+b.t;
        return m<n;
    }

    TapSoMoi operator++()
    {
        TapSoMoi a = *this;
        a.t++;
        a.x++;
        return a;
    }

    TapSoMoi& operator&= (const TapSoMoi b)
    {
       this->x=b.x;
       this->y=b.y;
       this->z=b.z;
       this->t=b.t;
    }
};

template <class T>

class Mang
{
    int size =0;
    T arr[1000];
    public:

    friend istream& operator >> (istream& in, Mang& a)
    {
        T n;
        while (cin>>n)
        {
            a.arr[a.size++]=n;
        }
        return in;
    }

    friend ostream& operator << (ostream& ou, const Mang a)
    {
   
        T max = a.arr[0];
        for (int i=1;i<a.size;i++)
        {
            if(max<a.arr[i])
            max=a.arr[i];
        }
        ou<<max<<endl;

        return ou;

    }

    T sum()
    {
        T res = this->arr[0];
        for (int i=1;i<this->size;i++)
        {
            res = this->arr[i]+res;
        }
        return res;
    }

};

int main()
{
    char m;
    cin>>m;
    Mang <int> a;
    Mang <TapSoMoi> b;
    if (m=='A')
    {
        cin>>a;
        cout<<a<<a.sum();
    }
    else
    {
        cin>>b;
        cout<<b<<b.sum();
    }
    return 0;
}





