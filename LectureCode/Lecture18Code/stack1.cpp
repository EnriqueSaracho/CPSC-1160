#include <vector>
#include <iostream>

template <typename T>
struct stack{

    void push(T x){
        top.push_back(x);
    }
    T pop(){
        T tmp = peek();
        top.pop_back();
        return tmp;
    }
    T peek(){
        if(isEmpty()){
            std::cerr << "THE STACK IS EMPTY";
            exit(1);
        }
        return top.back();
    }
    bool isEmpty(){
        return top.empty();
    }


    private:
        std::vector<T> top;

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