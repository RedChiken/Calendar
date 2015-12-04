// Tester

//#include "FileController.h"
#include "ScheduleManager.h"
#include <string>

using namespace std;

int main(void){
	//FileController fc;
	//list<JBsSchedule> list, readList;
	ScheduleManager *obj = ScheduleManager::getInstance();
	TimeManager start, end, repeat;
	start.setDate(2016, 2, 28);
	start.setTime(23, 59, 59);

	repeat.setDate(0, 0, 0);
	repeat.setTime(0, 0, 1);

	//end.setDate(2015, 12, 17);
	//end.setTime(12, 2, 1);

	TimeManager result = start + repeat;
	JBsSchedule temp("test", start, end, "test ScheduleManager class");
	//obj->addSchedule(temp);
	//obj->deleteSchedule(temp);
	//obj->recursiveWrite(temp, repeat, 3);

	//list<JBsSchedule> readList;
//	list = fc.readFile();
	/*
	for (int i = 0; i < 10; i++){
		string s = to_string(i * 100);
		string c = "context";
		TimeManager tm;
		tm.setDate(2015, 12, 3);
		tm.setTime(3, 30, 30);
		tm.setRepeatDate(true, false, false, 0);
		JBsSchedule sc(s, tm, c);
		list.push_back(sc);
	}*/
	
	

//	fc.writeFile(list);
	//readList = fc.readFile();

	cout << "file is read\n";

	return 0;
}