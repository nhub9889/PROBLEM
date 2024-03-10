//http://www.upcoder.xyz/'index.php/412586ffe14841461bc9bb39c0f5044a8778cb6c5b04113351f046e7791f1aba/hzwqH''w4z_yRMoOMs!z5z'lBML4.skq'uMoxMfSbwdy'wmL3'?-27-75%27L4~4N5i929C?3?K485k3.6fjKNa?-fL.%274!52E491885/b123606d61726186fde83c5e6ccf912c11540e4f090c7f2a15d894b87a194431

#include <iostream>
using namespace std;


class fraction{
    int a,b;
public:
    void Reduce (int a, int b);
    void Set (int m, int n);
    int first ();
    int second ();
};

void fraction::Reduce(int m,int n)
{
    while (m!=n)
    {
        if (m>n)
        m-=n;
        else n-=m;
    }
    a/=m;
    b/=m;
}

void fraction::Set(int m, int n)
{
    a=m;
    b=n;
}
void ifraction(istream& input, fraction& ps)
{
    int a,b;
    input>>a>>b;
    ps.Set(a,b);
}
void ofraction(ostream& output, fraction& ps)
{
    output<<ps.first()<<"/"<<ps.second();
}

int fraction::first()
{
    return a;
}
int fraction::second()
{
    return b;
}

int main()
{
    fraction ps;
    ifraction(cin,ps);
    ps.Reduce(ps.first(),ps.second());
    ofraction(cout,ps);
    return 0;
}

