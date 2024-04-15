//http://www.upcoder.xyz/'index.php/38a02f3aaff900f693152a42a0a41d0768c2f2cab664b391a6942158a08d63cf/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'A@38'e_A8bkh2N8k0~i9..@8kC6-9?1Oh5i-7%27Hk2EA:nm!2!@Yu?C~uA:1B@~RA:i*C3/598ec44b17b054aae5ff247c1407dae5d21d79b9ea2853acd67398cf89212b06
#include <iostream>
 using namespace std;


class fraction
{
    int numerator;
    int denominator;
    public:
    fraction ()
    {
        numerator = 1;
        denominator = 1;
    }

    friend istream& operator >> (istream& in , fraction& n)
    {
        in>>n.numerator>>n.denominator;
        return in;
    }

    friend ostream& operator << (ostream& ou, const fraction n)
    {
        if (n.numerator ==0)
        ou<<0;
        if (n.denominator<0)
        ou<<-n.numerator<<"/"<<-n.denominator;
        else ou<<n.numerator<<"/"<<n.denominator;
        return ou;

        
    }

    void Reduce ()
    {
        int m=abs(numerator) , n =abs(denominator);
        while (m!=n)
        {
            if (m>n)
            m-=n;
            if (m<n)
            n-=m;
        }
        if (denominator<0)
        {
            numerator= -numerator;
        denominator=-denominator;
        }
        numerator/=m;
        denominator/=m;
        
    }

    const fraction operator+ (const fraction b)
    {
        fraction a = *this;
        fraction result;
        result.numerator = a.numerator*b.denominator + b.numerator*a.denominator;
        result.denominator = a.numerator*b.denominator;
        return result;
    }

    const fraction operator + (const int b)
    {
        fraction a =*this;
        fraction result;
        result.numerator=b*a.denominator + a.numerator;
        result.denominator = a.denominator;
        return result;
    }

    fraction cover (int b)
    {
        fraction result;
        result.numerator = b;
        result.denominator =1;
        return result;
    }
    int num()
    {
        return numerator;
    }
    int den()
    {
        return denominator;
    }

};



class complex 
{
    int re;
    int im;
    public:
    complex()
    {
        re = 0;
        im = 0;
    }
    friend istream& operator >> (istream& in , complex &n)
    {
        in>>n.re>>n.im;
        return in;
    }
    friend ostream& operator<< (ostream& ou, const complex n)
    {
        if (n.re==0&&n.im==0)
        {
            ou<<0;
            return ou;
        }
        else if (n.re==0)
        
           {
                if (n.im==1)
                ou<<"i";
                else if (n.im==-1)
                ou<<"-"<<"i";
                else if (n.im==0)
                ou<<0;
                else ou<<n.im<<"i";
                return ou;
            }
        else if (n.im==0)
            {
                ou<<n.re;
                return ou;
            }
       else 
            { 
                ou<<n.re;
                if (n.im>0&&n.im!=1)
                    ou<<"+"<<n.im<<"i";
                else if (n.im==1)
                    ou<<"+"<<"i";
                else if (n.im==-1)
                    ou<<"-"<<"i";
                else if (n.im<0)
                    ou<<n.im<<"i";
                return ou;
            
            }
    }
   
    const complex operator + ( complex b)
    {
        complex a = *this;
        complex result ;
        result.re = a.re + b.re;
        result.im = a.im +b.im;
        return result;
    }
    const complex operator + (fraction b)
    {
      
        complex a = *this;
        complex result;
        result.re = b.num() + a.re;
        result.im= a.im + b.den();
      
        return result;
    }
    const complex operator + (const int b)
    {
        complex a= *this;
        complex result ;
        result.re = a.re +b;
        result.im=a.im;
        return result;
    }
    
};
int main()
{
    char m;
    int b;
    fraction c;
    complex d;
    complex a;
    cin>>a;
    cin>>m;
    cout<<a<<endl;
    
    if (m=='i')
    {
        cin>>b;
        cout<<b<<endl;
        cout<<a+b;

    }
    if (m=='z')
    {
        cin>>d;
        cout<<d<<endl;
        cout<<a+d;
    } 
    if (m=='p')
    {
        cin>>c;
        c.Reduce();
        cout<<c<<endl;
       cout<<a+c;
        
    }
    return 0;
    
}