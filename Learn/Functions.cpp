#include <cmath>
#include <math.h>
#include <stdint.h>
//hàm tìm cặp chỉ số i, j mà a[i]!=a[j] và |a[i]-a[j]| nhỏ nhất

double minPair(double a[], int n, int& Idi, int& Idj)
{
    double dmin = -1, d;
    Idj = Idi = -1;
    for (int j=n-1; j>= 1; j--)
    {
        for (int i= j-1; i>=0;i--)
        {
            if (a[i] != a[j])
            {
                d = fabs(a[i]-a[j]);
                if (dmin == -1 || dmin>d)
                {
                    Idj = j;
                    Idi = i;
                    dmin = d;
                } 
            }
        }
    }
    return dmin ;
}

double minPair (double a[], int n , int& Idi, int& Idj)
{
    double dmin = -1, d; 
    int i , j;
    Idj = Idi = -1;
    j = n;
    while (--j)
    {
        i = j;
        while (i--)
        {
            if (a[i]!= a[j])
            {
                d=fabs(a[i]-a[j]);
                if (dmin=-1||dmin>d)
                {
                    dmin = d;
                    Idi =i;
                    Idj = j;
                }
            }
        }
    }
    return dmin ;
}
//---------------------------------------------------//


//hàm tìm đoạn có tổng lớn nhất
double maxSum (double a[], int n, int& Idi, int&Idk)
{
    double maxSum= a[0];
    Idi = Idk = 0;
    for (int i=0;i<n;i++)
    {
        for (int k = i;k<n;k+=)
        {
            double s = 0;
            for (int j = i; j<=k;j++)
            {
                s+= a[j];
            }
            if (maxSum< s)
            {
                maxSum = s;
                Idi = i;
                Idk = k;
            }
        }
    }
    return maxSum;
}


double maxSum (double a[], int n, int& Idi, int& Idk)
{
    double maxS = a[0];
    Idi = Idk = 0;
    for (int i=0;i<n;i++)
    {
        double s = 0;
        for (int k=i;k<n;k++)
        {
            s+=a[k];
            if (maxS < s)
            {
                maxS = s;
                Idi = i;
                Idk = k;
            }
        }
    }
    return maxS;
}

//--------------------------------------------------------//

//tìm ước chung lớn nhất bằng thuật toán Euclide
long GreatestCommonDivisor (long a, long b)
{
    if (a < 0) 
    a =-a;
    if (b<0)
    b=-b;
    while (a!=0&&b!=0)
    {
        if(a>b)
        {
            a=a%b;
        }
        else
        {
            b=b%a;
        }
    }
    return a+b;
}

//------------------------------------------//


//-----------------chia để trị (thay a bởi a^2 và n bởi n/2) --> thuật toán nhị phân--------------------//

//tính nhanh luỹ thừa bậc cao

double qpower_n (double a, long n)
{
    double result = 1;
    while (n)
    {
        if (n%2==1)
        {
            result*=a;
        }
        a*=a;
        n/=2;
    }
}
//---------------------------------//

//tính a^n mod b

long ModPower_n(long a, long b, long n)
{
    long d =1;
    while(n--)
    {
        d = d*a%n;
    }
    return d;
}
long qModPower_n(long a, long b, long n)
{
    long d =1, p=a;
    while (n)
    {
        if (n%2==1)
        {
            d=d*p%b;
        }
        p = (p*p)%b;
        n/=2;
    }
    return d;
}
//-----------------------------------------------//


//phân tích ra thừa số nguyên tố
void Factors(long n, long primes[], long k[], int& np)
{
    if(n<0)
    {
        Factors(-n,primes,k,np);
        primes[0] = -primes[0];
        return ;
    }
    if(n<=3)
    {
        primes[0]=n;
        k[0]=1;
        np=1;
        return;
    }
    else{
        long p= 2;
        long countFactors=0;
        np =0;
        while (n>1)
        {
            if(n%p==0)
            {
                {
                primes[np]=p;
                np++;
                }
                countFactors++;
                k[np-1]=countFactors;
                n/=p;
            }
            else 
            {
                p++;
                countFactors=0;
            }
            
        }
    }
}

void qFactors (long n, long primes[], long k[], int &np)
{
    if (n<0)
    {
        qFactors(-n,primes,k,np);
        primes[0]=-primes[0];
        return ;
    }
    if (n<=3)
    {
        primes[0]=n;
        k[0]=1;
        np=1;
    }
    else{
        long p=2;
        long countFactor=0;
        double sqrt_n = sqrt(n);
        np=0;
        while (n>1)
        {
            if (n%p==0)
            {
                if (countFactor==0)
                {
                    primes[np]=p;
                    np++;
                }
                countFactor++;
                k[np-1]=countFactor;
                n/=p;
            }
            else
            {
                p++;
                countFactor = 0;
                if (q>sqrt_n)
                {
                    primes[np]=n;
                    k[np]=1;
                    np++;
                    break;
                }
            }
        }
    }
}


//------------------------------------------//

//tính xấp xỉ lượng giác
const int MaxN = 200;
const double Pi = 3.141592653;

void SinCos (double x, double& sinx, double& cosx)
{
    long n = MaxN, m;
    long k = (long)(x/2*Pi);
    double sx, cx;
    if (x<0)
    {
        k--;
    }
    x-= 2*k*Pi;
    m =n;
    while (m--)
    {
        x/=2;
    }
    sinx= x - x*x*x/6;
    cosx= 1 - x*X/2;
    while (n--)
    {
        sx = 2*sinx*cosx;
        cx = 1- 2*sinx*cosx;
        sinx = sx ;
        cosx = cx;
    }
}
// sin(x) = 2sin(x/2)cos(x/2);
// cos(x) = 1 -2sin^2(x/2);
// --> sin(x/2^(n-1)) = 2sin(x/2^(n)cos(x/2^(n)))
//     cos(x/2^(n-1)) = 1 - 2sin^2(x/2^n)
// x between 0 and 2pi, n more than 20, y = x/2^n 
// -> sin(y)~~ y - (y)^3/6
//     cos(y)~~ 1 - y^2/2
// with any x, k = (intof)x/2pi
// change x by x - 2kpi which between 2pi and 0
// sin(x) and cos(x) not change

//-----------------------------------------------//


//tích ma trận vuông

#include <iostream>
using namespace std;
const int MaxSz = 20;
typedef double MATRIX[MaxSz][MaxSz];
void matrixPrint (ostream& ou, MATRIX&A, int n)
{
    for (int i =0 ;i< n ;i++)
    {
        for (int j =0 ;j<n;j++)
        ou<<A[i][j]<<" ";
        ou<<endl;
    }
    ou<<endl;
}
void matrixProduct (MATRIX&A, MATRIX&B, MATRIX&C, int n)
{
    for (int i =0 ;i<n;i++)
    {
        for (int  j=0;j<n;j++)
        {
            C[i][j]=0;
            for (int k = 0 ; k< n ;k++)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
}
// vi du
void main()
{
    int n = 3;
    MATRIX A= {{1,2,3},{0,4,1},{1,5,6}};
    MATRIX B= {{1,0,2},{3,1,0},{4,2,5}};
    MATRIX C;
    matrixPrint(cout,A,n);
    matrixPrint(cout,B,n);
    matrixProduct(A,B,C,n);
    matrixPrint(cout,C,n);
}
//-----------------------------------------------//


