#include <iostream>

const int CAP = 5; 

template <typename T>
struct queue{
        void enq(T x){
            if(isFull()){
                std::cerr << "QUEUE IS FULL";
                exit(1);
            }
            size++;
            arr[end] = x;
            end = (end+1)%CAP;
        }
        T deq(){
            if(isEmpty()){
                std::cerr << "QUEUE is EMPTY";
                exit(1);
            }
            size--;
            T ret_val = arr[start];
            start = (start +1)%CAP;
            return ret_val;

        }
        bool isFull(){
            return size == CAP;

        }
        bool isEmpty(){
            return size == 0;
        }
        T front(){
           if(isEmpty()){
                std::cerr << "QUEUE is EMPTY";
                exit(1);
            }
            return arr[start]; 
        }
    private:
        T arr[CAP];
        int start = 0, end = 0, size = 0;
        //need more variables

};

int main(){
    queue<int> Q;
    Q.enq(1);
    Q.enq(2);
    Q.enq(3);
    Q.enq(4);
    Q.enq(5);
    Q.deq();
    Q.enq(6);
    while(!Q.isEmpty()){
        std::cerr << Q.deq() <<  " ";
    }
}