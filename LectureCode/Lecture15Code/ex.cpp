#include <iostream>
#include <vector>

struct node
{
    int data;
    node *next;
};

// function should return the new head of the list
node *rev_inplace(node *p)
{
    if (!p || !p->next)
    {
        return p;
    }
    node *curr = p;
    node *prev = nullptr;
    node *next = curr->next;
    while (next)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;
    return curr;
}

node *i_copy_list(node *p)
{
    if (!p)
    {
        return p;
    }
    node *h = new node{p->data, nullptr};
    node *t = h;
    p = p->next;
    while (p)
    {
        t->next = new node{p->data, nullptr};
        t = t->next;
        p = p->next;
    }
    return h;
}

node *copy_list(node *p)
{
    if (!p)
    {
        return p;
    }
    return new node{p->data, copy_list(p->next)};
}

node *rev_copy_list(node *p)
{
    node *q = nullptr;
    while (p)
    {
        q = new node{p->data, q};
        p = p->next;
    }
    return q;
}

void print(node *p)
{
    for (; p; p = p->next)
    {
        std::cout << p->data << " ";
    }
    std::cout << std::endl;
}

node *r_append(int x, node *p)
{
    if (!p)
    {
        return new node{x, nullptr};
    }
    p->next = r_append(x, p->next);
    return p;
}

node *insert(int x, node *p)
{
    if (!p || p->data > x)
    {
        return new node{x, p};
    }
    p->next = insert(x, p->next);
    return p;
}
node *append(int x, node *p)
{
    node *h = p;
    if (!p)
    {
        return new node{x, p};
    }
    while (p->next)
    {
        p = p->next;
    }
    p->next = new node{x, nullptr};
    return h;
}
node *vect_2_ll(const std::vector<int> &v)
{
    node *h = nullptr;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        h = new node{v[i], h};
    }
    return h;
}

node *r_vect_2_ll(const std::vector<int> &v, unsigned i = 0)
{
    if (i == v.size())
    {
        return nullptr;
    }
    return new node{v[i], r_vect_2_ll(v, i + 1)};
}

node *delete_list(node *p)
{
    while (p)
    {
        node *tmp = p->next;
        delete p;
        p = tmp;
    }
    return nullptr;
}

// should return the head of the new list
node *sel_sort(node *p)
{
    for (node *i = p; i; i = i->next)
    {
        node *min = i;
        for (node *j = i->next; j; j = j->next)
        {
            if (j->data < min->data)
            {
                min = j;
            }
        }
        int tmp = i->data;
        i->data = min->data;
        min->data = tmp;
    }

    return p;
}

int main()
{
    node *h = new node{1, new node{2, new node{4, new node{7, new node{10, nullptr}}}}};
    print(h);
    h = r_append(17, h);
    print(h);
    node *h2 = nullptr;
    h2 = insert(3, h2);
    print(h2);
    h = insert(6, h);
    print(h);
    // std::vector<int> v = {5,12,4,12,78,43,9,10};
    // node* p = r_vect_2_ll(v);
    // print(p);

    // p = sel_sort(p);
    // print(p);
    // return 0;
}