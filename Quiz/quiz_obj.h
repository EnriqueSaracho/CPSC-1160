#ifndef QO_H
#define QO_H
#include <iostream>

/*
SAMPLE OUTPUT
------OBJECT 1--------
[ 39 97 46 86 58 11 40 44 60 76  ]
[ 46 86 58 40 44 60 76  ]
------OBJECT 2--------
[ 11 5 58 12 6  ]
[ 58 12 6  ]
------OBJECT 3--------
[ 68 46 50 63 24 66 55 97 31 33 5 41 92 76 71 70 38 28 47 93 0 68 3 14 97  ]
[ 68 46 50 24 66 92 76 70 38 28 0 68 14  ]
*/
class quiz_obj
{
    public:
    //create an array of the size passes filled with random number between 0-100
    quiz_obj(int);

    //delete all dynamic memory 
    ~quiz_obj();

    // delete old memory and than deep copy
    const quiz_obj& operator=(const quiz_obj&);

    //deep copy
    quiz_obj(const quiz_obj&);

    //prints out the array
    friend std::ostream& operator<<(std::ostream&, const quiz_obj&);

    //remove all odd numbers from the array
    void remove_odds();
    
private:
    //you can not add more variables
    int * size; //size of the array
    int * arr; // array to store the ints
};
 void quiz_obj::remove_odds(){
      
 }

std::ostream& operator<<(std::ostream& out, const quiz_obj& obj){
   return out;
}

quiz_obj::quiz_obj(int n)
{
 
}

quiz_obj::~quiz_obj()
{
    
}

const quiz_obj& quiz_obj::operator=(const quiz_obj& rhs){
    return *this;
}

quiz_obj::quiz_obj(const quiz_obj& rhs){
    
}


#endif