#include <iostream>
#include <cmath>      
#include <cstdlib>   
#include <ctime>
#include <fstream>

//Remeber to comment this function
void get_coefficients(std::ifstream& fin, int& a, int& b,int& c, int& d){
 
}

//Remeber to comment this function
void print_starting_equation(int a, int b, int c , int d){

}

//Remeber to comment this function
void cal_new_coefficients(int a, int b,int c, int d, int& x, int& xy,int& y){

}
//Remeber to comment this function
void print_expanded_equation(int x,int xy,int y){
 
}

int main()
{
   int a,b,c,d,x,xy,y;
   std::string myFile;
   std::cout << "Which file would you like to process" << std::endl;
   std::cin >> myFile;
   std::ifstream fin;
   fin.open(myFile);
   if (fin.is_open())
   {
      while ( !fin.eof() )
      {
         get_coefficients(fin,a,b,c,d);
         print_starting_equation(a,b,c,d);
         cal_new_coefficients(a,b,c,d,x,xy,y);
         print_expanded_equation(x,xy,y);
      }
      fin.close();
   }


   return 0;
}

