#include "letter_counter.h"
#include <iostream>

int main(){
    letter_counter lc1("hafdkashdHDJkhkhduqkasJDHkajHdweiehhakljsaha");
    letter_counter lc2("BBBBBCE");
    letter_counter lc3 = lc2;

    std::cout << " lc1 " <<  lc1 << std::endl;
    std::cout << " lc2 "<<  lc2 << std::endl;
    lc2.add('A');
    lc2.add('B');
    lc2.add('D');
    lc2.add('Z');
    std::cout << " lc2 "<<  lc2 << std::endl;
    std::cout << " lc3 "<<  lc3 << std::endl;
    letter_counter lc4 = lc2-lc3;
    std::cout << " lc2-lc3 "<<  lc4 << std::endl;
    lc4 = lc1-lc2;
    std::cout << " lc1-lc2 "<<  lc4 << std::endl;
    lc4 = lc2-lc1;
    std::cout << " lc1-lc2 "<<  lc4 << std::endl;
    lc4 = lc1-lc1;
    std::cout << " lc1-lc1 "<<  lc4 << std::endl;
    return 0;
}