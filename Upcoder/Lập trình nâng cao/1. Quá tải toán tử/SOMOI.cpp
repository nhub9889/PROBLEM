//http://www.upcoder.xyz/'index.php/d491f44314d3d11986bf5643ce9a8ddeeff9dd4c25c1fa069c0731ed0072aa17/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'8@1'5dEb-a9fdELk7?L7.6.d8CKL-~2.-d_6%27SrPpm3/86ade8758c7b3752a49d91b451d4c40f2bbfefb122d74607714c7677d13fee62
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
        int result=0;
        while (n)
        {
            result += n%10;
            n/=10;
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
    SoMoi  operator+ (SoMoi b)
    {
        SoMoi a = *this;
        
        int n = a.Moi()+b.Moi();
        SoMoi result(n);
        return result;

    }
};
int main()
{
    SoMoi a, b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    if (a>b)
    cout<<"true"<<endl;
    else cout<<"false"<<endl;
    cout<<a+b;
    return 0;
}