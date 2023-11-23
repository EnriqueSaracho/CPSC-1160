#include <iostream>
#include "stack.h"

struct state{
    int k;
    std::string s;
    
};

void bin_seq(int k, std::string s = ""){
    if(k == 0){
        std::cout << s << std::endl;
        return;
    }

    bin_seq(k-1,s + "0");
    bin_seq(k-1,s + "1");
}

void bin_seq_s(int k){
    stack<state> s;
    s.push({k,""});
    while(!s.isEmpty()){
        state x = s.pop();
        if(x.k == 0){
            std::cout << x.s << std::endl;
        }else{
            s.push({x.k-1,x.s+'1'});
            s.push({x.k-1, x.s+'0'});
        }
    }
}

int main(){
    /*stack<int> s;
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
    }*/
    bin_seq_s(3);
}