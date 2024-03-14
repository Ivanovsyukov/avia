#ifndef __TICKET_DATABASE__
#define __TICKET_DATABASE__
#include "ticket.h"
#include "array.h"
#include "utils.h"
struct Node{
	Ticket data;
    int num_element;
	Node * next;
};

class DataBase{
    int last_numeral_;
	int count_;
	Node* begin_;
	Node* end_;
public:
    DataBase(int last_numeral=0, int count=0, Node* begin=nullptr, Node* end=nullptr):last_numeral_(last_numeral), count_(count), begin_(begin), end_(end){}
    //DataBase(Ticket& first);
    //first
    void addRecord(Ticket& addend);//ok
    void clear();//ok
    void schedule(Array<char> from_, Array<char> to_);
    void printDB() const;
    void saveDB(const char filename[]) const;
    void exportDB(const char filename[]) const;
    int openDB(const char filename[]);
    void deleteRecord_for_ID(int indentifical);//ok
    Node* findRecord_for_input(Array<char> from_, Array<char> to_) const;
    //second
    void sort();
    Node* findRecord_for_ID(int ID);
    void deleteRecord_for_Node(Node* need_delete);
    ~DataBase(){//ok
        Node* now;
	    while(begin_){
		    now = begin_->next;
		    delete begin_;
		    begin_ = now;
	    }
	    begin_ = end_ = nullptr;
	    count_ = 0;
    }
};



//void mySort(DataBase& DB, bool (*comparator)(const student&, const student&) );
#endif