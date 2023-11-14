/*
Lecture 18
14/11/2023
*/
#include <iostream>
#include <vector>

/*
Stack functions
    push    add to the top
    pop     remove from the top
    peek    look at the top
*/

template <typename T>
struct stack
{
    void push(T x)
    {
        top.push_back(x);
    }
    T pop()
    {
        if (isEmpty())
        {
            std::cerr << "STACK IS EMPTY";
            exit(1);
        }
        T retVal = top.back();
        top.pop_back();
        return retVal;
    }
    T peek()
    {
        if (isEmpty())
        {
            std::cerr << "STACK IS EMPTY";
            exit(1);
        }
        return top.back();
    }
    bool isEmpty()
    {
        return top.empty();
    }

private:
    std::vector<int> top;
};

int main()
{
    stack<int> s;
    s.push(4);
    s.push(7);
    std::cout << s.pop() << std::endl;
    s.push(-3);
    std::cout << s.peek() << std::endl;
    while (!s.isEmpty())
    {
        std::cout << s.pop() << std::endl;
    }
}