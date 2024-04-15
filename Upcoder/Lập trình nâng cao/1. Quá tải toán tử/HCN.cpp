//http://www.upcoder.xyz/'index.php/e7bae006be9d486222272438aab16b2f52cf938f986de67b4468aad33a208bb9/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'7_6'3-LKLA@f86A8A-f~97~8j2@i7.4k6Oh5'J:1Sk~Lj:1?!BlA:1z8/f7d905e3e762f9ae3671624ab53061553481fc62f933dc1243e7d4a8940701cd
#include <iostream>
using namespace std;


class HCN
{
    double a,b;
    public:
    friend istream& operator >> (istream& in , HCN &a)
    {
        in>>a.a>>a.b;
        return in;
    }
    friend ostream& operator << (ostream& ou, HCN b)
    {
        ou<<"[HCN] "<<b.a<<","<<b.b;
        return ou;
    }
    double CV ()
    {
        return (a + b )*2;
    }
    bool operator < (HCN b)
    {
        HCN a= *this;
        return a.CV()<b.CV();
    }
    double operator + (double b)
    {
        HCN a =*this;
        return a.CV()+b;
    }
};

int main()
{
    HCN a,b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    if (a<b)
    cout<<"true";
    else cout<<"false";
    return 0;
}