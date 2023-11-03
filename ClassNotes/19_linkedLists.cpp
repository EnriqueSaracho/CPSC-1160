#include <iostream>

struct node
{
    int data;
    node *next;
};

void print(node *h)
{
    for (; h; h = h->next)
    {
        std::cout << h->data << " ";
    }
    std::cout << std::endl;
}

int main()
{
    node *p = new node{3, nullptr};
    p->next = new node{5, nullptr};
    p->next->next = new node{2, nullptr};
    p->next->next->next = new node{7, new node{4, nullptr}};
    // Linked list so fat:
    // p -> 3 -> 5 -> 2 -> 7 -> 4 -> nullptr
    // std::cout << p->next->next->next->next->data << std::endl; // prints 4

    print(p);
}