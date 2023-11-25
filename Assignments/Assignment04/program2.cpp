#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void print(std::vector<int> &v)
{
    std::cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "]" << std::endl;
}

std::vector<int> merge(std::vector<int> &v1, std::vector<int> &v2)
{
    // if both sequences are in ascending order
    if (v1[0] < v1[1] && v2[0] < v2[1])
    {
        int i = 0,
            j = 0;
        while (i < v1.size())
    }
}

int main()
{
    std::fstream fin;
    std::string fileName;
    std::cout << "What file do you wish to run: " << std::endl;
    std::cin >> fileName;
    fin.open(fileName);

    std::string size;
    if (fin.is_open())
    {
        while (fin >> size)
        {
            // Reading sequence 1
            int s = stoi(size);
            std::vector<int> v1(s);
            for (int i = 0; i < s; i++)
            {
                fin >> v1[i];
            }
            // Reading sequence 2
            fin >> size;
            s = stoi(size);
            std::vector<int> v2(s);
            for (int i = 0; i < s; i++)
            {
                fin >> v2[i];
            }
            // Creates merged sequence
            std::vector<int> m = merge(v1, v2);
        }
    }
}