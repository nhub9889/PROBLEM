//http://www.upcoder.xyz/'index.php/85f72160f79aaa4892084c561b006ca069d926c6b695fd4a15188ef445bc6165/lvypJ''0y3.0SdSKOr&0z5'nnOMy!Rmp'SsSgpeRv'wwjmBw'E89'FEgib_e_Md66-8-fK~-h7NL4ihM6.5A~'PHXC2EPd_HC2FJ&MLQ2/e8d97c3e6a56714d33cec9d7437a8e6c817dbd6d9554548ebbd194ed16e794eb
#include <iostream>
#include <fstream>
#include <cstdlib>
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

void contro7(ofstream& out)
{
    int q = 10000;
    int m = 0;
    Node* cur = head;
    while (cur->pNext != nullptr)
    {
        Node* p = cur->pNext;
        while (p != nullptr)
        {
            if (q > abs(cur->data - p->data))
            {
                q = abs(cur->data - p->data);
                m = 0;
            }
            if (q == abs(cur->data - p->data))
                m++;
            p = p->pNext;
        }
        cur = cur->pNext;
    }
    out << m << " " << q << endl;
    cur = head;
    while (cur->pNext != nullptr)
    {
        Node* p = cur->pNext;
        while (p != nullptr)
        {
            if (q == abs(cur->data - p->data))
            {
                if (cur->data < p->data)
                {
                    out << "(" << cur->data << ", " << p->data << ") ";
                }
                else
                {
                    out << "(" << p->data << ", " << cur->data << ") ";
                }
            }
            p = p->pNext;
        }
        cur = cur->pNext;
    }
}

int main()
{
    int n;
    ifstream in ("CONTRO.inp");
    ofstream out ("CONTRO.out");
    in>>n;
    
    while (n--)
    {
        int data;
        in>>data;
        insert(data);
    }
    contro7(out);
    deleteN();
    in.close();
    out.close();
    return 0;
}