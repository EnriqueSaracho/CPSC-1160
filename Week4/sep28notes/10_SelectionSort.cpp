/*
28/09/2023
Notes:
    - Selection sort.
        - Using for loop.
        - Recursively.
*/
#include <iostream>
#include <vector>

// Selection sort function.
void selSort(std::vector<int> &v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        int m = i;
        for (unsigned int j = i + 1; j < v.size(); j++)
        {
            if (v[m] > v[j])
            {
                m = j;
            }
        }
        int tmp = v[m];
        v[m] = v[i];
        v[i] = tmp;
    }
}

// Recursive selection sort. DO NOT do this.
void recSelSort(std::vector<int> &v, int i = 0)
{
    if (i == v.size())
    {
        return;
    }
    int m = i;
    for (unsigned int j = i + 1; j < v.size(); j++)
    {
        if (v[m] > v[j])
        {
            m = j;
        }
    }
    int tmp = v[m];
    v[m] = v[i];
    v[i] = tmp;
    recSelSort(v, i + 1);
}

int main()
{
    std::vector<int> v = {2, 4, 1, 3, 5};
    // selSort(v);
    recSelSort(v);
    for (auto &i : v)
    {
        std::cout << i << " ";
    }
    return 0;
}