/*
Question 1:
T(1) = 1
T(n) = 2 + T(n/2)
     = 2 + 2 + T(n/4)
     = 2 + 2 + 2 + T(n/8)
T(n) = 2 * k + T(n/(2^k))           a)

    n - k = 1
    k = n - 1

T(n) = 1 * (n-1) + T(n/(2^(n-1)))
     = n - 1 + T(n/(2^(n-1)))       b)

O(logn)                             c)

binary search                       d)

*/

/*
Question 2:
a)   An integer number.
     f(3,8) output -> -5
     Returns the difference between a and b (a - b).

b)   An integer number.
     foo(4) output -> 24
     Returns factorial.
*/

#include <iostream>
#include <vector>

/*Question 3:*/
bool isSorted(std::vector<int> &v, int n = 0)
{
}

int main()
{
     std::vector<int> v = {1, 2, 3, 4, 5};
     std::cout << isSorted(v) << std::endl;
}