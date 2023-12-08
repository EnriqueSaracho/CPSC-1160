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

// Print linked list
void print(node *h)
{
    for (; h; h = h->next)
    {
        std::cout << h->data << "->";
    }
    std::cout << "nullptr" << std::endl;
}

// Print linked list recursively
void printRec(node *p)
{
    if (p) // or p != nullptr
    {
        std::cout << p->data << "->";
        printRec(p->next);
        return;
    }
    std::cout << "nullptr" << std::endl;
}

// Add a new node at the beginning of the linked list
node *add(node *p, int n)
{
    p = new node{n, p};
    return p;
}

// Adds a new node to the end of an existing node list
// It modifies the existing linked list
void appendExisting(node *p, int num)
{
    if (!p->next)
    {
        p->next = new node{num, nullptr};
        return;
    }
    appendExisting(p->next, num);
}

// Adds a new node to the end of an existing node list
// It creates a new linked list with the modification
node *appendNew(node *p, int num)
{
    if (!p)
    {
        return new node{num, nullptr};
    }
    return new node{p->data, appendNew(p->next, num)};
}

// Adds a new node to the end of an existing node list
// This is the instructors function
// It modifies the existing linked list
node *append(node *p, int num)
{
    if (!p)
    {
        return new node{num, nullptr};
    }
    p->next = append(p->next, num);
    return p;
}

// Inserts a new node into a
node *insert(node *p, int num)
{
    if (!p || p->data > num)
    {
        return new node{num, p};
    }
    p->next = insert(p->next, num);
    return p;
}

// Creates a linked list out of a vector
node *vecToList(std::vector<int> &v, int i = 0)
{
    if (i >= v.size() - 1)
    {
        return new node{v[i], nullptr};
    }
    return new node{v[i], vecToList(v, i + 1)};
}

node *copyVector(std::vector<int> &v)
{
    node *p = nullptr;
    for (int i = v.size() - 1; i > -1; i--)
    {
        p = new node{v[i], p};
    }
    return p;
}

// Removes a node from a linked list
node *remove(node *p, int num)
{
    if (!p)
    {
        return p;
    }
    if (p->data == num)
    {
        node *n = p->next;
        delete p;
        return remove(n, num);
    }
    p->next = remove(p->next, num);
    return p;
}
node *removeNode(node *p, int n)
{
    if (!p)
        return p;
    if (p->data == n)
    {
        node *tmp = p;
        delete p;
        p = tmp;
        return p;
    }
    p->next = remove(p->next, n);
    return p;
}

// Deletes all nodes in a linked list
node *deleteList(node *p)
{
    while (!p)
    {
        node *tmp = p;
        p = p->next;
        delete tmp;
    }
    return nullptr;
}
// The instructors version of delete linked list
// node *deleteList(node *p)
// {
//     while (!p)
//     {
//         node *tmp = p->next;
//         delete p;
//         p = tmp;
//     }
//     return p;
// }
node *deleteLL(node *p)
{
    if (!p)
        return p;
    node *tmp = p;
    p = p->next;
    delete tmp;
    return deleteLL(p);
}

int main()
{
    // node *p = new node{3, nullptr};
    // p->next = new node{5, nullptr}; // the '->' dereferences the pointer and accesses the node's property. same as (*p).next
    // p->next->next = new node{2, nullptr};
    // p->next->next->next = new node{7, new node{4, nullptr}};
    // Linked list so far:
    // p -> 3 -> 5 -> 2 -> 7 -> 4 -> nullptr
    // std::cout << p->next->next->next->next->data << std::endl; // prints 4

    // print(p);
    // printRec(p);

    // adding a new node at the beginning of the linked list
    // p = new node{6, p};
    // p = add(p, 8);

    // adding a new node a the end of the list
    // appendExisting(p, 8);
    // p = appendNew(p, 9);
    // p = append(p, 12);

    // print(p);

    // adding a new node at the right spot in a sorted linked list
    // node *h = new node{1, new node{2, new node{5, new node{11, new node{42, nullptr}}}}};
    // print(h);
    // h = insert(h, 4);
    // print(h);

    // creating a linked list out of a vector
    // std::vector<int> v = {1, 3, 4, 5, 8, 5};
    // std::vector<int> v = {1, 3, 4, 5};
    // node *p = copyVector(v);
    // print(p);
    // node *h = vecToList(v);
    // print(h);

    // removing a node from a linked list
    // h = remove(h, 5);
    // print(h);
    // p = removeNode(p, 4);
    // print(p);

    // deleting a list
    // h = deleteList(h);
    // std::cout << "deleting..." << std::endl;
    // print(h);
    // p = deleteLL(p);
    // print(p);
}