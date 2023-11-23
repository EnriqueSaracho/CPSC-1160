#include <iostream>
#include <cctype>
#include <vector>
#include <cmath>
#include "stack.h"

struct state{
    int row;
    int col;
    int cost;
};


int path_s(const std::vector<std::vector<int>> & m){
    stack<state> s;
    int count = -1;
    s.push({0,0,0});

    while(!s.isEmpty()){
        state tmp = s.pop();
        if(tmp.row >= m.size() || tmp.col >= m[tmp.row].size() || m[tmp.row][tmp.col] == 0){
            
        }
        else if(tmp.row == m.size()-1 && tmp.col == m[tmp.row].size() -1 ){
            tmp.cost += m[tmp.row][tmp.col];
            if(count == -1){
                count = tmp.cost;
            }else if(count > tmp.cost){
                count = tmp.cost;
            }
        }else{
            s.push({tmp.row+1,tmp.col,tmp.cost + m[tmp.row][tmp.col]});
            s.push({tmp.row,tmp.col+1,tmp.cost + m[tmp.row][tmp.col]});
        }
   
    }

    return count;
}

int path(const std::vector<std::vector<int>> & m,int row = 0, int col = 0){
    //dead end
    if(row >= m.size() || col >= m[row].size() || m[row][col] == 0){
        return 0;
    }
    //path found
    if(row == m.size()-1 && col == m[row].size() -1 ){
        return 1;
    }
    return path(m,row+1,col)+path(m,row,col+1);
}





//should check to see if the string that is passes in has correct brackets
//only look at () and []
bool brac_check(const std::string & str){
    stack<char> s;

    for( auto x : str){
        if(x == '('){
            s.push(')');
        }else if(x == '['){
            s.push(']');
        }else if( x == ']' || x == ')'){
            if(s.isEmpty() || s.pop() != x){
                return false;
            }
            
        }
    }

    return s.isEmpty();
}

int main(){
    std::vector<std::vector<int>> m = {{1,2,0,1},{2,4,2,2},{0,10,2,1}};

    
    for(auto x : m){
        for( auto y : x){
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << path_s(m) << std::endl;
    std::cout << brac_check("[][](([]))") << std::endl;
    std::cout << brac_check("[][") << std::endl;
    std::cout << brac_check("[]]") << std::endl;
    std::cout << brac_check("[([)]]") << std::endl;

    
    
}