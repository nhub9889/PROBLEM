
//http://www.upcoder.xyz/'index.php/a7cf9bd46555eb67cff9074bce981dc91843afd7e23990156ee753958cd4a6ef/nwuTF''4zx!wrcrLKv~4y7'jqKOx&SiT'rrrhmNBx'yxfpky'?_A%276O1Pi797OcFf6Nb74962647ckMAEbj4?%272EA:1r!iEAq_nC2p@:1i!ulA:1N6/fddbc0905923a90a4707eb70668800f8318c84bb3b65201fa932ca60e1644c58
#include <iostream>
#include <cmath>
using namespace std;

class DaThuc
{
    
    int def;
    int arr[10000];
    public:
    friend istream& operator >> (istream& in, DaThuc &a)
    {
        in>>a.def;
        for (int i=a.def;i>=0;i--)
        {
            in>>a.arr[i];
        }
        return in;
    }
    friend ostream& operator << (ostream& ou, DaThuc b)
    {
        if (b.def < 0)
        cout<<0;
        else for (int i = b.def; i>=0 ;i--)
        {
            if (i==b.def&&i!=0)
            {
                if (b.arr[i]>1||(b.arr[i]<0&&b.arr[i]!=-1))
                {
                    cout<<b.arr[i];
                }
                if (b.arr[i]==-1)
                {
                    cout<<"-";
                }
                if (i>1)
                {
                    cout<<"x^"<<i;
                    continue;
                }
                if (i==1)
                {
                    cout<<"x";
                    continue;
                }
               
               
                
            }
            else if (b.arr[i]>1&&i!=0)
            {
                cout<<"+"<<b.arr[i];
                if (i>1)
                {
                    cout<<"x^"<<i;
                    continue;
                }
                if (i==1)
                {
                    cout<<"x";
                    continue;
                }
               
            }
            
            else if (b.arr[i]<0&&i!=0&&b.arr[i]!=-1)
            {
                cout<<b.arr[i];
                if (i>1)
                {
                    cout<<"x^"<<i;
                    continue;
                }
                if (i==1)
                {
                    cout<<"x";
                    continue;
                }
               
            }

            else if (b.arr[i]==1&&i!=0)
            {
                if (i>1)
                {
                    cout<<"+x^"<<i;
                    continue;
                }
                if (i==1)
                {
                    cout<<"+x";
                    continue;
                }
            }
            else if (b.arr[i]==-1&&i!=0)
            {
                
                 if (i>1)
                {
                    cout<<"-x^"<<i;
                    continue;
                }
                if (i==1)
                {
                    cout<<"-x";
                    continue;
                }
            }

            else if (i==0&&i!=b.def)
            {
                if (b.arr[i]>0)
                cout<<"+"<<b.arr[i];
                if (b.arr[i]<0)
                cout<<b.arr[i];
            }
            else if (i==0 && i== b.def)
            {
                if (b.arr[i]!= 0)
                cout<<b.arr[i];
            }
        }
        return ou;
    }

    DaThuc DaoHam()
    {
        DaThuc b =*this;
        for (int i = 0;i < b.def ;i++)
        {
           b.arr[i] = b.arr[i+1] * (i+1);
        }

        b.def--;
        return b;
    }
};


int main()
{ 
    DaThuc a;
    cin>>a;
    cout<<a<<endl;
    cout<<a.DaoHam()<<endl;
    cout<<(a.DaoHam()).DaoHam()<<endl;
}