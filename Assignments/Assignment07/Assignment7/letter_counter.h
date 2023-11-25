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
     * @return letter_counter object itself.
     */
    letter_counter();

    /**
     * Constructor function.
     * Initializes the letter_counter object and stores in a circular linked list of head 'd' each letter from the input string as well
     * as the amount of times it appears.
     *
     * @param str - string.
     * @return letter_counter object itself.
     */
    letter_counter(std::string);

    /**
     * Copy constructor function.
     * Copies the values from the object of the right hand side of the 'equals' operator to the newly declared object.
     *
     * @param obj - letter_counter object.
     * @return letter_counter object itself.
     */
    letter_counter(const letter_counter &);

    /**
     * Destructor funciton.
     * Deletes the values from the object.
     *
     * @return modifies the letter_counter object itself.
     */
    ~letter_counter();

    /**
     * Assignment operator.
     * Copies the values from the object of the right hand side of the 'equals' operator to the newly declared object.
     * Gets called when the current object already has been initialized.
     *
     * @param obj - letter_counter object.
     * @return modifies the letter_counter object itself.
     */
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
     * Creates a new letter_counter object with the linked list of head 'd' being the result of the difference between two other
     * letter_counter object's lists values.
     *
     * @param a - letter_counter object.
     * @param b - letter_counter object.
     * @return letter_counter object - difference between 'a' and 'b'.
     */
    friend const letter_counter operator-(const letter_counter &, const letter_counter &);

    /**
     * Adds a new letter to the linked list of the letter_counter object.
     *
     * @param ch - character being added.
     * @return void - updates this object's linked list.
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

    // value wasn't on the list
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
    d = new node;
    d->next = d;
    d->prev = d;
    size = obj.size;

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
    if (d->next != d)
    {
        node *p = d->next;
        while (p != d)
        {
            node *tmp = p;
            p = p->next;
            delete tmp;
        }
    }
    delete d;
    d = nullptr;
    size = 0;
    std::cout << "-------------------DELETE-------------------" << std::endl;
}

const letter_counter &letter_counter::operator=(const letter_counter &obj)
{
    if (this != &obj)
    {
        // deleting
        size = 0;
        node *p = d->next;
        while (p != d)
        {
            node *tmp = p;
            p = p->next;
            delete tmp;
        }
        delete d;
        d = nullptr;
        p = nullptr;

        // Copying
        std::cout << "-------------------ASSIGNMENT-------------------" << std::endl;
        size = obj.size;
        d = new node;
        d->next = d;
        d->prev = d;
        p = obj.d->next;
        int count;
        for (; p != obj.d; p = p->next)
        {
            count = p->data.count;
            for (int i = 0; i < count; i++)
            {
                add(p->data.value);
            }
        }
    }
    return *this;
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
    while (p != a.d)
    {
        // if q is already at dummy but not p
        if (q == b.d)
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
            dif = p->data.count - q->data.count;
            if (dif > 1)
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
            q = (q != b.d) ? q->next : q;
        }
    }

    return letter_counter(str);
}

#endif