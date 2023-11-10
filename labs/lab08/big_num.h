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

   void print();

private:
   struct node
   {
      int data;
      node *next;
   };
   node *head = nullptr;
   int n; // length of digits array
};

big_num::big_num(std::string str)
{
   n = str.size();
   for (int i = 0; i < n; i++)
   {
      head = new node{(str[i] - '0'), head};
   }
}

big_num big_num::operator+(const big_num &y)
{
   std::string str;
   int s, c = 0;
   node *b = head;
   node *a = y.head;

   while (a && b)
   {
      s = (a->data + b->data + c) % 10;
      str += (s + '0');

      if ((a->data + b->data + c) > 9)
         c = 1;
      else
         c = 0;

      a = a->next;
      b = b->next;
   }

   while (a)
   {
      s = (a->data + c) % 10;
      str += (s + '0');

      if ((a->data + c) > 9)
         c = 1;
      else
         c = 0;
      a = a->next;
   }
   while (b)
   {
      s = (b->data + c) % 10;
      str += (s + '0');

      if ((b->data + c) > 9)
         c = 1;
      else
         c = 0;
      b = b->next;
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
   std::string str = "";
   big_num::node *p = x.head;
   while (p)
   {
      str += p->data + '0';
      p = p->next;
   }
   for (int i = x.n - 1; i > -1; i--)
   {
      out << str[i];
   }
   return out;
}

#endif