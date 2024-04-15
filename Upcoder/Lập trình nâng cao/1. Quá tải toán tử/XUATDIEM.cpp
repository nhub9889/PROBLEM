//http://www.upcoder.xyz/'index.php/1fa534a71654afc47e208a81aa60359a5e1e8ef72c8b6ad524f8adfcd91522ca/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'CA:'7ck799LNc_6f_4.6i85~h?6~-7gb70F8%27Dw:1?Cu$Kh1?3~EAn1?C2p0/ed65f210f1220422ae48ec6aee25ea6f83308a3dbaea7b4211a2a8386567d08b
#include <iostream>
using namespace std;
class POINT
{
    int x ,y;
    public:
    POINT()
    {
        x =0 ;
        y =0 ;
    }
    friend istream& operator >> ( istream& in , POINT &a)
    {
        in>>a.x>>a.y;
        return in;
    }
    friend ostream& operator << (ostream& ou, POINT b)
    {
        ou<<"("<<b.x<<","<<b.y<<")";
        return ou;
    }
    bool operator < (POINT b)
    {
        if (this->x<b.x)
        return true;
        else if (this->x==b.x)
            if (this->y<b.y)
            return true;
        return false;
    }
    bool operator == (POINT b)
    {
        return (this->x==b.x)&&(this->y==b.y);
    }
    POINT operator+ (POINT b)
    {
        POINT result;
        result.x = this->x+b.x;
        result.y= this->y+b.y;
        return result;
    }

};
int main()
{
    POINT arr[1000];
    int i=0;
    while (cin>>arr[i])
    {
        i++;
    }
    POINT sum=arr[0], max=arr[0];
    for (int n = 1;n<i;n++)
    {
        sum = sum + arr[n];
        if (max<arr[n])
        max=arr[n];
    }
    cout<<max<<endl<<sum;
    return 0;
}