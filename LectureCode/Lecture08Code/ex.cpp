#include <iostream>
#include <vector>

void in_sr(std::vector<int> & v, int i = 1){
    if(i == v.size()){
        return;
    }
    int tmp = v[i];
    int j;
    for(j = i-1; j >= 0 && tmp < v[j]; j--){
        v[j+1] = v[j];
    }
    v[j+1] = tmp;
    in_sr(v,i+1);
}


int in_s(std::vector<int> & v){
    int count = 0;
    for(unsigned i = 1; i < v.size(); i++){
        int tmp = v[i];
        int j;
        for(j = i-1; j >= 0 && ++count && tmp < v[j]; j--){
            v[j+1] = v[j];
        }
        v[j+1] = tmp;
    }
    return count;
}

int path(std::vector<std::vector<int>> & m,unsigned r = 0, unsigned c = 0, int p_s = 0){
    if(r == m.size() || c == m[r].size() || m[r][c] == 0){
        return -1;
    }
    p_s += m[r][c];
    if(r == m.size()-1 && c == m[r].size()-1){
        return p_s;
    }
    
    int a = path(m,r+1,c,p_s);
    int b = path(m,r,c+1,p_s);

    if( a == -1 && b == -1){
        return -1;
    }
    if(a == -1){
        return b;
    }
    if(b == -1){
        return a;
    }
    if(a < b){
        return a;
    }
    return b;
}
int main(){
    std::vector<std::vector<int>>  m = {{1, 2, 4, 0, 4}, 
                                        {4, 3, 3, 2, 4},
                                        {0, 0, 1, 2, 1},
                                        {1, 0, 2, 2, 1},
                                        {1, 4, 2, 3, 2}};
    std::vector<int> v = {1,2,3,4,6,5,7,8,9,10};
    std::cout << path(m) << std::endl;
    in_sr(v);
    for(auto x : v){
        std::cout << x << " ";
    }
    std::cout << std::endl;


}