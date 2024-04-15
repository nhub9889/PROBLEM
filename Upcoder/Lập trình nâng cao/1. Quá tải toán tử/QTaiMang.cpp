//http://www.upcoder.xyz/'index.php/91e7e7f83a5edcce159b52a3fb1f801fb1159c319e11fc5d4737c802f65e347a/mtzS?%27%273w4@vTeTdPu_306%27BpeNz$pnS%27TtTbqMnw%27xukojx%27.2%27M2-6:dlC6_983--eE4k8@-9.L_f?igMh%27Q0C2$v:1?l~pA:1Sj~E@MhBC2Ew4/34a1c41d875fe4817fafde6b9de20142e47db03484f2eab89a6cdecf202e8924
#include <iostream>
using namespace std;

class Array
{
    int n;
    int arr[1000];
    public:
    Array()
    {
        n =1 ;
        arr[0]={0};
    }
    friend istream& operator >> (istream& in , Array &a)
    {
        in>>a.n;
        for (int i =0 ;i<a.n;i++)
        {
            in>>a.arr[i];
        }
        return in;
    }
    friend ostream& operator << (ostream& ou, Array b)
    {
        for (int i =0;i<b.n;i++)
        {
            cout<<b.arr[i]<<" ";
        }
        return ou;
    }
    Array operator+ (){return *this;}
    int& operator[] (int n)
    {
        return arr[n];
    }
    Array& operator= (Array b)
    {
        this->n=b.n;
        for (int i =0 ;i<b.n;i++)
        {
            this->arr[i]=b.arr[i];
        }
        return *this;
    }
    bool operator == (const Array b) const
    {
        if (this->n==b.n)
        {
            for (int i =0 ;i<b.n;i++)
            {
                if (this->arr[i]!=b.arr[i])
                {
                    return false;
                }
            }
        }
        else return false;
        return true;
    }
    bool operator != (const Array b) const
    {
        return !(*this==b);
    }

};
int main()
{
    Array a,b;
    cin>>a>>b;
    if (a==b)
    cout<<"yes";
    else cout<<"no";
    return  0;
}