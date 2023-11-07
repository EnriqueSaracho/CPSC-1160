#include <iostream>

class letter_counter
{
private:
    struct item
    {
        char value;
        int count;
    };
    item *A;
    int size;

public:
    letter_counter();
    letter_counter(std::string);
    friend std::ostream &operator<<(std::ostream &out, const letter_counter &obj);
    void add(char i);
    int binarySearch(char, int, int);
    void quickSort(int, int);
};

letter_counter::letter_counter()
{
    size = 0;
}

int main()
{
}