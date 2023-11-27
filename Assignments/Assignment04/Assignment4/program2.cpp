#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/**
 * Print function.
 * Takes a vector of integers and prints it values.
 *
 * @param v - vector of integers.
 * @return void - console text.
 */
void print(std::vector<int> &v)
{
    std::cout << "[ ";
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << "]" << std::endl;
}

/**
 * Merge function.
 * Takes two vector of integers in either ascending or descending order and merges them to create
 * one in ascending order.
 *
 * @param v1 - vector of integers.
 * @param v2 - vector of integers.
 * @return m - vector of integers
 */
std::vector<int> merge(std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<int> m(v1.size() + v2.size());
    int i, j, k = 0;
    // if both sequences are in ascending order
    if (v1[0] < v1[1] && v2[0] < v2[1])
    {
        i = 0;
        j = 0;
        while (i < v1.size() && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                m[k] = v1[i];
                i++;
                k++;
            }
            else
            {
                m[k] = v2[j];
                j++;
                k++;
            }
        }
        while (i < v1.size())
        {
            m[k] = v1[i];
            i++;
            k++;
        }
        while (j < v2.size())
        {
            m[k] = v2[j];
            j++;
            k++;
        }
        return m;
    }

    // v1 ascending, v2 descending
    if (v1[0] < v1[1] && v2[0] > v2[1])
    {
        i = 0;
        j = v2.size() - 1;
        while (i < v1.size() && j > -1)
        {
            if (v1[i] < v2[j])
            {
                m[k] = v1[i];
                i++;
                k++;
            }
            else
            {
                m[k] = v2[j];
                j--;
                k++;
            }
        }
        while (i < v1.size())
        {
            m[k] = v1[i];
            i++;
            k++;
        }
        while (j > -1)
        {
            m[k] = v2[j];
            j--;
            k++;
        }
        return m;
    }

    // v1 descending, v1 ascending
    if (v1[0] > v1[1] && v2[0] < v2[1])
    {
        i = v1.size() - 1;
        j = 0;
        while (i > -1 && j < v2.size())
        {
            if (v1[i] < v2[j])
            {
                m[k] = v1[i];
                i--;
                k++;
            }
            else
            {
                m[k] = v2[j];
                j++;
                k++;
            }
        }
        while (i > -1)
        {
            m[k] = v1[i];
            i--;
            k++;
        }
        while (j < v2.size())
        {
            m[k] = v2[j];
            j++;
            k++;
        }
        return m;
    }

    // both descending
    i = v1.size() - 1;
    j = v2.size() - 1;
    while (i > -1 && j > -1)
    {
        if (v1[i] < v2[j])
        {
            m[k] = v1[i];
            i--;
            k++;
        }
        else
        {
            m[k] = v2[j];
            j--;
            k++;
        }
    }
    while (i > -1)
    {
        m[k] = v1[i];
        i--;
        k++;
    }
    while (j > -1)
    {
        m[k] = v2[j];
        j--;
        k++;
    }
    return m;
}

/**
 * Main function.
 * Prompts the user to enter the name of a file, reads from it and uses functions to create merged vectors
 * out of the sequences in the input file.
 */
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
            int s1 = stoi(size);
            std::vector<int> v1(s1);
            for (int i = 0; i < s1; i++)
                fin >> v1[i];

            // Reading sequence 2
            fin >> size;
            int s2 = stoi(size);
            std::vector<int> v2(s2);
            for (int i = 0; i < s2; i++)
                fin >> v2[i];

            // Printing vectors 1 and 2
            std::cout << "Vector 1" << std::endl;
            print(v1);
            std::cout << "Vector 2" << std::endl;
            print(v2);

            // Creates merged sequence
            std::vector<int> m = merge(v1, v2);
            std::cout << "Merged Vector" << std::endl;
            print(m);

            std::cout << std::endl;
        }
    }
}