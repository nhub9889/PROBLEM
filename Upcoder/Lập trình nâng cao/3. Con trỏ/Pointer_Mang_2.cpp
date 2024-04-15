//http://www.upcoder.xyz/'index.php/c681d8ecef92a7ad05426c2b4a32b9e31fc3c49d0d4ec6dfb9e818d948565d84/hzwqH''w4z_yRMoOMs!z5z'lBML4.skq'RwokBKpu's0hnmv'698'L7-0-i2ih?bOE-g89e__e8h7bOKgiC.0%27?pq@yr?C2$_&M?C2qi&2*KimA:105/6f902ab508ef1b3f18e35e2636fc8c2832a8e2434256b16eb9589b4cd03f5afa
#include <iostream>
#include <cmath>
#include <vector>
#include <malloc.h>
using namespace std;

int main()
{
    int n ; 
    cin>>n;
    int **arr = new int*[n];
    for (int i = 0 ; i< n ;i++)
    {
        arr[i] = new int[n];
    }


    for (int i = 0 ;i<n; i++)
    {
        for (int  j= 0 ; j<n; j++)
        if (i==j)
        arr[i][j]=1;
        else arr[i][j]=0;
    }
    for (int  i = 0 ; i< n ;i++)
    {
        for (int  j = 0 ;j<n;j++)
        cout<<arr[i][j]<<" ";
        cout<<endl;
    }
   for (int  i = 0 ;i < n ;i++)
   {
    delete arr[i];
   }
    return 0;
}