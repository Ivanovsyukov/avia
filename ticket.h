#ifndef MY_TICKET_2021
#define MY_TICKET_2021
struct date{
    int day;
    int mounth;
    int year;
    int hour;
    int minutes;
};
class Ticket{
    char number[7];
    char from[3];
    char to[3];
    date date_avia;
    int count_ticket;
    double sale;
public:
    Ticket(char number[7]={}, char from[3]={}, char to[3]={}, int time[5]={}, int count_ticket=0, double sale=0.0);
    void set(char* data);
    ~Ticket();
};
#endif