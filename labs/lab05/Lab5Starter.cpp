#include <iostream>
#include <ctime>
#include <cmath>
#include <vector>

const int MAX = 1000;
const char CLASS[] = {'A','B','C'};

struct Points{
   int x,y;
   char c;
   
   double dist(Points q){
      return sqrt(pow(x-q.x,2)+pow(y-q.y,2));
   }
};

int findClose(std::vector<Points> &v, Points user) {
   int min = 0;
   double dist;
   for(int i = 0; i < v.size(); i++) {
      dist = user.dist(v[i]);
      if(dist < user.dist(v[min])) {
         min = i;
      }
   }
   return min;
}

int main(){
   srand(time(0));
   
   std::vector<Points> v(MAX);

   // Generating points
   for(int i = 0; i < v.size(); i++) {
      v[i].x = rand()%10001;
      v[i].y = rand()%10001;
      v[i].c = CLASS[rand()%3];
      // std::cout << i << " x = " << v[i].x << ", y = " << v[i].y << ", c = " << v[i].c << std::endl;
   }

   // Reading user values
   Points user;
   std::cout << "Enter X and Y ";
   std::cin >> user.x;
   std::cin >> user.y;

   // Finding five closests points and assigning c value
   std::vector<Points> close(5);
   int p;
   int a = 0, b = 0, c = 0;
   for(int i = 0; i < close.size(); i++) {
      p = findClose(v, user);
      close[i] = v[p];
      v[p].x = 1000000;
      v[p].y = 1000000;
      switch(close[i].c) {
         case 'A':
            a++;
            break;
         case 'B':
            b++;
            break;
         case 'C':
            c++;
            break;
      }
   }
   if (a >= b && a >= c) {
      user.c = CLASS[0];
   } else if (b > a && b >= c) {
      user.c = CLASS[1];
   } else {
      user.c = CLASS[2];
   }

   // Print results
   std::cout << "(" << close[0].x << "," << close[0].y << ") is class " << close[0].c << " and the distance is: " << user.dist(close[0]) << std::endl;
   std::cout << "(" << close[1].x << "," << close[1].y << ") is class " << close[1].c << " and the distance is: " << user.dist(close[1]) << std::endl;
   std::cout << "(" << close[2].x << "," << close[2].y << ") is class " << close[2].c << " and the distance is: " << user.dist(close[2]) << std::endl;
   std::cout << "(" << close[3].x << "," << close[3].y << ") is class " << close[3].c << " and the distance is: " << user.dist(close[3]) << std::endl;
   std::cout << "(" << close[4].x << "," << close[4].y << ") is class " << close[4].c << " and the distance is: " << user.dist(close[4]) << std::endl;
   std::cout << "(" << user.x << "," << ") is class " << user.c << std::endl; 
}