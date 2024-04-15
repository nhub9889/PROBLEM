//https://codeforces.com/contest/770/problem/B
#include <bits/stdc++.h>
using namespace std;

long long sumOfDigits(long long a)
{
    long long sum = 0;
    while (a)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

long long findMax(long long x)
{

    long long b = 1, ans = x;

    while (x)
    {

        long long cur = (x - 1) * b + (b - 1);

        if (sumOfDigits(cur) > sumOfDigits(ans) ||
            (sumOfDigits(cur) == sumOfDigits(ans) &&
             cur > ans))
            ans = cur;

        x /= 10;
        b *= 10;
    }

    return ans;
}

int main()
{
    long long n;
    cin>>n;
    cout << findMax(n);
    return 0;
}
