#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H
#include <list>
#include "JBsSchedule.h"

#define SCHEDULE "schedule.txt"

using namespace std;

class FileController{
public:
	FileController();
	FileController(const FileController &fc);
	~FileController();

	void writeFile(list<JBsSchedule> &list);
	list<JBsSchedule> readFile();
	bool isScheduleExist(JBsSchedule &schedule);	//need JBsSchedule's == operator

};
#endif