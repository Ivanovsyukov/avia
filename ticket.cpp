#include "ticket.h"
#include <fstream>
#include <cstring>
#include "utils.h"

void Ticket::set(char* data){
    unsigned int ind=0;
    size_t i=0;
    size_t otstup=0;
    char s=data[i];
    while(ind!=9){
        if (s==' '){
            if(ind==4){

            }
            ++ind;
        } else if(s==','){
            continue;
        }
        if (ind==1){
            if (s==' '){
                otstup=0;
            } else {
                number[otstup]=s;
                ++otstup;
            }
            
        } else if (ind==2){
            if (s==' '){
                otstup=0;
            } else {
                from[otstup]=s;
                ++otstup;
            }
        } else if (ind==3){
            if (s==' '){
                otstup=0;
            } else {
                to[otstup]=s;
                ++otstup;
            }
        } else if (ind==4){
            int ind_date=0;
            char* tmp=nullptr;
            if (s==' '){
                otstup=0;
            } else {
                if (s=='.'){
                    if(ind_date==0){
                        if (strlen(tmp)==2){
                            if (tmp[0]=='0'){
                                date_avia->day=tmp[1]-'0';
                            } else {
                                date_avia->day=str_num_to_int_num(tmp);
                            }
                        } else {
                            date_avia->day=str_num_to_int_num(tmp);
                        }
                    } else if(ind_date==1){
                        if (strlen(tmp)==2){
                            if (tmp[0]=='0'){
                                date_avia->mounth=tmp[1]-'0';
                            } else {
                                date_avia->mounth=str_num_to_int_num(tmp);
                            }
                        } else {
                            date_avia->mounth=str_num_to_int_num(tmp);
                        }
                    }
                } else {
                    push_element(tmp, &otstup, s);
                }
            }
        }
        ++i;
        s=data[i];
    }
}