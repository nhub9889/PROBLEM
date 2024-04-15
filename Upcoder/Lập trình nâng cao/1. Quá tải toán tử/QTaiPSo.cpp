//http://www.upcoder.xyz/'index.php/973af3112245a64c80acb8afd6199e936785eb9cec05ea847451e118dcc10a78/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'92'C75P8-~e~0F6Agh72i85L7-8@7d_78c@'UyA:_zC2Ek&pnC2q@x1?C7/94b73308f474a8d7bad1b710c6b77b6c3a7734ece227239a4408d688db9cce4b
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
    bool operator == (fraction b)
    {
        return this->denominator==b.denominator&&this->numerator==b.numerator;
    }
    fraction operator + (fraction b)
    {
        fraction result;
        result.numerator=this->numerator*b.denominator+b.numerator*this->denominator;
        result.denominator=this->denominator*b.denominator;
        return result;
    }
};


int main()
{
    fraction a,b;
    cin>>a>>b;
    fraction sum = a+b;
    sum.Reduce();
    cout<<sum;
    return 0;
}