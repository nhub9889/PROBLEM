//http://www.upcoder.xyz/'index.php/21b7526641a3fd3da69c41784a497aa6db89d4bd91f500e3e94e5ca6cc08877c/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'E4:'_7Dj483NCDMK?c@M9gC~1F6-97~3OMdi%27vaR!hmb:1N2/e701b036cfc7d20b819ab426852fc81582ea231f6dbc631314aadad289af7a0d
#include <iostream>
#include <cmath>
using namespace std;

class DIEM
{
    protected:
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
        ou<<"("<<b.x<<","<<b.y<<")";
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
class TAMGIAC : public DIEM
{
    DIEM A, B, C;
    public:
    friend istream& operator >> ( istream& in , TAMGIAC &a)
    {
        in>>a.A>>a.B>>a.C;
        return in;
    }
    friend ostream& operator<< (ostream& ou, TAMGIAC a)
    {
        ou<<a.A<<a.B<<a.C;
        return ou;
    }
    double S()
    {
        return abs(this->A-this->B)+abs(this->A-this->C)+abs(this->B-this->C);
    }
    double operator + (TAMGIAC b)
    {
        TAMGIAC a = *this;
        return a.S()+ b.S();
    }
    
    bool operator < (TAMGIAC b)
    {
        TAMGIAC a =*this;
        return a.S()<b.S();
    }
    bool operator == (TAMGIAC b)
    {
        if (this->A==b.A&&this->B==b.B&&this->C==b.C||this->A==b.B&&this->B==b.A&&this->C==b.C||this->A==b.C&&this->B==b.B&&this->C==b.A||this->A==b.A&&this->B==b.C&&this->C==b.B||this->A==b.B&&this->B==b.C&&this->C==b.A||this->A==b.C&&this->B==b.A&&this->C==b.B) 
        return true;
    }
};

int main()

{
    TAMGIAC a,b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    double m = a.S();
    double n = b.S();
    if (m<n)
    cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    if (a==b)
    cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
}