/* Reading from files
Lecture 3
12/09/2023
Notes:
    - Files.
        - Reading from file.
Related files:
    - numTest.txt
    - test.txt
*/
#include <iostream>
#include <fstream> // allows to read from file
#include <string>  // for getline()

int main()
{
    std::ifstream fin;
    std::string line;
    char c;
    int x, y;
    fin.open("test.txt");

    if (fin.is_open())
    {
        while (fin >> line) // word by word
            // while (fin >> c) // char by char
            // while (getline(fin, line)) // line by line
            while (!fin.eof()) // end of life
            {
                fin >> x >> y;
                std::cout << (x + y) << std::endl;
            }
        fin.close();
    }
}