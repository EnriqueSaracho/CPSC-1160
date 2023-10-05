#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

/* Reads the coefficients from each line of the input file.
   Input:   Referenced integer variables a, b, c, d.
            Referenced ifstream fin.
   Output:  Referenced integer variables a, b, c, d with updated values.
*/
void get_coefficients(std::ifstream &fin, int &a, int &b, int &c, int &d)
{
   fin >> a >> b >> c >> d;
}

/* Prints the starting equation ((ax+by)(cx+dy)) with the values from the coefficients.
   Input:   integer variables a, b, c, d.
   Output:  the starting equation in a console message.
*/
void print_starting_equation(int a, int b, int c, int d)
{
   std::cout << "(" << a << "x" << ((b < 0) ? "" : "+") << b << "y)(" << c << "x" << ((d < 0) ? "" : "+") << d << "y)" << std::endl;
}

/* Uses the already stored coefficients to calculate the new ones.
   Input:   Integer variables a, b, c, d.
            Referenced integer variables x, xy, y.
   Output:  Referenced integer variables x, yx, y with updated values.
*/
void cal_new_coefficients(int a, int b, int c, int d, int &x, int &xy, int &y)
{
   x = a * c;
   xy = a * d + b * c;
   y = b * d;
}

/* Prints the expanded equation.
   Input:   Integer variables x, xy, y.
   Output:  The expanded equations in a console message.
*/
void print_expanded_equation(int x, int xy, int y)
{
   if (x == 0 && xy == 0 && y == 0)
      std::cout << 0 << std::endl;
   else
   {
      if (x != 0)
      {
         if (x != 1)
         {
            if (x == -1)
               std::cout << "-";
            else
               std::cout << x;
         }
         std::cout << "x^2";
      }
      if (xy != 0)
      {
         if (x != 0 && xy > 0)
            std::cout << "+";
         if (xy != 1)
         {
            if (xy == -1)
               std::cout << "-";
            else
               std::cout << xy;
         }
         std::cout << "xy";
      }
      if (y != 0)
      {
         if (x != 0 && xy != 0 && y > 0)
            std::cout << "+";
         if (y != 1)
         {
            if (xy == -1)
               std::cout << "-";
            else
               std::cout << y;
         }
         std::cout << "y^2";
      }
      std::cout << std::endl;
   }
}

int main()
{
   int a, b, c, d, x, xy, y;
   std::string myFile;
   std::cout << "Which file would you like to process" << std::endl;
   std::cin >> myFile;
   std::ifstream fin;
   fin.open(myFile);
   if (fin.is_open())
   {
      while (!fin.eof())
      {
         get_coefficients(fin, a, b, c, d);
         print_starting_equation(a, b, c, d);
         cal_new_coefficients(a, b, c, d, x, xy, y);
         print_expanded_equation(x, xy, y);
      }
      fin.close();
   }

   return 0;
}
