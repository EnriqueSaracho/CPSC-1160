/* Linked Lists
Lecture 15
*/
#include <iostream>
#include <vector>

struct node
{
    int data;
    node *next;
};

// Prints a linked list
void print(node *p)
{
    for (; p; p = p->next)
    {
        std::cout << p->data << " ";
    }
}

// Appends a new node at the end of the list
node *append(node *p, int n)
{
    if (!p)
    {
        return new node{n, nullptr};
    }
    p = append(p->next, n);
    return p;
}

// Returns the copy of a linked list
node *iterative_copy_list(node *p)
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

// Returns the copy of a linked list
node *copy_list(node *p)
{
    if (!p)
    {
        return p;
    }
    return new node{p->data, copy_list(p->next)};
}

// Returns a reversed copy of a linked list.
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

// Returns the modified reversed list.
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

// Should return the head of the new list
// try making one without changing the values of the nodes
node *selection_sort(node *p)
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
    h = append(h, 17);
    print(h);
    // std::vector<int> v = {5, 12, 4, 12, 78, 43, 9, 10};
    // node *p = r_vect_2_11(v);
    // print(p);
    // p = sel_sort(p);
    // print(p);
    return 0;
}