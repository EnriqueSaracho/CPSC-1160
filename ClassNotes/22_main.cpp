/* Double Linked Lists
Lecture 17
09/11/2023
Notes:
    - Double linked lists
*/
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
    while (q->next)
    {
        if (q->data == n)
        {
            if (!q->prev)
            {
                q->next->prev = nullptr;
                p = p->next;
                delete q;
                q = p;
            }
            else
            {
                q->prev->next = q->next;
                q->next->prev = q->prev;
                node *tmp = q;
                q = q->next;
                delete tmp;
            }
        }
        else
        {
            q = q->next;
        }
    }
    if (q->data == n)
    {
        q->prev->next = nullptr;
        delete q;
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
        p->next->prev = p;
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

    p = new node{nullptr, 2, p};
    p->next->prev = p;

    p = new node{nullptr, -1, p};
    p->next->prev = p;

    p = insert(p, -10);
    p = insert(p, -10);
    p = insert(p, 10);
    p = insert(p, 9);
    p = insert(p, 9);
    p = remove(p, 5);
    p = remove(p, -10);

    node *q = p;
    while (q->next) // printing forwards
    {
        std::cout << q->data << " ";
        q = q->next;
    }
    std::cout << q->data << " ";
    std::cout << std::endl;

    while (q) // printing backwards
    {
        std::cout << q->data << " ";
        q = q->prev;
    }
    std::cout << std::endl;

    return 0;
}