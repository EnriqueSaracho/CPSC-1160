#ifndef Q_H
#define Q_h
#include <iostream>

class final_obj{
    public:
        final_obj();
        ~final_obj();
        final_obj(const final_obj&);
        const final_obj& operator=(const final_obj&);
        friend std::ostream& operator<<(std::ostream&,const final_obj&);
        void add(int);
        void remove();
    private:
        int *arr;
        int cap;
        //You will need more variables;
};

std::ostream& operator<<(std::ostream& out ,const final_obj& rhs){
    
    return out;
}

final_obj::final_obj(){
    
}
final_obj::~final_obj(){
   
}
final_obj::final_obj(const final_obj& rhs){
    
}

const final_obj& final_obj::operator=(const final_obj& rhs){
    return *this;
}
void final_obj::add(int x){
    
}
void final_obj::remove(){
    

}



#endif