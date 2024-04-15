//http://www.upcoder.xyz/index.php/problems/submit/163/58558ca06305e9682af030f48bc39a4a/B_=_A_*_C
#include <iostream>
#include <cmath>
using namespace std;

struct Node
{
    int data;
    Node* pNext = nullptr;
};

Node* head = nullptr;

Node* makeNode (int n)
{
    Node *p = new Node;
    if (p!= nullptr)
    {
        p->data = n;
        p->pNext = nullptr;
    }
    return p;
}

void insertK (int n, int k)
{
    if (head == nullptr)
    {
        head = new Node;
        head -> data = n;
        head ->pNext = nullptr;
    }
    else 
    {
        Node* cur = head;
        Node* p = makeNode(n);
        if (k>1)
        {
          for (int i = 1; i< k-1 ;i++)
        {
            cur = cur -> pNext;
        }
        p->pNext= cur->pNext;
        cur->pNext = p;  
        }
        else
        {
            p->pNext = cur;
            head = p;
        }
        
    }
}

void insert (int n)
{
    if (head == nullptr)
    {
        head= makeNode(n);
    }
    else
    {
        Node *p = makeNode(n);
        Node * cur = head;
        while (cur->pNext!= nullptr)
        {
            cur = cur->pNext;
        }
        cur ->pNext = p;
    }
}

void print()
{
    Node * cur  = head;
    while (cur != nullptr)
    {
        cout<<cur->data<<" ";
        cur = cur->pNext;
    }
}

void deleteN()
{
    Node* cur = head;
    while (cur!= nullptr)
    {
         Node* temp = cur;
        cur = cur->pNext;
        delete temp;
    }
    head = nullptr;
}

void insertSort (int n)
{
    Node* p = makeNode(n);
    Node* cur = head;
    if (head==nullptr)
    {
        insert(n);
    }
    else if (n<head->data)
    {
        p ->pNext = cur;
        head = p;
    }
    else
    {
        while (cur->pNext!=nullptr&&cur->pNext->data<n)
        {
            cur= cur->pNext;
        }
        p->pNext = cur->pNext;
        cur->pNext= p; 
    }
}

bool contro5()
{
    Node *cur = head;
    if (head==nullptr||head->pNext==nullptr)
    return false;

    while (cur->pNext->pNext!=nullptr)
    {
        
        if (cur==nullptr||cur->pNext==nullptr||cur->pNext->pNext==nullptr)
        return false;
        Node* i = cur->pNext;
        while (i->pNext!=nullptr)
        {
            Node *j = i->pNext;
            while (j!=nullptr)
            {
                if (cur->data+i->data==j->data)
                {
                    return true;
                }
                j= j->pNext;
            }
            i=i->pNext;
        }
        cur= cur->pNext;
    }
    return false;
}

void contro6 ()
{
    Node *cur = head;
    int arr[100];
    int count = 0;
    int i =1;
    if (head==nullptr||head->pNext==nullptr)
    return ;
    while (cur-> pNext!=nullptr&&cur->pNext->pNext!=nullptr)
    {
        if (cur->pNext->data == cur->data*cur->pNext->pNext->data)
        {
            arr[count] = i+1;
            count++;
        }
        cur = cur ->pNext;
        i++;
    }
    if (count==0)
    {
        cout<<-1;
        return;
    }
    cout<<count <<endl;
    for (int i = 0 ;i< count ;i++)
    {
        cout<<arr[i]<<" ";
    }

}

int main()
{
    int m;
    cin>>m;
    if (m==1)
    {
        cout<<-1;
        return 0;
    }
    while (m--)
    {
        int a;
        cin>>a;
        insert(a);
    }
   
    
    contro6();
    deleteN();
    return  0;
}