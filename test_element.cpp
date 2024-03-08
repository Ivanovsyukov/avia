#include <iostream>
#include <fstream>
#include <cstring>
#include "ticket.h"
#include "array.h"
#include "utils.h"

int main(){
    Array<char> number1;
    number1.push_back('1');
    number1.push_back('2');
    number1.push_back('3');
    Array<char> number2;
    number2.push_back('2');
    number2.push_back('2');
    number2.push_back('3');
    int result=number1.str_to_int(number1)+number2.str_to_int(number2);
    std::cout<<result<<std::endl;
    return 0;
}