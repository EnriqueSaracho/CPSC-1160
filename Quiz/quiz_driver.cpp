#include <iostream>
#include <cmath>
#include "quiz_obj.h"

int main(){
    srand(time(0));
    quiz_obj qo1(10);
    quiz_obj qo2(5);
    quiz_obj qo3(25);
    std::cout << "------OBJECT 1--------" << std::endl;
    std::cout << qo1 << std::endl;
    qo1.remove_odds();
    std::cout << qo1 << std::endl;
    std::cout << "------OBJECT 2--------" << std::endl;
    std::cout << qo2 << std::endl;
    qo2.remove_odds();
    std::cout << qo2 << std::endl;
    std::cout << "------OBJECT 3--------" << std::endl;
    std::cout << qo3 << std::endl;
    qo3.remove_odds();
    std::cout << qo3 << std::endl;
    
}