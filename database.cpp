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

void DataBase::deleteRecord_for_ID(int indentifical){
	Node * parent=nullptr;
	Node * now = begin_;
	while (now && now->num_element!=indentifical){
		parent = now;
		now = now->next;
	}
	if (now){
		if (indentifical == end_->num_element){
			end_ = parent;
		}

		if (parent){
			parent->next = now->next;
			// parent->next = parent->next->next;
		} else {
			begin_ = begin_->next;
		}
		delete now;
	}
	if(indentifical==last_numeral_){
		--last_numeral_;
	}
	--count_;	 
}

void DataBase::clear(){
	Node * parent=nullptr;
	Node * now = begin_;
	if (now->data.count()==0){
		begin_=begin_->next;
		delete now;
	}
	while (now){
		parent = now;
		now = now->next;
		if (now==end_ && now->data.count()==0){
			end_=parent;
			delete now;
			parent->next=nullptr;
		} else if (now->data.count()==0){
			parent->next = now->next;
			delete now;
		}
	}
}