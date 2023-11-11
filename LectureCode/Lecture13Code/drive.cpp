#include <iostream>
#include "point.h"

int main(){
 if(42){
        int x = 4;
        point p(1,2);
        point q = p; // <=> point q(p);
        q = p;
        q = q;
    }   
    std::cout << "Hello" << std::endl;
}

point fun(point  x){

}