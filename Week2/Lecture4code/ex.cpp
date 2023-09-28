#include <iostream>
const int MAX_SIZE = 100;
void rev_array(int[],int);
//reverse an array
void rev_array(int a[],int size){
    for(int i = 0; i <size/2; i++){
        int tmp = a[i];
        a[i] = a[size-i-1];
        a[size-i-1] = tmp;
    }
}

void times_by_2(int a[],int size){
    for(int i = 0; i < size; i++){
        a[i]*=2;
    }
}

void print(int a[], int size){
    for(int i = 0; i < size; i++){
        std::cout << a[i] <<std::endl;
    }
}

void print(int a[][3], int row,int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            std::cout << a[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}
int main(){
    //DO NOT DO THIS
    //int size;
    //std::cout << "Enter the size ofn the array (most ne 100 or less)" << std::endl;
    //std::cin >> size;
    //int d[size]
    const int size = 5;
    int d[size] = {1,2,3};
    d[4] = 100;
    print(d,size);
    //times_by_2(d,size);
    rev_array(d,size);
    print(d,size);
    int m[2][3];
    m[0][1] = 5;
    print(m,2,3);
    return 0;
}