//http://www.upcoder.xyz/index.php/problems/submit/465/87f3ddefe64ccaa79d192dd29ef69c12/L%E1%BB%9Bp_h%C3%ACnh_vu%C3%B4ng,_h%C3%ACnh_ch%E1%BB%AF_nh%E1%BA%ADt_-_%C4%91a_h%C3%ACnh

//http://www.upcoder.xyz/'index.php/e7bae006be9d486222272438aab16b2f52cf938f986de67b4468aad33a208bb9/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'7_6'3-LKLA@f86A8A-f~97~8j2@i7.4k6Oh5'J:1Sk~Lj:1?!BlA:1z8/f7d905e3e762f9ae3671624ab53061553481fc62f933dc1243e7d4a8940701cd
#include <iostream>
using namespace std;


class HCN
{
    protected:
    double a,b;
    public:
    HCN()
    {
        a=0;
        b=0;
    }
    HCN(int m, int n)
    {
        a=m;
        b=n;
    }
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
    
};

class HV : public HCN
{
    public:
    HV()
    {
        HCN();
    }
    HV(int b)
    {
        HCN(b,b);
    }
    friend istream& operator >>(istream& in, HV &a)
    {
        in>>a.a;
        a.b=a.a;
        return in;
    }
};



int main()
{
    char a;
    while (cin>>a)
    {
        if (a=='a')
        {
             
           HV hv;
           cin>>hv;
            cout<<hv.CV()<<endl;
        }
        else 
        {
           
           HCN hcn;
           cin>>hcn;
            cout<<hcn.CV()<<endl;
        }
    }

    return 0;
}