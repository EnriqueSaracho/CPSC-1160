/*
19/09/2023
Notes:
    - Recursion.
        - Baseline.
    - Binary search.
*/
#include <iostream>
#include <vector>

int factorial(int n)
{
    // Baseline.
    if (n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int sum_vector(std::vector<int> &v, int i = 0)
{
    if (i == static_cast<int>(v.size() - 1))
        return v[i];
    return v[i] + sum_vector(v, i + 1);
}

// By dividing the vector in multiple parts
int sum_vector(std::vector<int> &v, int low, int high)
{
    if (high = low)
        return v[low];
    int mid = (low + high) / 2;
    return sum_vector(v, low, mid) + sum_vector(v, mid + 1, high);
}

// Recursive binary search
int bin_s(std::vector<int> &v, int key, int low, int high)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (v[mid] == key)
    {
        return mid;
    }
    else if (v[mid] > key)
    {
        return bin_s(v, key, low, mid - 1);
    }
    else
    {
        return bin_s(v, key, mid + 1, high);
    }
}
int bin_s(std::vector<int> &v, int key)
{
    return bin_s(v, key, 0, v.size() - 1);
}

int main()
{
    // std::cout << factorial(5);

    std::vector<int> v = {1, 3, 6, 9, 12, 16, 21, 38, 50};

    // std::cout << sum_vector(v);

    std::cout << bin_s(v, -8);
}