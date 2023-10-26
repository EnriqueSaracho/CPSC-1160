#ifndef P_H
#define P_H

#include <iostream>

class point
{
public:
    point(int a, int b);    // Constructor
    point(const point &og); // Copy constructor
    ~point();               // Delete constructor

    const point &operator=(const point &rhs); // Copy constructor from the other side of the operator

private:
    int *x;
    int y;
};

point::point(int a, int b)
{
    x = new int(a);
    y = b;
}
point::~point()
{
    std::cout << "DELETED" << std::endl;
    delete x;
}
point::point(const point &og)
{
    x = new int(*og.x);
    y = og.y;
}
const point &point::operator=(const point &rhs)
{
    if (&rhs == this)
    {
        return *this;
    }
    delete x;
    y = rhs.y;
    x = new int(*rhs.x);
    return *this;
}

#endif