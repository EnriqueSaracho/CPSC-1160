/* Queues (arrays)
Lecture 20
21/11/2023

enqueue -> add to the end
dequeue -> remove from the front
front -> look at the front(start)
*/
#include <iostream>

const int CAP = 10;

template <typename T>
struct queue
{
public:
    void enqueue(T x)
    {
        if (isFull())
        {
            std::cerr << "QUEUE IS FULL";
            exit(1);
        }
        size++;
        arr[end] = x;
        end = (end + 1) % CAP;
    }
    T dequeue()
    {
        if (isEmpty())
        {
            std::cerr << "QUEUE IS FULL";
            exit(1);
        }
        size--;
        T ret = arr[start];
        start = (start + 1) % CAP;
        return ret;
    }
    T front()
    {
        if (isEmpty())
        {
            std::cerr << "QUEUE IS FULL";
            exit(1);
        }
        return arr[start];
    }
    bool isEmpty()
    {
        return size == 0;
    }
    bool isFull()
    {
        return size == CAP;
    }

private:
    T arr[CAP];
    int start = 0;
    int end = 0;
    int size = 0;
};

int main()
{
    queue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.dequeue();
    Q.enqueue(6);
    while (!Q.isEmpty())
    {
        std::cout << Q.dequeue() << " " << std::endl;
    }
}