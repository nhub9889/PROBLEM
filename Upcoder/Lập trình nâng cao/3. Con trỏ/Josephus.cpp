//http://www.upcoder.xyz/'index.php/39eace27fd2ead9b5ed29bd4c191b14279c0412214a8e7dff1982d3248f933d5/kuxRI''zx0~zpNReNt$x64'moNe5@qlR'pxRfoLqs'vviBnt'-3'ej5NCf~KM18C5gLke_K4MC.7k.98Lj3~'cSuOpnxt7/c214ac0ed2d4a15c9300cda7cb4db27a6de3c8705490670e5d7bcee92c23a39d
#include <iostream>

using namespace std;



struct Node
{
    int data;
    Node* pNext;
};
Node* head = nullptr;
Node* tail = nullptr;
Node* makeNode (int n)
{
    Node* p = new Node;
    if (p!=nullptr)
    {
        p->data = n;
        p->pNext = nullptr;
    }
    return p;
}

void insert (int n)
{
    if (head == nullptr)
    {
        head = makeNode(n);
    }
    else if (tail == nullptr)
    {
        tail = makeNode (n);
        head->pNext = tail;
        tail->pNext = head;
    }
    else
    {
        Node *p = makeNode(n);
        p->pNext = head;
        tail->pNext = p;
        tail = p;
    }
}

int del (int n, Node* &next)
{
    Node* cur = next;
    if (head==nullptr||tail==nullptr)
    return -1;
    while (n--)
    {
        cur = cur->pNext;
    }
    next = cur->pNext->pNext;
    int res = cur->pNext->data;
    if (cur->pNext == head)
    {
        Node* p = cur->pNext;
        cur->pNext = head->pNext;
    }
    else if (cur->pNext == tail)
    {
        Node* p = cur->pNext;
        cur->pNext = tail->pNext;
    }
    else
    {
        Node* p = cur->pNext;
        cur->pNext = cur->pNext->pNext;
    }
    return res;

}
int main()
{
    int m , n ; 
    
    cin>>m>>n;
    for (int i = 1 ; i<= m ;i++)
    {
        insert(i);
    }
    Node* next = head;
    while (m--)
    {
        cout<<del(n-2,next)<<" ";
    }
    return 0;
}
