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
*/

using namespace std;

class FileController{
public:
	FileController();
	FileController(const FileController &fc);
	virtual ~FileController();
	void writeFile(list<JBsSchedule> list);
	list<JBsSchedule> readFile();
	/*
	overloading that need conditions.
	*/
private:
	ofstream out;
	ifstream in;
};