#ifndef WOMBAT_H
#define WOMBAT_H

class point{

    public:
        point(int,int);
        
        point (const point & );
        ~point();
        const point& operator=(const point &);


    private:
        int * x;
        int y;
};

point::point(int x, int y){
    this->x = new int(x);
    this->y = y;
}

point::~point(){
    std::cout << "DELETE" << std::endl;
    delete x;
}

point::point (const point & rhs){
    y = rhs.y;
    x = new int(*rhs.x);
}

const point& point::operator=(const point & rhs){
    if(this == &rhs){
        return *this;
    }
    delete this->x;
    this->y = rhs.y;
    this->x = new int(*rhs.x);
    return *this;

}

#endif