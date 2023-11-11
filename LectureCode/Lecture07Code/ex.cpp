#include <iostream>
#include <vector>

int sel_sr(std::vector<int> &v, int i = 0)
{
    if (i == v.size() - 1)
    {
        return 0;
    }
    int min = i;
    int count = 0;
    for (unsigned j = i + 1; j < v.size(); j++)
    {
        if (++count && v[min] > v[j])
        { // <-
            min = j;
        }
    }
    int temp = v[i];
    v[i] = v[min];
    v[min] = temp;
    return sel_sr(v, i + 1) + count;
}

void sel_s(std::vector<int> &v)
{
    for (unsigned i = 0; i < v.size(); i++)
    {
        int min = i;
        for (unsigned j = i + 1; j < v.size(); j++)
        {
            if (v[min] > v[j])
            {
                min = j;
            }
        }
        int temp = v[i];
        v[i] = v[min];
        v[min] = temp;
    }
}
int max_r(std::vector<int> &v, int i = 0)
{
    if (i == static_cast<int>(v.size() - 1))
    {
        return v[i];
    }
    // int max = max_r(v,i + 1);
    if (v[i] > max_r(v, i + 1))
    { //<- count
        return v[i];
    }
    return max_r(v, i + 1);
}

int main()
{
    std::vector<int> v = {3, 6, 12, 4, 12, 7, 45, 2, 9, 1};
    std::cout << max_r(v) << std::endl;
    std::cout << sel_sr(v) << std::endl;
    for (auto &x : v)
    {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}