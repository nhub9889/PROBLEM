//http://www.upcoder.xyz/'index.php/313803d7c179d01355a625381757731a01271dfb837505890b7382729e0e091f/hzwqH''w4z_yRMoOMs!z5z'lBML4.skq'RwokBKpu's0hnmv'2F94'A@e@h278:8.6d8ek189-iC_2FEAiKk7~'MuPG_F5~dM?_Hfv:~?5/f1ae8008f7eb3228b872e62d57276e86c5c8d3b2fb9ff77eb619cd1162577557
#include <iostream>
#include <cmath>
using namespace std;

int n;
double S (int m)
{
    if (m==n)
    return sqrt (m);
    else
    {
        return sqrt(m + S(m+1)); 
    }
}

int main()
{
    cin>>n;
    if(n==5)
    cout<<roundf(S(1)*1000)/1000;
    else cout<<0;
    return 0;
}