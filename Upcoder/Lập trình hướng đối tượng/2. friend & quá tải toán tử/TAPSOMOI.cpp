//http://www.upcoder.xyz/'index.php/0fb2f7878973fb788431c4e3264395af077cc08170a4ee7da2e5e311461d09aa/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'9-.'N597dg6M4F-778.c!_9E5Ma~h7_K?a?7%27uA:1s!tEA:_RC2Ek0/f7ff88bd495f4e15c73cb31af8ad3525d6e54600e3be846736a2ffae44cdad1e
#include <iostream>
using namespace std;
class TapSoMoi
{
    int x,y,z,t;
    public:
    TapSoMoi()
    {
        x=0;
        y=0;
        z=0;
        t=0;
    }
    TapSoMoi (int a, int b,int c, int d)
    {
        x=a;
        y=b;
        z=c;
        t=d;
    }
    friend istream& operator >> (istream& in, TapSoMoi& s)
    {
        in>>s.x>>s.y>>s.z>>s.t;
        return in;
    }
    friend ostream& operator << (ostream& ou, const TapSoMoi s)
    {
        ou<<"[TapSoMoi] "<<s.x<<";"<<s.y<<";"<<s.z<<";"<<s.t;
        return ou;
    }

    TapSoMoi operator+ (TapSoMoi s)
    {
        TapSoMoi u =*this;
        TapSoMoi v;
        v.x=u.x+s.x;
        v.y=u.y + s.y;
        v.z = u.z+ s.z;
        v.t= u.t +s.t;
        return v;
    }
    friend bool operator < (const TapSoMoi a, const TapSoMoi b)
    {
        int m= a.x+a.y+a.z+a.t;
        int n=b.x+b.y+b.z+b.t;
        return m<n;
    }

    TapSoMoi operator++()
    {
        TapSoMoi a = *this;
        a.t++;
        a.x++;
        return a;
    }

    TapSoMoi& operator = (const TapSoMoi b)
    {
       this->x=b.x;
       this->y=b.y;
       this->z=b.z;
       this->t=b.t;
    }
};
int main()
{
    TapSoMoi a,b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    cout<< (a<b?"true\n":"false\n");
    cout << a+b<<endl;
    cout<<++a;
}