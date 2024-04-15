#include <stdio.h>
#include <stdarg.h>

auto FindMax (int n, auto first , ...)
{
    auto val = first , largest = first;
    va_list vl;
    va_start (vl, first);
    for (int i =1; i<n;i++)
    {
        val = va_arg(vl, decltype(first));
        if (largest < val)
            largest = val;
    }
    va_end(vl);
    return largest;
}

//------thử-----//

int main(int argc, char** argv)
{
    int m = FindMax(7, 702, 422, 632, 834, 892, 123 ,7678);
    printf ("The largest int valure is : %d\n",m);

    double t = FindMax(5, 4335.54, 4646.66, 4454.0, 45454,5454.33);
    printf ("%d The largest double value is : \n",t);

    return 0;
}

//------------------------------------------------------------------------//

#include <vector>
#include <iostream>
using namespace std;
auto FindMax(vector<auto>& a)
{
    auto largest = a.front();
    for (auto& v: a)
    {
        if (largest < v)
            largest = v;
    }
    return largest;
}

//sử dụng initializer_list thay cho vector
auto FindMax (const initializer_list<auto>& L)
{
    auto propotype = *(L.begin());
    vector <decltype(propotype)> a(L); // a{L}
    return FindMax(a);
}

//sử dụng template
template <class T>
T FindMaxT(initializer_list <T> L)
{
    vector <T> a{L};
    return FindMax(a);
}


//--------thử---------//
int main( int argc, char** argv)
{
    int m = FindMax({7398,43534,4534,35454,2323});
    cout<<"The largest value is:"<<t<<endl;

    double t = FindMax({2742.3432,23432.23423,324432.5454,3443.0});
    cout<<"The largest double value is:" << t<<endl;

    vector < double> a{326423.3432,4234.234234,3424.4575,76787.768876,6786};
    t=FindMax(a);
    cout<<"The 2nd largest double value is:"<< t <<endl;
    return 0;
}