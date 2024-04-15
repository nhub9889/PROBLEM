//http://www.upcoder.xyz/'index.php/0228a5cf12ea2c7592cb446ec5fca9b3944f1c50f6a73e56d085ba260a0f6721/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'-6'7f.K4i7-2-MgE-@aOi8-g-d_58ML9d_M'WjhnvRA8/c252ed984583cd23db9ccf9d5fd5b99789d291ee3d87256ea7c91b510ff7f720
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

class Arfraction : public fraction
{
    int n;
    fraction arr[1000];
    public:
    Arfraction()
    {
        n = 0;
    }
    fraction operator [] (int n)
    {
        return arr[n];
    };
    friend istream& operator >> (istream& in , Arfraction &a)
    {
        fraction b;
        while (in>>b)
        {
            a.arr[a.n]=b;
            a.n++;
        }
        return in;
    }
    friend ostream& operator << (ostream& ou, Arfraction b)
    {
        for (int i =0 ;i<b.n;i++)
        {
            cout<<b.arr[i]<<" ";
        }
        return ou;
    }
    fraction Sum()
    {
        fraction sum;
        for (int i = 0;i<n;i++)
        {
            sum = sum + arr[i];
        }
        return sum;
    }
};
int main()
{
    Arfraction n;
    cin>>n;
    fraction sum = n.Sum();
    sum.Reduce();
    cout<<sum;
    return 0;
}