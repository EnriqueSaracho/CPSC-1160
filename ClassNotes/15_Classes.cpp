/*
Lecture 11
Notes:
    - header file: point.h
*/
// #include <iostream>
// #include <cmath>
#include "point.h"
#include "point.h"

// class point
// {
// public:
//     point(int a, int b = 10) // Constructor
//     {
//         x = a;
//         y = b;
//     }
//     point() // Constructor with default parameters
//     {
//         x = 0;
//         y = 0;
//     }
//     void print() // Print function
//     {
//         std::cout << "(" << x << "," << y << ")" << std::endl;
//     }
//     point mid(point &p)
//     {
//         return point((x + p.x) / 2, (y + p.y) / 2);
//     }
//     double dist(point &p)
//     {
//         return std::sqrt(std::pow((x + p.x), 2) + std::pow((y + p.y), 2));
//     }

// private:
//     int x;
//     int y;
// };

int main()
{
    point p(4, 3);
    point q; // Default parameter
    point r = p.mid(q);
    std::cout << (q == r) << std::endl;
    std::cout << (p == 4) << std::endl; // p.operator==(4)
    std::cout << (3 == p) << std::endl;

    std::cout << p << std::endl;

    p.print();
    q.print();
    r.print();
    std::cout << "p-q dist: " << p.dist(q);
}