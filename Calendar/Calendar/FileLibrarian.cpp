#include <string.h>
#include "FileLibrarian.h"
#pragma warning(disable:4996)
#define SIZE 1000

/*
parsing char(3) : 1
time string(2) : 17
title max(1) : 40
context max(1) : 300
nulptr(1) : 1
*/

FileLibrarian::FileLibrarian(){

}
FileLibrarian::FileLibrarian(const FileLibrarian &flb){

}
FileLibrarian::~FileLibrarian(){

}

void FileLibrarian::recursiveWrite(string date, int times){

}
void FileLibrarian::rangeWrite(JBsSchedule from, JBsSchedule to){

}
void FileLibrarian::rangeWrite(JBsSchedule from, JBsSchedule to, bool condition){

}
void FileLibrarian::writeFile(list<JBsSchedule> sched, string date){
	outputObj.open(date + ".txt");
	for (int i = 0; i < sched.size(); i++){
		outputObj << toString(sched.back()).c_str() << endl;
	}
}
list<JBsSchedule> FileLibrarian::readFile(string date){
	list<JBsSchedule> schedules;
	this->inputObj.open(date + ".txt", ios::in);
	while (!inputObj.eof()){
		char temp[SIZE];
		inputObj.getline(temp, SIZE);
		schedules.push_front(parseString(temp));
	}
	inputObj.close();
	return schedules;
}

JBsSchedule FileLibrarian::parseString(char* input){
	char *temp;
	temp = strtok(input, "^");
	string title(temp);
	temp = strtok(NULL, "^");
	string start(temp);
	temp = strtok(NULL, "^");
	string end(temp);
	temp = strtok(NULL, "^");
	string context(temp);
	JBsSchedule ret(title, start, end, context);
	return ret;
}
bool FileLibrarian::addSchedule(JBsSchedule sched, string date){
	
	list<JBsSchedule> list = readFile(date);
	bool ret = isScheduleExist(list, sched);
	if (ret){
		list.push_front(sched);
	}
	return ret;
}
bool FileLibrarian::deleteSchedule(JBsSchedule sched, string date){
	JBsSchedule temp;
	list<JBsSchedule> list = readFile(date);
	bool ret = isScheduleExist(list, sched);
	for (int i = 0; (i < list.size()) && ret; i++){
		temp = list.back();
		if (temp != sched){
			list.push_back(sched);
		}
	}
	writeFile(list, date);
	return ret;

}
bool FileLibrarian::isScheduleExist(list<JBsSchedule> list, JBsSchedule data){
	bool ret = false;
	std::list<JBsSchedule> clone(list);
	while (!ret){
		ret = (clone.back() == data);
	}
	return ret;
}