//http://www.upcoder.xyz/'index.php/9d3a0c369eb966396448c1a5b39ba7a7975a1148aacc9e22535af53cf75d0e6f/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'867'0F5f-5M1F.-79~5NK378@c_-5~9k1!CK'Mmu?CB$j:1Sk~E@u1?C~EA:1?R8/4da0b2904e33f8058d67d0a776411387a1e987327b005daed57303b4e69fedb5

#include <iostream>
#include <cmath>
using namespace std;


class SoDao
{
    int n;
    public:

    int Dao ()
    {
        int result = 0;
        while (n)
        {
            result = result*10 +n%10; 
            n/=10;
        }
        return result;
    }

    friend istream& operator >> (istream& in, SoDao &a)
    {
        in>>a.n;
        return in;
    }

    friend ostream& operator << (ostream& ou, SoDao b)
    {
        ou<<"[SoDao] "<<b.n;
        return ou;
    }

    bool operator > (SoDao b)
    {
        SoDao a = *this;
        return a.Dao()>b.Dao();
    }

    int operator + (int n)
    {
        SoDao a=*this;
        return a.Dao()+n;
    }
};

template <class T>
struct array
{
    T arr[100];
    int n = 0;
};

template <class T>
istream& operator >> (istream& in , array <T> &a)
{
    in>>a.arr[a.n];
    a.n++;
    return in;
}

template <class T>
int Sum (array <T> arr)
{
    int sum = 0;
    for (int i =0 ;i <arr.n;i++)
    {
        sum = arr.arr[i] + sum;
    }
    return sum;
}

template <class T>
T Max(array <T> arr)
{
    T max = arr.arr[0];
    for (int i = 1; i<arr.n;i++)
    {
        if (arr.arr[i]>max)
        max =arr.arr[i];
    }
    return max;
}


int main()
{
    array <int> arr;
    array <SoDao> brr;
    char s;
    while (cin>>s)
    {
        if (s=='T')
        {
            cin>>arr;
        }
        else cin>>brr;
    }
    if (arr.n==0)
    cout<<"khong co"<<endl<<"khong co"<<endl;
    else
    {
        cout<<Sum(arr)<<endl<<Max(arr)<<endl;
    }
    if (brr.n==0)
    cout<<"khong co"<<endl<<"khong co"<<endl;
    else
    {
        cout<<Sum(brr)<<endl<<Max(brr)<<endl;
    }
    return 0;
}