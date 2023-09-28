/* Recursive find max in vector problem from lab02 explained in class. */

#include <iostream>
#include <vector>

int max_r(std::vector<int> &v, int i = 0)
{
    if (i == static_cast<int>(v.size() - 1))
    {
        return v[i];
    }
    int max = max_r(v, i + 1); // Complexity analisis. Instead of calling the function on the if.
    if (v[i] > max)
    {
        return v[i];
    }
    return max;
}

int main()
{
    std::vector<int> v = {3, 6, 12, 4, 12, 7, 45, 2, 9};
    std::cout << max_r(v) << std::endl;
    return 0;
}