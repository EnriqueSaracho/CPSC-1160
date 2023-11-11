/*
Lecture 14 maybe?
Header file: point&classes.h
*/
#include <iostream>
#include "point&classes.h"

int main()
{
    if (43)
    {
        point p(1, 2);
        point q = p;
        p = q;
    }
    std::cout << "Hello" << std::endl;
}

// void fun(point p)
// {
// }

point fun(point p)
{
    return p;
}