#include <iostream>
#include <fstream>
#include <cstring>
#include "database.h"
#include "ticket.h"
#include "array.h"
#include "utils.h"

int main(){
    Array<Ticket> for_sort;
    char* input="add CA-909, PKX, SVO, 19.02.2024 8:40, 19.02.2024 17:00, 5, 80499";
    Ticket prime1(input);
    input="add CA-909, PKX, SVO, 19.02.2024 8:39, 19.02.2024 17:00, 5, 80499";
    Ticket prime2(input);
    input="add CA-909, PKX, SVO, 19.02.2024 8:45, 19.02.2024 17:00, 5, 80499";
    Ticket prime3(input);
    for_sort.push_back(prime1);
    for_sort.push_back(prime2);
    for_sort.push_back(prime3);
    for_sort.sort(time_from_ticket);
    std::cout<< for_sort <<std::endl;
    /*
    DataBase all;
    char* input="add CA-909, PKX, SVO, 19.02.2024 8:40, 19.02.2024 17:00, 5, 80499";
    Ticket prime1(input);
    all.addRecord(prime1);
    delete[] input;
    input="add CA-909, PKX, SVO, 19.02.2024 8:39, 19.02.2024 17:00, 5, 80499";
    Ticket prime2(input);
    all.addRecord(prime2);
    delete[] input;
    input="add CA-909, PKX, SVO, 19.02.2024 8:45, 19.02.2024 17:00, 5, 80499";
    Ticket prime3(input);
    all.addRecord(prime2);
    delete[] input;
    Array<char> air;
    air.push_back('P');
    air.push_back('K');
    air.push_back('X');
    date my;
    my.day=19;
    my.mounth=2;
    my.year=2024;
    my.hour=0;
    my.day=0;
    all.schedule(air, my);
    */
    /*
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
    */
    return 0;
}