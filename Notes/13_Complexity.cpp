#include <iostream>
#include <vector>

/*
How many additions?
assume n >= 2 and n < v.size()
T(2) =  1   <-- base case
T(n) =  3 + T(n-1)   <-- general    3 * 1 + T(n-1)
        3 + 3 + T(n-2)              3 * 2 + T(n-2)
        3 + 3 + 3 + T(n-3)          3 * 3 + T(n-3)
                                    ...
                                    3 * K + T(n-k)
    now solve k

    n - k = 2
    k = n - 2
                                    3 * (n - 2) + T(n-(n-2))
                                    3n - 6 + T(2)
                                    3n - 6 + 1
                                    3n - 5

*/
int fun(std::vector<int> &v, int n)
{
    if (n == 2)
    {
        return v[0] + v[1];
    }
    else
    {
        return v[n] + v[n] + v[n] + fun(v, n - 1);
    }
}

int main()
{
}