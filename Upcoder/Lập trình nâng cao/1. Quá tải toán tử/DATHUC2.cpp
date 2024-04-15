//http://www.upcoder.xyz/'index.php/4e42840e04135f798e58abd46dd5e65970f27ab46128fde531ec5e729e39e4b3/hzwqH''w4z_yRMoOMs!z5z'lBML4.skq'RwokBKpu's0hnmv'687'768ck8A9A?0OL3ECk4.L4N7_eF8975M7%27C2g@yh?C2L@j1?Cd$om1?Cu$e:1*h2EAR5/88c810e9c0021dc484b032b8aec1923427088b267e1660065ba9bb6365e6c2b1
#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;


class BACNHAT
{
    int a,b;
    public:
    BACNHAT()
    {
        a=b= 0;
    }
    BACNHAT(int x, int y)
    {
        a=x;
        b= y;
    }
friend istream& operator >> (istream& in , BACNHAT &a)
{
    in>>a.a>>a.b;
    return in;
}
friend ostream& operator << (ostream& ou, BACNHAT a)
{
    if (a.a==0&&a.b==0)
    {
        ou<<0;
        return ou;
    }
    if (a.a!=0)
    ou<<a.a<<"x";
    if (a.a!=0&&a.b>0)
    ou<<"+";
    if (a.b!=0)
    ou<<a.b;
    return ou;
}

int tinhGiaTri (int x)
{
    BACNHAT a= *this;
    return x*a.a +a.b;
}
BACNHAT operator+(BACNHAT b)
{
    BACNHAT a =*this;
    BACNHAT result;
    result.a=a.a+b.a;
    result.b=a.b+b.b;
    return result;
}
bool operator == (BACNHAT b)
{
    BACNHAT a= *this;
    return a.a+a.b==b.a+b.b;
}
};
int main()
{
    BACNHAT a, b;
    cin>>a>>b;
    int x;
    cin>>x;
    cout<<a<<endl<<b<<endl;
    cout<<a<<"+"<<b<<"="<<a+b<<endl;
    cout<<a.tinhGiaTri(x)<<endl<<b.tinhGiaTri(x)<<endl;
    if (a==b)
    cout<<"TRUE";
    else cout<<"FALSE";
    return 0;
}