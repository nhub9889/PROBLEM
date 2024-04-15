//http://www.upcoder.xyz/'index.php/434c6d5fc3eb138c7779de7ee6bbbe3265379158600f8ce27e26144519fd5577/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'.A9'hf~6KN7M9?58MK95-M6iLj4kLD77O3_6%27FA:nm!igk&h?C2q@x1?C~EK:1?ph$A:7/adc284b09b58cf2d2dcaa06a8cb7037ab5295675465edba09cc7f1bcbbbd85f1
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
    
    protected:
    int numerator;
    int denominator;
    public:
    fraction ()
    {
        numerator = 0;
        denominator =1;
    }
    fraction (int a, int b)
    {
        numerator =a;
        denominator =b;
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
   fraction operator+ (fraction b)
   {
    fraction a =*this, result;
    result.numerator=a.denominator*b.numerator+a.numerator*b.denominator;
    result.denominator=a.denominator*b.denominator;
    return result;
   }
   int Numerator()
   {
    return numerator;
   }
   int Denominator()
   {
    return denominator;
   }

   
};

class MixedNumber : public fraction
{
    int n;
    public:
    MixedNumber()
    {
        n=0;
    }
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
    virtual MixedNumber operator+ (MixedNumber b)
    {
        MixedNumber result, a=*this;
        result.n=this->n+b.n;
        result.numerator=a.denominator*b.numerator+a.numerator*b.denominator;
    result.denominator=a.denominator*b.denominator;
    return result;
    }
    
    
};
int main()
{
    MixedNumber a,b;
    cin>>a>>b;
   
    cout<<a+b;
    return 0;
}