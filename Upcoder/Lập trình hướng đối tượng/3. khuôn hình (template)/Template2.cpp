//http://www.upcoder.xyz/'index.php/9a0ce8e658f261f3098168cd16499c1d1e2c59702f4485efd211cff6608cb4e1/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'~.'9!8Kjh.3@i4:8N4i8f.9Nf8Lfieh4_C8'sOmsBDxL&axuD49/6d51431181fa5d5c6344e3991b652008ccb600d4841f8a42ee95252791448903
#include <iostream>
using namespace std;


class fraction{
    int a,b;
public:
    void Reduce ();
    void Set (int m, int n);
    int first ();
    int second ();
    fraction operator+ (fraction b)
{
    fraction a=*this;
    fraction res;
    res.a= a.a*b.b+a.b*b.a;
    res.b=a.b*b.b;
    res.Reduce();
    return res;
    
}
    friend istream& operator >> (istream& in , fraction &a)
    {
        in>>a.a>>a.b;
        return in;
    }

    friend ostream& operator << (ostream& ou, const fraction ps)
    {ou<<ps.a<<"/"<<ps.b;
    return ou;
    }


};

void fraction::Reduce()
{
    int m=a;
    int n=b;
    while (m!=n)
    {
        if (m>n)
        m-=n;
        else n-=m;
    }
    a/=m;
    b/=m;
}

void fraction::Set(int m, int n)
{
    a=m;
    b=n;
}
void ifraction(istream& input, fraction& ps)
{
    int a,b;
    input>>a>>b;
    ps.Set(a,b);
}
void ofraction(ostream& output, fraction& ps)
{
    output<<ps.first()<<"/"<<ps.second();
}

int fraction::first()
{
    return a;
}
int fraction::second()
{
    return b;
}

template <class T>

class Array
{
    T arr[1000];
    int size =0;
    public:

    friend istream& operator >> (istream& in ,Array &a)
    {
        T n ;
        while (in>>n)
        {
            a.arr[a.size++]=n;
        }
    return in;
    }

    friend ostream& operator << (ostream& ou, const Array a)
    {
        T sum = a.arr[0];
        for ( int i=1;i<a.size;i++)
        {
           sum = sum + a.arr[i];
        }
        ou<<sum;
        return ou;
    }
};
int main()
{
    char m;
    cin>>m;
    Array <fraction> a;
    Array <int> b;
    if (m=='a')
    {
        cin>>b;
        cout<<b;
    }
    else{
        cin>>a;
        cout<<a;
    }
}
