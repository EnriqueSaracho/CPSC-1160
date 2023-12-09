#include <iostream>

struct node
{
    int data;
    node *next;
};

void print(node *p)
{
    std::cout << "[ ";
    for (; p; p = p->next)
        std::cout << p->data << " ";
    std::cout << "]" << std::endl;
    return;
}

bool propSubset(node *p, node *q)
{
    int matches = 0,
        pCount = 0,
        qCount = 0;
    while (p && q)
    {
        if (p->data == q->data)
        {
            matches++;
            pCount++;
            qCount++;
            p = p->next;
            q = q->next;
        }
        else
        {
            qCount++;
            q = q->next;
        }
    }

    if (p)
        return false;

    while (q)
    {
        qCount++;
        q = q->next;
    }

    if (matches == pCount)
        if (pCount < qCount)
            return true;
        else
            return false;
    return false;
}

int main()
{
    // Test 1
    // node *p = new node{2, new node{3, nullptr}};
    // node *q = new node{2, new node{3, new node{5, nullptr}}};

    // Test 2
    // node *p = new node{2, new node{4, nullptr}};
    // node *q = new node{1, new node{2, new node{3, new node{4, nullptr}}}};

    // Test 3
    // node *p = new node{2, new node{3, new node{4, nullptr}}};
    // node *q = new node{2, new node{3, new node{4, nullptr}}};

    // Test 4
    // node *p = new node{2, nullptr};
    // node *q = nullptr;

    // Test 5
    node *p = nullptr;
    node *q = new node{2, nullptr};

    std::cout << "p: ";
    print(p);
    std::cout << "q: ";
    print(q);

    std::cout << propSubset(p, q) << std::endl;
}