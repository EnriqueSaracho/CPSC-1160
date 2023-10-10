#include <iostream>
#include <vector>

struct point
{
    int x = 0; // 0 is the default value.
    int y = 0;

    void print()
    {
        std::cout << x << " " << y << std::endl;
    }
};

// is best to pass structs as reference like vectors
bool comp(point &p, point &q)
{
    return p.x == q.x & p.y == q.y;
}

int main()
{
    point p = {9, 2};
    point q = p; // makes a deep copy
    // point &q = p; // makes a reference
    std::cout << p.x << " " << p.y << std::endl;
    std::cout << q.x << " " << q.y << std::endl;

    p.x = 12; // changes only p (not q)
    p.y = 5;
    std::cout << p.x << " " << p.y << std::endl;
    std::cout << q.x << " " << q.y << std::endl;
}