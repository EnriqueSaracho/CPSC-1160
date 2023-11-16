/* Vectors
Lecture 4
14/09/2003
Notes:
    - Vectors.
        - Declaration.
        - Adding values.
        - Passing vectors as arguments.
        - For each loop ('auto' type).
        - Multidimentional vectors.
*/
#include <iostream>
#include <vector>

// Passing a .
void times_by_2(std::vector<int> &); // Prototype.
void times_by_2(std::vector<int> &v) // Pass in by reference.
{
    for (auto &x : v)
    {
        x *= 2;
    }
}

// Reverse vector
std::vector<int> rev(std::vector<int> a)
{
    for (int i = 0; i < a.size() / 2; i++)
    {
        int tmp = a[i];
        a[i] = a[a.size() - i - 1];
        a[a.size() - i - 1] = tmp;
    }
}

int main()
{
    // std::vector<int> v(10, 5); // (size, values)
    // std::vector<int> v = {1, 2, 3, 4}; // only works when speciffyign the version when compiling
    int size = 8;
    std::vector<int> v(size); // unlike arrays, the size in declaration can be a variable.
    v.push_back(10);          // avoid

    for (unsigned int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << std::endl;
    }

    times_by_2(v);

    for (auto &x : v) // loop for vectors (for each)
    {
        std::cout << x << std::endl;
    }

    std::vector<std::vector<int>> m(2, std::vector<int>(3)); // multi-dimensional vector.
    m.push_back(std::vector<int>(2));                        // Adds another element(vector) of the first dimension

    for (auto &row : m)
    {
        for (auto &x : row)
        {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}