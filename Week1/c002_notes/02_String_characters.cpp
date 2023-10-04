/*
07/09/2023
Notes:
    - string characters
*/
#include <iostream>

int main()
{
    std::string str = "Hello World";
    for (int x = 0; x < str.size(); x++)
    {
        char letter = str[x];
        if (letter > 65 || letter < 90)
        {
            std::cout << letter << std::endl;
        }
    }
    return 0;
}