#include <iostream>

void swap(int *a, int *b) // Pointers as parameters.
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void swap(int &a, int &b) // This better tho (referenced variables, for this case).
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int main()
{
    int c, d;
    c = 2;
    d = 3;
    swap(&c, &d);
}