//http://www.upcoder.xyz/'index.php/a8b035010387bd616f620e6dd5ab10011b2d7d85625133cf0cc75f8e2d621944/mtzS?%27%273w4@vTeTdPu_306%27BpeNz$pnS%27TtTbqMnw%27xukojx%27.9F%273~K@d8CA:C-89EAgL?9?f8-5OdNL6~6?%27QkvEAR_nC2qj&1*s2EA&m?C2m4/23c6a0c68349b97e8f766d0344fab6db523af7f0381394047992cc0e0379864e

#include <iostream>
using namespace std;


class SoMoi
{
    int n;
    public:
    SoMoi()
    {
        n=0;
    }
    SoMoi (int k)
    {
        n=k;
    }
    int Moi()
    {
        int result=0, temp = n;
        while (temp>0)
        {
            result += temp%10;
            temp/=10;
        }
        return result;
    }
    friend istream& operator >> (istream& in, SoMoi &a)
    {
        in>>a.n;
        return in;
    }
    friend ostream& operator << (ostream& ou, const SoMoi a)
    {
        ou<<"[SoMoi] "<<a.n;
        return ou;
    }
    bool operator > (SoMoi b)
    {
        SoMoi a =*this;
        return a.Moi() > b.Moi();
    }
    bool operator == (SoMoi b)
    {
        return this->n==b.n;
    }
    SoMoi  operator+ (SoMoi b)
    {
        SoMoi a = *this;
        int n = a.Moi() + b.Moi();
        SoMoi result (n);
        return result;

    }
    int operator + (int b)
    {
        return this->Moi() + b;
    }
};

template <class T>
void Max(T *a, int n )
{
    int q =0;
    T max = a[0];
    for (int i = 0 ;i < n;i++)
    {
        if (a[i]>max)
        max =a[i];
    }
    for (int  i =0 ;i < n; i++)
    {
        if (a[i]==max)
        q++;
    }
    cout<<max<<endl<<q<<endl;
}

template <class T>
void Sum (T *a, int n)
{
    int sum = 0;
    for (int i = 0; i <n ;i++)
    sum = a[i] + sum;
    cout<<sum;
}
int main()
{
    char s;
    cin>>s;
    int arr[1000];
    SoMoi brr[1000];
    int n = 0 ;
    if (s=='N')
    {
        while (cin>>arr[n])
        n++;
        Max(&arr[0], n );
        Sum(&arr[0], n );
    }
    else
    {
        
        while (cin>>brr[n])
        n++;
        Max(&brr[0], n );
        cout<<"[SoMoi] ";
        Sum(&brr[0], n );
    }
    return 0;
}