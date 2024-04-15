//http://www.upcoder.xyz/'index.php/af0474354158cf98897a3146f64ca143c11de9a41e98c285d8dce279ab41c342/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'?.A%27.?dk5gEKh4k58.A@7@5K-C:8!_7Le@ei%27IEARh*c2EAM_6/0740ccb739dff6ea5788bd66172b55633c9988be94b66b82ce3b068f09220ea3
#include <iostream>
#include <cmath>
using namespace std;

class DIEM
{
    int x;
    int y;
    public:
    
    DIEM()
    {
        x =0 ; y= 0;
    }
    DIEM (int a, int b)
    {
        x =a ; y= b;
    }
    int X()
    {
        return x;
    }
    int Y()
    {
        return y;
    }
    friend istream& operator >> ( istream& in , DIEM&a)
    {
        in>>a.x>>a.y;
        return in;
    }
    friend ostream& operator << ( ostream& ou , DIEM b)
    {
        ou<<"("<<b.x<<", "<<b.y<<")";
        return ou;
    }
    bool operator == (DIEM b)
    {
        DIEM a =* this;
        return  (a.x==b.x)&&(a.y==b.y);
    }
    double operator - (DIEM b)
    {
        DIEM a = *this;
        double result;
        result = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
        return result;
    }
};

class HCN
{
    DIEM A, B, C, D;
    public:
    friend istream& operator >> (istream& in , HCN &a)
    {
        in>>a.A>>a.B>>a.C>>a.D;
        return in;
    }
    friend ostream& operator << (ostream& ou , HCN a)
    {
        ou<<a.A<<" "<<a.B<<" "<<a.C<<" "<<a.D;
        return ou;
    }
    double S()
    {
        HCN a =*this;
        return (a.A-a.B)*(a.B-a.C);
    }

    double operator + (HCN b)
    {
        HCN a =* this;
        return a.S() + b.S();
    }

    bool operator < (HCN b)
    {
        return this->S()<b.S();
    }
    bool operator > (HCN b)
    {
        return this->S()>b.S();
    }
    bool operator == (HCN b)
    {
        return this -> S()== b.S();
    }
};

class TGV
{
    DIEM A, B, C;
    public:
    friend istream& operator >> ( istream& in , TGV &a)
    {
        in>>a.A>>a.B>>a.C;
        return in;
    }
    friend ostream& operator<< (ostream& ou, TGV a)
    {
        ou<<a.A<<" "<<a.B<<" "<<a.C;
        return ou;
    }
    double S()
    {
        return (this->A-this->B)*(this->A-this->C)/2;
    }
    double operator + (TGV b)
    {
        TGV a = *this;
        return a.S()+ b.S();
    }
    
    bool operator < (TGV b)
    {
        TGV a = *this;
        return a.S()<b.S();
    }
    bool operator > ( TGV b)
    {
        TGV a =*this;
        return a.S()>b.S();
    }
    bool operator == (TGV b)
    {
        return this->S()==b.S();
    }
};

class HT
{
    DIEM t;
    int r;
    public:
    friend istream& operator >> (istream& in , HT &a)
    {
        in>>a.t>>a.r;
        return  in;
    }
    friend  ostream& operator<< (ostream& ou, HT &a)
    {
        ou<<"("<<a.t.X()<<", "<<a.t.Y()<<", "<<a.r<<")";
        return ou;
    }
    double S()
    {
        return this->r*this->r*3.14;
    }
    double operator + (HT b)
    {
        return this->S() + b.S();
    }
    bool operator < (HT b)
    {
        return this->S()<b.S();
    }
    bool operator > (HT b)
    {
        return this->S()>b.S();
    }
    bool operator == (HT b)
    {
        return this->S()==b.S();
    }
};

int main()
{
    HCN a, b;
    TGV m ,n ;
    HT x ,y;
    cin>>a>>b>>m>>n>>x>>y;
    cout<<a<<endl<<b<<endl<<m<<endl<<n<<endl<<x<<endl<<y<<endl;
    cout<<a+b<<endl<<m+n<<endl<<x+y<<endl;
    if (a<b) cout <<"1<2"<<endl;
    if (a > b) cout<<"1>2"<<endl;
    if (a==b) cout<<"1=2"<<endl;
    if (m<n) cout<<"1<2"<<endl;
    if (m>n) cout<<"1>2"<<endl;
    if (m==n) cout<<"1=2"<<endl;
    if (x<y) cout<<"1<2"<<endl;
    if (x>y) cout<<"1>2"<<endl;
    if (x==y) cout<<"1=2"<<endl;
}