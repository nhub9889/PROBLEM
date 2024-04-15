//http://www.upcoder.xyz/'index.php/69bc22a68e7c245db9fca15c2be5c20feea6056d215b4d5b338cab077f112463/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'-5'5k7egL:1kM-ECj7-65-h?0Nh-8gk1?_e%27Vz1?!uEA:i*o2EARg*C~Ljn1?Cv$Aj1?l~:A2/71c215561f4f2614645d90ce5d981454689954bbf46defd236f24ec80e942ea6
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
    Array operator+ (Array b)
    {

        Array a= *this,result;
        if (a.n>b.n)
        {
            result.n=a.n;
        }
        else result.n=b.n;
        for (int i=0;i<result.n;i++)
        {
            result.arr[i]=a.arr[i]+b.arr[i];
        }
        return result;
    }
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
    Array sum =a +b;
    cout<<sum;
    return  0;
}