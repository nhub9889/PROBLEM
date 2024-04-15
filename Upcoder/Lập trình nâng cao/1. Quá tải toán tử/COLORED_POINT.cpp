//http://www.upcoder.xyz/'index.php/8d983e7376ddcb57d4054c7978008e4a0b0c461cd5e156d7ecb50eeebf76d5d6/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'98-'O6lC46K8d!fD-b86khf_895@_d~b:bN-'UA:1s!dlA:1Sj~FQQOuFb$UWIWt0/4bb40d0c9db3b2ed53ca070b7d50a89df583624d288182ff951bb16de45b99de
#include <iostream>
#include <malloc.h>
#include <string>
using namespace std;


class COLORED_POINT
{
    int x ,y;
    string z;
    public:
    friend istream& operator >> (istream& in, COLORED_POINT &a)
    {
        in>>a.x>>a.y>>a.z;
        return in;
    }
    void change ()
    {
        
        if (this->x>this->y)
        this->z="1F00F3";
    }
    friend ostream& operator << (ostream& ou, COLORED_POINT b)
    {
        ou<<"("<<b.x<<","<<b.y<<",#"<<b.z<<")";
        return ou;
    }
    bool same()
    {
        COLORED_POINT a =*this;
        return (a.z=="5DC3A8");
    }
};
int main()
{
    int n, count =0 ;
    cin>>n;
    COLORED_POINT *arr = new COLORED_POINT[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        if (arr[i].same())
        count++;
        cout<<arr[i]<<" ";
        arr[i].change();
    }
    cout<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}