#include <iostream>

bool hasDuplicate(std::string str, char a, int i = 0)
{
    if (i == str.size())
        return false;
    if (a == str[i])
    {
        // str[i] = '';
        return hasDuplicate(str, a, i + 1);
    }
}

int main()
{
    std::string str = "Hello";
    std::cout << hasDuplicate(str, 'l');
    return 0;
}