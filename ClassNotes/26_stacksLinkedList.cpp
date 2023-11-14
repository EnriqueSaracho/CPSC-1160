/*
Lecture 18
*/

#include <iostream>
#include "stack.h"

void binarySequence(int k, std::string s = "")
{
    if (k == 0)
    {
        std::cout << s << std::endl;
        return;
    }

    binarySequence(k - 1, s + '0');
    binarySequence(k - 1, s + '1');
}

void binSeqStack(int k)
{
    stack<std::string> s;
    s.push("");
    while (!s.isEmpty())
    {
        std::string tmp = s.pop();
        if (tmp.size() == k)
        {
            std::cout << tmp << std::endl;
        }
        else
        {
            s.push(tmp + '0');
            s.push(tmp + '1');
        }
    }
}

int main()
{
    // stack<int> s;
    // s.push(4);
    // s.push(7);
    // std::cout << s.pop() << std::endl;
    // s.push(-3);
    // std::cout << s.peek() << std::endl;
    // while (!s.isEmpty())
    // {
    //     std::cout << s.pop() << std::endl;
    // }

    // binarySequence();
}