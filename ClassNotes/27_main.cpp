/*
Lecture 19
- Stacks
This is the problem from lab3 but with stacks instead of normal recursion.
*/
#include <iostream>
#include <vector>
#include "stack.h"

struct state
{
    int row;
    int col;
    int cost;
};

int path(const std::vector<std::vector<int>> &m)
{
    stack<state> s;
    int count = -1;
    if (m[0][0] == 0)
    {
        return -1;
    }
    s.push({0, 0, 0});
    while (!s.isEmpty())
    {
        state tmp = s.pop();
        if (tmp.row >= m.size() || tmp.col >= m[tmp.row].size() || m[tmp.row][tmp.col] == 0)
        {
        }
        else if (tmp.row == m.size() - 1 && tmp.col == m[tmp.row].size() - 1)
        {
            tmp.cost += m[tmp.row][tmp.col];
            if (count == -1)
            {
                count = tmp.cost;
            }
            else if (count > tmp.cost)
            {
                count = tmp.cost;
            }
            count++;
        }
        else
        {
            s.push({tmp.row + 1, tmp.col, tmp.cost + m[tmp.row][tmp.col]});
            s.push({tmp.row, tmp.col + 1, tmp.cost + m[tmp.row][tmp.col]});
        }
    }
    return count;
}

int main()
{
    std::vector<std::vector<int>> matrix{
        {2, 2, 7, 0, 4},
        {4, 0, 0, 2, 4},
        {0, 1, 1, 2, 1}};
    std::cout << path(matrix) << std::endl;
}