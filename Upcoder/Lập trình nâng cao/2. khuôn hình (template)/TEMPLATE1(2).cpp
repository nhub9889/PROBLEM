//http://www.upcoder.xyz/'index.php/ae065776305b63e2fe9fd65e01d644308ad00009cd646a9e15e41e8ace3d4644/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'C9-'j6-67_4kf?53Mg~e?E3jh9b!5D9.j89E%27EAn1?Cn$vwoSj~Bj:1Sj~kkhn*y2E@q1?Cu$Rm1?CBk@7/3e89fd2874378c0741be2d94b5f82ec766127bb3fd6616eaf89528594ec77b6c
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

typedef struct 
{
    double x;
    double y;
}Oxy;

typedef struct
{
    double x;
    double y;
    double z;
}Oxyz;


istream& operator >> (istream& in, Oxy &a)
{
    in>>a.x>>a.y;
    return in;
}
ostream& operator << (ostream& ou, Oxy b)
{
    ou<<"("<<b.x<<","<<b.y<<")";
    return ou;
}

double operator - (Oxy b, Oxy a)
{
    double result;
    result = sqrt((a.x-b.x)*(a.x - b.x) + (a.y-b.y)*(a.y - b.y));
    return result;
} 

bool operator<(const Oxy& a, const Oxy& b) {
    if (a.x != b.x) {
        return a.x < b.x; 
    }
    return a.y < b.y;
}


istream& operator >> (istream& in, Oxyz &a)
{
    in>>a.x>>a.y>>a.z;
    return in;
}
ostream& operator << (ostream& ou, Oxyz b)
{
    ou<<"("<<b.x<<","<<b.y<<","<<b.z<<")";
    return ou;
}

double operator - (Oxyz b, Oxyz a)
{
    double result;
    result = sqrt((a.x-b.x)*(a.x - b.x) + (a.y-b.y)*(a.y - b.y) + (a.z - b.z)*(a.z-b.z));
    return result;
} 

bool operator<(const Oxyz& a, const Oxyz& b) {
    if (a.x != b.x) {
        return a.x < b.x; 
    }
   
    if (a.y!=b.y)
    return a.y < b.y;
    return a.z <b.z;
}



template <class T>
double Max(T *a, int n)
{
    int k = 0;
    double arr[1000];
    for (int i = 0 ;i < n -1;i++)
    {
        for (int j = i+1; j<n ;j++)
        {
            arr[k] = a[i] - a[j];
            k++;
        }
    }
    double max = arr[0];
    for (int  i =1 ;i < k; i++)
    {
        if (arr[i]>max)
        max =arr[i];
    }
    return max;
}
template <class T>
void sortM(T *a, int n)
{
    for (int i = 0 ; i < n-1 ;i++)
    {
        for (int j =i+1; j<n;j++)
        {
            if (a[j]<a[i])
            {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
template <class T>
void sortL(T *a, int n)
{
    for (int i = 0 ; i < n-1 ;i++)
    {
        for (int j =i+1; j<n;j++)
        {
            if (a[i]<a[j])
            {
                T temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int m = 0 , n = 0;
    Oxy arr[100];
    Oxyz brr[100];
    string input;
    while (cin>>input)
    {
        if (input=="Oxy")
        {
            cin >> arr[m];
            m++;
        }
        else
        {
            cin >> brr[n];
            n++;
        }
    }
    sortM(&arr[0], m);
    sortL(&brr[0], n);
    for (int  i = 0 ; i< m ;i++)
    {
        cout<< arr[i] <<" ";
    }
    cout<<endl;
    for (int  i = 0 ;i < n;i++)
    {
        cout << brr[i] <<" ";
    }
    cout<<endl;
    cout<<roundf(Max(&arr[0],m)*1000)/1000;
    cout<<endl<<roundf(Max(&brr[0],n)*1000)/1000;
    return 0;
    
}