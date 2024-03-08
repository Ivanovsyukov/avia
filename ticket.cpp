#include "ticket.h"
#include <fstream>
#include <cstring>
#include "utils.h"

Ticket::Ticket(const char* data){
    size_t len=strlen(data);
    char s=0;
    int ind=0;
    bool mistake=false;
    Array<char>* for_m;
    int indate=0;
    Array<char>* element=nullptr;
    for(size_t i=0; i<len && int(data[i])!=0; ++i){
        s=data[i];
        if(s==' '){
            if (mistake){

            }
            ++ind;
            if (ind==4 || ind==5){
                indate=0;
                Array<char>* element=nullptr;
            }
        } else if (s!=','){
            switch (ind){
            case 1:
                numeral_->push_back(s);
                break;
            case 2:
                from_->push_back(s);
                break;
            case 3:
                to_->push_back(s);
                break;
            case 4:
                for_m->push_back(s);
                if ((s>='0' && s<='9')||(s=='.')){
                    if (s=='.'){
                        ++indate;
                    } else {
                        element->push_back(s);
                    }
                } else {
                    mistake=true;
                }
                break;
            default:
                break;
            }
        }
    }
}