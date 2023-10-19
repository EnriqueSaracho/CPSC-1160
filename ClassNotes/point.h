#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class point
{
public:
    // Here goes documentation for the functions
    // What it does
    // Input
    // Output
    point(int a, int b = 10); // Constructor
    point();                  // Constructor with default parameters
    void print();             // Print function
    point mid(point &p);
    double dist(point &p);

    bool operator==(point &p);
    bool operator==(int x);
    friend bool operator==(int a, point &p);
    friend std::ostream &operator<<(std::ostream &out, const point &p);

private:
    int x;
    int y;
};

// Only protopytes should be inside the class, so functions go outside.
point::point(int a, int b)
{
    x = a;
    y = b;
}
point::point()
{
    x = 0;
    y = 0;
}
void point::print()
{
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
point point::mid(point &p)
{
    return point((x + p.x) / 2, (y + p.y) / 2);
}
double point::dist(point &p)
{
    return std::sqrt(std::pow((x + p.x), 2) + std::pow((y + p.y), 2));
}
bool point::operator==(point &p)
{
    return x == p.x && y == p.y;
}
bool point::operator==(int a)
{
    return x == a;
}
bool operator==(int a, point &p)
{
    return p.x == a;
}
std::ostream &operator<<(std::ostream &out, const point &p)
{
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

#endif