#include <iostream>
#include <vector>


void sel_sort_r(std::vector<int> & v, int n){
    if(n == 1){
        return;
    }
    int m = 0;
    int c = 0;
    for(int i = 1; i < n; i++){
        if(v[m] < v[i]){ //<-
            m = i;
        }
    }
    int temp = v[n-1];
    v[n-1]= v[m];
    v[m] = temp;
    return sel_sort_r(v,n-1);
}

void sel_sort_r(std::vector<int> & v){
    return sel_sort_r(v,v.size());
}

void sel_sort(std::vector<int> & v){
    for(unsigned i = 0; i < v.size(); i++){
        int m = i;
        for(unsigned j = i+1; j < v.size(); j++){
            if(v[j] < v[m]){
                m = j;
            }
        }
        int temp = v[m];
        v[m] = v[i];
        v[i] = temp;
    }
}

int main(){
    std::vector<int> v = {43,2,67,1,7,3,9,19,4};
    sel_sort(v);
    for(auto x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;

}