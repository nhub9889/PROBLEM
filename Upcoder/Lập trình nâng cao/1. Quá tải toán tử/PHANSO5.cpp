//http://www.upcoder.xyz/'index.php/943e95d4e55c0407f3fb0659a5995a0af411d9178bc40d08c8a34054b20d6190/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'8?4%27C77A9eOKfEb78O74E5@2-f3gg@1?EA_K%27PnC2T@yo?CB$A:,*~.3/55e44f4018480dbb9856aadf692725825196bb0a6369d48e8e784415839bdf7a
#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;


class fraction
{
    int num;
    int den;
    public :
    friend istream& operator >> (istream& in, fraction &a)
    {
        in>>a.num>>a.den;
        return in;
    }
    friend ostream& operator << (ostream& ou, fraction b)
    {
        ou<<b.num<<"/"<<b.den;
        return ou;
    }
    fraction operator++()
    {
        fraction result = *this;
        result.num++;
        return result;
    }
    fraction operator--()
    {
        fraction result = *this;
        result.num--;
        return result;
    }
};
int main()
{
    fraction a;
    cin>>a;
    string s;
    cin>>s;
    cout<<a<<endl;
    if (s=="++")
    {
        cout<<++a;
    }
    else cout<<--a;
    return 0;
}