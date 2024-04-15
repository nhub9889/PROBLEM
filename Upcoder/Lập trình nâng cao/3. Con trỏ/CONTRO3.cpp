//http://www.upcoder.xyz/'index.php/39918bc40e54aef4443646d72d1bfd2527d7276305cb4ec565150ebc5949c220/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'C69'@e?Mf6Ch6@_8.8N0.6K-hN5@57LA89lK%27uj:1R!qlA:1S!uEA:_3C2S@01?C~xt:1*N0/67d2a9cfe2e93ad4d03f624af643d512b18c0f9427b3f6381d3be515484f68ac
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

int main()
{
    int m ,n ,k;
    cin>>m>>n>>k;
    cout<<m+1<<endl;
    while (m--)
    {
        int a;
        cin>>a;
        insert(a);
    }
    insertK(n,k);
    print();
    deleteN();
    return  0;
}