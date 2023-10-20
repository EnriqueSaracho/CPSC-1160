/*
Lecture 2
07/09/2023
Notes on:
    - std::string
    - std::cout
    - if statements
    - loops
    - scopes
*/
#include <iostream>
#include <cmath>
#include <string>

int main()
{
    std::string str;
    int x = 8;
    str = "hello";
    str += " World";
    str += "!";
    str[0] = 'H';
    str += std::to_string(x);
    std::cout << str << std ::endl;

    if (false || x > 0)
    {
    }
    else if (42)
    {
    }
    else
    {
    }

    x = 0;
    while (x < 10)
    {
        x++;
        std::cout << x << std::endl;
    }

    do
    {

    } while (x == 43);

    for (int x = 0; x < 10; x++)
    {
    }

    for (;;)
    {
    }

    // Scopes
    {
        int y;
        {
            int y;
            {
                int y;
            }
        }
    }

    return 0;
}