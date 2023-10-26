#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <cmath>

class circle{
    public:
        circle();
        //x and y are the centre of the circle
        circle(int a, int b, int rad);
        friend std::ostream& operator <<(std::ostream& out, const circle & c);
        //return a new circle with the radius a times bigger;
        circle operator *(int a);
        //check if two circle intersect
        friend bool operator==(const circle & c,const circle & b);        
    private:
        int x;
        int y;
        int r;
};


circle::circle(){
    x = 0;
    y = 0;
    r = 10;
}
circle::circle(int a, int b, int rad){
    x = a;
    y = b;
    r = rad;
}
std::ostream& operator <<(std::ostream& out, const circle & c){
    std::cout << "(" << c.x << "," << c.y << ")" << " rad = " << c.r << std::endl;
}
//return a new circle with the radius a times bigger;
circle circle::operator *(int a){
    return circle(x,y,r*a);
}
//check if two circle intersect
bool operator==(const circle & c,const circle & b){
    return sqrt(pow(c.x-b.x,2) + pow(b.y-c.y,2)) < (c.r+b.r);
}

#endif