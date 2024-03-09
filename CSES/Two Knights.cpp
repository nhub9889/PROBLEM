//https://cses.fi/problemset/task/1072
#include <iostream>
#include <stdio.h>
using namespace std;
#define FOR(i,a,n) for (int i =a;i<n;i++)
#define ll long long;

int KnightMoves (int n)
{
    return n*n*(n*n-1)/2;
}

int KnightKill (int n)
{

}

int main()
{
    int n;
    FOR(i,0,n)
    {
        if (i==1)
        cout<<0<<endl;
        if (i==2)
        cout<<KnightMoves(i)<<endl;
        if (i==3)
        cout<<KnightMoves(i) - KnightKill(i)<<endl;
        else cout<<KnightMoves(i) - KnightKill(i) -2 <<endl;
    }
}