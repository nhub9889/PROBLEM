//http://www.upcoder.xyz/'index.php/02f3197a3b5d97be0a54819e0a3abf7ab4fcd11143c649937a623ace8e2f35dd/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'vdStObrfsMu'vBMx'A_1__78'-6lE-75?795e-6h8~53j.978f6:6k78f%278.71?55E4-2/62313316a1a17c35d2bb513871ec89e713fee5bf26484e101135ee3795e64164

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

