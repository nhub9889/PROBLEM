//http://www.upcoder.xyz/index.php/problems/submit/237/38afc86d1d7f35849c976668a985e45f/%C3%94n_t%E1%BA%ADp_qu%C3%A1_t%E1%BA%A3i,_template,_nh%E1%BA%ADp_xu%E1%BA%A5t_file
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int gcd (int a, int b)
{
    while (b!=0)
    {
        int r = a%b;
        a =b;
        b =r;
    }
    return a;
}

struct PhanSo
{
    unsigned int a = 0;
    unsigned int b = 1;

void reduce (PhanSo &a)
{
    int r = gcd(a.a,a.b);
    a.a = a.a/r;
    a.b = a.b/r;
}
   friend istream& operator >> (istream& in, PhanSo &a)
{
    in>>a.a;
    char q ;
    in>>q;
    in>>a.b;
    return  in;
}
friend ostream& operator << (ostream& out, const PhanSo& b)
{
    PhanSo c = b;
    c.reduce(c);
    if (c.a==0)
    out<<0;
    else if (c.b == 1)
    {
        out<<c.a;
    }
    else
    {
        out<<c.a<<"/"<<c.b;
    }
    return out;
}

bool operator == ( PhanSo b)
{
    return this->a*b.b == this->b*b.a;
}

bool operator > (PhanSo b)
{
    return this->a*b.b > this->b*b.a;
}



PhanSo operator + (PhanSo b)
{
    PhanSo res;
     res.a = this->a*b.b + b.a*this->b;
     res.b = this->b*b.b;
     reduce(res);
     return res;
}
};


template <class T>
struct array
{
    T arr[100];
    int n;

   friend istream& operator >> (istream& in, array <T> &a)
    {
        in>>a.n;
        for (int i =0 ;i < a.n ;i ++)
        {
            in>>a.arr[i];
        }
        return in;
    }

   friend ostream& operator << (ostream& ou, const array <T>& b)
    {
        for (int  i = 0 ;i < b.n ;i++)
        {
            ou<<b.arr[i]<<" ";
        }
        return ou;
    }
};

    template <class T>
    T tongPhanTu(array <T> a)
    {
        T sum  =a.arr[0];
        for (int  i = 1 ; i < a.n; i++)
        {
            sum = sum + a.arr[i];
        }
        return sum;
    }

    template <class T>
    T phanTuMax(array<T> a)
    {
        T max = a.arr[0];
        for (int i = 1 ; i< a.n ;i++)
        {
            if (a.arr[i]>max)
            max =a.arr[i];
        }
        return max;
    }

    template <class T>
    void sapXep (array<T> &a, char r = '<')
    {
        if (r=='<')
        for (int i = 0 ; i < a.n-1 ; i++)
        {
            for (int  j = i+1; j< a.n ;j++)
            {
                if (a.arr[i]>a.arr[j])
                {
                    T temp = a.arr[i];
                    a.arr[i] = a.arr[j];
                    a.arr[j] = temp;

                }
            }
        }
        else
        {
            for (int i = 0 ; i < a.n-1 ; i++)
        {
            for (int  j = i+1; j< a.n ;j++)
            {
                if (a.arr[j]>a.arr[i])
                {
                    T temp = a.arr[i];
                    a.arr[i] = a.arr[j];
                    a.arr[j] = temp;

                }
            }
        }
        }
    }

    template <class T>
    array<T> operator + (array<T>& a, array<T>& b)
    {
        int m;
        array<T> res;
        if (a.n>b.n)
        {
            res.n = a.n;
            m = b.n;
            for (int i = 0 ; i< m;i++)
        {
            res.arr[i] = a.arr[i] + b.arr[i];
        }
         for (int  i = m ; i< res.n ; i++)
        {
            res.arr[i] = a.arr[i];
        }
        }
        else
        {
res.n = b.n;
m =a.n;
for (int i = 0 ; i< m;i++)
        {
            res.arr[i] = a.arr[i] + b.arr[i];
        }
         for (int  i = m ; i< res.n ; i++)
        {
            res.arr[i] = b.arr[i];
        }
        }
         
        
       
        return res;
    }

void print (array <int> q, char r = '<')
{
    if (r=='<')
    {
        for (int i = 0 ;i < q.n ;i++)
    {
       if (q.arr[i]%2==0)
       cout<<q.arr[i]<<" ";
    }
for (int i = 0 ;i < q.n ;i++)
    {
       if (q.arr[i]%2!=0)
       cout<<q.arr[i]<<" ";
    }
    }
    else
    {
        for (int i = 0 ;i < q.n ;i++)
    {
       if (q.arr[i]%2!=0)
       cout<<q.arr[i]<<" ";
    }
    for (int i = 0 ;i < q.n ;i++)
    {
       if (q.arr[i]%2==0)
       cout<<q.arr[i]<<" ";
    }
    }
    
}


int main()
{
    char s;
    cin>>s;
    array <int> arra1,arra2;
    array <PhanSo> arrb1, arrb2;
    if (s == 'I')
    {
        cin>>arra1>>arra2;
        array <int> sum = arra1 + arra2;
        cout<<arra1<<endl<< "MAX 1 = "<<phanTuMax(arra1)<<endl<<"SUM 1 = "<<tongPhanTu(arra1)<<endl;
        sapXep(arra1,'<');
        print(arra1,'<');
        cout<<endl<<arra2<<endl<<"MAX 2 = "<<phanTuMax(arra2)<<endl<<"SUM 2 = "<<tongPhanTu(arra2)<<endl;
        sapXep(arra2,'>');
        print(arra2,'>');
        
        cout<<endl<<sum;
    }
    else
    {
        cin>>arrb1>>arrb2;
        array <PhanSo> sum ;
        sum = arrb1 + arrb2;
        cout<<arrb1<<endl<< "MAX 1 = "<<phanTuMax(arrb1)<<endl<<"SUM 1 = "<<tongPhanTu(arrb1)<<endl;
        sapXep(arrb1,'<');
        cout<<arrb1<<endl;
        cout<<arrb2<<endl<<"MAX 2 = "<<phanTuMax(arrb2)<<endl<<"SUM 2 = "<<tongPhanTu(arrb2)<<endl;
        sapXep(arrb2,'>');
        cout<<arrb2<<endl;
        cout<<sum; 
    }
    return 0;
}
