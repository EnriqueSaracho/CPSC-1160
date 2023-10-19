#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <cmath>

class Line
{
public:
    Line();
    Line(int, int, int, int);
    bool operator==(const Line &);
    friend std::ostream &operator<<(std::ostream &out, const Line &l);
    Line operator+(int a);
    friend Line operator+(int, const Line &); // The left hand size parameter represents the value to the left of the operator, and viceversa.
    Line operator*(int a);
    Line operator-();

private:
    int x1, y1, x2, y2;
    double length() const;
};

Line::Line()
{
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
}
Line::Line(int a, int b, int c, int d)
{
    x1 = a;
    y1 = b;
    x2 = c;
    y2 = d;
}
double Line::length() const
{
    return std::sqrt(std::pow((x1 - x2), 2) + std::pow((y1 - y2), 2));
}
bool Line::operator==(const Line &l)
{
    return length() == l.length();
}
std::ostream &operator<<(std::ostream &out, const Line &l)
{
    out << "(" << l.x1 << "," << l.y1 << ")(" << l.x2 << "," << l.y2 << ") distance = " << l.length() << std::endl;
    return out;
}
Line Line::operator+(int x)
{
    return Line(x1 + x, y1, x2 + x, y2);
}
Line operator+(int y, const Line &l)
{
    return Line(l.x1, l.y1 + y, l.x2, l.y2 + y);
}
Line Line::operator*(int a)
{
    return Line(x1, y1, x2 * a, y2 * a);
}
Line Line::operator-()
{
    return Line(x2, y2, x1, y1);
}

#endif