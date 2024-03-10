//http://www.upcoder.xyz/'index.php/9a051a2d87a208b067b994b4097ab5b4469cffe77c76c4b368280f76f3ffbde4/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'yKpvLjoiuew'0iPz'E9:6!93'489.L4E5:6@MeghNbkLd8K@b8.A:hj8O'5~4:1872678/159de5a06b3dff4a3b31fda13b9fef2261d4990d66fa8796b907329342c09e0d

#include <iostream>
using namespace std;

class fraction{
    int a,b;
public:
    
    void Reduce ()
    {
    int m=a, n=b;
    while (m!=n)
    {
        if (m>n)
        m-=n;
        else n-=m;
    }
    a/=m;
    b/=m;
}

    void Set (int m, int n)
    {
    a=m;
    b=n;
    };
    
    int first (){
    return a;
}

    int second ()
    {
    return b;
}
    void plus()
    {
    int m=a;
    a=a*a+b*b;
    b=b*m;
    Reduce();
    Set(a,b);
    
}
    void inverse()
    {
    swap (a,b);
}
void ifraction(istream& input)
{
    int a,b;
    input>>a>>b;
    Set(a,b);
}
void ofraction(ostream& output)
{
    output<<first()<<"/"<<second()<<endl;
   
}

    
};



int main()
{
    fraction ps;
    ps.ifraction(cin);
    ps.ofraction(cout);
    cout<<ps.first()<<endl;
    cout<<ps.second()<<endl;
    ps.inverse();
    ps.ofraction(cout);
    ps.Reduce();
    ps.inverse();
    ps.ofraction(cout);
    ps.plus();
    ps.ofraction(cout);
}

