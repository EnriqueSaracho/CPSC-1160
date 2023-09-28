#include <iostream>
#include <cctype>
#include <ctime>

int main(){
    srand(time(0));
    std::string str = "Hello World!";
    for(unsigned i = 0; i < str.size(); i++){
        //if(str[i] < 'A' || str[i] > 'Z'){
        if(!isupper(str[i])){
            std::cout << static_cast<char>(toupper(str[i])) << std::endl;
        }
    }
    for(int i = 0; i < 10; i++){
        std::cout << (rand()%81+20) << std::endl;
    }

    return 0;
}