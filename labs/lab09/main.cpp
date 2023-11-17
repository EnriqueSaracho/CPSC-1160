#include <iostream>
#include "stack.h"

float revPolEq(std::string str)
{
    stack<float> s;
    for (auto c : str)
    {
        if (c >= '0' && c <= '9')
            s.push((c - '0') * 1.0);
        else
        {
            if (s.isEmpty())
            {
                std::cerr << "Invalid equation";
                exit(1);
            }
            float b = s.pop();
            if (s.isEmpty())
            {
                std::cerr << "Invalid equation";
                exit(1);
            }
            float a = s.pop();
            switch (c)
            {
            case '+':
                s.push(a + b);
                break;
            case '-':
                s.push(a - b);
                break;
            case '*':
                s.push(a * b);
                break;
            case '/':
                if (b == 0)
                {
                    std::cerr << "Divide by 0 error";
                    exit(1);
                }
                s.push(a / b);
                break;
            default:
                std::cerr << "Invalid equation";
                exit(1);
            }
        }
    }
    if (s.isEmpty())
    {
        std::cerr << "Invalid equation";
        exit(1);
    }
    float result = s.pop();
    if (!s.isEmpty())
    {
        std::cerr << "Invalid equation";
        exit(1);
    }
    return result;
}

int main()
{
    std::string test1 = "543--643++/";
    std::string test2 = "72364-+*/";
    std::string test3 = "436-*32-8+";
    std::string test4 = "111-/";
    // std::cout << revPolEq(test1) << std::endl;
    // std::cout << revPolEq(test2) << std::endl;
    // std::cout << revPolEq(test3) << std::endl;
    std::cout << revPolEq(test4) << std::endl;
    return 0;
}