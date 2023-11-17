#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>

class letter_counter
{
private:
    struct item
    {
        char value;
        int count;
    };
    struct node
    {
        node *prev;
        item data;
        node *next;
    };
    node *d;
    int size;

public:
    /**
     * Default constructor function.
     *
     * @return letter_counter - the letter_counter class object.
     */
    letter_counter();

    /**
     * Constructor function.
     * Initializes the letter_counter object and stores in the dinamic array 'A' each letter from the input string as well
     * as the amount of times it appears.
     *
     * @param str - string.
     * @return letter_counter - the letter_counter class object.
     */
    letter_counter(std::string);

    // Copy constructor:
    letter_counter(const letter_counter &);

    // Destructor:
    // ~letter_counter();

    /**
     * Prints the information from the vector of structs 'A' in an ordered manner.
     *
     * @param out - ostream object.
     * @param obj - letter_counter object.
     * @return std::ostream - customized ostream object.
     */
    friend std::ostream &operator<<(std::ostream &out, const letter_counter &obj);

    /**
     * Creates a new letter_counter object with the vector of structs 'A' being the result of the difference between two other
     * letter_counter object's vectors values.
     *
     * @param a - letter_counter object.
     * @param b - letter_counter object.
     * @return letter_counter object - difference between 'a' and 'b'.
     */
    friend const letter_counter operator-(const letter_counter &, const letter_counter &);

    /**
     * Adds a new letter to the vector of the letter_counter object.
     *
     * @param ch - character being added.
     * @return void - updates this object's vector.
     */
    void add(char i);

    /**
     * Searches for a letter inside the vector of this letter_counter object.
     *
     * @param key - character/letter being looked for.
     * @param low - int, lowest index of partition.
     * @param high - int, highest index of partition.
     * @return integer - '-1' if not found, any other value represents the location/index of the character in the vector.
     */
    // int binarySearch(char, int, int);

    /**
     * Sortes the vector of structs 'A' by 'value' alphabetically.
     *
     * @param low - lowest index of partition.
     * @param highest - highest index of partition.
     * @return void - updates this objects vector.
     */
    // void quickSort(int, int);

    /**
     * Searches for a letter inside the vector of a letter_counter object.
     *
     * @param a - letter_counter object.
     * @param key - character/letter being looked for.
     * @param low - int, lowest index of partition.
     * @param high - int, highest index of partition.
     * @return integer - '-1' if not found, any other value represents the location/index of the character in the vector.
     */
    // friend int binarySearch(const letter_counter &, char, int, int);
};

void letter_counter::add(char ch)
{
    node *p;
    // if the linked list is empty
    if (d->next == d)
    {
        p = new node{d, {ch, 1}, d->next};
        p->next->prev = p;
        p->prev->next = p;
        size++;
        return;
    }

    // looking for the value in the linked list
    p = d->next;
    for (; p != d && p->data.value < ch; p = p->next)
        ;
    if (p->data.value == ch)
    {
        p->data.count++;
        return;
    }
    node *t = new node{p->prev, {ch, 1}, p};
    t->next->prev = t;
    t->prev->next = t;
    size++;
}

letter_counter::letter_counter()
{
    d = new node;
    d->next = d;
    d->prev = d;
    size = 0;
}

letter_counter::letter_counter(std::string str)
{
    d = new node;
    d->next = d;
    d->prev = d;
    size = 0;

    for (auto c : str)
    {
        add(static_cast<char>(toupper(c)));
    }
}

letter_counter::letter_counter(const letter_counter &obj)
{
    std::cout << "-------------------COPY-------------------" << std::endl;
    size = obj.size;

    d = new node;
    d->next = d;
    d->prev = d;

    node *p = obj.d->next;
    for (; p != obj.d; p = p->next)
    {
        add(p->data.value);
    }
}

// letter_counter::~letter_counter()
// {
//     delete A;
//     A = nullptr;
//     std::cout << "-------------------DELETE-------------------" << std::endl;
// }

std::ostream &operator<<(std::ostream &out, const letter_counter &obj)
{
    out << "[ ";
    letter_counter::node *p = obj.d->next;
    for (; p != obj.d; p = p->next)
    {
        out << p->data.value << ":" << p->data.count << " ";
    }
    out << "]";
    return out;
}

const letter_counter operator-(const letter_counter &a, const letter_counter &b)
{
    std::string str = "";
    int index, diff;
    for (int i = 0; i < a.size; i++)
    {
        index = binarySearch(b, a.A[i].value, 0, b.size - 1);
        diff = index < 0 ? 0 : b.A[index].count;
        for (int j = 0; j < (a.A[i].count - diff); j++)
        {
            str += a.A[i].value;
        }
    }
    return letter_counter(str);
}

// void letter_counter::quickSort(int low, int high)
// {
//     if (low >= high)
//     {
//         return;
//     }
//     if (low + 1 == high)
//     {
//         if (A[low].value > A[high].value)
//         {
//             item temp = A[low];
//             A[low] = A[high];
//             A[high] = temp;
//         }
//         return;
//     }

//     int i = low, j = high;
//     int mid = (i + j) / 2;
//     item pivot = A[mid];
//     A[mid] = A[i];
//     while (i < j)
//     {
//         while (i < j && pivot.value <= A[j].value)
//         {
//             j--;
//         }
//         A[i] = A[j];
//         while (i < j && pivot.value >= A[i].value)
//         {
//             i++;
//         }
//         A[j] = A[i];
//     }
//     A[j] = pivot;
//     mid = i;
//     quickSort(low, mid - 1);
//     quickSort(mid + 1, high);
// }

// int binarySearch(const letter_counter &a, char key, int low, int high)
// {
//     if (low > high)
//         return -1;
//     int mid = (low + high) / 2;
//     if (a.A[mid].value == key)
//         return mid;
//     else if (a.A[mid].value > key)
//         return binarySearch(a, key, low, mid - 1);
//     else
//         return binarySearch(a, key, mid + 1, high);
// }

#endif