#include "twoStacks.h"
#include <iostream>

int main()
{
    TwoStacks stacks;

    stacks.pushB(5);
    std::cout << stacks.isEmptyA() << std::endl;
    std::cout << stacks.isEmptyB() << std::endl;
    std::cout << stacks.popB() << std::endl;
}