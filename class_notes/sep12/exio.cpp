#include <iostream>
#include <fstream> // allows to read from file
#include <string>  // for getline()

int main()
{
    std::ifstream fin;
    std::string line;
    char c;
    int x, y;
    fin.open("numTest.txt");

    if (fin.is_open())
    {
        // while (fin >> line) // word by word
        // while (fin <, c) // char by char
        // while (!fin.eof())
        while (getline(fin, line)) // line by line
        {
            fin >> x >> y;
            std::cout << (x + y) << std::endl;
        }
        fin.close();
    }
}