/* Dynamic Programing
Lecture 21
23/11/2023
*/
#include <iostream>
#include <vector>

// std::string commonSubStr(std::string a, std::string b)
// {
//     std::string common = "";
//     int i = 0;
//     while (i)
// }

int path(std::vector<std::vector<int>> &m)
{
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