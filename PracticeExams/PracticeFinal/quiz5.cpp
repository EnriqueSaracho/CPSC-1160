#include <iostream>

struct node
{
    int data;
    node *next;
};

void print(node *p)
{
    for (; p; p = p->next)
    {
        std::cout << p->data << " ";
    }
}

node *odd_even(node *);

int main()
{
    node *p = new node{1, new node{3, new node{5, new node{6, new node{8, new node{9, nullptr}}}}}};
    p = odd_even(p);

    print(p);
}

node *odd_even(node *p)
{
    node *h = p;
    for (; p; p = p->next)
    {
        if (p->data % 2 == 0)
        {
            p->next = new node{p->data, p->next};
            p = p->next->next;
        }
        else
        {
            node *tmp = p;
            p = p->next;
            if (p == h)
                h = h->next;
            delete tmp;
        }
    }
    return h;
}