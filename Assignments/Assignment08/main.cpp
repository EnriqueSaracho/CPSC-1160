#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include "stack.h"

void storeValues(std::vector<std::vector<int>> &m, std::fstream &fin, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            fin >> m[i][j];
}

template <typename T>
void print(std::vector<std::vector<T>> &m)
{
    for (auto &row : m)
    {
        for (auto &x : row)
        {
            std::cout << std::setw(3) << x << " ";
        }
        std::cout << std::endl;
    }
}

void pathFinder(std::vector<std::vector<int>> &m, int rows, int cols)
{
    // Creating map matrix
    std::vector<std::vector<char>> map(rows, std::vector<char>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            map[i][j] = '-';

    stack<int> s;
    for (auto &row : m)
        for (auto &x : row)
        {
            if (x == 0)
            {
            }
        }
}

int main()
{
    std::fstream fin;
    std::string filename;
    // std::cout << "Enter input file name: ";
    // std::cin >> filename;
    // fin.open(filename);
    fin.open("Matrix.txt");

    if (!fin.is_open())
    {
        std::cout << "Unable to read from a file";
        return 1;
    }
    else
    {
        int rows, cols;
        fin >> rows >> cols;
        std::vector<std::vector<int>> m(rows, std::vector<int>(cols));
        storeValues(m, fin, rows, cols);
        print(m);
        pathFinder(m, rows, cols);
    }

    fin.close();
}