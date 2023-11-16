#include <iostream>
#include "stack.h"

// Checks to see if the brackets in a string are properly accomodated.
bool bracketCheck(std::string str)
{
    stack<char> s;
    for (auto c : str)
    {
        if (c == '[')
            s.push(']');
        else if (c == '(')
            s.push(')');
        else if (s.isEmpty() || c != s.pop())
            return false;
    }
    return s.isEmpty();
}

int main()
{
    std::string str1 = "([()])";
    std::string str2 = "()[[]()]";
    std::string str3 = "(([)])";
    std::string str4 = "()[]()";
    std::string str5 = "()[](]";
    std::string str5 = "(([()]))";
    std::cout << bracketCheck(str1) << std::endl;
    std::cout << bracketCheck(str2) << std::endl;
    std::cout << bracketCheck(str3) << std::endl;
    std::cout << bracketCheck(str4) << std::endl;
    std::cout << bracketCheck(str5) << std::endl;
}