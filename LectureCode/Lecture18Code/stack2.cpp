#include <vector>
#include <iostream>

template <typename T>
struct stack{

    void push(T x){
        if(isFull()){
            std::cerr << "THE STACK IS FULL";
            exit(1);
        }
        arr[top++] = x;
    }
    T pop(){
        if(isEmpty()){
            std::cerr << "THE STACK IS EMPTY";
            exit(1);
        }
        return arr[--top];
    }
    T peek(){
        if(isEmpty()){
            std::cerr << "THE STACK IS EMPTY";
            exit(1);
        }
        return arr[top-1];
       
    }
    bool isEmpty(){
        return top == 0;
    }
    bool isFull(){
        return top == 10;
    }
    private:
        T arr[10];
        int top = 0;

};

int main(){
    stack<int> s;
    s.push(3);
    s.push(6);
    s.push(9);
    s.pop();
    std::cout << s.peek() << std::endl;
    s.push(-6);
    s.push(12);
    s.peek();
    while(!s.isEmpty()){
         std::cout << s.pop() << std::endl;
    }
}