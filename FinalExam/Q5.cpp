#include <iostream>

void xOut(std::string& s){
   
}

int main(){
    std::cout<< std::endl << "TEST 1"<< std::endl;
    std::string s= "11121133Y22223" ;
    std::cout << s<< std::endl;
    xOut(s);
    std::cout << s<< std::endl;
    std::cout<< std::endl << "TEST 2"<< std::endl;
    s= "" ;
    std::cout << s<< std::endl;
    xOut(s);
    std::cout << s<< std::endl;
    std::cout<< std::endl << "TEST 3"<< std::endl;
    s= "1111111" ;
    std::cout << s<< std::endl;
    xOut(s);
    std::cout << s<< std::endl;
    std::cout<< std::endl << "TEST 4"<< std::endl;
    s= "123kdjuUd2" ;
    std::cout << s<< std::endl;
    xOut(s);
    std::cout << s<< std::endl;
    std::cout<< std::endl << "TEST 5"<< std::endl;
    s= "Hello  There" ;
    std::cout << s<< std::endl;
    xOut(s);
    std::cout << s<< std::endl;
    return 0;
}