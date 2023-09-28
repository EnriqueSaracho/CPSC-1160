#include <iostream>
#include <cmath>

int main(){
    std::string str;
    double r = std::pow(3,7);
    int x;
    str = "hello";
    str += " world";
    str += '!';
    str[0] = 'H';
    str += std::to_string(x);
    std::cout << str << std::endl;

    if(false || x > 0 ){

    }else if(42){
    
    }else{

    }
    x = 0;
    while(x < 10){
        x++;
        std::cout << x;
    }
    do{
        
    }while(x == 43);

    for(; ;){

    }

    return 0;
}