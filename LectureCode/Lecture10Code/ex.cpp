#include <vector>
#include <iostream>
#include <ctime>
#include <cmath>

struct point{
    int x = rand()%15;
    int y = rand()%15;

    void print(){
        std::cout << x << " " << y << std::endl;
    }
    bool comp(point & q){
        return x == q.x && y == q.y;
    }

    point mid(point & p){
        point r;
        r.x = (p.x+ x)/2;
        r.y = (p.y + y)/2;
        return r;
    }
    double dist(point & p){
        return sqrt(pow(x - p.x,2)+ pow(y - p.y,2));
    }

};

double closest_dist(std::vector<point> & p_v){
    if(p_v.size() < 2){
        return 0;
    }
    double min = p_v[0].dist(p_v[1]);
    for(unsigned i = 0; i < p_v.size(); i++){
        for(unsigned j = i+1; j < p_v.size(); j++){
            if(min > p_v[i].dist(p_v[j])){
                min =  p_v[i].dist(p_v[j]);
            }
        }
    }
    return min;
}



int main(){
    srand(time(0));
    point p = {9,10};
    point q = p;
    //std::cout << p.x << " " << p.y << std::endl;
    //std::cout << q.x<< " " << q.y << std::endl;
    p.print();
    q.print();
    std::cout << p.comp(q) << std::endl;
    p.x = 12;
    p.y = 5;
    //std::cout << p.x << " " << p.y << std::endl;
    //std::cout << q.x<< " " << q.y << std::endl;
    p.print();
    q.print();
    std::cout << p.comp(q) << std::endl;
    point w = p.mid(q);
    w.print();
    std::cout << w.dist(q) << std::endl;

    std::vector<point> v_p(10);
    for(auto & x : v_p){
        x.print();
    }
    std::cout << closest_dist(v_p) << std::endl;
}