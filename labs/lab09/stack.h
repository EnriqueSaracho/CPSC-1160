#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class stack
{
public:
    stack();
    void push(T);
    T pop();
    T peek();
    bool isEmpty();

private:
    struct node
    {
        T data;
        node *next;
    };
    node *top;
};

template <typename T>
stack<T>::stack()
{
    top = nullptr;
}
template <typename T>
void stack<T>::push(T x)
{
    top = new node{x, top};
}
template <typename T>
T stack<T>::pop()
{
    T val = peek();
    node *tmp = top;
    top = top->next;
    delete tmp;
    return val;
}
template <typename T>
T stack<T>::peek()
{
    if (isEmpty())
    {
        std::cerr << "STACK IS EMPTY";
        exit(1);
    }
    return top->data;
}
template <typename T>
bool stack<T>::isEmpty()
{
    return !top;
}

#endif