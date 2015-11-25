#include <iostream>
#include <fstream>
#include "JBsSchedule.h"
#include <list>
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
	void rangeWrite(JBsSchedule from, JBsSchedule to);
	void rangeWrite(JBsSchedule from, JBsSchedule to, bool condition);
	
	bool deleteSchedule(JBsSchedule sched, string date);
	bool addSchedule(JBsSchedule sched, string date);
	//bool overwriteSchedule(Schedule sched, string date);
	//i dont have any idea about it.
	
	//bool deleteFile(string date);
	//i think this function won't be used later. tell me if you need

private:
	FileLibrarian();
	FileLibrarian(const FileLibrarian &flb);
	void writeFile(list<JBsSchedule> schd, string date);
	list<JBsSchedule> readFile(string date);
	JBsSchedule parseString(char* input);
	inline string toString(JBsSchedule input){
		return input.getTitle() + "^" + input.getStartTime() + "^" + input.getEndTime() + "^" + input.getContext();
	};
	bool isScheduleExist(list<JBsSchedule> list, JBsSchedule data);
	static FileLibrarian *lib;
	ofstream outputObj;
	ifstream inputObj;
	
	//bool isFileExist(string fileName);
};