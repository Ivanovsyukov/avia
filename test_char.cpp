#include <iostream>

int main(){
    const int SIZE=100;
    char str[SIZE]={};
    std::cin.getline(str,SIZE);
    for(int i=0; i<SIZE; ++i){
        std::cout << str[i];
    }
    delete[] str;
    char str[SIZE]={};
    std::cin.getline(str,SIZE);
    for(int i=0; i<SIZE; ++i){
        std::cout << str[i];
    }
    return 0;
}