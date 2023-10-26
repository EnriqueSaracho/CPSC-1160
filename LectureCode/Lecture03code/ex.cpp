#include <iostream>

const double PI = 3.14;
int pow2(int);
template <typename T> void my_swap(T & a, T & b);
//What it does
// What inputs it take  in (assume a >= 0)
// What does it output
int my_pow(int,int);
int my_pow(int);

void print(const std::string & str){
    std::cout << str << std::endl;
}

template <typename T>
void my_swap(T & a, T & b){
    T tmp = a;
    a = b;
    b = tmp;
    return;
}
/*
void my_swap(char & a, char & b){
    char tmp = a;
    a = b;
    b = tmp;
}

void my_swap(std::string&  a, std::string & b){
    std::string tmp = a;
    a = b;
    b = tmp;
}
*/
void max_min(int a, int b, int & max, int &min){
    max = a;
    min = b;
    if(a < b){
        max = b;
        min = a;
    }
}

int main(){
    std::string s = "hello world!";
    int max, min;
    std::cout << my_pow(2,4) << std::endl;
    print("wombat");
    max_min(2,7,max,min);
    std::cout << max << " " << min <<std::endl;
    return 0;
}

int my_pow(int x){
    return x*x;
}
//What it does
// What inputs it take  in (assume a >= 0)
// What does it output
int my_pow(int x, int a){
    int result = 1;
    for(int i =0; i < a; i++){
        result *= x;
    }
    return result;
}

int pow2(int x){
    return x*x;
}
