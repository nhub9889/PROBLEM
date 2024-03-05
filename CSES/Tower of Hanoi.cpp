https://cses.fi/problemset/result/8614453/
#include <iostream>
#include <string>
#include <stack>
using namespace std;
int n=0;
void HNTowern (int disc)
{
    if (disc==1)
    {
        n++;
        return;
    }
    if (disc==2)
    {
        n+=3;
        return;
    }
    else
    {
        disc--;
        HNTowern(disc);
        n++;
        HNTowern(disc);
    }
}
void HNTower (int a, int b, int c, int disc )
{
     if (disc==1)
    {
        cout<<a<<" "<<c;
        disc--;
        return;
    } 
    if (disc == 2)
     {
        cout<<a<<" "<<b<<endl;
        cout<<a<<" "<<c<<endl;
        cout<<b<<" "<<c<<endl;
        disc-=2;
        return;
     }
     else
     {
        disc--;
        HNTower (a,c,b,disc);
        cout<<a<<" "<<c<<endl;
        HNTower (b,a,c,disc);
 
     }
};
int main()
{
    int disc;
    cin>>disc;
    HNTowern(disc);
    cout<<n<<endl;
    HNTower(1, 2, 3, disc);
    
 
    
}
