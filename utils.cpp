#include "utils.h"
#include <fstream>

bool srav_str(const char* one,  const char* two){//сравнение строк
    int i=0;
    char s1=one[i];
    char s2=two[i];
    while(s1!=0 && s2!=0 && s1==s2){
        ++i;
        s1=one[i];
        s2=two[i];
    }
    return (s1==0 && s2==0);
}

int str_num_to_int_num(const char* number){//перевод строки в число
    int result=0;
    int i=0;
    char s=number[i];
    while(s!=0){
        result=result*10+(int)(s-'0');
        ++i;
        s=number[i];
    }
    return result;
}