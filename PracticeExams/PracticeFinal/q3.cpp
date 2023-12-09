#include <iostream>

int peak(int A[], int start, int end)
{
    if (start >= end)
        return start;
    if (A[start] > A[start + 1])
        return start;
    if (A[end] > A[end - 1])
        return end;

    int middle = (start + end) / 2;
    if (middle == end || A[middle] > A[middle + 1])
        return peak(A, start, middle);
    return peak(A, middle + 1, end);
}
int peak(int A[], int n)
{
    return peak(A, 0, n - 1);
}

int main()
{
    int B[] = {11, 13, 70, 60, 58, 46, 21};
    int C[] = {24, 45, 26};
    int D[] = {11, 22, 33, 44, 55, 66};

    std::cout << "B: " << peak(B, 7) << std::endl;
    std::cout << "C: " << peak(C, 3) << std::endl;
    std::cout << "D: " << peak(D, 6) << std::endl;
}