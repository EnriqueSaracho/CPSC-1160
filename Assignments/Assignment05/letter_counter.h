#ifndef AO_H
#define AO_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
class letter_counter{
    private:
        
        struct item{
            char value;
            int count;

        };
        std::vector<item> A;
        int size;
    public:
        letter_counter();
        letter_counter(std::string);
        friend std::ostream& operator<<(std::ostream & out,const letter_counter & obj);
        friend const letter_counter operator-(const letter_counter &,const letter_counter &);
        void add(char i);
};
void letter_counter::add(char ch){
    
}


letter_counter::letter_counter(){
    size = 0;
}

letter_counter::letter_counter(std::string str){
    
}


std::ostream& operator<<(std::ostream & out, const letter_counter & obj){
    return out;
}

const letter_counter operator-(const letter_counter & a,const letter_counter & b){
    return letter_counter();
}
    


#endif