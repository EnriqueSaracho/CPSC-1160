/* Stacks (arrays)
Lecture 18
14/11/2023
*/
#include <iostream>
#include <vector>

/*
Array stack are better for fixed sizes.
*/

template <typename T>
struct stack
{
    void push(T x)
    {
        if (isFull())
        {
            std::cerr << "STACK IS FULL";
            exit(1);
        }
        arr[top++] = x;
    }
    T pop()
    {
        if (isEmpty())
        {
            std::cerr << "STACK IS EMPTY";
            exit(1);
        }
        return arr[--top];
    }
    T peek()
    {
        if (isEmpty())
        {
            std::cerr << "STACK IS EMPTY";
            exit(1);
        }
        return arr[top - 1];
    }
    bool isEmpty()
    {
        return (top < 1);
    }
    bool isFull()
    {
        return (top == 10);
    }

private:
    T arr[10];
    int top = 0;
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