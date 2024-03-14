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

void DataBase::schedule(Array<char> from_air, date data_from){
	Ticket* important=nullptr;
	size_t important_size=0;
	Node * now = begin_;
	while(now){
		if (now->data.from()==from_air && (equal_date_without_time(data_from, now->data.date_from()))){
			push_element(important, &important_size, now->data);
		}
		now = now->next;
	}
	//sort
	Ticket* tmp = new Ticket[important_size];
	Ticket* from = important;
	Ticket* to = tmp;
	for(size_t step=1; step < important_size; step*=2){
		size_t start1, end1, start2, end2;
		size_t indto = 0;
		for(size_t start=0; start<important_size; start += 2*step){
			start1 = start;
			end1 = start1+step;
			end1 = end1<important_size ? end1 : important_size;
			start2 = end1;
			end2 = start2+step;
			end2 = end2<important_size ? end2 : important_size;
			while(start1<end1 && start2<end2){
				to[indto++] = (minimum_time_without_date(from[start1++].date_from(), from[start2++].date_from())) ? from[start1++] : from[start2++];
			}
			while(start1<end1){
				to[indto++] = from[start1++];
			}
			while(start2<end2){
				to[indto++] = from[start2++];
			}
		}
		std::swap(from, to);
	}

	if (from!=important){
		size_t ind=0;
		while(ind < important_size){
			important[ind] = tmp[ind];
			++ind;
		}
	}
	delete[] tmp;
	//output
	for(size_t i=0; i<important_size; ++i){
		std::cout<<important[i].ID()<<" "<<important[i].from()<<important[i].date_from()<<std::endl;
	}
}