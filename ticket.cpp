#include "ticket.h"
#include <iostream>
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
        if(s==' '){
            if (mistake!=0 || ind==9){
                miss=true;
            } else {
                if (ind==8){
                    count_ticket_=for_m.str_to_int();
                } else if(ind==4 && indate==2){
                    date_from_.year=element.str_to_int();
                } else if(ind==5){
                    date_from_.minutes=element.str_to_int();
                } else if(ind==6 && indate==2){
                    date_to_.year=element.str_to_int();
                } else if(ind==7){
                    date_to_.minutes=element.str_to_int();
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
                    if (s==':'){
                        if (indate==0){
                            date_from_.hour=element.str_to_int();
                        }else {
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
                        } else{
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
                    if (s==':'){
                        if (indate==0){
                            date_to_.hour=element.str_to_int();
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
                    }
                } else {
                    mistake=10;//Неверная команда
                }
                break;
            default:
                break;
            }
        }
    }
    if (miss){
        std::cout<<"mistake: "<< mistake<<std::endl;
        throw "Misstake";
    } else {
        sale_=for_m.str_to_double();
    }
}

Ticket::Ticket(const Ticket& other){
    numeral_=other.numeral_;
    from_=other.from_;
    to_=other.to_;
    date_from_=other.date_from_;
    date_to_=other.date_to_;
    count_ticket_=other.count_ticket_;
    sale_=other.sale_;
}


Ticket& Ticket::operator=(const Ticket& other){
    if (this!=&other){
        numeral_=other.numeral_;
        from_=other.from_;
        to_=other.to_;
        date_from_=other.date_from_;
        date_to_=other.date_to_;
        count_ticket_=other.count_ticket_;
        sale_=other.sale_;
    }
    return *this;
}

bool operator==(const Ticket& left, const Ticket& right){
    if ((left.ID()==right.ID())&&(left.from()==right.from())&&(left.to()==right.to())&&(left.date_from()==right.date_from())&&(left.date_to()==right.date_to())&&(left.count()==right.count())&&(left.sale()==right.sale())){
        return true;
    } else {
        return false;
    }
}

bool operator!=(const Ticket& left, const Ticket& right){
    if (left==right){
        return false;
    } else {
        return true;
    }
}

bool operator<(const Ticket& left, const Ticket& right){
    if (left.date_from()<right.date_from()){
        return true;
    } else if(left.date_from()==right.date_from()){
        if(left.ID()<right.ID()){
            return true;
        } else if(left.ID()==right.ID()){
            if(left.sale()<right.sale()){
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::ifstream& operator>>(std::ifstream& infile, Ticket& X){
    char* input=new char[2];
    size_t h=2;
    input[0]='a';
    input[1]=' ';
    char s;
    infile>>s;
    while(s!='\n' && s!='\r'){
        input=push_element(input, &h, s);
        infile>>s;
    }
    X=Ticket(input);
    return infile;
}

std::ofstream& operator<<(std::ofstream& outfile, const Ticket& X){
    outfile<<X.ID();
    outfile<<', '<<' ';
    outfile<<X.from();
    outfile<<', '<<' ';
    outfile<<X.to();
    outfile<<', '<<' ';
    outfile<<X.date_from();
    outfile<<', '<<' ';
    outfile<<X.date_to();
    outfile<<', '<<' ';
    outfile<<X.count();
    outfile<<', '<<' ';
    outfile<<X.sale();
    return outfile;
}

std::ostream& operator<<(std::ostream& out, const Ticket& X){
    out<<X.ID()<<", ";
    out<<X.from()<<", ";
    out<<X.to()<<", ";
    out<<X.date_from()<<", ";
    out<<X.date_to()<<", ";
    out<<X.count()<<", ";
    out<<X.sale();
    return out;
}

std::ostream& operator<<(std::ostream& out, const date& X){
    out<<X.year;
    out<<' ';
    if (X.mounth<10){
        out<<'0';
    }
    out<<X.mounth;
    out<<'.';
    if (X.day<10){
        out<<'0';
    }
    out<<X.day;
    out<<'.';
    if (X.hour<10){
        out<<'0';
    }
    out<<X.hour;
    out<<':';
    if (X.minutes<10){
        out<<'0';
    }
    out<<X.minutes;
    return out;
}

bool operator==(const date& left, const date& right){
    if ((left.day==right.day)&&(left.mounth==right.mounth)&&(left.year==right.year)&&(left.hour==right.hour)&&(left.minutes==right.minutes)){
        return true;
    } else {
        return false;
    }
}

bool operator!=(const date& left, const date& right){
    if(left==right){
        return false;
    } else{
        return true;
    }
}

bool operator<(const date& left, const date& right){
    if((left.day<right.day)&&(left.mounth<right.mounth)&&(left.year<right.year)&&(left.hour<right.hour)&&(left.minutes<right.minutes)){
        return false;
    } else{
        return true;
    }
}