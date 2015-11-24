#include "FileLibrarian.h"
#include "Schedule.h"
#include <list>
#include <string.h>
#pragma warning(disable:4996)

FileLibrarian::FileLibrarian(){

}
FileLibrarian::FileLibrarian(const FileLibrarian &flb){

}
FileLibrarian::~FileLibrarian(){

}

void FileLibrarian::recursiveWrite(string date, int times){

}
void FileLibrarian::rangeWrite(Schedule from, Schedule to){

}
void FileLibrarian::rangeWrite(Schedule from, Schedule to, bool condition){

}
void FileLibrarian::writeFile(list<Schedule> sched, string date){
	outputObj.open(date + ".txt");
	for (int i = 0; i < sched.size(); i++){
		char temp[INT_MAX];
		strcpy(temp, toString(sched.back()).c_str());
		outputObj << temp << endl;
	}
}
list<Schedule> FileLibrarian::readFile(string date){
	list<Schedule> schedules;
	this->inputObj.open(date + ".txt", ios::in);
	while (!inputObj.eof()){
		char temp[INT_MAX];
		inputObj.getline(temp, INT_MAX);
		schedules.push_front(parseString(temp));
	}
	inputObj.close();
	return schedules;
}

Schedule FileLibrarian::parseString(char* input){
	char *temp;
	temp = strtok(input, "^");
	string title(temp);
	temp = strtok(NULL, "^");
	string start(temp);
	temp = strtok(NULL, "^");
	string end(temp);
	temp = strtok(NULL, "^");
	string context(temp);
	Schedule ret(title, start, end, context);
	return ret;
}
bool FileLibrarian::addSchedule(Schedule sched, string date){
	
	list<Schedule> list = readFile(date);
	bool ret = isScheduleExist(list, sched);
	if (ret){
		list.push_front(sched);
	}
	return ret;
}
bool FileLibrarian::deleteSchedule(Schedule sched, string date){
	Schedule temp;
	list<Schedule> list = readFile(date);
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
bool FileLibrarian::isScheduleExist(list<Schedule> list, Schedule data){
	bool ret = false;
	std::list<Schedule> clone(list);
	while (!ret){
		ret = (clone.back() == data);
	}
	return ret;
}