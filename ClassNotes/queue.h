#ifndef Q_H
#define Q_H

template <typename T>
class queue
{
public:
    queue(); // constructor
    void enqueue(T);
    T dequeue();
    T front();
    bool isEmpty();

private:
    struct node
    {
        T data;
        node *next;
    };
    node *head;
    node *tail;
};

template <typename T>
queue<T>::queue()
{
    head = tail = nullptr;
}

template <typename T>
void queue<T>::enqueue(T x)
{
    if (!head)
    {
        head = new node{x, tail};
        tail = head;
    }
    else
    {
        tail->next = new node{x, nullptr};
        tail = tail->next;
    }
}

template <typename T>
T queue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cerr << "QUEUE IS FULL";
        exit(1);
    }
    T ret = front();
    node *tmp = head;
    head = head->next;
    if (!head)
        tail = nullptr;
    delete tmp;
    return ret;
}

template <typename T>
T queue<T>::front()
{
    if (isEmpty())
    {
        std::cerr << "QUEUE IS FULL";
        exit(1);
    }
    return head->data;
}

template <typename T>
bool queue<T>::isEmpty()
{
    return !head;
}

#endif