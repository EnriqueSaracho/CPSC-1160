#include <iostream>
#include <vector>
#include <cctype>


int partition(std::vector<int> & v, int low,int high){
    int piv = v[low];
    
    while(low < high){
        while(low < high && piv <= v[high]){
            high--;
        }
        v[low]= v[high];
        while(low < high && piv >= v[low]){
            low++;
        }
        v[high] =v[low];
    }
    v[low] = piv;
    return low;
}

void qs(std::vector<int> & v, int low,int high){
    if(low >= high){
        return;
    }
    int piv = partition(v,low,high);
    qs(v,low,piv-1);
    qs(v,piv+1,high); 
}

void qs(std::vector<int> & v){
    qs(v,0,v.size()-1);
}


int odd_minus_even(std::vector<int> & v ,int i = 0){
    return 0;
}
std::vector<int> same_combo(std::vector<int> &v,std::vector<int> &w){
    std::vector<int> c;
    
    return c;
}
void print(std::vector<int> &v){
    for(int i : v){
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main(){
    std::vector<int> v = {3,5,3,9,3,5,-6};
    std::vector<int> v3 = {1,6,2,19,21,4,7,2,2,100,-2,-6,8};
    std::vector<int> v1 = {1,2,4,4,6,8,10,12,25,25,25};
    std::vector<int> v2 = {-4,2,4,5,7,7,10,10,10,10,16,25,25};
    std::vector<int> v4;
    std::vector<int> v5 = {1,2,3,4,5,6,7};
    std::cout << "Quick Sort Test 1" << std::endl;
    print(v);
    qs(v);
    print(v);
    std::cout << "Quick Sort Test 2" << std::endl;
    print(v3);
    qs(v3);
    print(v3);
    std::cout << "------------------" << std::endl;
    std::cout << "Combo Test 1" << std::endl;
    print(v1);
    print(v2);
    std::vector<int> c = same_combo(v1,v2);
    print(c);
    std::cout << "Combo Test 2" << std::endl;
    print(v1);
    print(v4);
    c = same_combo(v1,v4);
    print(c);
    std::cout << "Combo Test 3" << std::endl;
    print(v2);
    print(v5);
    c = same_combo(v2,v5);
    print(c);
    std::cout << "------------------" << std::endl;
    std::cout << "odd_minus_even Tests" << std::endl;
    std::cout << odd_minus_even(v) << std::endl;
    std::cout << odd_minus_even(v5) << std::endl;
    std::cout << odd_minus_even(v4) << std::endl;
   
    return 0;
}
