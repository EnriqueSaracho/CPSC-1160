/*
Lecture 4
14/09/2023
Notes:
    - Arrays.
        - Types.
        - Declaration.
        - Passing as arguments.
        - Multidimentional.
*/
#include <iostream>
const int MAX_SIZE = 100;

// Passing multi-dimensional array as argument.
void printArray(int a[][3], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Reverse an array
// To create a copy of an array you would have to pass the new array as an argument.
// Because when passing an array it is automatically a reference.
void revArray(int a[], int size)
{
    int temp;
    for (int i = 0, j = size - 1; i < size / 2; i++, j--)
    {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
    }
}

void timesBy2(int a[], int size) // The argument serves as a pointer to the first element of the array. So the values can be altered.
{
    for (int i = 0; i < size; i++)
    {
        a[i] * 2;
        // a[i] *= 2; // this would change the array;
    }
}

void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << a[i] << std::endl;
    }
}

int main()
{
    // DO NOT DO THIS
    //  int size;
    //  std::cout << "Enter the size of the array" << std::endl;
    //  std::cin >> size;
    //  int d[size];

    const int size = 5;
    int d[5]{1, 2, 3};
    d[4] = 100;

    int a[5], b; // this is ok

    // for (int i = 0; i < size; i++)
    // {
    //     std::cout << d[i] << std::endl;
    // }

    printArray(d, size);
    std::cout << std::endl;

    timesBy2(d, size); // it doesn't change the array because it creates a copy. Well it would if I created a new parameter where i could put a new empty array and add logic to change its values.
    printArray(d, size);
    std::cout << std::endl;

    revArray(d, size);
    printArray(d, size);
    std::cout << std::endl;

    int m[2][3]; // multi-dimensional array.
    m[0][1] = 0; // asigning a value.
    printArray(m, 2, 3);

    return 0;
}