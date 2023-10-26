#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class point{
    public:
        //What it does
        //input
        //output
        point(int a, int b = 10);

        point();
        void print();
        point mid(point& p);
        double dist(point & p);
        friend bool operator==(point & p,point & q);
        bool operator==(int x);
        friend bool operator==(int a, point & p);
        friend std::ostream & operator<<(std::ostream & out, const point & p);
        
    private:
        int x;
        int y;
};

point::point(int a, int b){
    x = a;
    y = b;
}
point::point(){
    x = 0;
    y = 0;
}
void point::print(){
    std::cout << "(" << x << "," << y << ")" << std::endl;
}
point point::mid(point& p){
    return point((x + p.x)/2, (y + p.y)/2);
}
double point::dist(point & p){
    return sqrt(pow(x-p.x,2) + pow(y-p.y,2));
}
bool operator==(point & p,point & q){
    return q.x == p.x && q.y == p.y;
}
bool point::operator==(int a){
    return x == a;
}

bool operator==(int a, point & p){
    return p.x == a;
}

std::ostream & operator<<(std::ostream & out, const point & p){
    out << "(" << p.x << "," << p.y << ")";
    return out;
}

#endif