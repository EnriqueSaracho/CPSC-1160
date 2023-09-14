#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Hello World" << std::endl;
    std::fstream fin;
    std::string line;
    fin.open("numTest.txt");
    if (fin.is_open())
    {
    }
    return 0;
}