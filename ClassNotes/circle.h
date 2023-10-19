#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

class circle
{
public:
    circle();
    circle(int a, int b, int rad);
    friend std::ostream &operator<<(std::ostream &out, const circle &c);
    circle operator*(int a);                                  // return a new circle with the radius x times bigger;
    friend bool operator==(const circle &c, const circle &b); // check if two circle intersect

private:
    int x;
    int y;
    int r;
};

circle circle::operator*(int a)
{
    return circle(x, y, r * a);
}
bool operator==(const circle &c, const circle &b)
{
    return (std::sqrt(std::pow((c.x + b.x), 2) + std::pow((c.y + b.y), 2)) < (c.r + b.r));
}

#endif