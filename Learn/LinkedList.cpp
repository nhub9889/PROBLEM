#include <iostream>
#include <malloc.h>
typedef struct node* point;
using namespace std;

//liên kết đơn kiểu dữ liệu integer
struct node
{
    int data;
    point next;
};
point getNode (int x)
{
    point p;
    p = (point)malloc(sizeof(node));
    if (p != nullptr)
    {
        p -> data = x;
        p -> next = nullptr;
    }
    return p;
}

point head =nullptr;
point tail = nullptr;

void addFirst (point &head, point &tail, int x)
{
    point r =getNode(x);
    if (head == nullptr)
        head = tail =r;
    else
    {
        r->next = head;
        head =r;
    }
}

void addLast (point &head, point &tail, int x)
{
    point r =getNode(x);
    if (head == nullptr)
        head = tail = r;
    else{
        tail -> next = r;
        tail = r;
    }
}

void addAfter (point p, int x)
{
    point q = getNode(x);
    q->next = p->next;
    p->next = q;
}

void deleteFirst (point &head)
{
    if (head==tail)
    {
        free(head);
        head=tail=nullptr;
    }
    else{
        point temp = head ->next;
        free(head);
        head = temp;
    }
}

void deleteLast (point &head, point &tail)
{
    if (head == tail)
    {
        free(head);
        head= tail =nullptr;
    }
    else
    {
       point p = head;
       while (p->next != nullptr)
       {
        p = p->next;
       }
        free(tail);
        tail = p;
        p-> next = nullptr; 
    } 
     
}

void delList(point &head)
{
    point temp = nullptr;
    while (head)
    {
        temp = head;
        head = head -> next;
        free(temp);
    }
}

int main()
{
    return 0;
}