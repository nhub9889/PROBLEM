//http://www.upcoder.xyz/'index.php/9aca0f123f4fa3f88374dc66872dfa9da451373a80bc2ea4b573a6c85e10b7f7/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'~55'-h7O.ei-.3NM2g-86!E8:C-9@L3NK73_'TEA:_?C2EAT6/3c2cea4335e3a54b11351264b0e2bd7611a168ad61819e184fc8252959926d8e
#include <iostream>
#include <cmath>
using namespace std;


class SoDao
{
    int n;
    public:

    int Dao ()
    {
        int result = 0;
        while (n)
        {
            result = result*10 +n%10; 
            n/=10;
        }
        return result;
    }

    friend istream& operator >> (istream& in, SoDao &a)
    {
        in>>a.n;
        return in;
    }

    friend ostream& operator << (ostream& ou, SoDao b)
    {
        ou<<"[SoDao] "<<b.n;
    }

    bool operator > (SoDao b)
    {
        SoDao a = *this;
        return a.Dao()>b.Dao();
    }

    int operator + (int n)
    {
        SoDao a=*this;
        return a.Dao()+n;
    }
};
int main()
{
    SoDao a,b;
    cin>>a>>b;
    cout<<a<<endl<<b<<endl;
    if (a>b)
    cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    int m = a+0;
    int n = b+0;

    cout<<n+m;
    return 0;
}