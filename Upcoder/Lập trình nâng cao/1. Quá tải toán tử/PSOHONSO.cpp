//http://www.upcoder.xyz/'index.php/e05aaace3a679679c46e71ec698d718103d662db078ad3c23ed3c467bfa4fee4/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'C37'.b~56N8.7?96-8.7-EgE4k1P.5.7OfiK%27Wj:1S!tEA:1*yDEA&H?C2Eo&s?C2E7/fd2fe2a2be3c37d8ce365bc2579d73fb683e5755d94b6bba4d62b044639c0dae
#include <iostream>
#include <string>
using namespace std;

int gcd (int a ,int b)
{
    while (b!=0)
    {
        int c = a%b;
        a = b;
        b = c;
    }
    return a;
}
class fraction
{
    
    public:
    int numerator;
    int denominator;
    fraction ()
    {
        numerator = 0;
        denominator =1;
    }
    friend istream& operator >> (istream& in , fraction &a)
    {
        in>>a.numerator>>a.denominator;
        return  in;
    }
    friend ostream& operator << (ostream& ou, fraction b)
    {
        ou<<b.numerator<<"/"<<b.denominator;
        return ou;
    }
    void Reduce()
    {
        int r = gcd (this->denominator, this->numerator); 
       this->numerator/=r;
       this->denominator/=r;
       if (this->denominator<0)
       {
        this->numerator*=-1;
        this->denominator*=-1;
       }
       
    }

    bool operator != (fraction b)
    {
        return this->denominator!=b.denominator&&this->numerator!=b.numerator;
    }
};

class MixedNumber : public fraction
{
    int n;
    public:
    friend istream& operator >> (istream& in , MixedNumber &a)
    {
        in>>a.n>>a.numerator>>a.denominator;
        return in;
    }
    friend ostream& operator << (ostream& ou, MixedNumber b)
    {
        ou<<b.n<<" "<<b.numerator<<"/"<<b.denominator;
        return ou;
    }
    bool operator != (MixedNumber b)
    {
        return this->n!=b.n&&this->denominator!=b.denominator&&this->numerator!=b.numerator;
    }


   MixedNumber ReduceM(string k = "true")
    {
        MixedNumber result=*this;
             fraction::Reduce();
            if (numerator/denominator>=1)
            {
                n+=numerator/denominator;
                numerator = numerator%denominator;
            }
            result=*this;
            return result;
    }
    fraction ReduceF(string k = "false")
    {
        fraction result;
            numerator += denominator*n;
            fraction::Reduce();
            result.numerator=numerator;
            result.denominator=denominator;
        
        return result;
    }
    int SUM()
    {
        return this->denominator+this->numerator+this->n;
    }
    bool operator > (MixedNumber b)
    {
        return this->SUM()>b.SUM();
    }
    
};
int main()
{
    MixedNumber a,b;
    cin>>a>>b;
    string k ;
    cin>>k;
    if (a!=b)
    cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    if (a>b)
    cout<<"TRUE"<<endl;
    else cout<<"FALSE"<<endl;
    if (k=="true")
    {
       cout<< a.ReduceM()<<endl<<b.ReduceM();
    }
    else
    {
        cout<<a.ReduceF()<<endl<<b.ReduceF();
    }
    return 0;
}