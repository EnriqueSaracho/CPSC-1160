#include <iostream>
#include <vector>

void twoLargest(std::vector<int> &, int &, int &);

int main()
{
    std::vector<int> v = {4, 6, 2, 3, 7};
    int a;
    int b;
    twoLargest(v, a, b);
}

void twoLargest(std::vector<int> &v, int &a, int &b)
{
    a = v[0];
    b = v[1];
    for (int i = 2; i < v.size(); i++)
    {
        if (v[i] > a && v[i] > b) // if its greater than both
            if (a < b)
                a = v[i];
            else
                b = v[i];
        else if (v[i] > a && v[i] < b) // if its greater than a but not b
            a = v[i];
        else if (v[i] < a && v[i] > b) // if its greater than b but not a
            b = v[i];
    }
}
