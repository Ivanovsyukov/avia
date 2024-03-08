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
    number1.push_back('.');
    number1.push_back('3');
    Array<char> number2;
    number2.push_back('2');
    number2.push_back('2');
    number2.push_back('.');
    number2.push_back('3');
    double result=number1.str_to_double(number1)+number2.str_to_double(number2);
    std::cout<<result<<std::endl;
    return 0;
}