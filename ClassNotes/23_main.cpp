/* Circular Linked Lists
Lecture 17
*/
#include <iostream>

struct node
{
    node *prev;
    int data;
    node *next;
};

void remove(int x, node *d)
{
    node *q = d->next;
    while (q != d)
    {
        if (q->data == x)
        {
            q->prev->next = q->next;
            q->next->prev = q->prev;
            node *tmp = q;
            q = q->next;
            delete tmp;
        }
        else
        {
            q = q->next;
        }
    }
}

void insert(int x, node *d)
{
    node *q = d->next;
    for (; q != d && q->data < x; q = q->next)
        ;
    node *t = new node{q->prev, x, q};
    t->next->prev = t;
    t->prev->next = t;
}

void add(node *d, int x)
{
    node *t = new node{d, x, d->next};
    t->next->prev = t;
    t->prev->next = t;
}

void print(node *d)
{
    node *p = d->next;
    while (p != d)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

int main()
{
    node *dummy = new node;
    dummy->next = dummy;
    dummy->prev = dummy;
    add(dummy, 6);
    add(dummy, 3);
    add(dummy, 1);
    insert(5, dummy);
    insert(-5, dummy);
    insert(15, dummy);
    insert(15, dummy);
    remove(-5, dummy);
    remove(15, dummy);
    print(dummy);
    return 0;
}