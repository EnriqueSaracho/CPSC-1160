#ifndef LL_H
#define LL_H
#include <iostream>

template <typename T>
class ll
{
public:
    ll();                            // default constructor
    ll(const ll &);                  // copy constructor
    ~ll();                           // deconstructor
    const ll &operator=(const ll &); // asignment operator
    void add(T);
    void append(T);
    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const ll<U> &);

private:
    struct node
    {
        T data;
        node *next;
    };
    node *head;

    node *copyList(node *);
    node *deleteList(node *);
    node *append(node *, T);
};

template <typename T>
ll<T>::ll()
{
    head = nullptr;
}

template <typename T>
ll<T>::ll(const ll &rhs)
{
    head = copyList(rhs.head);
}

template <typename T>
ll<T>::~ll()
{
    head = deleteList(head);
}

template <typename T>
const ll<T> &ll<T>::operator=(const ll &rhs)
{
    if (this != &rhs)
    {
        head = deleteList(head);
        head = copyList(rhs.head);
    }
    return *this;
}

template <typename T>
void ll<T>::add(T x)
{
    head = new node{x, head};
}

template <typename T>
void ll<T>::append(T x)
{
    head = append(head, x);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const ll<T> &rhs)
{
    typename ll<T>::node *p = rhs.head;
    while (p)
    {
        out << p->data << " ";
        p = p->next;
    }
    return out;
}

template <typename T>
typename ll<T>::node *ll<T>::copyList(node *p)
{
    if (!p)
        return p;
    return new node{p->data, copyList(p->next)};
}

template <typename T>
typename ll<T>::node *ll<T>::deleteList(node *p)
{
    if (p)
    {
        deleteList(p->next);
        delete p;
    }
    return nullptr;
}

template <typename T>
typename ll<T>::node *ll<T>::append(node *p, T x)
{
    if (!p)
    {
        return new node{x, p};
    }
    p->next = append(p->next, x);
    return p;
}

#endif