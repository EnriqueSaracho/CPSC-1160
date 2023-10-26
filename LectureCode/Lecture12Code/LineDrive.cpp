#include "Line.h"

int main(){
   Line l1(0,2,1,4);
   Line l2(2,4,3,6);
   std::cout << ((l2 == l1)? "Are":"Aren't") << " same length" << std::endl;
   std::cout << l1 << std::endl;
   l1 = 3+ l1;
   std::cout << l1 << std::endl;
   l1 =  l1 + 4;
   std::cout << l1 << std::endl;
   l1 = l1 * 2;
   std::cout << l1 << std::endl;
   std::cout << ((l2 == l1)? "Are":"Aren't") << " same length" << std::endl;
}