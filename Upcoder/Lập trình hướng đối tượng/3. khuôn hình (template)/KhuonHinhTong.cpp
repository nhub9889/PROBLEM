//http://www.upcoder.xyz/'index.php/6719bf1d5ef6bf4a10d5099647c8542378f2a2c65c3ea2feaab23e3ea5b44773/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'A?1%27C4gA-7.id-LjfOif7Ak8!M6Ne:aNie~K%27tPoqobye*t2EA:nm!3/af36052d7bd972f2551ca4cb15fab6afb015733b7c2399e36a180ea78bc5efef
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
       in>>n;
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
        if (a.size == 0)
        ou<<"khong co";
        else
        ou<<sum;
        return ou;
    }
};
int main()
{
    
    Array <fraction> a;
    Array <int> b;
    char m;
    while (cin>>m)
    {
        if (m =='a')
        cin>>b;
        else if (m =='b')
        cin>>a;
        cin.ignore();
    }
    
    cout<<b<<endl<<a;
}
