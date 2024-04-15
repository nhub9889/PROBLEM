//http://www.upcoder.xyz/'index.php/539fb0721a4c94e570a3be5168ca52b83a82ebb6908fadb122d5ea14b9abec88/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'8A-'-8e.KkciK7.988k_9Nh73lLeiLO5NCKL'Q1?Cq$unnn!wmA:n9/415c8e5e13a4fd058a69a6e3fc4f7e36afec4efa5784ed63b67e687d7f132e8b
#include  <iostream>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

class person
{
    protected:
    string name;
    int date;
    string born;
    public:
    person()
    {
        name="Ho Ten";
        date = 1000;
        born ="Que Quan";
    }
    void set (string a, int b, string c)
    {
        name = a;
        date =b;
        born =c;
    }
    string getN()
    {
        return name;
    }
    string getB()
    {
        return born;
    }
    int getD()
    {
        return date;
    }
    ~person(){};
    friend istream& operator >> (istream& in , person& a)
    {
        getline(in,a.name);
        in>>a.date;
        in.ignore();
        getline(in,a.born);
        return in;
    }
    friend ostream& operator << ( ostream& ou, person b)
    {
        ou<<"Ho Ten: "<<b.name<<endl;
        ou<<"Nam Sinh: "<<b.date<<endl;
        ou<<"Que quan: "<<b.born<<endl;
        return ou;
    }
    
};

class student : public person
{
    string cl;
    int point[1000];
    int size;
    public:
    student()
    {
        cl="Khoa";
        size = 0;
        
    }
    friend istream& operator >> (istream& in , student& a)
    {
        getline(in,a.name);
        in>>a.date;
        in.ignore();
        getline(in,a.born);
        getline (in,a.cl);
        int i =0 ;
        while (in>>a.point[i])
        {
            i++;
        }
        a.size = i;
        return in;

    }
    double sum()
    {
        double result;
        for (int i =0 ;i< this->size;i++)
        {
            result+=this->point[i];
        }
        return result/this->size;
    }
    friend ostream& operator << (ostream& ou, student b)
    {
         ou<<"Ho Ten: "<<b.name<<endl;
        ou<<"Nam Sinh: "<<b.date<<endl;
        ou<<"Que quan: "<<b.born<<endl;
        ou<<"Khoa: "<<b.cl<<endl;
        ou<<"Diem cac mon: ";
        for (int i=0;i<b.size;i++)
        {
            cout<<b.point[i]<<" ";
        }
        float dtb= b.sum();
        ou<<endl<<"Diem trung binh: "<<round(dtb*100)/100;
       return ou;
    } 
    ~student(){};
};
int main()
{
    student a;
    cin>>a;
    cout<<a;
   
    return 0;
}