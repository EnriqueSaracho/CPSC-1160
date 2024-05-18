/* Pointers
Lecture 14 (I think)
20/10/2023
Notes:
    - Pointers
        - int *p = &a;
        - (*) dereferences pointers.
        - Pointers are stack memory.
        - A pointer is a memory address.
        - With the asterisk you dereference it and are able to acces the value.
*/
#include <iostream>

void swap(int *a, int *b) // Pointers as parameters.
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
void swap(int &a, int &b) // This better tho (referenced variables, for this case).
{
    int tmp = a;
    a = b;
    b = tmp;
    return;
}

int main()
{
    int c, d;
    swap(c, d);

    int *p = new int;
    *p = 42;
    *p = 3; // Updates the value to a 3;

    int *q = new int(4); // Starts the inside value at a 4.
    int *r;
    r = p; // r is a new pointer pointing to the same piece of memory as p.
    p = q; // now p and q are pointing at the same piece of memory, r didn't change.

    *q = 6;
    std::cout << *q << std::endl; // prints 6 (value in q).

    // delete r; // what should be done for no memory leak
    r = new int(12); // leaves the value 3 (from line 35) as an unreferenced piece of memory (memory leak).
                     // C++ doesn't have a garbage collector.

    delete q;
    // q = nullptr; // what should be done to avoid dangling pointer.
    q = r;
    // Now q is pointing to a free piece of memory (dangling pointer, problem).
    p = nullptr;

    // With structs
    // point *pt= new point{3,4};
    // (*pt).x = 5;
    // pt -> y = 7; same thing.
    // pt -> dist(*pt); // Calling a function of a struck;

    if (p) // Checks if the pointer is not a null pointer.
    {
        std::cout << "p is a dangling pointer" << std::endl;
    }

    if (p == nullptr) // Checks if it is a null pointer
    {
        std::cout << "p is a dangling pointer" << std::endl;
    }
    if (!p) // Same
    {
    }

    if (q == r) // Checks if they point to the same location.
    {
        std::cout << "q == r (they point to the same location)" << std::endl;
    }
    if (*q == *r) // Checks if they point to the same value.
    {
        std::cout << "*q == *r (they point to locations containing the same value)" << std::endl;
    }

    // Dinamic arrays
    int arrSize = 5;
    int *arr = new int[arrSize];
    int *arr2 = new int[5]{1, 2, 3, 4}; // {1, 2, 3, 4, 0}
    arr[2] = 5;                         // Nothing changes when initializing a value. Better to use this way.
    *(arr + 3) = 4;                     // same thing as arr[3] = 4
    *arr = 1;                           // Changes the first element
    arr[100] = 42;                      // Extends the size and intitializes 100th element.

    std::cout << "arr = [" << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << "]" << std::endl;

    // You can return a dinamic array from a function
    // int *make_array(int size)
    // {
    //     return new int[size];
    // }

    // void newArr(int &*arr)
    // {
    //     delete[] arr;
    //     arr = new int[10];
    // }

    delete[] arr;
    arr = nullptr;

    // Two-dimensional dinamic array
    int **matrix = new int *[3];
    for (int i = 0; i < 3; i++)
    {
        matrix[i] = new int[4];
    } // Declaration

    matrix[1][2] = 2;

    // Passing matrix to a method
    // void printMatrix(int **matrix, int row, int col)
    // {}

    // Deleting
    for (int i = 0; i < 3; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;

    // struct arr
    // {
    //     int size;
    //     int *a;
    // };
    // arr *pt = new arr;
    // pt->a = new int[5];
    // p->size = 5;
    // delete pt->a;
    // delete pt;
}