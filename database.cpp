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
	DataBase mini;
	Node * now = begin_;
	while(now){
		if (now->data.from()==from_air && (equal_date_without_time(data_from, now->data.date_from()))){
			mini.addRecord(now->data);
		}
		now = now->next;
	}
	//sort
	mini.sort(time_from_ticket);
	//output
	Node * nows = mini.begin_;
	while(nows){
		std::cout<<nows->data.from()<<" "<<nows->data.date_from()<<std::endl;
		nows = nows->next;
	}
}

void DataBase::sort(bool (*comparator)(const Ticket&, const Ticket&)){
	if (begin_ == end_) return;
	bool isSorted = false;
	do{
		// Split
		DataBase tmp[2];
		unsigned char p=0;
		tmp[p].begin_ = tmp[p].end_ = begin_;
		begin_ = begin_->next;
		tmp[!p].begin_ = tmp[!p].end_ = nullptr;

		while(begin_ != nullptr){
			if(comparator(begin_->data, tmp[p].end_->data))
				p = !p;
			if (tmp[p].begin_)
				tmp[p].end_->next = begin_;
			else
				tmp[p].begin_ = begin_;
			tmp[p].end_ = begin_;
			begin_ = begin_->next;
		}
		if (tmp[p].end_) tmp[p].end_->next=nullptr;
		if (tmp[!p].end_) tmp[!p].end_->next=nullptr;

		// Merge
		if (tmp[!p].begin_){
			bool s1, s2;
			p = comparator(tmp[0].begin_->data, tmp[1].begin_->data) ? 0 : 1;
			begin_ = end_ = tmp[p].begin_;
			tmp[p].begin_ = tmp[p].begin_->next;
			while(tmp[p].begin_){
				s1 = comparator(tmp[p].begin_->data, end_->data);
				s2 = comparator(tmp[!p].begin_->data, end_->data);
				if(s1==s2)
					p = comparator(tmp[0].begin_->data, tmp[1].begin_->data) ? 0 : 1;
				else
					if(s1){
						p=!p;
					}
				end_->next = tmp[p].begin_;
				end_ = end_->next;
				tmp[p].begin_ = tmp[p].begin_->next;
			}
			end_->next = tmp[!p].begin_;
			end_ = tmp[!p].end_;
		} else{
			isSorted = true;
			begin_ = tmp[p].begin_;
			end_ = tmp[p].end_;
		}
	}while(!isSorted);
}
