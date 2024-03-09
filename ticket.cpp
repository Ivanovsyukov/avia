#include "ticket.h"
#include <fstream>
#include <cstring>
#include "utils.h"

Ticket::Ticket(const char* data){
    size_t len=strlen(data);
    char s=0;
    unsigned int ind=0;
    unsigned int mistake=0;
    Array<char> for_m;
    unsigned int indate=0;
    unsigned int point_last=0;
    Array<char> element;
    bool miss=false;
    for(size_t i=0; i<len && int(data[i])!=0 && !miss && point_last<3; ++i){
        s=data[i];
        if(s==' ' || point_last==2){
            if (mistake!=0){
                miss=true;
            } else {
                if (ind==8){
                    count_ticket_=for_m.str_to_int();
                } else if(ind==9){
                    sale_=for_m.str_to_double();
                }
                ++ind;
                for_m=Array<char>(0);
                if (ind>=4 && ind<=7){
                    indate=0;
                    element=Array<char>(0);
                } else if (ind==9){
                    indate=0;
                    point_last=0;
                }
            }
        } else if (s!=','){
            switch (ind){
            case 1:
                numeral_.push_back(s);
                if (numeral_.size()>7){
                    mistake=1;//Неверный номер
                }
                break;
            case 2:
                from_.push_back(s);
                if (from_.size()>3){
                    mistake=2;//Неверный номер от
                }
                break;
            case 3:
                to_.push_back(s);
                if (to_.size()>3){
                    mistake=3;//Неверный номер до
                }
                break;
            case 4:
                for_m.push_back(s);
                if ((s>='0' && s<='9')||(s=='.')){
                    if (s=='.'){
                        if (indate==0){
                            date_from_.day=element.str_to_int();
                        } else if (indate==1){
                            date_from_.mounth=element.str_to_int();
                        } else if (indate==2){
                            date_from_.year=element.str_to_int();
                        } else {
                            mistake=4;
                        }
                        ++indate;
                        element=Array<char>(0);
                    } else {
                        element.push_back(s);
                    }
                } else {
                    mistake=4;//Неверный формат даты
                }
                break;
            case 5:
                for_m.push_back(s);
                if ((s>='0' && s<='9')||(s==':')){
                    if (s=='.'){
                        if (indate==0){
                            date_from_.hour=element.str_to_int();
                        } else if (indate==1){
                            date_from_.minutes=element.str_to_int();
                        } else {
                            mistake=5;
                        }
                        ++indate;
                        element=Array<char>(0);
                    } else {
                        element.push_back(s);
                    }
                } else {
                    mistake=5;//Неверный формат времени
                }
                break;
            case 6:
                for_m.push_back(s);
                if ((s>='0' && s<='9')||(s=='.')){
                    if (s=='.'){
                        if (indate==0){
                            date_to_.day=element.str_to_int();
                        } else if (indate==1){
                            date_to_.mounth=element.str_to_int();
                        } else if (indate==2){
                            date_to_.year=element.str_to_int();
                        } else {
                            mistake=7;
                        }
                        ++indate;
                        element=Array<char>(0);
                    } else {
                        element.push_back(s);
                    }
                } else {
                    mistake=7;//Неверный формат даты
                }
                break;
            case 7:
                for_m.push_back(s);
                if ((s>='0' && s<='9')||(s==':')){
                    if (s=='.'){
                        if (indate==0){
                            date_to_.hour=element.str_to_int();
                        } else if (indate==1){
                            date_to_.minutes=element.str_to_int();
                        } else {
                            mistake=8;
                        }
                        ++indate;
                        element=Array<char>(0);
                    } else {
                        element.push_back(s);
                    }
                } else {
                    mistake=8;//Неверный формат времени
                }
                break;
            case 8:
                if(s>='0' && s<='9'){ 
                    for_m.push_back(s);
                } else {
                    mistake=9;//Неверная команда
                }
                break;
            case 9:
                for_m.push_back(s);
                if((s>='0' && s<='9')||(s=='.')){ 
                    if (s=='.'){
                        if(indate==1){
                            mistake=11;//Неверная команда
                        }
                        ++indate;
                    } else {
                        if(indate==1){
                            ++point_last;
                        }
                    }
                } else {
                    mistake=10;//Неверная команда
                }
                break;
            default:
                break;
            }
        }
        if (miss){
            std::cout<<mistake<<std::endl;
            throw "Misstake";
        }
    }
}