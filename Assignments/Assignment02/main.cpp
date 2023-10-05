#include <iostream>

/**
 * Takes an array of characters and two indexes and swaps the values in said indexes.
 *
 * @param arr - The array of characters.
 * @param a - The first index.
 * @param b - The second index.
 * @return - void.
 */
void swapValues(char arr[], int a, int b)
{
    char temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

/**
 * Prints all elements in an array of characters of size 4.
 *
 * @param arr - The array of characters.
 * @param i - The index of the array.
 * The output is the elements of the array printed in the console.
 */
void printComb(char arr[], int i = 0)
{
    if (i < 4)
    {
        std::cout << arr[i];
        printComb(arr, i + 1);
    }
    else
    {
        std::cout << "\n";
    }
}

/**
 * Generates all posible combinations of an array of characters of size 4.
 *
 * @param arr - The array of characters.
 * @param index - The index of the array being swaped.
 * The output is the combinations passed to the printComb function to be printed to the console.
 */
void genComb(char arr[], int index = 0)
{
    if (index == 4)
    {
        printComb(arr);
        return;
    }

    for (int i = index; i < 4; i++)
    {
        swapValues(arr, index, i);
        genComb(arr, index + 1);
        swapValues(arr, index, i);
    }
}

int main()
{
    char arr[] = {'^', 'V', '>', '<'};
    genComb(arr);
    return 0;
}