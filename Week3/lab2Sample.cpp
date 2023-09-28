#include <iostream>
#include <vector>
#include <cmath>

void forward(int n);
void backward(int n);
int sumR(int n);
int sumDigits(int n);
int maxR(const std::vector<int> &v,int i = 0);
void revV(std::vector<int> &v,int i = 0);

int main(){
  int n;
  std::vector<int> v = {3,16,2,19,7,11,3};
  std::cout <<"Enter an positive integer:";
  std::cin >> n;
  forward(n);
  std::cout << std::endl;
  backward(n);
  std::cout << std::endl; 
  std::cout << sumR(n) << std::endl;
  std::cout <<"Enter an positive integer:";
  std::cin >> n;
  std::cout << sumDigits(n) << std::endl;
  std::cout << "Max in vector = " << maxR(v) << std::endl; 
  revV(v);
  std::cout << "The vector is now reversed" << std::endl;
  std::cout << "[";
  for(auto i:v){
    std::cout << i << ",";
  }  
  std::cout << "]" << std::endl;
  return 0; 
   
}