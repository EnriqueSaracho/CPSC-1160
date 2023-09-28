#include <vector>
#include <iostream>
void times_by_2(std::vector<int>&);

void times_by_2(std::vector<int> &v){
    for(auto & x : v){
        x *= 2;
    }
}

std::vector<int> rev_(std::vector<int> a){
    for(int i = 0; i <a.size()/2; i++){
        int tmp = a[i];
        a[i] = a[a.size()-i-1];
        a[a.size()-i-1] = tmp;
    }
    return a;
}


int main(){
    int size = 8;
    std::vector<int> v(size);
    v.push_back(0);
    int i = 0;
    for(auto & x : v){
        x = i++;
    }
    times_by_2(v);
    for(unsigned i = 0; i < v.size();i++){
       std::cout << v[i] <<std::endl;
    }

    std::vector<std::vector<int>>m(2,std::vector<int>(3));
    m.push_back(std::vector<int>(3));
    
    //for(auto & row : m){
    //    for(auto & x : row){
    //        std::cout << x << " ";
    for(unsigned i = 0; i < m.size();i++){
        for(unsigned j = 0; j < m[i].size();j++){
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
    //std::cout << v[0] <<std::endl;

}