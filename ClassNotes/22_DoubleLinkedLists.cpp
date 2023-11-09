#include <iostream>

struct node
{
    node *prev;
    int data;
    node *next;
};

node *remove(node *p, int n)
{
    if (!p)
        return p;

    node *q = p;
    while (q)
    {
        if (q != 3)
        {
            q->prev = q;
            q->next->prev = q->prev;
            delete q;
        }
        q = q->next;
    }
    return p;
}

node *insert(node *p, int n)
{
    if (!p)
        return new node{p, n, p};

    node *q;
    for (q = p; q->next && q->data < n; q = q->next)
        ;

    if (!q->prev)
    {
        p = new node{nullptr, n, p};
        p->next->next = p;
    }

    else if (!q->next && q->data < n)
    {
        q->next = new node{q, n, nullptr};
    }

    else
    {
        node *t = new node{q->prev, n, q};
        t->next->prev = t;
        t->prev->next = t;
    }

    return p;
}

int main()
{
    node *p = nullptr;
    p = new node{nullptr, 5, nullptr}; // creating the first node
    p = new node{nullptr, 3, p};       // inserting new node at the beginninng
    p->next->prev = p;

    p->next = new node{p, 4, p->next}; // inserting in the middle
    p->next->next->prev = p->next;

    node *q = p;
    while (q->next) // printing forwards
    {
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << q->data << " ";
    std::cout << std::endl;

    // while (q) // printing backwards
    // {
    //     std::cout << q->data << " ";
    //     q = q->prev;
    // }
    // std::cout << std::endl;

    // p = insert(p, 4);
    p = remove(p, 3);
    while (q->next) // printing forwards
    {
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << q->data << " ";

    return 0;
}