#include <string.h>
#include "ScheduleManager.h"
#include "FileController.h"
#include <iostream>
#include <list>
#include "JBsSchedule.h"
#pragma warning(disable:4996)
#define SIZE 1000

/*
parsing char(3) : 1
time string(2) : 17
title max(1) : 40
context max(1) : 300
nulptr(1) : 1
*/

ScheduleManager::ScheduleManager(){

}
ScheduleManager::ScheduleManager(const ScheduleManager &flb){

}
ScheduleManager::~ScheduleManager(){

}

void ScheduleManager::recursiveWrite(JBsSchedule schedule, TimeManager cycle, int times = 0){
	file = new FileController();
	bool flag = (times == 0);
	if (flag){
		recursiveWrite(schedule, cycle, 10);
	}
	else{
		list<JBsSchedule> temp = file->readFile();
		for (int i = 0; i < times; i++){
			temp.push_front(schedule);
			
			schedule.getStartTime() += cycle;
			schedule.getEndTime() += cycle;
			/*
			I think we need constructor JBsSchedule(JBsSchedule start, TimeManager cycle)
			that add startTime and endTime as much as cycle time.
			And we need += operator in JBsSchedule
			*/
		}
		file->writeFile(temp);
	}
	delete file;
}

bool ScheduleManager::addSchedule(JBsSchedule sched){
	file = new FileController();
	bool flag = file->isScheduleExist(sched);
	if (flag){
		file->readFile().push_front(sched);
	}
	delete file;
	return flag;
}
void ScheduleManager::deleteSchedule(JBsSchedule sched){
	file = new FileController();
	JBsSchedule temp;
	list<JBsSchedule> list = file->readFile();
	std::list<JBsSchedule>::iterator findSchedule = std::find(list.begin(), list.end(), sched);
	list.erase(findSchedule);
	/*
	for (int i = 0; i < list.size(); i++){
		temp = list.front();
		if (temp != sched){
			list.push_back(temp);
		}
	}
	*/
	file->writeFile(list);
	delete file;
}