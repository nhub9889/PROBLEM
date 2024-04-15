
//http://www.upcoder.xyz/'index.php/a073a04005baf795b4b8cf6997fe4eb963eeb7149eb4b4263b974d3656f66fcc/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'A_2'_99.94iM9jgkblM5.6O08.Ag5.2.8dE7'1?C2EA:nm!ulA:1Sj3/da22091ede7751bf907fbbf3dd138ac13a0691c853bb81ff756b53e57ce704f0
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
void reduce ( int &a ,int &b)
{
    int m = gcd(a,b) ;
    a=a/m;
    b=b/m;
    if (b<0)
    {
    a=-a;
    b=-b;
    }
   
}



class DTHANG
{
   
    public:
     int a, b, c;
    friend istream& operator >> (istream& in , DTHANG &a)
    {
        in>>a.a>>a.b>>a.c;
        return in;
    }
    friend ostream& operator << (ostream& ou, DTHANG b)
    {
        if (abs(b.a)==1)
        {
            if (b.a>0)
            cout<<"x";
            else cout<<"-x";
        }
        else if (b.a!=0)
        {
            cout<<b.a<<"x";
        }
        if (b.a!=0&&b.b>0)
        ou<<" + ";
         if (b.a!=0&&b.b<0)
        ou<<" - ";
        if (abs(b.b)==1)
        {
           
                cout<<"y";
           
        }
        else if (b.b>0)
        {
            cout<<b.b<<"y";
        }
        else if (b.b<0)
        {
            cout<<-b.b<<"y";
        }
        if((b.a!=0||b.b!=0)&&(b.c<0))
        ou<<" - ";
        if((b.a!=0||b.b!=0)&&(b.c>0))
        ou<<" + ";
        if (b.c<0)
        cout<<-b.c;
        if (b.c>0)
        cout<<b.c;
        ou<<" = 0";
        return ou;

    }
};
    void PT (DTHANG a, DTHANG b)
    {
        int d = a.a*b.b - a.b*b.a;
        int dx = -a.c*b.b + b.c*a.b;
        int dy = -a.a*b.c + b.a*a.c;
        
        if (d==0)
        {
            if (dx==0&&dy==0)
            cout<<"T"<<endl<<0;
            else
            {
                cout <<"S"<<endl;
                float d;
                 if (a.a!=0)
                
                    d = abs(b.a*(-a.c/a.a)+b.c)/sqrt(b.a*b.a+b.b*b.b);
                
                else d = abs(b.b*(-a.c/a.b)+b.c)/sqrt(b.a*b.a+b.b*b.b);
                
                cout<<roundf(d*1000)/1000;
            } 
            
        }
        else
        {
            if (a.a*b.a+b.b*a.b==0)
            {
                cout<<"V"<<endl;
            }
            else cout<<"C"<<endl;
            int f = d;
            reduce(dx,d);
            reduce(dy,f);
            if (d!=1)
            {
                cout<<"("<<dx<<"/"<<d<<", ";
            }
            else 
            {
                cout<<"("<<dx<<", ";
            }
            if (f!=1)
            {
                cout<<dy<<"/"<<f<<")";
            }
            else
            {
                cout<<dy<<")";
            }
        }

    }
    int main()
    {
        DTHANG a, b;
         cin>>a>>b;
         cout<<a<<endl<<b<<endl;
         PT(a,b);
    }
