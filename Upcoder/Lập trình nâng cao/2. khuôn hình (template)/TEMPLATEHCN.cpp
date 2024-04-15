//http://www.upcoder.xyz/'index.php/72ba62d0f369854964ad3725a6060a9a41e683ed431c85c84b354bfd5df31c3a/hzwqH''w4z_yRMoOMs!z5z'lBML4.skq'RwokBKpu's0hnmv'6@8'~hN2-.eLLhfO7A7ek58M78K@2iMDMg@a'NiyA:n*k2Eom_?!IEARh*KiEA:_Sk2EAy5/a3f2971eb511d2d8f7b43252224fbea1185f7b388d5a9474a428359a623a02b2

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


class HCN
{
    double a,b;
    public:
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
    double operator + (HCN b)
    {
        return this->CV()+b.CV();
    }
};

template <class T>
T Min(T *a, int n)
{
    T min = a[0];
    for (int i = 1 ;i < n; i++)
    {
        if (a[i]<min)
        {
            min = a[i];
        }
    }
    return  min;
}
template <class T>
double Sum (T*a, int n)
{
    double sum = 0;
    for (int i = 0;i < n; i++)
    {
        sum = a[i] + sum;
    }
    return sum;
}
int main()
{
    char s;
    cin>>s;
    int  n = 0 ;
    HCN arr[100];
    int brr[100];
    if (s == 'N')
    {
        while (cin>>brr[n])
        n++;
        cout<<Min(&brr[0],n)<<endl;
        cout<<(int)Sum(&brr[0],n);
    }
    else
    {
         while (cin>>arr[n])
        n++;
        cout<<Min(&arr[0],n)<<endl;
        cout<<setprecision(1)<<fixed<<Sum(&arr[0],n);
    }
    return 0;
}