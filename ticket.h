#ifndef MY_TICKET_2021
#define MY_TICKET_2021
#include "array.h"
#include <fstream>
#include <iostream>
struct date{
    int day;
    int mounth;
    int year;
    int hour;
    int minutes;
};

bool operator==(const date& left, const date& right);
bool operator!=(const date& left, const date& right);
bool operator<(const date& left, const date& right);
std::ostream& operator<<(std::ostream& out, const date& X);

class Ticket{
    Array<char> numeral_;
    Array<char> from_;
    Array<char> to_;
    date date_from_;
    date date_to_;
    int count_ticket_;
    double sale_;
public:
    Ticket(Array<char> numeral, Array<char> from, Array<char> to, date date_from, date date_to, int count_ticket=0, double sale=0.0): numeral_(numeral), from_(from), to_(to), date_from_(date_from), date_to_(date_to), count_ticket_(count_ticket), sale_(sale){};
    Ticket(const char* data);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);
    Array<char> ID() const{return numeral_;}
    Array<char> from() const{return from_;}
    Array<char> to() const{return to_;}
    date date_from() const{return date_from_;}
    date date_to() const{return date_to_;}
    int count() const{return count_ticket_;}
    double sale() const{return sale_;}

    ~Ticket(){}
};

bool operator==(const Ticket& left, const Ticket& right);
bool operator!=(const Ticket& left, const Ticket& right);
bool operator<(const Ticket& left, const Ticket& right);

std::ostream& operator<<(std::ostream& out, const Ticket& X);
std::ifstream& operator>>(std::ifstream& infile, const Ticket& X);
std::ofstream& operator<<(std::ofstream& outfile, const Ticket& X);
#endif