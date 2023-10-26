#include "point.h"


int main(){
    point p(4,3); 
    point q;
    point r = p.mid(q);
    std::cout << (q == r) << std::endl;
    std::cout << (p == 4) << std::endl;
    std::cout << (4 == p) << std::endl;
    std::cout << p << "" << r << std::endl;
    p.print();
    q.print();
    r.print();
}