#include <iostream>
#include <fstream>
#include <list>
#include "JBsSchedule.h"

#define SCHEDULE_GROUP "schedule_group.txt"
#define SCHEDULE "schedule.txt"
/*
schedule.txt
>> string schedule_key
>> string title
>> string start_time
>> strnig end_time
>> string context

schedule_group.txt
>> string group_key
>> string schedule_key [foreign key from schedule.txt]

All of Schedules have at least one group even if group has just one Group.
*/

using namespace std;

class FileController{
public:
	FileController();
	FileController(const FileController &fc);
	virtual ~FileController();
	
	void writeFile(list<JBsSchedule> list);
	list<JBsSchedule> readFile();
	bool isScheduleExist(JBsSchedule schedule);	//need JBsSchedule's == operator
	
	
private:
	ofstream out;
	ifstream in;
};