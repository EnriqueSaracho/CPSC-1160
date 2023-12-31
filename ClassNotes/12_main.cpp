/* Insertion Sort (vectors)
Lecture 8
03/10/2023
Notes:
    - Recursion.
    - Insertion Sort.
*/

// Insertion Sort.
#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &list)
{
    int count = 0;
    for (unsigned int i = 1; i < list.size(); i++)
    {
        int tmp = list[i];
        int j;
        for (j = i - 1; j >= 0 && ++count && tmp < list[j]; j--)
        {
            list[j + 1] = list[j];
        }
        list[j + 1] = tmp;
    }
    std::cout << count << std::endl;
    return;
}

// Recursively (you don't want to do this).
void recInsertionSort(std::vector<int> &list, int i = 1)
{
    if (i == list.size())
    {
        return;
    }
    int tmp = list[i];
    int j;
    for (j = i - 1; j >= 0 && tmp < list[j]; j--)
    {
        list[j + 1] = list[j];
    }
    list[j + 1] = tmp;
    recInsertionSort(list, i + 1);
}

int main()
{
    std::vector<int> myList = {4, 7, 1, 3, 13, -6, 9, 12};
    // insertionSort(myList);
    recInsertionSort(myList);
    for (int i = 0; i < myList.size(); i++)
    {
        std::cout << myList[i] << " ";
    }
}