#include "database.h"
#include "ticket.h"
#include "array.h"
#include "utils.h"
/*
DataBase::DataBase(Ticket& first){
    count_=1;
    Node* red=new Node;
    red->data=first;
    red->num_element=1;
    red->next=nullptr;
    begin_=red;
    end_=red;
}
*/

void DataBase::addRecord(Ticket& addend){
    Node* tmp = new Node;
	tmp->next = nullptr;
	tmp->data = addend;
    tmp->num_element=++last_numeral_;
	if (begin_){
		end_->next = tmp;
		end_ = tmp;
	} else{
		begin_=tmp;
        end_=tmp;
	}
	++count_;
}

void deleteRecord_for_ID(DataBase& DB){
	Node* index = findRecord(DB);
	if (index == nullptr ) return;

	std::cout<< "Are you sure? (Y/N)";
	char ch[128];
	std::cin.get(ch, 128);
	if (ch[0]=='Y' || ch[0]=='y'){
		Node * parent=nullptr;
		Node * now = DB.begin;
		while (now && now!=index){
			parent = now;
			now = now->next;
		}
		if (now){
			if (index == DB.end){
				DB.end = parent;
			}

			if (parent){
				parent->next = index->next;
				// parent->next = parent->next->next;
			} else {
				DB.begin = DB.begin->next;
			}
			delete index;
		}
		--DB.count;
	}		 
}