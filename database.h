#ifndef __TICKET_DATABASE__
#define __TICKET_DATABASE__
#include "ticket.h"
#include "array.h"
#include "utils.h"
struct Node{
	Ticket data;
    int numeral_element;
	Node * next;
};

class DataBase{
	int count_;
	Node* begin_;
	Node* end_;
public:
    DataBase(int count=0, Node* begin=nullptr, Node* end=nullptr):count_(count), begin_(begin), end_(end){}
    DataBase(Node first);
    int addRecord();
    void clear();
    void schedule(Array<char> from_, Array<char> to_);
    void printDB() const;
    void saveDB(const char filename[]) const;
    void exportDB(const char filename[]) const;
    int openDB(const char filename[]);
    void deleteRecord(int indentifical);
    Node* findRecord(Array<char> from_, Array<char> to_) const;
    void sort();
    ~DataBase(){
        delete begin_;
        delete end_;
    }
};



//void mySort(DataBase& DB, bool (*comparator)(const student&, const student&) );
#endif