//http://www.upcoder.xyz/'index.php/69ea157680b180c073f67737ce2723364a8c815587e1a39c4ce33806a5e84701/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'94-'?8993LL82ki99gM7Nh8L6.e!5f7L~6~_%27FqR_zu2EA&-*Pjwunnm!Qvkqe0/fae3318666e1590908476782f320b4df90bcaf11a1de235853d080dc36c305f4
#include <iostream>
#include <cmath>
#include <vector>
#include <malloc.h>
using namespace std;

bool binary (int n)
{
    if (n==2||n==3)
    return true;
    else if (n<2||n%2==0)
    return false;
    else 
    {
        
        for (int i = 3; i<= sqrt(n); i+=2)
        {
            if (n%i==0)
            return false;
        }
    }
    return true;
}

int main()
{
    int n , m ;
    cin>>n>>m;
    for (int i = n; i<= m; i++)
    {
        if (binary(i))
        cout<<i<<" ";
    }
    return 0;
}