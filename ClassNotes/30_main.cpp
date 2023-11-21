/* Queues (linked lists)
Lecture 20
21/11/2023
*/
#include <iostream>
#include "queue.h"

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