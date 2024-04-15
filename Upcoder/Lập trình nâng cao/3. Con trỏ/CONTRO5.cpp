//http://www.upcoder.xyz/index.php/problems/submit/162/738154fc78448ee40fd819fef14802a1/A_=_B_+_C
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

int main()
{
    int m;
    cin>>m;
    while (m--)
    {
        int a;
        cin>>a;
        insertSort(a);
    }
   
    
    if (contro5()==true)
    cout<<"YES";
    else cout<<"NO";
    deleteN();
    return  0;
}