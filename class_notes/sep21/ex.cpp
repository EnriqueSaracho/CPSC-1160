#include <iostream>
#include <vector>

// Returns the binary representation.
void dec2Bin(int num)
{
    if (num != 0)
    {
        dec2Bin(num / 2);
        std::cout << (num % 2);
    }
}

// Checks if a vector is in ascending order.
bool isAsc(std::vector<int> &v, int i = 0)
{
    if (i == v.size() - 1)
    {
        return true;
    }
    return v[i] < v[i + 1] && isAsc(v, i + 1);
}

// TODO: Fix.
// Returns true if the string is PALINDROME.
// bool pali(const std::string &s, int i, int j)
// {
//     if (i >= j)
//     {
//         return true;
//     }
//     if (s[i] != s[j])
//     {
//         return false;
//     }
//     pali(s, i + 1, j - 1);
// }
// bool pali(const std::string &s)
// {
//     return pali(s, 0, s.size() - 1);
// }

int main()
{
    /* Calling pali */
    // std::string w1 = "racecar";
    // std::string w2 = "burger";
    // std::cout << pali(w1) << std::endl;
    // std::cout << pali(w2) << std::endl;

    /* Calling isAsc */
    // std::vector<int> ov = {1, 2, 3, 4, 5};
    // std::vector<int> uv = {1, 2, 1, 4, 5};
    // std::cout << isAsc(ov) << std::endl;
    // std::cout << isAsc(uv) << std::endl;

    /* Callin dec2Bin */
    dec2Bin(7);
}