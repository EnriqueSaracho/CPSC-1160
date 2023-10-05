#include <iostream>
#include <fstream>

int main(){
    std::ifstream fin;
    std::string line;
    char c;
    int x ,y;
    fin.open("numTest.txt");

    if(fin.is_open()){
        //while(getline(fin,line)){
        while(fin >> line){
        //while(!fin.eof()){
            std::cout << line << std::endl;
            //fin >> x >> y;
            //std::cout << (x+y) << std::endl;
        }
        fin.close();
    }

}