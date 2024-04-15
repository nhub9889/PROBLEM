#include <iostream>
#include <stdio.h>
using namespace std;
double EquationSn(int n, double a, double b, double c)
{
    double lastS = 3, S = -1, nextS = a*a -2*b;
    int k = 0;
    while (k<n)
    {
        double U = nextS;
        nextS = -a*nextS- b*S - c*lastS;
        lastS = S;
        S = U;
        k++;
    }
    return lastS;
}
int main()
{
    double a, b, c, result; int n;
    cin>>a>>b>>c>>n;
    cout<<"S(n)="<<result<<endl;
    return 0;
}
//S = x^3 + ax^2 + bx +c = 0
//Sn = x^n + y^n +z^n (x, y, z are root of S)
// have:
//S0 =3;
//S1 = x+y+z=-a;
//S2 = x^2 +y^2 +z^2=(x+y+z)^2 -2(xy + yz +xz)=a^2 - 2b;
//Sn = -aSn-1 -bSn-2 -cSn-3    if(n>=3)