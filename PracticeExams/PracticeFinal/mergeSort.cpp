#include <iostream>
#include <vector>

void print(std::vector<int> &v)
{
    std::cout << "[ ";
    for (auto &x : v)
    {
        std::cout << x << " ";
    }
    std::cout << "]" << std::endl;
}

void merge(std::vector<int> &v, int ls, int le, int rs, int re, std::vector<int> &w)
{
    int i = ls;
    int j = rs;
    int k = ls;
    for (; i <= le && j <= re;)
    {
        if (v[i] < v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    for (; i <= le; i++, k++)
        w[k] = v[i];
    for (; j <= re; j++, k++)
        w[k] = v[j];
    int p = ls;
    for (; p <= re; p++)
    {
        v[p] = w[p];
    }
}
void mergeSort(std::vector<int> &v, int low, int high, std::vector<int> &w)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(v, low, mid, w);
    mergeSort(v, mid + 1, high, w);
    merge(v, low, mid, mid + 1, high, w);
}
void mergeSort(std::vector<int> &v)
{
    std::vector<int> w(v.size());
    mergeSort(v, 0, v.size() - 1, w);
}

int main()
{
    std::vector<int> v = {7, 4, 10, 3, 13, 21};
    print(v);
    mergeSort(v);
    print(v);
}