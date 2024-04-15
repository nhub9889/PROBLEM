//http://www.upcoder.xyz/'index.php/5d85786d6458e5afbc3c6d08381ae092d99742e741bf8538d00f7e2cd2734763/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'A85'55NL~bFM59e~a897_689lfAj4889_AE7'S?C2E@Mo?C~Lj:1?C~wA:1?!dlA:1?p~oL:13/dc98c3a83300584cc098d4f014c7238bb58b31fee8faaf946a7efb03f02c11cc
#include <iostream>
#include <cmath>
#include <string>
using namespace std;
class SOCHANLE
{
    string n;
    public:
    friend istream& operator >> ( istream& in ,SOCHANLE &a)
    {
        in>>a.n;
        return in;
    }

    
    int tongThanhPhan(SOCHANLE a, int b=0)
    {
        int result = 0;
        if (b==0)
        {
            for (int i=0;i<a.n.size();i++)
        {
            if (i%2==0)
            {
                int x = (int)(a.n[i])-48;
            
               
                result+=x;
            }
            
        }
       
        }
        else
        {
 for (int i=0;i<a.n.size();i++)
        {
            if (i%2!=0)
            {
                int x = (int)(a.n[i]) - 48;
                result+=x;
            }
        }

        }
         return result;
    }
    int CHUSOCHAN()
    {
       int result=0;
        for (int i=0;i<this->n.size();i++)
        {
            if (i%2==0)
            result=result*10+(int)this->n[i] - 48;
        }
        return result;
    }
    friend ostream& operator << (ostream& ou , SOCHANLE b)
    {
        
        ou<<b.CHUSOCHAN();
        return ou;
    }
    bool operator < (SOCHANLE b)
    {
        return this->CHUSOCHAN()<b.CHUSOCHAN();
    }
};
int main()
{
    SOCHANLE a,b;
    cin>>a>>b;
    int n;
    cin>>n;
    cout<<a.CHUSOCHAN()<<endl<<b.CHUSOCHAN()<<endl;
    if (a<b)
    cout<<"true";
    else cout<<"false";
    cout<<endl;
    cout<<a.tongThanhPhan(a,n)<<endl<<b.tongThanhPhan(b,n)<<endl;
}