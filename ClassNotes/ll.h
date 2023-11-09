#ifndef LL_H
#define LL_H

#include <iostream>

template <typename T>
class ll
{
public:
    ll(); // Constructor
    void add(T);
    void append(T);
    friend std::ostream &operator<<(std::ostream &, const ll &);

    ~ll();                           // Destructor
    ll(const ll &);                  // Copy constructor
    const ll &operator=(const ll &); // Assignment operator

private:
    struct node
    {
        T data;
        node *next;
    };

    node *copyList(node *);
    node *deleteList(node *);
    node *append(node *, T);
    node *head;
};

template <typename T>
ll::node *ll::append(node *p, int x)
{
    if (!p)
        return new node{x, p};
    p->next = append(p->next, x);
    return p;
}

ll::node *ll::deleteList(node *p)
{
    if (p)
    {
        deleteList(p->next);
        delete p;
    }
}

ll::node *ll::copyList(node *p)
{
    if (p)
        return p;
    return new node{p->data, copyList(p->next)}; // TODO: Check if this is correct
}

ll::ll()
{
    head = nullptr;
}

void ll::add(int x)
{
    head = new node{x, nullptr};
}

std::ostream &operator<<(std::ostream &out, const ll &rhs)
{
    ll::node *p = rhs.head;
    while (p)
    {
        out << p->data << " ";
        p = p->next;
    }
    return out;
}

ll::~ll()
{
    head = deleteList(head);
}
ll::ll(const ll &rhs)
{
    head = copyList(rhs.head);
}
const ll &ll::operator=(const ll &rhs)
{
    if (this != &rhs)
    {
        head = deleteList(head);
        head = copyList(rhs.head);
    }
    return *this;
}

#endif