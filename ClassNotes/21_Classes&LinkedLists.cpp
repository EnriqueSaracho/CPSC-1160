#include "ll.h"
#include <iostream>

int main()
{
    ll<double> l;
    l.add(9.4);
    l.append(3);
    std::cout << l;
}