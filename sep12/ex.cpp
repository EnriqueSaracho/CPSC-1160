#include <iostream>

const double PI = 3.14; // Global variable example (always constants)

// Funtion/method creation
int pow2(int); // Prototype

int myPow(int, int = 2); // default parameter has to be after the non-default parameter
// int myPow(int) // You can also overload

// Function with string parameter
// The & makes the function reference the variable instead of creating a new one (if it doesn't have 'const' it has to be a variable, not literal).
// The 'const' makes it not changeable (safer when referencing).
void print(const std::string &str)
{
    std::cout << str << std::endl;
}

void max_min(int a, int b, int &max, int &min)
{
    max = a;
    min = b;
    if (a < b)
    {
        max = b;
        min = a;
    }
}

// Function documentation:
// What it does
// Inputs (Assumptions about the input too (ex: a >= 0))
// Output
int main()
{
    std::cout << pow2(3) << std::endl;

    std::cout << myPow(2, 2) << std::endl;
    std::cout << myPow(2, 4) << std::endl;
    std::cout << myPow(2, 6) << std::endl;
    std::cout << myPow(2, 8) << std::endl;

    std::string s = "Hello World";
    print(s);

    // Manipulating variables with functions
    int max, min;
    max_min(2, 7, max, min);
    std::cout << max << " " << min << std::endl;

    return 0;
}

// Actual funtion
int pow2(int x)
{
    return x * x;
}

int myPow(int x, int n)
{
    int result = x;
    for (int i = 1; i < n; i++)
    {
        result *= x;
    }
    return result;
}