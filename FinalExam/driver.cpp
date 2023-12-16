#include <iostream>
#include "final_obj.h"

int main(){
    final_obj fo;
    fo.add(1);
    fo.add(2);
    fo.add(3);
    fo.add(4);
    fo.add(5);
    fo.remove();
    fo.remove();
    fo.remove();
    std::cout << fo << std::endl;
    fo.add(6);
    std::cout << fo << std::endl;
    fo.add(7);
    std::cout << fo << std::endl;
    fo.add(8);
    std::cout << fo << std::endl;
    fo.add(9);
    std::cout << fo << std::endl;
    fo.remove();
    fo.add(10);
    fo.add(11);
    std::cout << fo << std::endl;
    
    final_obj fo1 = fo;
    fo.add(12);
    std::cout << fo1 << std::endl;
    std::cout << fo << std::endl;
    fo.remove();
    fo.remove();
    fo.remove();
    std::cout << fo << std::endl;
    fo.add(1);
    fo.add(2);
    fo.add(3);
    fo.add(4);
    fo.add(5);
    std::cout << fo << std::endl;
    fo.add(43);
    std::cout << fo << std::endl;
    return 0;
}