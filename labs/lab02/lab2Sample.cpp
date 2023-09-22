#include <iostream>
#include <vector>
#include <cmath>

/*  Displays each integer number from 0 to 'n' to the console.
      Input:  integer 'n'.
      Output: console message.
*/
void forward(int n)
{
  if (n > 0)
    forward(n - 1);
  std::cout << n << ",";
};

/*  Displays each integer number from 'n' to 0.
      Input:  integer 'n'.
      Output: console message.
*/
void backward(int n)
{
  std::cout << n << ",";
  if (n > 0)
    backward(n - 1);
};

/*  Returns the sum of all integer numbers from 0 to 'n'.
      Input:  integer 'n'.
      Output: integer value representing the sum.
 */
int sumR(int n)
{
  if (n < 1)
    return n;
  return (n + sumR(n - 1));
};

/*  Returns the sum of all digit numbers in 'n'.
      Input:  integer 'n'.
      Output: integer value representing the sum.
*/
int sumDigits(int n)
{
  if (n <= 0)
    return n;
  return (n % 10 + sumDigits(n / 10));
};

/*  Returns the maximum value in a vector.
      Input:  vector of integers 'v'.
      Output: integer representing the maximum value.
 */
int maxR(const std::vector<int> &v, int i = 0)
{
  if (i == v.size() - 1)
    return v[i];
  if (v[i] > maxR(v, i + 1))
    return v[i];
  else
    return maxR(v, i + 1);
};

/*  Reverses the values in a vector.
      Input: referenced vector of integers 'v'.
      Output: reversed referenced vector of integers 'v.
*/
void revV(std::vector<int> &v, int i = 0)
{
  if (i < v.size() / 2)
  {
    v[i] += v[v.size() - i - 1];
    v[v.size() - i - 1] = v[i] - v[v.size() - i - 1];
    v[i] -= v[v.size() - i - 1];
    revV(v, i + 1);
  }
};

int main()
{
  int n;
  std::vector<int> v = {3, 16, 2, 19, 7, 11, 3};
  std::cout << "Enter an positive integer:";
  std::cin >> n;
  forward(n);
  std::cout << std::endl;
  backward(n);
  std::cout << std::endl;
  std::cout << sumR(n) << std::endl;
  std::cout << "Enter an positive integer:";
  std::cin >> n;
  std::cout << sumDigits(n) << std::endl;
  std::cout << "Max in vector = " << maxR(v) << std::endl;
  revV(v);
  std::cout << "The vector is now reversed" << std::endl;
  std::cout << "[";
  for (auto i : v)
  {
    std::cout << i << ",";
  }
  std::cout << "]" << std::endl;
  return 0;
}