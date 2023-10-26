
#ifndef LINE_H 
#define LINE_H

#include <iostream>
#include <cmath>
#include <iostream>
#include <cstdlib>


class Line {
   public:
      Line(int,int,int,int);
      bool operator==(const Line &);
      friend std::ostream& operator<<(std::ostream&, const Line &);
      friend Line operator+(int, const Line &);
      friend Line operator+(const Line &,int);
      friend Line operator*(const Line &,int);
      Line operator-();
     
   private:
      int x1,y1,x2,y2;
      double dist() const;
};

Line::Line(int a,int b,int c,int d){
   x1 = a;
   y1 = b;
   x2 = c;
   y2 = d;
}

double Line::dist() const{
   return sqrt(pow(x1-x2,2)+ pow(y1-y2,2));
}

bool Line::operator==(const Line & rhs){
   return dist() == rhs.dist();
}

std::ostream& operator<<(std::ostream& out, const Line & rhs){
   out << "(" << rhs.x1 << "," << rhs.y1 <<  ")(" << rhs.x2 << "," << rhs.y2 <<  ") ";
   out << "dist = " << rhs.dist();
   return out;
}

Line operator+(int a, const Line & rhs){
   return Line(rhs.x1 + a,rhs.y1, rhs.x2+a,rhs.y2);
}

Line operator+(const Line & lhs,int a){
   return Line(lhs.x1,lhs.y1 + a, lhs.x2,lhs.y2+ a);
}
Line operator*(const Line & lhs,int a){
   return Line(lhs.x1,lhs.y1, lhs.x2*a,lhs.y2* a);
}
Line Line::operator-(){
   return Line(x2,y2,x1,y1);
}

#endif  

