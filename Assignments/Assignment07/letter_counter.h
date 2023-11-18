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
    ~letter_counter();

    // Assignment operator
    const letter_counter &operator=(const letter_counter &);

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
    size = obj.size;

    d = new node;
    d->next = d;
    d->prev = d;

    node *p = obj.d->next;
    int count;
    for (; p != obj.d; p = p->next)
    {
        count = p->data.count;
        for (int i = 0; i < count; i++)
            add(p->data.value);
    }
    std::cout << "-------------------COPY-------------------" << std::endl;
}

letter_counter::~letter_counter()
{
    node *p = d->next; // TODO: create delete list function
    while (p != d)
    {
        d = p->next;
        p->next->prev = d;
        node *tmp = p;
        p = p->next;
        delete tmp;
    }
    std::cout << "-------------------DELETE-------------------" << std::endl;
}

const letter_counter &letter_counter::operator=(const letter_counter &obj)
{
    if (this != &obj)
    {
    }
}

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
    letter_counter::node *p = a.d->next;
    letter_counter::node *q = b.d->next;
    int dif;
    while (p != a.d || q != b.d)
    {
        // if p is already at dummy but not q
        if (p == a.d)
        {
            while (q != b.d)
            {
                dif = q->data.count;
                for (int i = 0; i < dif; i++)
                    str += q->data.value;
                q = q->next;
            }
        }
        // if q is already at dummy but not p
        else if (q == b.d)
        {
            while (p != a.d)
            {
                dif = p->data.count;
                for (int i = 0; i < dif; i++)
                    str += p->data.value;
                p = p->next;
            }
        }
        // if both p and q are at the same value
        else if (p->data.value == q->data.value)
        {
            dif = std::abs(p->data.count - q->data.count);
            for (int i = 0; i < dif; i++)
                str += p->data.value;
            p = (p != a.d) ? p->next : p;
            q = (q != b.d) ? q->next : q;
        }
        // if p is less than q
        else if (p->data.value < q->data.value)
        {
            dif = p->data.count;
            for (int i = 0; i < dif; i++)
                str += p->data.value;
            p = (p != a.d) ? p->next : p;
        }
        // if q is less than p
        else
        {
            dif = q->data.count;
            for (int i = 0; i < dif; i++)
                str += q->data.value;
            q = (q != b.d) ? q->next : q;
        }
    }
    return letter_counter(str);
}

#endif