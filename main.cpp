#include <iostream>
#include <fstream>
#include "utils.h"
//#include "database.h"
#include "ticket.h"

int main(){
	bool out=true;
	const int SIZE=100;
	size_t len;
	char s;
	int i;
	do{
		i=0;
		char* command=nullptr;
		char str[SIZE]={};
		std::cout << "> ";
    	std::cin.getline(str,SIZE);
		len=0;
		s=str[i];
		while(s!=' '){
			push_element(command, &len, s);
			++i;
			s=str[i];
		}
		if(srav_str(command, "load")){
			//load имя_файла_с_БД — чтение базы данных из файла;
		} else if(srav_str(command, "save")){
			//save имя_файла_с_БД — запись базы данных в файл;
		} else if(srav_str(command, "add")){
			//add номер рейса, аэропорт вылета, аэропорт прибытия, дата и время вылета, дата и время прилёта, количество билетов, цена
		} else if(srav_str(command, "delete")){
			//delete ID — удаление записи по её уникальному номеру ID;
		} else if(srav_str(command, "clear")){
			//clear — удаление всех записей из базы данных, у которых количество билетов равно 0;
		} else if(srav_str(command, "print")){
			//print — вывод всего списка авиабилетов, отсортированного по дате и времени вылета (по возрастанию);
		} else if(srav_str(command, "schedule")){
			//schedule аэропорт_вылета дата_вылета — список рейсов отправляющихся из заданного аэропорта в определеную дату, отсортированных по времени вылета;
		} else if(srav_str(command, "from")){
			//from аэропорт_вылета to аэропорт_прилёта on дата_вылета — список билетов (количество больше 0) на текущую дату, отсортированный по возрастанию цены (при равенстве цен упорядоченные по возрастанию времени вылета);
		} else if(srav_str(command, "find")){
			//find аэропорт_вылета to аэропорт_прилёта — самый дешёвый авиаперелет, возможно с одной пересадкой (количество билетов должно быть больше 0);
		} else if(srav_str(command, "buy")){
			//buy номер_рейса дата_вылета — купить самый дешёвый билет на заданный номер рейса на заданную дату (кол-во билетов в базе должно уменьшиться на единицу);
		} else if(srav_str(command, "export")){
			//export имя_файла — вывод всего списка авиабилетов (отсортированного по возрастанию даты и времени вылета) в текстовый файл;
		} else if(srav_str(command, "quit")){
			out=false;
		} else {
			//плохая команда
		}
		delete[] command;
		delete[] str;
	}while(out);
    return 0;
}