//http://www.upcoder.xyz/'index.php/91114346da4a9db92ad226767851dc0ce21c0cd1cf19f8f61e9a2a0a43fbe7e6/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'-9'90_56MC8d?M7-9@0FCdg5?9-MA-8M3Fh%27EAh_zk2EAM_kC2Ee&nnC2Ev8/f8c07e5fb0b919c665290d31370ae8195ce6e2bc5bd44856cd560b0eb4865ad1
#include <iostream>
#include <cmath>
using namespace std;
class BacNhat
{
    int a,b;
    public:
    BacNhat()
    {
        a=b= 0;
    }
    BacNhat(int x, int y)
    {
        a=x;
        b= y;
    }
friend istream& operator >> (istream& in , BacNhat &a)
{
    in>>a.a>>a.b;
    return in;
}
friend ostream& operator << (ostream& ou, BacNhat a)
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
    BacNhat a= *this;
    return x*a.a +a.b;
}
BacNhat operator+(BacNhat b)
{
    BacNhat a =*this;
    BacNhat result;
    result.a=a.a+b.a;
    result.b=a.b+b.b;
    return result;
}
bool operator == (BacNhat b)
{
    BacNhat a= *this;
    return a.a+a.b==b.a+b.b;
}
};
int main()
{
    BacNhat a, b;
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