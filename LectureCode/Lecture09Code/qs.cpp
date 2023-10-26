#include <iostream>
#include <vector>

int part(std::vector<int> & v,int low,int high){
    int mid = (low + high)/2;
    int piv = v[mid];
    v[mid] = v[low];
    while(low < high){
        while(low <high && piv <= v[high]){
            high--;
        }
        v[low] = v[high];
        while(low < high && piv >= v[low]){
            low++;
        }
        v[high] = v[low];
    }
    v[high] = piv;
    return low;
}

void qs(std::vector<int> & v,int low,int high){
    if(low >= high){
        return;
    }
    if(low+1 == high){
        if(v[low] > v[high]){
            int temp = v[low];
            v[low] = v[high];
            v[high]= temp;
        }
        return;
    }
    int piv = part(v,low,high);
    qs(v,low,piv-1);
    qs(v,piv+1,high);
}

void qs(std::vector<int> & v){
    qs(v,0,v.size()-1);
}

int main(){
    std::vector<int> v = {5,3,9,11,11,7,4,13,8};
    qs(v);
    for(auto x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;
  
}