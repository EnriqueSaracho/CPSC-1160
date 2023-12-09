#ifndef TS_H
#define TS_H

#include <iostream>

class TwoStacks
{
public:
    TwoStacks();
    bool isEmptyA() const;
    bool isEmptyB() const;
    void pushA(int x);
    void pushB(int x);
    int popA();
    int popB();

private:
    static const int MAX_SIZE = 100;
    int S[MAX_SIZE];
    void sError(const std::string &msg) const;
    const int A = 0;
    const int B = 99;
    int a;
    int b;
    bool isFull() const;
};

void TwoStacks::sError(const std::string &msg) const
{
    std::cout << msg << std::endl;
    exit(1);
}

TwoStacks::TwoStacks()
{
    a = 0;
    b = MAX_SIZE - 1;
}

bool TwoStacks::isEmptyA() const
{
    return A == a;
}
bool TwoStacks::isEmptyB() const
{
    return B == b;
}
bool TwoStacks::isFull() const
{
    return (a > b || b < a);
}

void TwoStacks::pushA(int x)
{
    if (isFull())
        sError("Memory full");
    S[a++] = x;
}
void TwoStacks::pushB(int x)
{
    if (isFull())
        sError("Memory full");
    S[b--] = x;
}

int TwoStacks::popA()
{
    if (isEmptyA())
        sError("Stack A is empty");
    return S[--a];
}
int TwoStacks::popB()
{
    if (isEmptyB())
        sError("Stack B is empty");
    return S[++b];
}

#endif