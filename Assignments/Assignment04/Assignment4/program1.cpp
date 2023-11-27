#include <iostream>
#include <fstream>

void switchChars(std::string &str, int a, int b)
{
    char tmp = str[b];
    str[b] = str[a];
    str[a] = tmp;
}

void organize(std::string &str)
{
    int count = 0;
    for (auto c : str) // counts amount of uppercase letters in one loop
    {
        if (std::isupper(c))
            count++;
    }
    int j = 0;
    for (int i = 0; i < count; i++) // goes through the strings first number of uppercase letters and switches the ones that are not with the ones that are
    {
        if (!std::isupper(str[i]))
        {
            while (!std::isupper(str[count + j])) // finds the next uppercase letter out of place
                j++;
            switchChars(str, i, count + j);
            j++;
        }
    }
}

int main()
{
    std::fstream fin;
    std::string line;
    std::string fileName;
    std::cout << "What file do you wish to run: " << std::endl;
    std::cin >> fileName;
    fin.open(fileName);
    if (fin.is_open())
    {
        while (fin >> line)
        {
            std::cout << "unorganized " << line << std::endl;
            organize(line);
            std::cout << "organized " << line << std::endl;
            std::cout << std::endl;
        }
    }
}