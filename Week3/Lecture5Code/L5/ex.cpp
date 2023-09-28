#include <iostream>
#include <vector>

int f(int n){
    if(n == 1){
        return 1;
    }

    return n * f(n-1);

}

//sum up all the values in the vector
/*int sum_vector(std::vector<int> & v, int i=0){
    if(i == static_cast<int>(v.size())){
        return 0;
    }
    return v[i] + sum_vector(v,i+1);
}*/
/*
int sum_vector(std::vector<int> & v, int i){
    if(i == 0){
        return v[0];
    }
    return v[i] + sum_vector(v,i-1);
}
int sum_vector(std::vector<int> &v){
    if(v.size() == 0){
        return 0;
    }
    return sum_vector(v,v.size()-1);
}
*/

int sum_vector(std::vector<int> & v, int low,int high){
    if(low == high){
        return v[low];
    }
    int mid = (low + high)/2;
    return sum_vector(v,low,mid) + sum_vector(v,mid+1,high);
}
int sum_vector(std::vector<int> &v){
    if(v.size() == 0){
        return 0;
    }
    return sum_vector(v,0,v.size()-1);
}

int bin_s(std::vector<int> &v, int key, int low ,int high){
    if(low > high){
        return -1;
    }
    int mid = (low +high)/2;
    if(v[mid] == key){
        return mid;
    }else if(v[mid] > key){
        return bin_s(v,key,low,mid-1);
    }else{
        return bin_s(v,key,mid+1,high);
    }
}
int bin_s(std::vector<int> &v,int key){
    return bin_s(v,key,0,v.size()-1);
}

int main(){
    std::vector<int> v = {1,3,6,9,12,16,21,38,50};
    //std::cout << f(5);
    std::cout << bin_s(v,-8);
}