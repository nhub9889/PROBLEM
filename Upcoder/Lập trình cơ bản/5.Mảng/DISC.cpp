//http://www.upcoder.xyz/'index.php/190b79edaaa9a611e2c1a0d5f287b6351ce9a301c74529770ea40f39b2f44be1/jytsG''y3w&xqLqNex@y43'iSLK3~rhs'qvqjlPot'uzbRlu'.:3'-g9C73-i4:6-eF5fg5.alE598@2!7587'1?l2Eb&Nnf2Ee3/1d03f9cf2092814ecc01d86a9679a932f8733c13f6b1870e4f9ec5a6ae305a7a
#include <iostream>
using namespace std;

struct Point
{
    int key;
    Point* pnext = nullptr;
};

Point* createNode(int n)
{
    Point* add = new Point;
    if (add != nullptr)
    {
        add->key = n;
    }
    return add;
}

void insertAtHead(Point* &head, int n)
{
    Point* cur = createNode(n);
    if (cur != nullptr)
    {
        cur->pnext = head;
        head = cur;
    }
}

void deleteNode(Point* &head, int n)
{
    if (head == nullptr)
        return;

    if (head->key == n)
    {
        Point* temp = head;
        head = head->pnext;
        delete temp;
        return;
    }

    Point* p = head;
    while (p->pnext != nullptr)
    {
        if (p->pnext->key == n)
        {
            Point* cur = p->pnext;
            p->pnext = p->pnext->pnext;
            delete cur;
            return;
        }
        p = p->pnext;
    }
}

void print(Point* head)
{
    Point* cur = head;
    while (cur != nullptr)
    {
        cout << cur->key << " ";
        cur = cur->pnext;
    }
    cout << endl;
}

int main()
{
    int n, m;
    Point *stack = nullptr; 
    cin >> n >> m;
    for (int i = n; i >= 1; i--)
    {
        insertAtHead(stack, i);
    }
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        deleteNode(stack, k);
        insertAtHead(stack, k);
    }
    print(stack);
    return 0;
}
