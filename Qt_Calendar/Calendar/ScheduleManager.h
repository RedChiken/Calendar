#include <iostream>
#include <fstream>
#include "JBsSchedule.h"
#include "TimeManager.h"
#include "FileController.h"
#include <list>
using namespace std;

/*
this class can open and close file.
and also can read, write file.
overwriting and deletion will be also done in this class.
you guys just get this object(dont call it in class) and use function.

this class is not successfully completed.
*/

class ScheduleManager{
public:
	inline static ScheduleManager* getInstance(){
		if (lib == 0){
			lib = new ScheduleManager();
		}
		return lib; 
	}
	list<JBsSchedule> getScheduleList(TimeManager date);
	void recursiveWrite(JBsSchedule schedule, TimeManager cycle, int times = 0);
	void deleteSchedule(JBsSchedule sched);		//	delete specific schedule
	bool addSchedule(JBsSchedule sched);		//	add not-existed-schedule
	//bool overwriteSchedule(Schedule sched, string date);
	//i dont have any idea about it.

private:
	ScheduleManager();
	ScheduleManager(const ScheduleManager &flb);
	virtual ~ScheduleManager();
	FileController *file;
	static ScheduleManager *lib;
	
	//bool isFileExist(string fileName);
};