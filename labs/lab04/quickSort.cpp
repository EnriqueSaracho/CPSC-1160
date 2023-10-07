#include <iostream>
#include <vector>

/**
 * This function is only for testing.
 */
// void printList(std::vector<int> list)
// {
//     for (auto &x : list)
//     {
//         std::cout << x << " ";
//     }
//     std::cout << std::endl;
// }

/**
 * Swaps two referenced values of a vector that takes as arguments.
 *
 * @param a - The first index.
 * @param b - The second index.
 * @return void.
 */
void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

/**
 * Sorts a vector by using quicksort algorithm with the first element as pivot, and counts the comparisons made.
 * - This function has an overloaded part that sets the arguments.
 *
 * @param list - The vector.
 * @param low - The lowest index of the partition.
 * @param high - The highest index of the partition.
 * @param comp - The number of comparisons made.
 * @return comp
 */
int quickSortFirst(std::vector<int> &list, int low, int high, int comp = 0)
{
    if (low < high)
    {
        // Partition
        int pivot = list[low],
            i = low + 1,
            j = high;

        while (i < j)
        {
            if (++comp && list[i] > pivot && list[j] < pivot)
                swap(list[i], list[j]);
            if (++comp && list[i] <= pivot)
                i++;
            if (++comp && list[j] >= pivot)
                j--;
        }
        if (++comp && list[low] > list[j])
            swap(list[low], list[j]);
        comp += quickSortFirst(list, low, i - 1);
        comp += quickSortFirst(list, i, high);
    }
    return comp;
}
int quickSortFirst(std::vector<int> &list)
{
    return quickSortFirst(list, 0, list.size() - 1);
}

/**
 * Sorts a vector by using quicksort algorithm with the middle element as pivot, and counts the comparisons made.
 * - This function has an overloaded part that sets the arguments.
 *
 * @param list - The vector.
 * @param low - The lowest index of the partition.
 * @param high - The highest index of the partition.
 * @param comp - The number of comparisons made.
 * @return comp
 */
int quickSortMiddle(std::vector<int> &list, int low, int high, int comp = 0)
{
    if (low < high)
    {
        // Partition
        int pivot = list[(high + low) / 2],
            i = low,
            j = high;

        while (i < j)
        {
            if (++comp && list[i] > pivot && list[j] < pivot)
                swap(list[i], list[j]);
            if (++comp && list[i] <= pivot)
                i++;
            if (++comp && list[j] >= pivot)
                j--;
        }
        if (++comp && j > (high + low) / 2 && pivot > list[j])
            swap(list[(high + low) / 2], list[j]);
        else if (++comp && pivot < list[j])
            swap(list[(high + low) / 2], list[j]);
        comp += quickSortMiddle(list, low, i - 1);
        comp += quickSortMiddle(list, i, high);
    }
    return comp;
}
int quickSortMiddle(std::vector<int> &list)
{
    return quickSortMiddle(list, 0, list.size() - 1);
}

int main()
{
    srand(time(0));

    // -> TEST 1
    // User inputs size of vector.
    unsigned int size;
    std::cout << "Size of vector: ";
    std::cin >> size;
    std::cout << std::endl;

    // Creating ascending vector.
    std::vector<int> list(size);
    for (int i = 0; i < size; i++)
    {
        list[i] = i + 1;
    }

    // Sorting the list and counts comparisons.
    int comp1 = quickSortMiddle(list);
    int comp2 = quickSortFirst(list);

    // Printing test 1 results.
    std::cout << "Test 1" << std::endl;
    std::cout << std::endl;
    std::cout << "Middle: " << comp1 << std::endl;
    std::cout << "First: " << comp2 << std::endl;
    std::cout << std::endl;

    // -> TEST 2
    // Creating two random vectors.
    std::vector<int> list1(size);
    std::vector<int> list2(size);
    for (int i = 0; i < size; i++)
    {
        list1[i] = (rand() % 101);
        list2[i] = (rand() % 101);
    }

    // Running quicksorts and counting comparisons.
    int list1F = 0, // List 1 first as pivot total comparisons
        list2F = 0, // List 2 first as pivot total comparisons
        list1M = 0, // List 1 middle as pivot total comparisons
        list2M = 0, // List 2 middle as pivot total comparisons
        runs = 1000;
    for (int i = 0; i < runs; i++)
    {
        list1F += quickSortFirst(list1);
        list2F += quickSortFirst(list2);
        list1M += quickSortMiddle(list1);
        list2M += quickSortMiddle(list1);
    }

    // Calculating results.
    double middle = ((list1M + list2M) / 2.0) / runs;
    double first = ((list1F + list2F) / 2.0) / runs;

    // Printing test 2 results.
    std::cout << "Test 2" << std::endl;
    std::cout << std::endl;
    std::cout << "Middle: " << middle << std::endl;
    std::cout << "First: " << first << std::endl;
    std::cout << std::endl;
}