//http://www.upcoder.xyz/'index.php/1e4871a7dccfb433a173259ab82878ef4f332af7b3dbb7edbef62b9ed98236c2/mtzS?%27%273w4@vTeTdPu_306%27BpeNz$pnS%27TtTbqMnw%27xukojx%27:2-8%27MKNb.KfN5~1Oi2MbO4!9Agb.cO55~7:6%27UPW@VDwQ~GzS34/0b74adf9a95b70a1ce38b016ca478188ae1f3f0641e78eefd5bc27089a68545f
//http://www.upcoder.xyz/'index.php/41800616d4bbfc808b89fff3649167444d5e664df76cf8bef35151d9b5cfe4d3/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'2:6?%27@-e9g:5@if_9.2i7f.4kb-h4-A~7~5KL%27WOY!OhsV_I0C78/b921b6f1871c2e00eb34b2f5f9f101f2da1b09ec36b49949f23e4e9b5f169289
#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;
class ARRINT1
{
    int leng;
    int a[1000];
    public:
    ARRINT1 ()
    {
        for (int i=0;i<leng;i++)
        a[i]=0;
    }
    const ARRINT1 operator- (const ARRINT1 m)
    {
        ARRINT1 res=*this;
        int n;
        if(res.leng<m.leng)
        n=m.leng;
        else n=res.leng;
        ARRINT1 result;
        result.leng = n;
        for (int i=0;i<n;i++)
        {
            if(res.a[i]-m.a[i]>=0)
            result.a[i]=res.a[i]-m.a[i];
            else result.a[i]=-res.a[i]+m.a[i];
        }
        return result;
    }
    void getLeng (int n)
    {
        leng = n;
    }
    friend istream& operator >> (istream& in , ARRINT1& n)
    {
        for (int i=n.leng-1;i>=0;i--)
        in>>n.a[i];
        return in;
    }
    friend ostream& operator << (ostream& ou, const ARRINT1 m)
    {
        ou<<m.leng<<":"<<" ";
        for (int i=0;i<m.leng;i++)
        ou<<m.a[i];
    }
};
int main()
{
    int a,b;
    cin>>a>>b;
    ARRINT1 x,y;
    x.getLeng(a);
    y.getLeng(b);
    
    cin>>x>>y;
   
    cout<<x-y;
}