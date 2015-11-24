#include <iostream>
#include <fstream>
#include "Schedule.h"
using namespace std;

/*
this class can open and close file.
and also can read, write file.
overwriting and deletion will be also done in this class.
you guys just get this object(dont call it in class) and use function.

this class is not successfully completed.
*/

class FileLibrarian{
public:
	//FileLibrarian();
	
	virtual ~FileLibrarian();
	inline static FileLibrarian* getInstance(){ 
		lib = new FileLibrarian();
		return lib; 
	}
	void recursiveWrite(string date, int times);
	void rangeWrite(Schedule from, Schedule to);
	void rangeWrite(Schedule from, Schedule to, bool condition);
	
	bool deleteSchedule(Schedule sched, string date);
	bool addSchedule(Schedule sched, string date);
	//bool overwriteSchedule(Schedule sched, string date);
	//i dont have any idea about it.
	
	//bool deleteFile(string date);
	//i think this function won't be used later. tell me if you need

private:
	FileLibrarian();
	FileLibrarian(const FileLibrarian &flb);
	void writeFile(list<Schedule> schd, string date);
	list<Schedule> readFile(string date);
	Schedule parseString(char* input);
	inline string toString(Schedule input){
		return input.getTitle() + "^" + input.getStartTime() + "^" + input.getEndTime() + "^" + input.getContext();
	};
	bool isScheduleExist(list<Schedule> list, Schedule data);
	static FileLibrarian *lib;
	ofstream outputObj;
	ifstream inputObj;
	
	//bool isFileExist(string fileName);
};