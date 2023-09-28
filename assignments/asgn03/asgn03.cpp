#include <iostream>

void swapValues(char arr[], int a, int b)
{
    char temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void printCombination(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i];
    }
    std::cout << "\n";
}

void generateCombinations(char arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printCombination(arr, size);
        swapValues(arr, 0, i + 1);
    }
}

int main()
{
    char arr[] = {'A', 'B', 'C', 'D'};
    generateCombinations(arr, 4);
}