#include <iostream>
#include <vector>

int lin_s(const std::vector<int> & v, int key ,int low , int high){
    if(low == high){
        if(v[low]== key){
            return low;
        }
        return -1;
    }
    int mid = (low+high)/2;
    int a = lin_s(v,key,low,mid);
    int b = lin_s(v,key,mid+1,high);
    if(a > b){
        return a;
    }
    return b;
}

int lin_s(const std::vector<int> & v, int key){
    return lin_s(v,key, 0,v.size()-1);
}

void bin_gen(int k,int base,std::string s = ""){
    if(k == 0){
        std::cout << s << std::endl;
        return;
    }
    for(int i = 0 ; i < base; i++){
        bin_gen(k-1,base,s+std::to_string(i));
    }
}

void dec_2_bin(int x){
    if(x != 0 ){
        dec_2_bin(x/2); 
        std::cout << (x%2);
        
    }
}
bool is_asc(std::vector<int> & v, unsigned i =0){
    if(i == v.size()-1){
        return true;
    }
    return v[i] < v[i+1] && is_asc(v,i+1);
}
bool is_pali(const std::string & str, int low, int high){
    if(low >= high){
        return true;
    }
    /*if(str[low] != str[high]){
        return false;
    }
    return is_pali(str,low+1,high-1);*/
    return str[low] == str[high] && is_pali(str,low+1,high-1);
}

bool is_pali(const std::string & str){
    return is_pali(str,0,str.size()-1);
}

int main(){
    std::vector<int> ov = {1,2,3,4,5,6,7};
    std::vector<int> uv = {1,2,3,5,4};
    std::cout << is_pali("racgr") << std::endl;
    std::cout << is_asc(ov) << std::endl;
    std::cout << is_asc(uv) << std::endl;
    //dec_2_bin(10);
    std::cout << std::endl;
    //bin_gen(3,3);
    std::cout << lin_s(uv,9) << std::endl;
    return 0;
}