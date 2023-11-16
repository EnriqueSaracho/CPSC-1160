/* Strings and characters
Lecture 2
07/09/2023
Notes:
    - string characters
    - srand() and rand()
*/
#include <iostream>

int main()
{
    srand(time(0));
    std::string str = "Hello World";
    for (unsigned i = 0; i < str.size(); i++)
    {
        char letter = str[i];
        // if (letter < 65 || letter > 90)
        // if (letter < 'A' || letter > 'Z')
        if (!isupper(letter))
        {
            // std::cout << letter << std::endl;
            std::cout << static_cast<char>(toupper(letter)) << std::endl;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        std::cout << (rand() % 81 + 20) << std::endl;
    }
    return 0;
}