//http://www.upcoder.xyz/'index.php/a5b50a6346eefce304e3d16392371554e66b36b2b096262185e8eff8ecb330f1/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'?93-%27-d-73_48a.79g4:5?C-j5N9-L8jg7cFL%27EAh_zk2EAM_kC2Ee&hil6/674a8294f791c86d4494c83b00fcd1232cf9bac644e42e4b48bd53d54a246db0
#include <iostream>
#include <cmath>
using namespace std;

class BacHai
{
    int a,b,c;
    public:
    BacHai ()
    {
        a= 0;
        b= 0; 
        c=0;
    }
    BacHai (int x, int y, int z)
    {
        a=x;
        b=y;
        c=z;
    }

    friend istream& operator >> ( istream& in , BacHai &a)
    {
        in>>a.a>>a.b>>a.c;
        return in;
    }
    friend ostream& operator << (ostream& ou, BacHai &a)
    {
        if (a.a==0&&a.b==0&&a.c==0)
        {
            cout<<0;
            return ou;
        }
        if (a.a!=0)
        {
            ou<<a.a<<"x^2";
        }
        if (a.a!=0&&a.b!=0)
        ou<<"+";
        if (a.b!=0)
        {
            ou<<a.b<<"x";
        }
        if(a.b!=0&&a.c!=0)
        ou<<"+";
        if (a.c!=0)
        {
            ou<<a.c;
        }
        return ou;
    }

    int tinhGiaTri (int x)
    {
        int a = this->a;
        int b= this ->b;
        int c = this->c;
        return a*x*x +b*x+c;
    }

    BacHai operator+ (BacHai b)
    {
        BacHai result;
        result.a = this->a + b.a;
        result.b= this ->b + b.b;
        result.c= this-> c + b.c;
        return result;
    }

    bool operator==(const BacHai b)
    {
        BacHai a = *this;
        return (a.a==b.a)&&(a.b==b.b)&&(b.c==a.c);
    }
};

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
    if (a.a!=0&&a.b!=0)
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

BacHai operator * (BacNhat b)
{
    BacNhat a = *this;
    int x, y, z;
    z = a.b * b.b; 
    y = a.b*b.a + a.a*b.b;
    x=a.a*b.a;
    BacHai result = BacHai(x,y,z);
    return result;
}



};
int main()
{
    BacHai x,y;
    BacNhat a,b;
    cin>>x>>y>>a>>b;
    int n;
    cin>>n;
    cout<<x<<endl<<x.tinhGiaTri(n)<<endl;
    cout<<y<<endl<<y.tinhGiaTri(n)<<endl;
    BacHai z = x+y, t= a*b;
    cout<<z<<endl<<z.tinhGiaTri(n)<<endl;
    cout<<"("<<a<<")"<<"*"<<"("<<b<<")"<<"="<<t<<endl<<t.tinhGiaTri(n)<<endl;

    if (x==y&&x==t&&y==t)
    {
        cout<<"TRUE3";
    }
    else if (x==t)
    cout<<"TRUE1"<<endl;
    else if (y==t)
    cout<<"TRUE2"<<endl;
    else 
    cout<<"FALSE";
    
    return  0;
   
}