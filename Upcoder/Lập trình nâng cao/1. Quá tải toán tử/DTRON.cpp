//http://www.upcoder.xyz/'index.php/48cc2887e880e51f2b894d05cd587cf645307183ac52e71dbc3f9adbb6bc7257/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'?-4%27.-3~-6:8jdP58~6Nfk7e.79e?8387@5F%272EA:1?CBk@yr?CB6/23a0992e97323512a4c6f39f4d793f9015b73a68eadc75cd210a964dff7656f0
#include <iostream>
#include <cmath>
const float PI = 3.14;
using namespace std;

class DIEM
{
    
    public:

    int x;
    int y;
    friend istream& operator>> (istream& in, DIEM &a)
    {
        in>>a.x>>a.y;
        return in;
    }
    friend ostream& operator << (ostream& ou, DIEM b)
    {
        ou<<"("<<b.x<<","<<b.y<<")";
        return ou;
    }
    bool operator == (DIEM b)
    {
        return this->x==b.x&&this->y==b.y;
    }
     
};
double D (DIEM a, DIEM b)
    {
        return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    }
class DTRON
{
    
    public:

    double r;
    DIEM O;
    friend istream& operator >> (istream& in ,DTRON &a)
    {
        in>>a.O>>a.r;
        return in;
    }
    friend ostream& operator << (ostream& ou, DTRON b )
    {
        ou<<b.O<<" "<<b.r;
        return ou;
    }
    double P ()
    {
        return 2*PI*r;
    }
    bool operator == (DTRON b)
    {
        return this->P()==b.P();
    }
    bool operator < (DTRON b)
    {
        return this->P()<b.P();
    }
    double S()
    {
        return PI*r*r;
    }
    double operator + (DTRON b)
    {
        return this->S() + b.S();
    }
    
};

string VTTD (DTRON a, DTRON b)
    {
        double d = D(a.O,b.O);
        if (abs(a.r-b.r)<d&&d<(a.r+b.r))
            return "C";
        else
        {
            if (a.O==b.O)
            return "DT";
            else
        {
            if (d==abs(a.r-b.r))
            return "TXT";
            else 
        {
            if (d==a.r+b.r)
            return "TXN";
            else
        {
            if (d> a.r+b.r)
            return "NN";
            
        else
        {
            return "DN";
        }
        }
        }
        }
        }
        
        
        
    }
int main()
{
    DTRON a, b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    float d = a.S()+b.S();
    cout<<roundf(d*1000)/1000<<endl;
    if (a<b)
    cout<<"1 < 2";
    else if (a==b)
    cout<<"1 = 2";
    else 
    cout<<"1 > 2";
    cout<<endl <<VTTD(a,b);
    return 0;
}