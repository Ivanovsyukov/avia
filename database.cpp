#include "database.h"
#include "ticket.h"
#include "array.h"
#include "utils.h"

DataBase::DataBase(Ticket& first){
    count_=1;
    Node* red=new Node;
    red->data=first;
    red->num_element=1;
    red->next=nullptr;
    begin_=red;
    end_=red;
}