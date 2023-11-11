/*
Lecture 10
10/10/2023
Notes:
    - Structs
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

struct point
{
    int x = rand() % 14; // number between 0 and 15
    int y = rand() % 15;

    void print()
    {
        std::cout << x << " " << y << std::endl;
    }

    // the same functions but inside the struct
    bool comp(point &q)
    {
        return x == q.x & y == q.y;
    }
    point mid(point &q)
    {
        return point{(x + q.x), (y + q.y)};
    }

    // returns the distance between two points
    double dist(point &q)
    {
        return std::sqrt(std::pow((x - q.x), 2) + std::pow((y - q.y), 2));
    }
};

// is best to pass structs as reference like vectors
bool comp(point &p, point &q)
{
    return p.x == q.x & p.y == q.y;
}

// returning a point from a function
point mid(point &p, point &q)
{
    return point{(p.x + q.x), (p.y + q.y)};
}

// Find the two points in a vector closest to each other and returns distance
double minDist(std::vector<point> &v)
{
    if (v.size() < 2)
        return 0;

    double min = v[0].dist(v[1]);
    double dist;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            dist = v[i].dist(v[j]);
            if (dist < min)
                min = dist;
        }
    }
    return min;
}

int main()
{
    srand(time(0));
    point p = {9, 2};
    point q = p; // makes a deep copy
    // point &q = p; // makes a reference
    std::cout << p.x << " " << p.y << std::endl;
    std::cout << q.x << " " << q.y << std::endl;

    p.x = 12; // changes only p (not q)
    p.y = 5;
    std::cout << p.x << " " << p.y << std::endl;
    std::cout << q.x << " " << q.y << std::endl;

    point w = mid(p, q);
    w.print();

    // Calling the functions but from inside the struct
    point m = p.mid(q);
    m.print();
    std::cout << p.comp(m) << std::endl;

    // Calling distance function
    std::cout << w.dist(m) << std::endl;

    // With Vectors
    std::cout << std::endl;
    std::cout << "Vector part" << std::endl;
    std::vector<point> v_p(10);
    for (auto &x : v_p)
    {
        x.print();
    }
    std::cout << "Minimum distance: " << minDist(v_p) << std::endl;
}