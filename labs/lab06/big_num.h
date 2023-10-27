#ifndef BIGNUM_H
#define BIGNUM_H
#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

class big_num
{
public:
   // Should read in a string of only digits and store it in digits in reverse order
   // So "123" should be store as [3,2,1]
   // reverse order will make the math easier.
   big_num(std::string);

   // should print out the big_num
   friend std::ostream &operator<<(std::ostream &out, big_num &);

   // should add to big_nums together
   big_num operator+(const big_num &);

   // These three functions will manage memory
   // ~big_num();
   // big_num(const big_num &);
   // const big_num &operator=(const big_num &);

private:
   int *digits; // an array of numDigits digits
   int n;       // length of digits array
};

big_num::big_num(std::string str)
{
   n = str.size();
   digits = new int[n];
   for (int i = n - 1, j = 0; i > -1; i--, j++)
   {
      digits[j] = str[i] - '0';
   }
}

big_num big_num::operator+(const big_num &y)
{
   std::string str;
   int s, c = 0;
   for (int i = 0; (i < n || i < y.n); i++)
   {
      if (i > (n - 1) && i < (y.n - 1))
         s = (0 + y.digits[i] + c) % 10;
      else if (i < (n - 1) && i > (y.n - 1))
         s = (digits[i] + 0 + c) % 10;
      else
         s = (digits[i] + y.digits[i] + c) % 10;
      str += (s + '0');
      if ((digits[i] + y.digits[i] + c) > 9)
         c = 1;
      else
         c = 0;
   }
   if (c == 1)
   {
      str += '1';
      n++;
   }
   std::string rev;
   for (int i = str.size() - 1; i > -1; i--)
   {
      rev += str[i];
   }
   if (c == 1)
      n--;
   return big_num(rev);
}

std::ostream &operator<<(std::ostream &out, big_num &x)
{
   for (int i = x.n - 1; i > -1; i--)
   {
      out << x.digits[i];
   }
   return out;
}

#endif