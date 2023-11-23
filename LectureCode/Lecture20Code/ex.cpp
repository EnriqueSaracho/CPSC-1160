#include <iostream>
#include <cctype>
#include <vector>
#include <cmath>
#include "stack.h"
#include "queue.h"



struct state{
    int row;
    int col;
};

int path_s(const std::vector<std::vector<int>> & m){
    queue<state> s;
    int count = 0;
    if(m[0][0] == 0){
        return -1;
    }
    s.enqueue({0,0});
    
    while(!s.isEmpty()){
        state tmp = s.dequeue();
        if(tmp.row >= m.size() || tmp.col >= m[tmp.row].size() || m[tmp.row][tmp.col] == 0){
        }else if(tmp.row == m.size()-1 && tmp.col == m[tmp.row].size() -1 ){
            count++;

        }else{
            s.enqueue({tmp.row+1,tmp.col});
            s.enqueue({tmp.row,tmp.col+1});
        }
    }
    return count;
}

int path(const std::vector<std::vector<int>> & m,int count=0,int row = 0, int col = 0){
    //dead end
    if(row >= m.size() || col >= m[row].size() || m[row][col] == 0){
        return 0;
    }
    //path found
    if(row == m.size()-1 && col == m[row].size() -1 ){
        return 1;
    }
    int x = path(m,count + m[row][col],row+1,col);
    int y = path(m,count+ m[row][col],row,col+1);
    return x + y;
}

//should check to see if the string that is passes in has correct brackets
//only look at () and []


int main(){
    std::vector<std::vector<int>> m = {{1,2,0,1},{2,4,2,2},{0,10,2,1}};

    
    for(auto x : m){
        for( auto y : x){
            std::cout << y << " ";
        }
        std::cout << std::endl;
    }
    
    std::cout << path_s(m) << std::endl;

    queue<int> Q;
    Q.enqueue(1);
    Q.enqueue(2);
    Q.enqueue(3);
    Q.enqueue(4);
    Q.enqueue(5);
    Q.dequeue();
    Q.enqueue(6);
    while(!Q.isEmpty()){
        std::cerr << Q.dequeue() <<  " ";
    }
    
}