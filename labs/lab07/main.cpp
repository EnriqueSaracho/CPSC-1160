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
        std::cout << h->data << "->";
    }
    std::cout << "nullptr" << std::endl;
}

node *createList(const std::string &num, unsigned i = 0)
{
    if (i == num.size())
    {
        return nullptr;
    }
    return new node{num[i] - '0', createList(num, i + 1)};
}

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

node *mergeSort(node *l1, node *l2, node *l3 = nullptr)
{
    if (!l1 && !l2)
        return l3;

    if (l1 && !l2)
    {
        return new node{l1->data, mergeSort(l1->next, l2, l3)};
    }

    if (!l1 && l2)
    {
        return new node{l2->data, mergeSort(l1, l2->next, l3)};
    }

    if (l1->data < l2->data)
    {
        return new node{l1->data, mergeSort(l1->next, l2, l3)};
    }

    return new node{l2->data, mergeSort(l1, l2->next, l3)};
}

int main()
{
    std::string num1, num2;
    std::cout << "Enter a number: ";
    std::cin >> num1;
    std::cout << "Enter a number: ";
    std::cin >> num2;

    node *list1 = createList(num1);
    list1 = selection_sort(list1);
    node *list2 = createList(num2);
    list2 = selection_sort(list2);
    std::cout << "The linked lists" << std::endl;
    print(list1);
    print(list2);

    node *list3 = nullptr;
    list3 = mergeSort(list1, list2);
    std::cout << "Merged linked lists" << std::endl;
    print(list3);

    std::cout << "The linked lists" << std::endl;
    print(list1);
    print(list2);

    std::cout << std::endl;
}