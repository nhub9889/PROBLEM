#include <iostream>
#include <sstream>
#include <string>
#include <memory.h>
#include <malloc.h>
using namespace std;

class Drink
{
    protected:
    string name;
    char size;
    int amount;
    int prizes;

    public:

    Drink()
    {
        name = "noName";
        size = 'S';
        amount  =0 ;
        prizes = 0;
    }

void read(string a, char b, int m, int p)
    {
        name =a;
        size = b;
        amount = m;
        prizes = p;
    }
    int am()
    {
        return amount;
    }

    void print()
    {
        cout<<"Ten nuoc: "<<name<<endl;
        cout<<"Size Ly: "<<size<<endl;
        cout<<"So Luong: "<<amount<<endl;
        cout<<"Gia Tien :"<<prizes<<endl;

    }

    bool operator < ( Drink b)
    {
        return this->amount<b.amount;
    }

   
};

class Topping
{
    
    friend Drink;
    protected:
    string ntop;
    int atop;
    string type;
    public:
    Topping()
{
        ntop = "noTopping";
        atop = 0;
}
    Topping (string n, int m)
    {
        ntop = n;
        atop = m;
    }
};

class Coffee: public Drink
{
    string type;
    public:
    int Money()
    {
        return amount*prizes;
    }
    
    Coffee() : Drink()
    {
        type = "coffee";
    }
    void read (string a, char b, int am, int p, string t) 
    {
        name =a;
        size = b;
        amount = am;
        prizes = p;
        type = t;
    }
    void print()
    {
        Drink :: print();
        cout<<"Loai Ca Phe: "<<type;
    }
};

class Tea: public Drink, public Topping
{
    string type;
    public:
    int Money()
    {
        return ((atop*10000)+prizes)*amount;
    }
    Tea() :Drink()
    {
        type = "Tea";
    }
    void read (string a,char b, int am, int p, string t, string topp, int aa)
    {
         name =a;
        size = b;
        amount = am;
        prizes = p;
        type= t;
        ntop = topp;
        atop= aa;
    }
    void print()
    {
        Drink :: print();
        cout<<"Loai Tra: "<<type<<endl;
        cout<<"Loai Top__: "<<ntop<<endl; 
        cout<<"So Luong Top__: "<<atop<<endl;
    }
};

Drink findBestSellers(Coffee *a[],int n, Tea *b[],int m)
{
    Drink max= *a[0];
    for (int  i = 1 ;i<n;i++)
    {
        if (max.am() < a[i]->am())
        max= *a[i];
    }
    for (int  i = 0 ;i<m;i++)
    {
        if (max.am() < b[i]->am())
        max= *b[i];
    }
    return max;
}

int calculateTotalCost(Coffee* a[],int n, Tea* b[],int m)
{
    int result = 0;
    for (int i = 0 ;i<n;i++)
    {
        result+= a[i]->Money();
    }
    for (int i = 0 ;i<m;i++)
    {
        result+= b[i]->Money();
    }
    return result;
}

void readCoffee(string &a, char &b, int &am, int &p, string &t)
{
    cin >>a>>b>>am>>p>>t;
}
void sortC(Coffee* a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*a[j] < *a[i]) { 
                swap(a[i], a[j]); 
            }
        }
    }
}

void sortT(Tea* a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*a[j] < *a[i]) { 
                swap(a[i], a[j]); 
            }
        }
    }
}

void readTea(string &a,char &b, int &am, int &p, string &t, string &topp, int &aa)
{
    cin>>a>>b>>am>>p>>t>>topp>>aa;
}
int main() {
    int m, n;
    cin >> m;
    Coffee ac[50];
    Tea bt[50];

    Coffee* acPtr[50];
    for (int i = 0; i < m; i++) {
        string a;
        char b;
        int am, p;
        string t;
        readCoffee(a, b, am, p, t);
        ac[i].read(a, b, am, p, t);
        acPtr[i] = &ac[i]; 
    }
    cin >> n;
    Tea* btPtr[50];
    for (int i = 0; i < n; i++) {
        string a;
        char b;
        int am, p;
        string t, topp;
        int aa;
        readTea(a, b, am, p, t, topp, aa);
        bt[i].read(a, b, am, p, t, topp, aa);  
        btPtr[i] = &bt[i]; 
    }

    cout << "***DANH SACH CA PHE***";
    sortC(acPtr, m);
    for (int i = 0; i < m; i++) {
        cout<<endl;
        acPtr[i]->print(); 
        cout << endl;
    }

    cout<<endl << "***DANH SACH TRA***";
    sortT(btPtr, n);
    for (int i = 0; i < n; i++) {
        cout<<endl;
        btPtr[i]->print(); 
        cout << endl;
    }

    cout<<endl<<"***MON BAN CHAY NHAT***"<<endl;
    findBestSellers(acPtr,m,btPtr,n).print();
    cout<<endl;
    cout<<"----------------------------------------"<<endl<<"Tong so tien: "<<calculateTotalCost(acPtr,m,btPtr,n)<<"VND"<<endl<<"----------------------------------------";
    return 0;
}
