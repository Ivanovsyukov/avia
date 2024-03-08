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
class Ticket{
    Array<char>* numeral_;
    Array<char>* from_;
    Array<char>* to_;
    date date_avia_;
    int count_ticket_;
    double sale_;
public:
    Ticket(Array<char>* numeral=nullptr, Array<char>* from=nullptr, Array<char>* to=nullptr, date date_avia, int count_ticket=0, double sale=0.0): numeral_(numeral), from_(from), to_(to), date_avia_(date_avia), count_ticket_(count_ticket), sale_(sale){};
    Ticket(const char* data);
    Ticket(const Ticket& other);
    Ticket& operator=(const Ticket& other);
    Array<char>* ID(){return numeral_;}
    Array<char>* from(){return from_;}
    Array<char>* to(){return to_;}
    date date_ticket(){return date_avia_;}
    int count(){return count_ticket_;}
    double sale(){return sale_;}

    ~Ticket();
};

bool operator==(const Ticket& left, const Ticket& right);
bool operator!=(const Ticket& left, const Ticket& right);
bool operator<(const Ticket& left, const Ticket& right);

std::ostream& operator<<(std::ostream& out, const Ticket& X);
std::ifstream& operator>>(std::ifstream& infile, const Ticket& X);
std::ofstream& operator<<(std::ofstream& outfile, const Ticket& X);
#endif