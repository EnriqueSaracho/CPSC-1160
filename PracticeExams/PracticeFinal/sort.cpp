#include <iostream>
#include <vector>

void print(std::vector<int> &);
void swap(std::vector<int> &, int, int);

void selectionSort(std::vector<int> &);

void insertionSort(std::vector<int> &);

void mergeSort(std::vector<int> &);
void mergeSort(std::vector<int> &, int, int, std::vector<int> &);
void merge(std::vector<int> &, int, int, int, int, std::vector<int> &);

void quickSort(std::vector<int> &);
void quickSort(std::vector<int> &, int, int);

int main()
{
    std::vector<int> w = {13, 11, 6, 4, 20, 17};
    std::vector<int> v;

    v = w;
    std::cout << "Selection Sort" << std::endl;
    std::cout << "O(n^2)" << std::endl;
    print(v);
    selectionSort(v);
    print(v);
    std::cout << std::endl;

    v = w;
    std::cout << "Insertion Sort" << std::endl;
    std::cout << "O(n^2)" << std::endl;
    print(v);
    insertionSort(v);
    print(v);
    std::cout << std::endl;

    v = w;
    std::cout << "Merge Sort" << std::endl;
    std::cout << "O(nlogn)" << std::endl;
    print(v);
    mergeSort(v);
    print(v);
    std::cout << std::endl;

    v = w;
    std::cout << "Quick Sort" << std::endl;
    std::cout << "O(nlogn)" << std::endl;
    print(v);
    mergeSort(v);
    print(v);
    std::cout << std::endl;
}

void print(std::vector<int> &v)
{
    std::cout << "[ ";
    for (auto &x : v)
        std::cout << x << " ";
    std::cout << "]" << std::endl;
}

void swap(std::vector<int> &v, int i, int j)
{
    int tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

void selectionSort(std::vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int min = i;
        for (int j = i + 1; j < v.size(); j++)
            if (v[j] < v[min])
                min = j;
        if (min != i)
            swap(v, min, i);
    }
}

void insertionSort(std::vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && v[j] > v[j + 1])
        {
            swap(v, j, j + 1);
            j--;
        }
    }
}

void mergeSort(std::vector<int> &v)
{
    std::vector<int> w(v.size());
    mergeSort(v, 0, v.size() - 1, w);
}
void mergeSort(std::vector<int> &v, int start, int end, std::vector<int> &w)
{
    if (start >= end)
        return;
    int middle = (start + end) / 2;
    mergeSort(v, start, middle, w);
    mergeSort(v, middle + 1, end, w);
    merge(v, start, middle, middle + 1, end, w);
}
void merge(std::vector<int> &v, int aStart, int aEnd, int bStart, int bEnd, std::vector<int> &w)
{
    int i = aStart,
        j = bStart,
        k = aStart;
    while (i <= aEnd && j <= bEnd)
        if (v[i] < v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    while (i <= aEnd)
        w[k++] = v[i++];
    while (j <= bEnd)
        w[k++] = v[j++];
    for (int x = aStart; x <= bEnd; x++)
        v[x] = w[x];
}

void quickSort(std::vector<int> &v)
{
    quickSort(v, 0, v.size() - 1);
}
void quickSort(std::vector<int> &v, int start, int end)
{
    if (start >= end)
        return;

    int pivot = start,
        i = start + 1,
        j = end;
    while (i < j)
    {
        if (v[i] > v[pivot] && v[j] < v[pivot])
            swap(v, i, j);
        if (v[i] < v[pivot])
            i++;
        if (v[j] > v[pivot])
            j--;
    }
    swap(v, pivot, i);

    quickSort(v, start, i - 1);
    quickSort(v, i + 1, end);
}
