/*
03/10/2023
Notes:
    - Lab3 review.
    - Finding path in matrix.
*/
#include <iostream>
#include <vector>

int path(std::vector<std::vector<int>> &m, int r = 0, int c = 0, int p_s = 0)
{
    if (r == m.size() || c == m[r].size() || m[r][c] == 0)
    {
        return -1;
    }
    p_s += m[r][c];
    if (r == m.size() - 1 && c == m[r].size() - 1)
    {
        return p_s;
    }

    int a = path(m, r + 1, c, p_s);
    int b = path(m, r, c + 1, p_s);

    if (a == -1 && b == -1)
    {
        return -1;
    }
    if (a == -1)
    {
        return b;
    }
    if (b == -1)
    {
        return a;
    }
    if (a > b)
    {
        return a;
    }
    return b;
}

int main()
{
    std::vector<std::vector<int>> m = {
        {1, 2, 4, 0, 4},
        {4, 3, 3, 2, 4},
        {0, 0, 2, 2, 1},
        {1, 0, 2, 2, 1},
        {1, 4, 2, 3, 2}};
    std::cout << path(m) << std::endl;
}