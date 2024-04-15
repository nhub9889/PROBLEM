//http://www.upcoder.xyz/'index.php/244740a80879aa5f589f8276f4de0217cb3be73fea4bd97ada5c8b13b682b3b5/ixvr:''x0y$usKpMLw.530'kRdP0_Tjr'supinOmy'tygqiz'295'8!6gg47el_9~47a!78ihhf9hKM-kdk69's:1R!Nmo!Mi01/f4c8f67eb45a2573e997f0d0240787efcc8d93a569e8e1a7fcbbe51c15c73b88
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[10000];
    int* placemax = new int[100];
    int* placemin = new int[100];
   
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     int max = arr[0] , min = arr[0];
    for (int i =1;i<n;i++)
    {
        if (max<arr[i])
        max= arr[i];
        if (min>arr[i])
        min=arr[i];
    }

    int x =0 ,y=0;
    for (int i=0;i<n;i++)
    {
        if (arr[i]==max)
        {
            placemax[x++] = i;

        }
        if (arr[i]==min)
        {
            placemin[y++] = i;
        }
    }
    cout<<max<<endl;
  
    for (int i =0 ;i< x;i++)
    {
        cout<< placemax[i] +1<<" ";
    }
    cout<<endl<<min<<endl;
    for (int i=0;i<y;i++)
    {
        cout<< placemin[i]+1<<" ";
    }
    return 0;

}